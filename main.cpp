#include "./headers/Circle.h"
#include "./headers/Rectangle.h"
#include "./headers/Cube.h"
#include <fstream>
#include <iostream>
#include <sstream>

int main()
{
    Cube cube;
    cube.getData();
    cube.scaleUp(3,2,1);
    cube.translate(2,3,3);
}