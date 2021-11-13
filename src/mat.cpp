#include "mat.hpp"


Mat::Mat()
{
    row = col = -1;
    arr = nullptr;
}
Mat::Mat(int r, int c)
{
    row = r;
    col = c;
    arr = new float[row * col];
}
Mat::Mat(const Mat &m)
{
    row = m.row;
    col = m.col;
    arr = new float[row * col];
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            arr[j * row + i] = m.arr[j * row + i];
}
Mat::~Mat()
{
    delete[] arr;
}

Mat& Mat::operator = (const Mat& rhs)
{   
    row = rhs.row;
    col = rhs.col;
    
    delete[] arr;
    arr = new float[row * col];
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            arr[j * row + i] = rhs.arr[j * row + i];
    return *this;
}

Mat& Mat::operator += (const Mat& rhs)
{
    if (row != rhs.row && col != rhs.col)
        throw std::invalid_argument( "something wrong" );
    int size = row * col;
    for (int i = 0; i < size; i++)
        arr[i] += rhs.arr[i];
    return *this;
}
Mat Mat::operator + (const Mat& rhs)
{
    if (row != rhs.row && col != rhs.col)
        throw std::invalid_argument( "something wrong" );
    Mat res(row, col);
    int size = row * col;
    for (int i = 0; i < size; i++)
        res.arr[i] = arr[i] + rhs.arr[i];
    return res;
}
Mat& Mat::operator += (const float rhs)
{
    int size = row * col;
    for (int i = 0; i < size; i++)
        arr[i] += rhs;
    return *this;
}
Mat Mat::operator + (const float rhs)
{
    Mat res(row, col);
    int size = row * col;
    for (int i = 0; i < size; i++)
        res.arr[i] = arr[i] + rhs;
    return res;
}
Mat& Mat::operator -= (const Mat& rhs)
{
    if (row != rhs.row && col != rhs.col)
        throw std::invalid_argument( "something wrong" );
    int size = row * col;
    for (int i = 0; i < size; i++)
        arr[i] -= rhs.arr[i];
    return *this;
}
Mat Mat::operator - (const Mat& rhs)
{
    if (row != rhs.row && col != rhs.col)
        throw std::invalid_argument( "something wrong" );
    Mat res(row, col);
    int size = row * col;
    for (int i = 0; i < size; i++)
        res.arr[i] = arr[i] - rhs.arr[i];
    return res;
}
Mat& Mat::operator -= (const float rhs)
{
    int size = row * col;
    for (int i = 0; i < size; i++)
        arr[i] -= rhs;
    return *this;
}
Mat Mat::operator - (const float rhs)
{
    Mat res(row, col);
    int size = row * col;
    for (int i = 0; i < size; i++)
        res.arr[i] = arr[i] - rhs;
    return res;
}

Mat Mat::operator * (const Mat& rhs)
{
    if (col != rhs.row)
        throw std::invalid_argument( "something wrong" );
    Mat res(row, rhs.col);
    float sum;
    
    for (int i = 0; i < row; i++)
        for (int j = 0; j < rhs.col; j++)
        {
            sum = 0;
            for (int k = 0; k < col; k++)
                sum += arr[k * row + i] * rhs.arr[j * rhs.row + k];
            res.arr[j * res.row + i] = sum;
        }
    return res;
}
Mat Mat::operator * (const float rhs)
{

    Mat res(row, col);
    
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            res.arr[j * row + i] = arr[j * row + i] * rhs;
    return res;
}
Vec3 Mat::operator * (const Vec3& rhs)
{
    if (col == row == 3)
        throw std::invalid_argument( "something wrong" );
    
    Mat vec_mat(3, 1);

    vec_mat.arr[0] = rhs.x;
    vec_mat.arr[1] = rhs.y;
    vec_mat.arr[2] = rhs.z;

    Mat res = *this * vec_mat;

    return Vec3(res.arr[0], res.arr[1], res.arr[2]);

}
Mat Mat::operator / (const float rhs)
{

    Mat res(row, col);
    
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            res.arr[j * row + i] = arr[j * row + i] / rhs;
    return res;
}

void rotateZ(Mat &m, float phi)
{
    float cos_phi = cos(phi);
    float sin_phi = sin(phi);

    m.set(0, 0, cos_phi);
    m.set(0, 1, sin_phi);
    m.set(0, 2, 0);

    m.set(1, 0, -sin_phi);
    m.set(1, 1, cos_phi);
    m.set(1, 2, 0);

    m.set(2, 0, 0);
    m.set(2, 1, 0);
    m.set(2, 2, 1);
}

void rotateY(Mat &m, float phi)
{
    float cos_phi = cos(phi);
    float sin_phi = sin(phi);

    m.set(0, 0, cos_phi);
    m.set(0, 1, 0);
    m.set(0, 2, -sin_phi);

    m.set(1, 0, 0);
    m.set(1, 1, 1);
    m.set(1, 2, 0);

    m.set(2, 0, sin_phi);
    m.set(2, 1, 0);
    m.set(2, 2, cos_phi);
}

void rotateX(Mat &m, float phi)
{
    float cos_phi = cos(phi);
    float sin_phi = sin(phi);

    m.set(0, 0, 1);
    m.set(0, 1, 0);
    m.set(0, 2, 0);

    m.set(1, 0, 0);
    m.set(1, 1, cos_phi);
    m.set(1, 2, sin_phi);

    m.set(2, 0, 0);
    m.set(2, 1, -sin_phi);
    m.set(2, 2, cos_phi);
}




