#include "vertex.h"
#include "edge.h"
#include "face.h"

Edge *Vertex::getEdgeTo(const Vertex &v) const{
    for (auto e : edges) {
        if (e->getVertex(0) == &v || e->getVertex(1) == &v) {
            return e;
        }
    }
    return nullptr;
}