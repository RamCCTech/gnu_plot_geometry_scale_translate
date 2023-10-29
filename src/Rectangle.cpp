#include <iostream>
#include "../headers/Rectangle.h"

Rectangle::Rectangle():
    mP1(0,0),
    mP2(0,0),
    mP3(0,0)
{
}

Rectangle::~Rectangle()
{
}

void Rectangle::getData()
{
    double x1;
    double y1;

    double x3;
    double y3;

    std::cout << "Enter diagonal points" << std::endl;
    std::cin >> x1 >> y1 >> x3 >> y3;
    mP1 = Point(x1, y1);
    mP3 = Point(x3, y3);
    generateShape();
    
}
void Rectangle::generateShape()
{
    mData.push_back(mP1);
    mP2 = Point( mP3.x(), mP1.y());
    mData.push_back(mP2);
    mData.push_back(mP3);
    mData.push_back(Point(mP1.x(), mP3.y()));   
    mData.push_back(mP1);   
    saveShape();
}
