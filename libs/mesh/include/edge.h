#ifndef EDGE_H
#define EDGE_H

#include <Eigen/Core>
class Vertex;
class Face;

class Edge {
    Vertex *vi;
    Vertex *vj;

    int index;

    std::vector<Face *> faces;

public:
    Edge(Vertex &vi, Vertex &vj, int ind) : vi(&vi), vj(&vj), index(ind){};
    double getNeighboorArea();
    void addFace(Face &f) {
        faces.push_back(&f);
    }
    std::vector<Face *> getFaces() const {
        return faces;
    }
    Face *getFace(int i) const {
        return faces[i];
    }
    Vertex *getVertex(int i) const {
        if (i == 0) {
            return vi;
        } else {
            return vj;
        }
    }
    double getLength() const;
    double sumCotan() const;
    double sumArea() const;
    Vertex *anotherVertex(const Vertex &v) const {
        if (vi == &v) {
            return vj;
        } else {
            return vi;
        }
    }
};

#endif // EDGE_H