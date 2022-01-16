#include "headers/Matrix.hpp"

#include <iostream> //!DEBUG

#include <cassert>
#include <vector>


//*Constructors
Matrix::Matrix(int lines, int columns, int assign)
    :m_lines(lines), m_columns(columns), m_matrix(lines * columns, assign)
{
    assert(m_lines > 0 && m_columns > 0 && "Matrix dimensions cannot be negative or null");
}


Matrix::Matrix(Matrix const &matrix)
{
    m_lines = matrix.m_lines;
    m_columns = matrix.m_columns;
    m_matrix.assign(matrix.m_matrix.begin(), matrix.m_matrix.end());
}




//*Copy assignmement operator
Matrix& Matrix::operator=(Matrix const &matrix)
{
    m_lines = matrix.m_lines;
    m_columns = matrix.m_columns;
    m_matrix.assign(matrix.m_matrix.begin(), matrix.m_matrix.end());
    return *this;
}




//*Internal functions
std::size_t Matrix::dir(int const x, int const y) const noexcept
{
    assert(x > 0 && y > 0 && "The columns and the lines have to be > 0");
    assert(x <= m_lines && y <= m_columns && "The array size is higher");
    return ((m_columns * (x - 1)) + y) - 1;
}




//*Integrated assignment operators
int& Matrix::operator()(std::size_t x, std::size_t y)
{
    return m_matrix[dir(x, y)];
}


int const & Matrix::operator()(std::size_t x, std::size_t y) const
{
    return m_matrix[dir(x, y)];
}


Matrix& Matrix::operator+=(Matrix const &matrix)
{
    assert(m_lines == matrix.m_lines && m_columns == matrix.m_columns && "Matrix dimensions are different");
    for(std::size_t i = 0 ; i < m_matrix.size() ; i++)
    {
        m_matrix[i] += matrix.m_matrix[i];
    }
    return *this;
}


Matrix operator+(Matrix lhs, Matrix const & rhs) //Friendly Function
{
    lhs += rhs;
    return lhs;
}


Matrix& Matrix::operator-=(Matrix const &matrix)
{
    assert(m_lines == matrix.m_lines && m_columns == matrix.m_columns && "Matrix dimensions are different");
    for(std::size_t i = 0 ; i < matrix.m_matrix.size() ; i++)
    {
        m_matrix[i] -= matrix.m_matrix[i];
    }
    return *this;
}


Matrix operator-(Matrix lhs, Matrix const &rhs) //Friendly Fonction
{
    lhs -= rhs;
    return lhs;
}


Matrix operator*(Matrix const &lhs, Matrix const &rhs) //Friendly Function
{
    assert(lhs.m_columns == rhs.m_lines && "Error dimensions");
    Matrix copie{lhs.m_lines, rhs.m_columns, 0};
    for(int i = 1 ; i < (copie.m_lines + 1) ; i++)
    {
        for(int j = 1 ; j < (copie.m_columns + 1) ; j++)
        {
            for(int l = 1 ; l < (lhs.m_columns + 1) ; l++)
            {
                copie(i, j) = copie(i, j) + lhs(i, l) * rhs(l, j);
            }
        }
    }
    return copie;
}


Matrix& Matrix::operator*=(Matrix const &matrix)
{
    Matrix copie {matrix * (*this)};
    std::swap(*this, copie);
    return *this; 
}


Matrix operator*(Matrix matrix, int multiplicateur) //Friendly Function
{
    for(int &element : matrix.m_matrix)
    {
        element *= multiplicateur;
    }
    return matrix;
}


Matrix operator*(int multiplicateur, Matrix matrix) //Friendly Function
{
    for(int &element : matrix.m_matrix)
    {
        element *= multiplicateur;
    }
    return matrix;
}



//*Comparison operators
bool operator==(Matrix const &lhs, Matrix const &rhs) //Friendly Function
{
    if(lhs.m_lines != rhs.m_lines || lhs.m_columns != rhs.m_columns)
    {
        return false;
    }
    for(std::size_t i = 0 ; i < lhs.m_matrix.size() ; i++)
    {
        if(lhs.m_matrix[i] != rhs.m_matrix[i])
        {
            return false;
        }
    }
    return true;
}


//*Services
void Matrix::drawMatrix() const noexcept //!DEBUG FUNCTION
{
    for(int i = 0 ; i < m_lines ; i++)
    {
        for(int j = 0 ; j < m_columns ; j++)
        {
            std::cout << m_matrix[i * m_columns+ j] << " ";
        }
        std::cout << std::endl;
    }
}

int Matrix::getLines() const noexcept
{
    return m_lines;
}

int Matrix::getColumns() const noexcept
{
    return m_columns;
}


//*Functions
Matrix transposition(Matrix const &matrix)
{
    Matrix copie{matrix.m_columns, matrix.m_lines};
    for(int i = 1 ; i < (matrix.m_columns + 1) ; i++)
    {
        for(int j = 1 ; j < (matrix.m_lines + 1) ; j++)
        {
            copie(i, j) = matrix(j, i);
        }
    }

    return copie;
}

Matrix powMatrix(Matrix const &matrix, int pow)
{
    assert(pow > 0 && "A matrix cannot be null");
    Matrix resultat {matrix};
    for(int i = 1 ; i < pow ; i++)
    {
        resultat = resultat * matrix;
    }
    return resultat;
}
