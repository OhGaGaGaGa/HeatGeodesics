#ifndef FACE_H
#define FACE_H

#include <Eigen/Core>
class Vertex;
class Edge;

class Face {
    std::vector<Vertex*> vertices;
    std::vector<Edge*> edges;
    Eigen::Vector3d normal;
    Eigen::Vector3d grad;

    int index;
    
    void calcNormal();
public:
    Face(Vertex& v1, Vertex& v2, Vertex& v3, int ind) : index(ind) {
        vertices.push_back(&v1);
        vertices.push_back(&v2);
        vertices.push_back(&v3);

        calcNormal();
    }
    std::vector<Vertex*> getVertices() const {
        return vertices;
    }
    std::vector<Edge*> getEdges() const {
        return edges;
    }
    Vertex* getVertex(int i) const {
        return vertices[i];
    }
    Edge* getEdge(int i) const {
        return edges[i];
    }
    Eigen::Vector3d getNormal() const {
        return normal;
    }
    Eigen::Vector3d getGrad() const {
        return grad;
    }
    double getArea() const;

    void addEdge(Edge& e) {
        edges.push_back(&e);
    }
    void addVertex(Vertex& v) {
        vertices.push_back(&v);
    }
};

#endif // FACE_H