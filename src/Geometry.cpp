#include <fstream>
#include <iostream>
#include <sstream>

#include "../headers/Geometry.h"

Geometry::Geometry(/* args */)
{
}

Geometry::~Geometry()
{
}

void Geometry::saveShape()
{
  std::ofstream dataFile;
  dataFile.open("./output/output.txt");
  
  for (size_t i = 0; i < mData.size(); i++)
  {
    double r = 25 + ( std::rand() % ( 63 - 25 + 1 ) );
      dataFile << mData[i].x() << " " << mData[i].y() << " "<< r << std::endl;
  }
  dataFile.close();
}

void Geometry::saveShape3D()
{
  std::ofstream dataFile;
  dataFile.open("./output/output.txt", std::ios::trunc);
  
  for (size_t i = 0; i < mData.size(); i++)
  {
      dataFile << mData[i].x() << " " << mData[i].y() << " "<< mData[i].z() << std::endl;
  }
  dataFile.close();
}

std::vector<std::vector<double>> Geometry::createScalingMatrix(double scaleX, double scaleY, double scaleZ) {
    std::vector<std::vector<double>> scalingMatrix(4, std::vector<double>(4, 0.0));

    scalingMatrix[0][0] = scaleX;
    scalingMatrix[1][1] = scaleY;
    scalingMatrix[2][2] = scaleZ;
    scalingMatrix[3][3] = 1.0;

    return scalingMatrix;
}

std::vector<std::vector<double>> Geometry::createTranslationMatrix(double transX, double transY, double transZ){
  std::vector<std::vector<double>> transMatrix(4, std::vector<double>(4, 0.0));

    transMatrix[0][3] = transX;
    transMatrix[1][3] = transY;
    transMatrix[2][3] = transZ;
    transMatrix[0][0] = 1.0;
    transMatrix[1][1] = 1.0;
    transMatrix[2][2] = 1.0;
    transMatrix[3][3] = 1.0;

    return transMatrix;
}

std::vector<double> Geometry::multiplyMatrixVector(const std::vector<std::vector<double>>& matrix, const std::vector<double>& vector) {
    std::vector<double> result(4, 0.0);

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            result[i] += matrix[i][j] * vector[j];
        }
    }

    return result;
}
