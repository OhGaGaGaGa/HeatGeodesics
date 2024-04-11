#ifndef VERTEX_H
#define VERTEX_H

#include <Eigen/Core>
class Edge;
class Face;

class Vertex {
    Eigen::Vector3d position;
    int index;

    std::vector<Edge *> edges;
    std::vector<Face *> faces;

public:
    Vertex(const Eigen::Vector3d &posi, int ind) : position(posi), index(ind){};
    Eigen::Vector3d getPosition() const {
        return position;
    }
    int getIndex() const {
        return index;
    }
    std::vector<Edge *> getEdges() const {
        return edges;
    }
    std::vector<Face *> getFaces() const {
        return faces;
    }
    Eigen::Vector3d operator-(const Vertex &rhs) const {
        return position - rhs.getPosition();
    }
    void addEdge(Edge &e) {
        edges.push_back(&e);
    }
    void addFace(Face &f) {
        faces.push_back(&f);
    }
    Edge *getEdgeTo(const Vertex &v) const;
};

#endif // VERTEX_H