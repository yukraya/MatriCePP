#include <iostream>
#include "headers/Matrix.hpp"


int main(/*int argc, cahr const *argv[]*/)
{
    Matrix m1{3, 4};
    Matrix m2{4, 2};

    m1(1, 1) = 7;
    m1(1, 2) = 3;
    m1(1, 3) = 2;
    m1(1, 4) = 1;
    m1(2, 1) = 3;
    m1(2, 2) = 5;
    m1(2, 3) = 1;
    m1(2, 4) = 3;
    m1(3, 1) = 1;
    m1(3, 2) = 4;
    m1(3, 3) = 0;
    m1(3, 4) = 8;

    m2(1, 1) = 5;
    m2(1, 2) = 8;
    m2(2, 1) = 6;
    m2(2, 2) = 7;
    m2(3, 1) = 2;
    m2(3, 2) = 4;
    m2(4, 1) = 1;
    m2(4, 2) = 3;

    //Matrix m3 {m1 * m2};

    m2 *= m1;

    m2.drawMatrix();

    if(m1 == m2)
    {
        std::cout << "C'est égal !" << std::endl;
    }
    else
    {
        std::cout << "Ce n'est pas égal" << std::endl;
    }

    return 0;
}