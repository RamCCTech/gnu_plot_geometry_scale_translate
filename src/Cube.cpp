#include <fstream>
#include <iostream>
#include <sstream>
#include <math.h>

#include "../headers/Point.h"
#include "../headers/Cube.h"

Cube::Cube() :points(){
}

Cube::~Cube(){
}

void Cube::getData(){
    std::ifstream dataFile;
    dataFile.open("./input/cubeModel.stl");
    
    std::string line;

    while (std::getline(dataFile, line)) {

        if (line.find("vertex") !=std::string::npos) {
            std::istringstream iss(line);
            std::string token;
            float x,y,z;
            iss>>token>>x>>y>>z;

            Point point(x,y,z);
            points.push_back(point);
        }
    }

    dataFile.close();
    generateShape();
}

void Cube::scale(double scaleX, double scaleY, double scaleZ){
    std::vector<std::vector<double>> scalingMatrix = createScalingMatrix(scaleX, scaleY, scaleZ);
    
    for (int i = 0; i < points.size(); i++) {
        std::vector<double> pointHomogeneous = {points[i].x(), points[i].y(), points[i].z(), 1.0};
        std::vector<double> scaledPointHomogeneous = multiplyMatrixVector(scalingMatrix, pointHomogeneous);
        
        double scaledX = scaledPointHomogeneous[0] / scaledPointHomogeneous[3];
        double scaledY = scaledPointHomogeneous[1] / scaledPointHomogeneous[3];
        double scaledZ = scaledPointHomogeneous[2] / scaledPointHomogeneous[3];
        
        points[i] = Point(scaledX, scaledY, scaledZ);
    }
    
    generateShape();
}

void Cube::scaleUp(double scaleX, double scaleY, double scaleZ) {
    scale(scaleX,scaleY,scaleZ);
}


void Cube::scaleDown(double scaleX, double scaleY, double scaleZ) {
    double invScaleX = 1.0 / scaleX;
    double invScaleY = 1.0 / scaleY;
    double invScaleZ = 1.0 / scaleZ;

    scale(invScaleX, invScaleY, invScaleZ);
}

void Cube::translate(double transX, double transY, double transZ) {
    std::vector<std::vector<double>> transMatrix = createTranslationMatrix(transX, transY, transZ);

    for (int i = 0; i < points.size(); i++) {
        std::vector<double> pointHomogeneous = {points[i].x(), points[i].y(), points[i].z(), 1.0};
        std::vector<double> transPointHomogeneous = multiplyMatrixVector(transMatrix, pointHomogeneous);

        points[i] = Point(transPointHomogeneous[0], transPointHomogeneous[1], transPointHomogeneous[2]);
    }

    generateShape();
}

void Cube::rotate(char axis, double angle){
    double const pi = 3.14159265359;
    angle = (angle * (pi / 180));
 
    switch(axis){
        case 'x': {
            for (size_t i = 0; i < points.size(); i++){
                double xp = points[i].x();
                double yp = points[i].y();
                double zp = points[i].z();

                double xd = xp;
                double yd = (yp*cos(angle)) - (zp*sin(angle));
                double zd = (yp*sin(angle)) + (zp*cos(angle));

                points[i]=Point(xd,yd,zd);
            }
            break;
        }
        case 'y': {
            for (size_t i = 0; i < points.size(); i++)
            {
                double xp = points[i].x();
                double yp = points[i].y();
                double zp = points[i].z();

                double xd = (zp*sin(angle)) + (xp*cos(angle));
                double yd = yp;
                double zd = (zp*cos(angle)) - (xp*sin(angle));
                
                points[i]=Point(xd,yd,zd);
            }
            break;
        }
        case 'z': {
            for (size_t i = 0; i < points.size(); i++){
                double xp = points[i].x();
                double yp = points[i].y();
                double zp = points[i].z();

                double xd = (xp*cos(angle)) - (yp*sin(angle));
                double yd = (xp*sin(angle)) + (yp*sin(angle));
                double zd = zp;
                
                points[i]=Point(xd,yd,zd);
            }
            break;
        }
    }
    generateShape();
}


void Cube::generateShape(){
    mData.clear();
    for(int i=0;i<points.size();i++){
        mData.push_back(points[i]);
        if(i%3==2)mData.push_back(points[i-2]);
    }
    saveShape3D();
}