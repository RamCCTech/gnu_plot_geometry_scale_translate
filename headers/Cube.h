#pragma once

#include <vector>
#include "Geometry.h"
#include "Point.h"

class Cube:public Geometry
{

public:
    Cube();
    ~Cube();

    void getData();
    void scaleUp(double scaleX, double scaleY, double scaleZ);
    void scaleDown(double scaleX, double scaleY, double scaleZ);
    void translate(double transX, double transY, double transZ);
    void rotate(char axis, double angle);
protected:
    void generateShape();

private:
    void scale(double scaleX, double scaleY, double scaleZ);
    
    std::vector<Point> points;

};