#include <iostream>
#include <string>

class Figure {
protected:
    std::string name;
    int sides;
public:
    Figure() : name("Фигура"), sides(0) { }
    std::string get_name() {
        return name;
    }
    int get_sides() {
        return sides;
    }
    virtual bool check() {
        if (sides == 0) {
            return true;
        }
        else {
            return false;
        }
    }
    virtual void print_info() {
        std::cout << get_name() << ": " << std::endl;
        if (check() == true) {
            std::cout << "Правильная" << std::endl;
        }
        else {
            std::cout << "Неправильная" << std::endl;
        }
        std::cout << "Количество сторон: ";
        std::cout << get_sides() << std::endl;
    }
};

class Triangle : public Figure {
protected:
    int a, b, c, A, B, C;
public:
    Triangle(int a, int b, int c, int A, int B, int C) {
        name = "Треугольник";
        sides = 3;
        this->a = a;
        this->b = b;
        this->c = c;
        this->A = A;
        this->B = B;
        this->C = C;
    }
    int get_a() { return a; }
    int get_b() { return b; }
    int get_c() { return c; }
    int get_A() { return A; }
    int get_B() { return B; }
    int get_C() { return C; }

    bool check() override {
        if (A + B + C == 180) {
            return true;
        }
        else {
            return false;
        }
    }
    void print_info() {
        Figure::print_info();
        std::cout << "Стороны: " << std::endl;
        std::cout << "a=" << get_a() << "; " << "b=" << get_b() << "; " << "c=" << get_c() << std::endl;
        std::cout << "Углы: " << std::endl;
        std::cout << "A=" << get_A() << "; " << "B=" << get_B() << "; " << "C=" << get_C() << std::endl;
        std::cout << std::endl; 
    }
};

class Triangle_p : public Triangle {
public:
    Triangle_p(int a, int b, int c, int A, int B) : Triangle(a, b, c, A, B, 90) {
        name = "Прямоугольный треугольник";
    }
    bool check() override {
        if ((C == 90) && Triangle::check() == true) {
            return true;
        }
        else {
            return false;
        }
    }
};

class Triangle_rb : public Triangle {
public:
    Triangle_rb(int a, int b, int A, int B) : Triangle(a, b, a, A, B, A) {
        name = "Равнобедренный треугольник";
    }
    bool check() override {
        if (A == C && a == c && (Triangle::check() == true)) {
            return true;
        }
        else {
            return false;
        }
    }
};

class Triangle_rs : public Triangle {
public:
    Triangle_rs(int a) : Triangle(a, a, a, 60, 60, 60) {
        name = "Равносторонний треугольник";
    }
    bool check() override {
        if ((Triangle::check() == true) && A == 60 && B == A && a == c && a == b && b == c) {
            return true;
        }
        else {
            return false;
        }
    }
};

class Quadrangle : public Figure {
protected:
    int a, b, c, d, A, B, C, D;
public:
    Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D) {
        name = "Четырёхугольник";
        sides = 4;
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
        this->A = A;
        this->B = B;
        this->C = C;
        this->D = D;
    }
    int get_a() { return a; }
    int get_b() { return b; }
    int get_c() { return c; }
    int get_d() { return d; }
    int get_A() { return A; }
    int get_B() { return B; }
    int get_C() { return C; }
    int get_D() { return D; }

    bool check() override {
        if (A + B + C + D == 360) {
            return true;
        }
        else {
            return false;
        }
    }

    void print_info() {
        Figure::print_info();
        std::cout << "Стороны: " << std::endl;
        std::cout << "a=" << get_a() << "; " << "b=" << get_b() << "; " << "c=" << get_c() << "; " << "d=" << get_d() << std::endl;
        std::cout << "Углы: " << std::endl;
        std::cout << "A=" << get_A() << "; " << "B=" << get_B() << "; " << "C=" << get_C() << "; " << "D=" << get_D() << std::endl;
        std::cout << std::endl;
    }
};

class Parallelogram : public Quadrangle {
public:
    Parallelogram(int a, int b, int A, int B) : Quadrangle(a, b, a, b, A, B, A, B) {
        name = "Параллелограмм";
    }
    bool check() override {
        if (A == C && B == D && a == c && b == d && (Quadrangle::check() == true)) {
            return true;
        }
        else {
            return false;
        }
    }
};

class Romb : public Parallelogram {
public:
    Romb(int a, int A, int B) : Parallelogram(a, a, A, B) {
        name = "Ромб";
    }
    bool check() override {
        if (a == b && (Parallelogram::check() == true)) {
            return true;
        }
        else {
            return false;
        }
    }
};

class Parallel_p : public Parallelogram {
public:
    Parallel_p(int a, int b) : Parallelogram(a, b, 90, 90) {
        name = "Прямоугольник";
    }
    bool check() override {
        if (A == 90 && B == A && (Parallelogram::check() == true)) {
            return true;
        }
        else {
            return false;
        }
    }
};

class Square : public Parallel_p {
public:
    Square(int a) : Parallel_p(a, a) {
        name = "Квадрат";
    }
    bool check() override {
        if (a == b && (Parallel_p::check() == true)) {
            return true;
        }
        else {
            return false;
        }
    }
};

void printInfo(Figure* fig) {
    fig->print_info();
};

int main()
{
    setlocale(LC_ALL, "Russian");

    Figure f;
    printInfo(&f);
    std::cout << std::endl;
    
    Triangle t(10, 20, 30, 50, 60, 70);
    Triangle_p tp(10, 20, 30, 50, 40);
    Triangle_rb trb(10, 20, 40, 80);
    Triangle_rs trs(20);

    printInfo(&t);
    printInfo(&tp);
    printInfo(&trb);
    printInfo(&trs);

    Quadrangle q(10, 20, 30, 40, 50, 60, 70, 80);
    Parallel_p pp(10, 20);
    Square s(20);
    Parallelogram p(20, 30, 80, 90);
    Romb r(30, 60, 120);

    printInfo(&q);
    printInfo(&pp);
    printInfo(&s);
    printInfo(&p);
    printInfo(&r);

    return 0;
}