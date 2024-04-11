#include "vertex.h"
#include "edge.h"
#include "face.h"
#include <Eigen/Dense>
#include <iostream>
using std::cout;
using std::endl;

void Face::calcNormal() {
    Eigen::Vector3d e1 = vertices[1]->getPosition() - vertices[0]->getPosition();
    Eigen::Vector3d e2 = vertices[2]->getPosition() - vertices[0]->getPosition();
    normal = e1.cross(e2).normalized();
}

double Face::getArea() const {
    Eigen::Vector3d e1 = vertices[1]->getPosition() - vertices[0]->getPosition();
    Eigen::Vector3d e2 = vertices[2]->getPosition() - vertices[0]->getPosition();
    return 0.5 * e1.cross(e2).norm();
}