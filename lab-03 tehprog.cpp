#include <iostream>
#include <cmath>

// Абстрактный класс Точка
class Point {
protected:
    double x, y;  // Координаты точки

public:
    Point(double x = 0, double y = 0) : x(x), y(y) {}

    // Чисто виртуальные функции
    virtual void draw() const = 0;
    virtual void erase() const = 0;
    virtual void move(double dx, double dy) = 0;
    virtual void rotate(double angle) = 0;
};

class Line : public Point {
protected:
    double x2, y2;  // Конечная точка линии

public:
    Line(double x1, double y1, double x2, double y2) : Point(x1, y1), x2(x2), y2(y2) {}

    void draw() const override {
        std::cout << "Drawing Line from (" << x << ", " << y << ") to (" << x2 << ", " << y2 << ")\n";
    }

    void erase() const override {
        std::cout << "Erasing Line from (" << x << ", " << y << ") to (" << x2 << ", " << y2 << ")\n";
    }

    void move(double dx, double dy) override {
        x += dx; y += dy;
        x2 += dx; y2 += dy;
        std::cout << "Moving Line to new coordinates.\n";
    }

    void rotate(double angle) override {
        double rad = angle * M_PI / 180.0;
        double nx2 = x + (x2 - x) * cos(rad) - (y2 - y) * sin(rad);
        double ny2 = y + (x2 - x) * sin(rad) + (y2 - y) * cos(rad);
        x2 = nx2; y2 = ny2;
        std::cout << "Rotating Line by " << angle << " degrees.\n";
    }
};

// Класс для Квадрата
class Square : public Point {
protected:
    double side;  // Сторона квадрата

public:
    Square(double x, double y, double side) : Point(x, y), side(side) {}

    void draw() const override {
        std::cout << "Drawing Square with side " << side << " at (" << x << ", " << y << ")\n";
    }

    void erase() const override {
        std::cout << "Erasing Square at (" << x << ", " << y << ")\n";
    }

    void move(double dx, double dy) override {
        x += dx; y += dy;
        std::cout << "Moving Square to new coordinates.\n";
    }

    void rotate(double angle) override {
        std::cout << "Rotating Square by " << angle << " degrees.\n";
    }
};

// Класс для Параллелограмма с использованием виртуального наследования от квадрата
class Parallelogram : public virtual Square {
protected:
    double side2;  // Вторая сторона параллелограмма
    double angle;  // Угол между сторонами

public:
    Parallelogram(double x, double y, double side1, double side2, double angle) 
        : Square(x, y, side1), side2(side2), angle(angle) {}

    void draw() const override {
        std::cout << "Drawing Parallelogram with sides " << side << " and " << side2 
                  << " and angle " << angle << " at (" << x << ", " << y << ")\n";
    }

    void erase() const override {
        std::cout << "Erasing Parallelogram at (" << x << ", " << y << ")\n";
    }

    void move(double dx, double dy) override {
        x += dx; y += dy;
        std::cout << "Moving Parallelogram to new coordinates.\n";
    }

    void rotate(double angle) override {
        std::cout << "Rotating Parallelogram by " << angle << " degrees.\n";
    }
};

// Класс для Ромба
class Rhombus : public Square {
public:
    Rhombus(double x, double y, double side) : Square(x, y, side) {}

    void draw() const override {
        std::cout << "Drawing Rhombus with side " << side << " at (" << x << ", " << y << ")\n";
    }

    void erase() const override {
        std::cout << "Erasing Rhombus at (" << x << ", " << y << ")\n";
    }

    void move(double dx, double dy) override {
        x += dx; y += dy;
        std::cout << "Moving Rhombus to new coordinates.\n";
    }

    void rotate(double angle) override {
        std::cout << "Rotating Rhombus by " << angle << " degrees.\n";
    }
};

// Класс для Прямоугольника
class Rectangle : public Point {
protected:
    double width, height;  // Ширина и высота прямоугольника

public:
    Rectangle(double x, double y, double width, double height) 
        : Point(x, y), width(width), height(height) {}

    void draw() const override {
        std::cout << "Drawing Rectangle with width " << width << " and height " << height 
                  << " at (" << x << ", " << y << ")\n";
    }

    void erase() const override {
        std::cout << "Erasing Rectangle at (" << x << ", " << y << ")\n";
    }

    void move(double dx, double dy) override {
        x += dx; y += dy;
        std::cout << "Moving Rectangle to new coordinates.\n";
    }

    void rotate(double angle) override {
        std::cout << "Rotating Rectangle by " << angle << " degrees.\n";
    }
};

int main() {
    // Проверка функционала классов
    Line line(0, 0, 1, 1);
    line.draw();
    line.move(2, 2);
    line.rotate(45);
    line.erase();

    Square square(0, 0, 2);
    square.draw();
    square.move(3, 3);
    square.rotate(45);
    square.erase();

    Parallelogram parallelogram(0, 0, 2, 3, 45);
    parallelogram.draw();
    parallelogram.move(4, 4);
    parallelogram.rotate(30);
    parallelogram.erase();

    Rhombus rhombus(0, 0, 2);
    rhombus.draw();
    rhombus.move(5, 5);
    rhombus.rotate(60);
    rhombus.erase();

    Rectangle rectangle(0, 0, 2, 4);
    rectangle.draw();
    rectangle.move(6, 6);
    rectangle.rotate(90);
    rectangle.erase();

    return 0;
}
