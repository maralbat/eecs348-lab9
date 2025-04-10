#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <vector>
#include <iostream>
#include <iomanip>
#include <stdexcept>

template <typename T>
class Matrix {
private:
    int size;
    std::vector<std::vector<T>> data;

public:
    Matrix(int n) : size(n), data(n, std::vector<T>(n)) {}

    Matrix(const std::vector<std::vector<T>>& input) {
        size = input.size();
        for (const auto& row : input)
            if (row.size() != size)
                throw std::invalid_argument("Matrix must be square.");
        data = input;
    }

    int get_size() const {
        return size;
    }

    T get_value(int row, int col) const {
        if (row < 0 || col < 0 || row >= size || col >= size)
            throw std::out_of_range("Invalid indices");
        return data[row][col];
    }

    void set_value(int row, int col, T value) {
        if (row < 0 || col < 0 || row >= size || col >= size)
            throw std::out_of_range("Invalid indices");
        data[row][col] = value;
    }

    Matrix operator+(const Matrix& other) const {
        if (size != other.size)
            throw std::invalid_argument("Matrix size mismatch");
        Matrix result(size);
        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                result.data[i][j] = data[i][j] + other.data[i][j];
        return result;
    }

    Matrix operator*(const Matrix& other) const {
        if (size != other.size)
            throw std::invalid_argument("Matrix size mismatch");
        Matrix result(size);
        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j) {
                result.data[i][j] = 0;
                for (int k = 0; k < size; ++k)
                    result.data[i][j] += data[i][k] * other.data[k][j];
            }
        return result;
    }

    T sum_diagonal_major() const {
        T sum = 0;
        for (int i = 0; i < size; ++i)
            sum += data[i][i];
        return sum;
    }

    T sum_diagonal_minor() const {
        T sum = 0;
        for (int i = 0; i < size; ++i)
            sum += data[i][size - 1 - i];
        return sum;
    }


    void swap_rows(int row1, int row2) {
        if (row1 < 0 || row2 < 0 || row1 >= size || row2 >= size)
            throw std::out_of_range("Invalid row indices");
        std::swap(data[row1], data[row2]);
    }

    void swap_cols(int col1, int col2) {
        if (col1 < 0 || col2 < 0 || col1 >= size || col2 >= size)
            throw std::out_of_range("Invalid column indices");
        for (int i = 0; i < size; ++i)
            std::swap(data[i][col1], data[i][col2]);
    }


    void display() const {
        for (const auto& row : data) {
            for (const auto& val : row)
                std::cout << std::setw(8) << val;
            std::cout << std::endl;
        }
    }
};

#endif // MATRIX_HPP
