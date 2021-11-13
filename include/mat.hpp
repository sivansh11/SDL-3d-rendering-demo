#ifndef mat_hpp

#include <iostream>
#include <math.h>
#include <string>

#include "vec3.hpp"

struct Mat
{
    // matrix class with regular matrix operation implimented
    int row;
    int col;

    float *arr;

    Mat();
    Mat(int r, int c);
    Mat(const Mat &m);

    ~Mat();

    Mat& operator = (const Mat& rhs);

    Mat& operator += (const Mat& rhs);
    Mat operator + (const Mat& rhs);
    Mat& operator += (const float rhs);
    Mat operator + (const float rhs);

    Mat& operator -= (const Mat& rhs);
    Mat operator - (const Mat& rhs);
    Mat& operator -= (const float rhs);
    Mat operator - (const float rhs);

    Mat operator * (const Mat& rhs);
    Mat operator * (const float rhs);
    Vec3 operator * (const Vec3& rhs);

    Mat operator / (const float rhs);

    void set(int i, int j, float val)
    {
        arr[j * row + i] = val;
    }

    void show()
    {  
        for (int i = 0; i < row; i++)
        {
            std::string line;
            for (int j = 0; j < col; j++)
            {
                std::string num = std::to_string(arr[j * row + i]);
                line += num + ' ';
            }
            std::cout << line << std::endl;
        }
        std::cout << std::endl;
    }

};

void rotateZ(Mat &m, float phi);
void rotateY(Mat &m, float phi);
void rotateX(Mat &m, float phi);

#endif