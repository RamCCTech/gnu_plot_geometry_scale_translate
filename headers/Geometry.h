#include <vector>

#pragma once

#include "Point.h"

class Geometry
{
public:
    Geometry();
    ~Geometry();

    virtual void getData() = 0;

protected:
    virtual void generateShape() = 0;

    void saveShape();
    void saveShape3D();
    std::vector<double> multiplyMatrixVector(const std::vector<std::vector<double>>& matrix, const std::vector<double>& vector);
    std::vector<std::vector<double>> createScalingMatrix(double scaleX, double scaleY, double scaleZ);
    std::vector<std::vector<double>> createTranslationMatrix(double scaleX, double scaleY, double scaleZ);

protected:
    std::vector<Point> mData;
};
