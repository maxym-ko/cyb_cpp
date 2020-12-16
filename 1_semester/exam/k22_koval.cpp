/*
    Коваль Максим, К-22
    Варіант 12
*/

#include <iostream>
#include <cmath>

template<class T>
class Matrix {
private:
    unsigned int rows;
    unsigned int cols;
    T **elem_matrix;

    bool check_matrix() {
        return is_power_of_two(rows) && is_power_of_two(cols);
    }

    bool in_matrix_range(int rows2check, int cols2check) {
        return in_matrix_range_rows(rows2check) && in_matrix_range_cols(cols2check);
    }

    bool in_matrix_range_rows(int rows2check) {
        return rows2check > 0 && rows2check <= rows;
    }

    bool in_matrix_range_cols(int cols2check) {
        return cols2check > 0 && cols2check <= cols;
    }

    static bool is_power_of_two(int num) {
        return num != 0 && (num & (num - 1)) == 0;
    }

    static int get_close_power_of_two(int num) {
        return (int) (pow(2, ceil(log2(num))));
    }

    bool is_matrix_small() {
        return rows == 1 || cols == 1 || (rows < 5 && cols < 5);
    }

    Matrix get_filled_matrix() {
        int rows_old = rows;
        int cols_old = cols;
        int rows_res = get_close_power_of_two(rows_old);
        int cols_res = get_close_power_of_two(cols_old);

        Matrix<T> res(rows_res, cols_res);
        for (int i = 0; i < rows_old; i++) {
            for (int j = 0; j < cols_old; j++) {
                res.elem_matrix[i][j] = elem_matrix[i][j];
            }
        }
        for (int i = rows_old; i < rows_res; i++) {
            for (int j = cols_old; j < cols_res; j++) {
                res.elem_matrix[i][j] = 0;
            }
        }

        return res;

    }

    static Matrix combine_matrix(Matrix<T> a_11, Matrix<T> a_12, Matrix<T> a_21, Matrix<T> a_22) {
        int rows = a_11.rows + a_12.rows;
        int cols = a_11.cols + a_21.cols;

        Matrix<T> res(rows, cols);
        for (int i = 0; i < a_11.rows; i++) {
            for (int j = 0; j < a_11.cols; j++) {
                res.elem_matrix[i][j] = a_11(i, j);
            }
        }
        for (int i = 0; i < a_11.rows; i++) {
            for (int j = a_11.cols; j < a_11.cols + a_12.cols; j++) {
                res.elem_matrix[i][j] = a_12(i, j - a_11.cols);
            }
        }
        for (int i = a_11.rows; i < a_11.rows + a_21.rows; i++) {
            for (int j = 0; j < a_21.cols; j++) {
                res.elem_matrix[i][j] = a_21(i - a_11.rows, j);
            }
        }
        for (int i = a_11.rows; i < a_11.rows + a_21.rows; i++) {
            for (int j = a_21.cols; j < a_21.cols + a_22.cols; j++) {
                res.elem_matrix[i][j] = a_22(i - a_11.rows, j - a_21.cols);
            }
        }

        return res;

    }

    Matrix get_sub_matrix(int rows_sub_from, int rows_sub_to, int cols_sub_from, int cols_sub_to) {
        int rows_sub = rows_sub_to - rows_sub_from;
        int cols_sub = cols_sub_to - cols_sub_from;

        if (!in_matrix_range_rows(rows_sub_to) && !in_matrix_range_rows(rows_sub_from)
            && !in_matrix_range_cols(cols_sub_to) && !in_matrix_range_cols(cols_sub_to) &&
            !in_matrix_range(rows_sub, cols_sub)) {
            throw std::runtime_error("There size of the sub-matrix is out of range");
        }

        Matrix<T> res(rows_sub, cols_sub);
        for (int i = rows_sub_from; i < rows_sub_to; i++) {
            for (int j = cols_sub_from; j < cols_sub_to; j++) {
                res.elem_matrix[i - rows_sub_from][j - cols_sub_from] = elem_matrix[i][j];
            }
        }

        return res;
    }

public:
    Matrix(unsigned int rows, unsigned int cols) : rows(rows), cols(cols) {
        if (rows < 0 || cols < 0) throw std::runtime_error("Rows and columns should be positive");

        srand((unsigned) time(nullptr));

        elem_matrix = new T *[rows];
        for (int i = 0; i < rows; i++) {
            elem_matrix[i] = new T[cols];
        }
    }

    void fill(int num) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                elem_matrix[i][j] = num;
            }
        }
    }

    void fill_random(int max_element = 100) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                elem_matrix[i][j] = (rand() % max_element);
            }
        }
    }

    static Matrix strassen_algorithm(Matrix<T> a, Matrix<T> b) {
        if (a.is_matrix_small() && b.is_matrix_small()) return a * b;

        if (a.rows != b.cols && a.cols != b.rows) throw std::runtime_error("Matrix sizes don't fit");

        int rows_res = a.rows;
        int cols_res = b.cols;

        if (!a.check_matrix()) a = a.get_filled_matrix();
        if (!b.check_matrix()) b = b.get_filled_matrix();

        Matrix<T> A_11 = a.get_sub_matrix(0, a.rows / 2, 0, a.cols / 2);
        Matrix<T> A_12 = a.get_sub_matrix(0, a.rows / 2, a.cols / 2, a.cols);
        Matrix<T> A_21 = a.get_sub_matrix(a.rows / 2, a.rows, 0, a.cols / 2);
        Matrix<T> A_22 = a.get_sub_matrix(a.rows / 2, a.rows, a.cols / 2, a.cols);

        Matrix<T> B_11 = b.get_sub_matrix(0, b.rows / 2, 0, b.cols / 2);
        Matrix<T> B_12 = b.get_sub_matrix(0, b.rows / 2, b.cols / 2, b.cols);
        Matrix<T> B_21 = b.get_sub_matrix(b.rows / 2, b.rows, 0, b.cols / 2);
        Matrix<T> B_22 = b.get_sub_matrix(b.rows / 2, b.rows, b.cols / 2, b.cols);

        Matrix<T> P_1 = strassen_algorithm(A_11 + A_22, B_11 + B_22);
        Matrix<T> P_2 = strassen_algorithm(A_21 + A_22, B_11);
        Matrix<T> P_3 = strassen_algorithm(A_11, B_12 - B_22);
        Matrix<T> P_4 = strassen_algorithm(A_22, B_21 - B_11);
        Matrix<T> P_5 = strassen_algorithm(A_11 + A_12, B_22);
        Matrix<T> P_6 = strassen_algorithm(A_21 - A_11, B_11 + B_12);
        Matrix<T> P_7 = strassen_algorithm(A_12 - A_22, B_21 + B_22);

        Matrix<T> C_11 = P_1 + P_4 - P_5 + P_7;
        Matrix<T> C_12 = P_3 + P_5;
        Matrix<T> C_21 = P_2 + P_4;
        Matrix<T> C_22 = P_1 + P_3 - P_2 + P_6;

        Matrix<T> res = combine_matrix(C_11, C_12, C_21, C_22);

        return res.get_sub_matrix(0, rows_res, 0, cols_res);
    }

    unsigned int get_rows() const {
        return rows;
    }

    unsigned int get_cols() const {
        return cols;
    }

    Matrix transpose() {
        Matrix<T> res(cols, rows);
        for (int i = 0; i < cols; i++) {
            for (int j = 0; j < rows; j++) {
                res.elem_matrix[i][j] = elem_matrix[j][i];
            }
        }

        return res;
    }

    T operator()(int i, int j) {
        if (i < 0 || i >= rows || j < 0 || j >= cols) {
            throw std::runtime_error(
                    "There is no such an element (" + std::to_string(i) + ", " + std::to_string(i) + ")");
        }

        return elem_matrix[i][j];
    }

    Matrix operator+(const Matrix<T> &other) {
        if (rows != other.rows && cols != other.cols) {
            throw std::runtime_error("Matrix should have the same size for addition");
        }

        Matrix<T> res(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                res.elem_matrix[i][j] = elem_matrix[i][j] + other.elem_matrix[i][j];
            }
        }

        return res;
    }

    Matrix operator-(const Matrix<T> &other) {
        if (rows != other.rows && cols != other.cols) {
            throw std::runtime_error("Matrix should have the same size for subtraction");
        }

        Matrix<T> res(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                res.elem_matrix[i][j] = elem_matrix[i][j] - other.elem_matrix[i][j];
            }
        }

        return res;
    }

    Matrix operator*(const Matrix<T> &other) {
        if (rows != other.cols && cols != other.rows) throw std::runtime_error("Matrix sizes don't fit");

        Matrix<T> res(rows, other.cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < other.cols; j++) {
                for (int k = 0; k < cols; ++k) {
                    res.elem_matrix[i][j] += elem_matrix[i][k] * other.elem_matrix[k][j];
                }
            }
        }

        return res;
    }

    friend std::ostream &operator<<(std::ostream &os, Matrix<T> &matrix) {
        for (int i = 0; i < matrix.rows; i++) {
            for (int j = 0; j < matrix.cols; j++) {
                os << matrix(i, j) << " ";
            }
            os << std::endl;
        }
        return os;
    }
};

int main() {
    Matrix<double> matrix(15, 20);
    Matrix<double> matrix2(20, 15);

    matrix.fill_random(20);
    matrix2.fill_random(30);

    std::cout << matrix << std::endl;
    std::cout << matrix2 << std::endl;

    Matrix<double> res = Matrix<double>::strassen_algorithm(matrix, matrix2);

    std::cout << res;

    return 0;
}

/*
    1. Контейнери
    Існують наступні різновиди контейнерів:
        - послідовні контейнери
        - упорядковані (асоціативні) конейнери
        - неупорядковані контейнери.

    Послідовні контейнери - упорядковані колекції, в яких кожен елемент має свою визначену позицію.
    Можна добавити елемент у будь-яку позиція та дістати елемент з будь-якій позиції.
    Найвідоміші представники такого типу: vector, array, list, deque, forward_list

    Упорядковані (асоціативні) контейнери - упорядковані колекції, які забезпечують впорядкованість свої елементів.
    Найвідоміші представники такого типу: set, multiset, map, multimap

    Неупорядковані контейнери - неупорядковані колекції, у яких позиція елемента немає значення,
    а має значення лише наявний елемент у колекції, чи ні
    Найвідоміші представники такого типу: unordered_set, unordered_multiset, unordered_map, unordered_multimap

    Розглянемо декілька основних контейнерів:
        - vector - динамічний масив
        - array - фіксований масив
        - list - двобічний список (кожен елемент містить посилання на попередній, наступній елементи та значення)
        - forward_list - однобічний список (кожен елемент містить посилання на наступній елемент та значення)
        - deque - двобічна черга
        - set - множина, котра містить лише унікальні елементи
        - multiset - set, в якому допускаються повторення
        - map - set, в якому кожен елемент є парою "ключ-значення"
        - multimap - map, в якому допускаються повторення ключів
        - unordered_set - неупорядкований set
        - unordered_multiset - неупорядкований multiset
        - unordered_map - неупорядкований map
        - unordered_multimap - неупорядкований multimap

    2. Порозрядні (побітові) оператори
    Для початку перелічемо назви наявних побітові оператори та їх позначення:
        - побітовий зсув вправо (>>)
        - побітовий зсув вліво (<<)
        - побітове і (&)
        - побітова або (|)
        - побітове ні (~)
        - побітове виключне ні (^)
    Розглянемо кожен з операторів на прикладі:
        - 5 (0101) >> 1 = 2 (0010)
        - 5 (01010) << 2 = 20 (010100)
        - 5 (0101) & 2 (0010) = 0 (0000)
        - 5 (0101) | 2 (0010) = 7 (0111)
        - !5 (0101) = 10 (1010)
        - 5 (0101) ^ 3 (0011) =  (0110)
*/