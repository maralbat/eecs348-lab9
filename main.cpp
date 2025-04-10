#include <iostream>
#include "matrix.hpp"
#include <fstream>

int main() {
    string filename;
    cout << "Enter the input file name: ";
    cin >> filename;

    ifstream infile(filename);
    if (!infile) {
        cerr << "Failed to open file." << endl;
        return 1;
    }

    int n, typeFlag;
    infile >> n >> typeFlag;

    if (typeFlag == 0) {
        Matrix<int> m1(n), m2(n);
        m1.readFromFile(infile);
        m2.readFromFile(infile);

        cout << "Matrix 1:\n"; m1.display();
        cout << "\nMatrix 2:\n"; m2.display();

        cout << "\nMatrix 1 + Matrix 2:\n"; (m1 + m2).display();
        cout << "\nMatrix 1 * Matrix 2:\n"; (m1 * m2).display();

        cout << "\nMain Diagonal Sum: " << m1.mainDiagonalSum() << endl;
        cout << "Secondary Diagonal Sum: " << m1.secondaryDiagonalSum() << endl;

        m1.swapRows(0, 1);
        cout << "\nAfter swapping rows 0 and 1 in Matrix 1:\n"; m1.display();

        m1.swapCols(0, 1);
        cout << "\nAfter swapping columns 0 and 1 in Matrix 1:\n"; m1.display();

        m1.updateElement(0, 0, 99);
        cout << "\nAfter updating element (0,0) in Matrix 1 to 99:\n"; m1.display();

    } else if (typeFlag == 1) {
        Matrix<double> m1(n), m2(n);
        m1.readFromFile(infile);
        m2.readFromFile(infile);

        cout << "Matrix 1:\n"; m1.display();
        cout << "\nMatrix 2:\n"; m2.display();

        cout << "\nMatrix 1 + Matrix 2:\n"; (m1 + m2).display();
        cout << "\nMatrix 1 * Matrix 2:\n"; (m1 * m2).display();

        cout << "\nMain Diagonal Sum: " << m1.mainDiagonalSum() << endl;
        cout << "Secondary Diagonal Sum: " << m1.secondaryDiagonalSum() << endl;

        m1.swapRows(0, 1);
        cout << "\nAfter swapping rows 0 and 1 in Matrix 1:\n"; m1.display();

        m1.swapCols(0, 1);
        cout << "\nAfter swapping columns 0 and 1 in Matrix 1:\n"; m1.display();

        m1.updateElement(0, 0, 99.99);
        cout << "\nAfter updating element (0,0) in Matrix 1 to 99.99:\n"; m1.display();
    }

    return 0;
}
