#ifndef EDGE_H
#define EDGE_H

#include <Eigen/Core>
class Vertex;
class Face;

class Edge {
    Vertex* vi;
    Vertex* vj;

    int index;

    std::vector<Face*> faces;

public:
    double getNeighboorAera();
};

#endif // EDGE_H