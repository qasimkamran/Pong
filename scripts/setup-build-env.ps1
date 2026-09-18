[CmdletBinding()]
param(
    [string]$VcpkgRoot = (Join-Path $env:USERPROFILE "vcpkg"),
    [ValidateSet("x64", "x86", "arm64")]
    [string]$Architecture = "x64"
)

$ErrorActionPreference = "Stop"

$vswhere = Join-Path ${env:ProgramFiles(x86)} `
    "Microsoft Visual Studio\Installer\vswhere.exe"

if (-not (Test-Path -LiteralPath $vswhere)) {
    throw "vswhere.exe was not found. Install Visual Studio 2022 Build Tools or Visual Studio 2022 with the 'Desktop development with C++' workload."
}

$vsInstallPath = & $vswhere `
    -latest `
    -products * `
    -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 `
    -property installationPath

if (-not $vsInstallPath) {
    throw "No Visual Studio installation with the MSVC x86/x64 build tools was found. Add the 'Desktop development with C++' workload in Visual Studio Installer."
}

$devShellModule = Join-Path $vsInstallPath `
    "Common7\Tools\Microsoft.VisualStudio.DevShell.dll"

if (-not (Test-Path -LiteralPath $devShellModule)) {
    throw "Visual Studio developer-shell module was not found at '$devShellModule'."
}

Import-Module $devShellModule
Enter-VsDevShell `
    -VsInstallPath $vsInstallPath `
    -SkipAutomaticLocation `
    -DevCmdArguments "-arch=$Architecture -host_arch=x64"

$env:VCPKG_ROOT = (Resolve-Path -LiteralPath $VcpkgRoot).Path
$toolchain = Join-Path $env:VCPKG_ROOT "scripts\buildsystems\vcpkg.cmake"

if (-not (Test-Path -LiteralPath $toolchain)) {
    throw "The vcpkg toolchain was not found at '$toolchain'. Bootstrap vcpkg first or pass -VcpkgRoot <path>."
}

foreach ($command in @("cl.exe", "cmake.exe", "ninja.exe")) {
    if (-not (Get-Command $command -ErrorAction SilentlyContinue)) {
        throw "'$command' is not available on PATH after initializing the build environment."
    }
}

$env:CMAKE_TOOLCHAIN_FILE = $toolchain

Write-Host "Build environment ready:" -ForegroundColor Green
Write-Host "  Visual Studio: $vsInstallPath"
Write-Host "  Architecture:  $Architecture"
Write-Host "  vcpkg:        $env:VCPKG_ROOT"
Write-Host "  Toolchain:    $env:CMAKE_TOOLCHAIN_FILE"
Write-Host ""
Write-Host "Configure and build with:"
Write-Host "  cmake --fresh -S . -B build-ninja -G Ninja -DCMAKE_BUILD_TYPE=Release"
Write-Host "  cmake --build build-ninja"

