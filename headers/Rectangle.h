#pragma once

#include "Geometry.h"

class Rectangle:public Geometry
{    
public:
    Rectangle(/* args */);
    ~Rectangle();

    void getData();

protected:
    void generateShape();

    private:
        Point mP1;
        Point mP2;
        Point mP3;
};