#include <iostream>
#include <math.h>

#include "../headers/Point.h"
#include "../headers/Circle.h"

Circle::Circle() : mCenter(0, 0),
                   mRadius(0.0)
{
}

Circle::~Circle()
{
}

void Circle::getData()
{
    double x;
    double y;
    std::cout << "Enter Center Point and Radius (x,y,radius)" << std::endl;
    std::cin >> x >> y >> mRadius;
    mCenter = Point(x, y);
    generateShape();
}
void Circle::generateShape()
{
    const double pi = 3.14159;
    for (double angleDegree = 0; angleDegree <= 360; angleDegree += 2)
    {
        double angleRad = angleDegree * (pi / 180);
        double x = mCenter.x() + (mRadius * cos(angleRad));
        double y = mCenter.y() + (mRadius * sin(angleRad));

        Point cp = Point(x, y);
        mData.push_back(cp);
    }
    
    saveShape();
}