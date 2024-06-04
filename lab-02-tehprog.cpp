#include <iostream>

// Класс для векторов
class vect {
public:
    int dim;            // Размерность вектора
    double* b;          // Указатель на массив элементов вектора
    int num;            // Уникальный номер вектора
    static int count;   // Статический счётчик векторов

    // Конструктор с параметром размера
    vect(int dim) : dim(dim), num(++count) {
        b = new double[dim];
        std::cout << "Vector " << num << " created.\n";
    }

    // Конструктор копирования
    vect(const vect& v) : dim(v.dim), num(++count) {
        b = new double[dim];
        for (int i = 0; i < dim; ++i) {
            b[i] = v.b[i];
        }
        std::cout << "Vector " << num << " copied from Vector " << v.num << ".\n";
    }

    // Деструктор
    ~vect() {
        delete[] b;
        std::cout << "Vector " << num << " destroyed.\n";
    }

    // Оператор присваивания
    vect& operator=(const vect& v) {
        if (this == &v) return *this;
        delete[] b;
        dim = v.dim;
        b = new double[dim];
        for (int i = 0; i < dim; ++i) {
            b[i] = v.b[i];
        }
        std::cout << "Vector " << num << " assigned from Vector " << v.num << ".\n";
        return *this;
    }

    // Операторы сложения, вычитания, отрицания, скалярного произведения и умножения на скаляр
    vect operator+(const vect& v) const {
        vect result(dim);
        for (int i = 0; i < dim; ++i) {
            result.b[i] = b[i] + v.b[i];
        }
        std::cout << "Vector " << num << " + Vector " << v.num << " = Vector " << result.num << ".\n";
        return result;
    }

    vect operator-(const vect& v) const {
        vect result(dim);
        for (int i = 0; i < dim; ++i) {
            result.b[i] = b[i] - v.b[i];
        }
        std::cout << "Vector " << num << " - Vector " << v.num << " = Vector " << result.num << ".\n";
        return result;
    }

    vect operator-() const {
        vect result(dim);
        for (int i = 0; i < dim; ++i) {
            result.b[i] = -b[i];
        }
        std::cout << "Vector " << num << " negated = Vector " << result.num << ".\n";
        return result;
    }

    double operator*(const vect& v) const {
        double result = 0;
        for (int i = 0; i < dim; ++i) {
            result += b[i] * v.b[i];
        }
        std::cout << "Vector " << num << " * Vector " << v.num << " = " << result << ".\n";
        return result;
    }

    vect operator*(double k) const {
        vect result(dim);
        for (int i = 0; i < dim; ++i) {
            result.b[i] = b[i] * k;
        }
        std::cout << "Vector " << num << " * " << k << " = Vector " << result.num << ".\n";
        return result;
    }
};

// Инициализация статического члена класса
int vect::count = 0;

// Класс для матриц
class matr {
public:
    int dim;            // Размерность матрицы
    double** a;         // Указатель на массив массивов (матрица)
    int num;            // Уникальный номер матрицы
    static int count;   // Статический счётчик матриц

    // Конструктор с параметром размера
    matr(int dim) : dim(dim), num(++count) {
        a = new double*[dim];
        for (int i = 0; i < dim; ++i) {
            a[i] = new double[dim];
        }
        std::cout << "Matrix " << num << " created.\n";
    }

    // Конструктор копирования
    matr(const matr& m) : dim(m.dim), num(++count) {
        a = new double*[dim];
        for (int i = 0; i < dim; ++i) {
            a[i] = new double[dim];
            for (int j = 0; j < dim; ++j) {
                a[i][j] = m.a[i][j];
            }
        }
        std::cout << "Matrix " << num << " copied from Matrix " << m.num << ".\n";
    }

    // Деструктор
    ~matr() {
        for (int i = 0; i < dim; ++i) {
            delete[] a[i];
        }
        delete[] a;
        std::cout << "Matrix " << num << " destroyed.\n";
    }

    // Оператор присваивания
    matr& operator=(const matr& m) {
        if (this == &m) return *this;
        for (int i = 0; i < dim; ++i) {
            delete[] a[i];
        }
        delete[] a;
        dim = m.dim;
        a = new double*[dim];
        for (int i = 0; i < dim; ++i) {
            a[i] = new double[dim];
            for (int j = 0; j < dim; ++j) {
                a[i][j] = m.a[i][j];
            }
        }
        std::cout << "Matrix " << num << " assigned from Matrix " << m.num << ".\n";
        return *this;
    }

    // Операторы сложения, вычитания, отрицания, умножения на скаляр, умножения матриц и умножения матрицы на вектор
    matr operator+(const matr& m) const {
        matr result(dim);
        for (int i = 0; i < dim; ++i) {
            for (int j = 0; j < dim; ++j) {
                result.a[i][j] = a[i][j] + m.a[i][j];
            }
        }
        std::cout << "Matrix " << num << " + Matrix " << m.num << " = Matrix " << result.num << ".\n";
        return result;
    }

    matr operator-(const matr& m) const {
        matr result(dim);
        for (int i = 0; i < dim; ++i) {
            for (int j = 0; j < dim; ++j) {
                result.a[i][j] = a[i][j] - m.a[i][j];
            }
        }
        std::cout << "Matrix " << num << " - Matrix " << m.num << " = Matrix " << result.num << ".\n";
        return result;
    }

    matr operator-() const {
        matr result(dim);
        for (int i = 0; i < dim; ++i) {
            for (int j = 0; j < dim; ++j) {
                result.a[i][j] = -a[i][j];
            }
        }
        std::cout << "Matrix " << num << " negated = Matrix " << result.num << ".\n";
        return result;
    }

    matr operator*(const matr& m) const {
        matr result(dim);
        for (int i = 0; i < dim; ++i) {
            for (int j = 0; j < dim; ++j) {
                result.a[i][j] = 0;
                for (int k = 0; k < dim; ++k) {
                    result.a[i][j] += a[i][k] * m.a[k][j];
                }
            }
        }
        std::cout << "Matrix " << num << " * Matrix " << m.num << " = Matrix " << result.num << ".\n";
        return result;
    }

    matr operator*(double k) const {
        matr result(dim);
        for (int i = 0; i < dim; ++i) {
            for (int j = 0; j < dim; ++j) {
                result.a[i][j] = a[i][j] * k;
            }
        }
        std::cout << "Matrix " << num << " * " << k << " = Matrix " << result.num << ".\n";
        return result;
    }

    vect operator*(const vect& v) const {
        vect result(dim);
        for (int i = 0; i < dim; ++i) {
            result.b[i] = 0;
            for (int j = 0; j < dim; ++j) {
                result.b[i] += a[i][j] * v.b[j];
            }
        }
        std::cout << "Matrix " << num << " * Vector " << v.num << " = Vector " << result.num << ".\n";
        return result;
    }
};

// Инициализация статического члена класса
int matr::count = 0;

int main() {
    // Создание векторов
    vect v1(3);
    v1.b[0] = 1; v1.b[1] = 2; v1.b[2] = 3;

    vect v2(3);
    v2.b[0] = 4; v2.b[1] = 5; v2.b[2] = 6;

    // Выполнение операций над векторами
    vect v3 = v1 + v2;
    vect v4 = v1 - v2;
    vect v5 = -v1;
    double dotProduct = v1 * v2;
    vect v6 = v1 * 2;

    // Создание матриц
    matr m1(3);
    m1.a[0][0] = 1; m1.a[0][1] = 2; m1.a[0][2] = 3;
    m1.a[1][0] = 4; m1.a[1][1] = 5; m1.a[1][2] = 6;
    m1.a[2][0] = 7; m1.a[2][1] = 8; m1.a[2][2] = 9;

    matr m2(3);
    m2.a[0][0] = 9; m2.a[0][1] = 8; m2.a[0][2] = 7;
    m2.a[1][0] = 6; m2.a[1][1] = 5; m2.a[1][2] = 4;
    m2.a[2][0] = 3; m2.a[2][1] = 2; m2.a[2][2] = 1;

    // Выполнение операций над матрицами
    matr m3 = m1 + m2;
    matr m4 = m1 - m2;
    matr m5 = -m1;
    matr m6 = m1 * m2;
    matr m7 = m1 * 2;

    // Умножение матрицы на вектор
    vect v7 = m1 * v1;

    return 0;
}
