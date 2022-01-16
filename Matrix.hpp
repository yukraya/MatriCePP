#ifndef MATRICE_HPP
#define MATRICE_HPP

#include <vector>
#include <iostream>

class Matrix
{
    public:
        //*Constructors
        explicit Matrix() = delete; //No default constructor: A matrix cannot be null
        explicit Matrix(int lines, int columns, int assign = 0); //Main constructor
        Matrix(Matrix const &matrix); //Copy constructor

        //*Copy assignment operator
        Matrix& operator=(Matrix const &matrix); //*COMPLETE

        //*Integrated assignment operators
        int& operator()(std::size_t const x, std::size_t const y); //*COMPLETE
        int const & operator()(std::size_t x, std::size_t y) const; //*COMPLETE
        

        Matrix& operator+=(Matrix const &matrix); //*COMPLETE
        Matrix& operator-=(Matrix const &matrix); //*COMPLETE
        Matrix& operator*=(Matrix const &matrix); //*COMPLETE
        Matrix& operator/=(Matrix const &matrix); //TODO~

        friend Matrix operator+(Matrix lhs, Matrix const &rhs); //*COMPLETE
        friend Matrix operator-(Matrix lhs, Matrix const &rhs); //*COMPLETE
        friend Matrix operator*(Matrix const &lhs, Matrix const &rhs); //*COMPLETE
        friend Matrix operator*(Matrix matrix, int multiplicateur); //*COMPLETE
        friend Matrix operator/(Matrix lhs, Matrix const &rhs); //TODO~

        //*Comparison operators
        friend bool operator==(Matrix const &lhs, Matrix const &rhs); //*COMPLETE

        //*Services
        void drawMatrix() const noexcept; //!DEBUG SERVICE

        //*Functions
        friend Matrix powMatrix(Matrix const &matrix, int pow); //TODO

    private:
        //*Internal Functions
        std::size_t dir(int x, int y) const noexcept; //*COMPLETE

        int m_lines;
        int m_columns;
        std::vector<int> m_matrix;
};


#endif //MATRICE_HPP