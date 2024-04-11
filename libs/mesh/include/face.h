#ifndef FACE_H
#define FACE_H

#include <Eigen/Core>
class Vertex;
class Edge;

class Face {
    std::vector<Vertex*> vertexs;
    std::vector<Edge*> edges;
    Eigen::Vector3d normal;

    int index;
};

#endif // FACE_H