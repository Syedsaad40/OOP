#include <iostream>
using namespace std;

class Matrix {
private:
    int rows;
    int cols;
    double **arr;

public:
    Matrix() : rows(0), cols(0), arr(nullptr) {}

    Matrix(int r, int c) : rows(r), cols(c) {
        arr = new double*[rows];
        for (int i = 0; i < rows; ++i) {
            arr[i] = new double[cols]{0};
        }
    }

    Matrix(const Matrix &m) : rows(m.rows), cols(m.cols) {
        arr = new double*[rows];
        for (int i = 0; i < rows; ++i) {
            arr[i] = new double[cols];
            for (int j = 0; j < cols; ++j) {
                arr[i][j] = m.arr[i][j];
            }
        }
    }

    Matrix(Matrix &&other) noexcept : arr(other.arr), rows(other.rows), cols(other.cols) {
        other.arr = nullptr;
        other.rows = 0;
        other.cols = 0;
    }

    ~Matrix() {
        if (arr != nullptr) {
            for (int i = 0; i < rows; ++i) {
                delete[] arr[i];
            }
            delete[] arr;
            cout << "Matrix deleted" << endl;
        }
    }

    int getRows() const {
        return rows;
    }

    int getCols() const {
        return cols;
    }

    double& at(int r, int c) {
        if (r < 0 || r >= rows || c < 0 || c >= cols) {
            throw out_of_range("Index out of bounds");
        }
        return arr[r][c];
    }

    void fill(double value) {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                arr[i][j] = value;
            }
        }
    }

    Matrix transpose() const {
        Matrix transposed(cols, rows);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                transposed.arr[j][i] = arr[i][j];
            }
        }

        for (int i = 0; i < transposed.getRows(); ++i) {
            for (int j = 0; j < transposed.getCols(); ++j) {
                cout << transposed.arr[i][j] << " ";
            }
            cout << endl;
        }

        return transposed;
    }
};

int main() {
    Matrix mat(3, 3);
    mat.fill(5.0);

    cout << "Original Matrix:" << endl;
    for (int i = 0; i < mat.getRows(); ++i) {
        for (int j = 0; j < mat.getCols(); ++j) {
            cout << mat.at(i, j) << " ";
        }
        cout << endl;
    }

    cout << "Transpose Matrix:" << endl;
    mat.transpose();

    return 0;
}
