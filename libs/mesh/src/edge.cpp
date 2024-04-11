#include "vertex.h"
#include "edge.h"
#include "face.h"
#include <cassert>

double Edge::getNeighboorArea() {
    double area = 0;
    for (Face *face : faces) {
        area += face->getArea();
    }
    return area;
}

double Edge::getLength() const {
    return (vi->getPosition() - vj->getPosition()).norm();
}

double Edge::sumCotan() const {
    double sum = 0;
    assert(faces.size() == 2);
    for (Face *face : faces) {
        for (Vertex *vertex : face->getVertices()) {
            if (vertex != vi && vertex != vj) {
                Eigen::Vector3d e1 = vi->getPosition() - vertex->getPosition();
                Eigen::Vector3d e2 = vj->getPosition() - vertex->getPosition();
                sum += e1.dot(e2) / e1.cross(e2).norm();
            }
        }
    }
    return sum;
}

double Edge::sumArea() const {
    double sum = 0;
    for (Face *face : faces) {
        sum += face->getArea();
    }
    return sum;
}