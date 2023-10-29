#pragma once

#include "Geometry.h"
#include "Point.h"

class Circle:public Geometry
{

public:
    Circle();
    ~Circle();

    void getData();

    protected:
    void generateShape();

private:
    Point mCenter;
    double mRadius;
};