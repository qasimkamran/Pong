#include "raylib.h"

namespace physics
{
    bool PointAtEdge(Vector2 point, Vector2 edgeStart, Vector2 edgeEnd)
    {
        Vector2 edge = { edgeEnd.x - edgeStart.x, edgeEnd.y - edgeStart.y };
        Vector2 toPoint = { point.x - edgeStart.x, point.y - edgeStart.y };

        float crossProduct = (edge.x * toPoint.y) - (edge.y * toPoint.x);
        
        return crossProduct < 0.1f && crossProduct > -0.1f;
    }

    bool PointPastEdge(Vector2 point, Vector2 edgeStart, Vector2 edgeEnd)
    {
        Vector2 edge = { edgeEnd.x - edgeStart.x, edgeEnd.y - edgeStart.y };
        Vector2 toPoint = { point.x - edgeStart.x, point.y - edgeStart.y };

        float crossProduct = (edge.x * toPoint.y) - (edge.y * toPoint.x);
        
        return crossProduct < 0; 
    }
} //namespace physics
