#ifndef VERTEX_H
#define VERTEX_H

#include <Eigen/Core>
class Edge;
class Face;

class Vertex {
    Eigen::Vector3d position;
    int index;

    std::vector<Edge*> edges;
    std::vector<Face*> faces;
};

#endif // VERTEX_H