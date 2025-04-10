#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <cstdint>
#include <vector>
#include <iostream>
#include <iomanip>
#include <stdexcept>
using namespace std;

template <typename T>
class Matrix {
private:
    int size;
    vector<vector<T>> data;

public:
    Matrix(int n) : size(n), data(n, vector<T>(n)) {}

    void readFromFile(ifstream& in) {
        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                in >> data[i][j];
    }

    void display() const {
        for (const auto& row : data) {
            for (const auto& val : row)
                cout << setw(8) << fixed << setprecision(2) << static_cast<double>(val);
            cout << endl;
        }
    }

    Matrix operator+(const Matrix& other) const {
        Matrix result(size);
        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                result.data[i][j] = data[i][j] + other.data[i][j];
        return result;
    }

    Matrix operator*(const Matrix& other) const {
        Matrix result(size);
        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j) {
                result.data[i][j] = 0;
                for (int k = 0; k < size; ++k)
                    result.data[i][j] += data[i][k] * other.data[k][j];
            }
        return result;
    }

    T mainDiagonalSum() const {
        T sum = 0;
        for (int i = 0; i < size; ++i)
            sum += data[i][i];
        return sum;
    }

    T secondaryDiagonalSum() const {
        T sum = 0;
        for (int i = 0; i < size; ++i)
            sum += data[i][size - 1 - i];
        return sum;
    }

    void swapRows(int row1, int row2) {
        if (row1 < 0 || row2 < 0 || row1 >= size || row2 >= size)
            throw out_of_range("Invalid row indices");
        swap(data[row1], data[row2]);
    }

    void swapCols(int col1, int col2) {
        if (col1 < 0 || col2 < 0 || col1 >= size || col2 >= size)
            throw out_of_range("Invalid column indices");
        for (int i = 0; i < size; ++i)
            swap(data[i][col1], data[i][col2]);
    }

    void updateElement(int row, int col, T value) {
        if (row < 0 || col < 0 || row >= size || col >= size)
            throw out_of_range("Invalid indices");
        data[row][col] = value;
    }
};

template <typename T>
void swapMatrixRows(vector<vector<T>>& matrix, int row1, int row2) {
    if (row1 < 0 || row2 < 0 || row1 >= matrix.size() || row2 >= matrix.size())
        throw out_of_range("Invalid row indices");
    swap(matrix[row1], matrix[row2]);
}

template <typename T>
void updateMatrixElement(vector<vector<T>>& matrix, int row, int col, T value) {
    if (row < 0 || col < 0 || row >= matrix.size() || col >= matrix.size())
        throw out_of_range("Invalid indices");
    matrix[row][col] = value;
}

#endif // __MATRIX_HPP__