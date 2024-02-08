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
    virtual void print_info(Figure* fig) {
        std::cout << fig->get_name() << ": " << std::endl;
        if (fig->check() == true) {
            std::cout << "Правильная" << std::endl;
        }
        else {
            std::cout << "Неправильная" << std::endl;
        }
        std::cout << "Количество сторон: ";
        std::cout << fig->get_sides() << std::endl;
    }
};

class Triangle : public Figure {
protected:
    int a, b, c;
    int A, B, C;
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

    void print_info(Triangle* tgl) {
        
        Figure::print_info(tgl);
        std::cout << "Стороны: " << std::endl;
        std::cout << "a=" << tgl->get_a() << "; " << "b=" << tgl->get_b() << "; " << "c=" << tgl->get_c() << std::endl;
        std::cout << "Углы: " << std::endl;
        std::cout << "A=" << tgl->get_A() << "; " << "B=" << tgl->get_B() << "; " << "C=" << tgl->get_C() << std::endl;
        std::cout << std::endl; 

    }
};

class Triangle_p : public Triangle {
public:
    Triangle_p(int a, int b, int c, int A, int B) : Triangle(a, b, c, A, B, C = 90) {
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
    Triangle_rb(int a, int b, int A, int B) : Triangle(a, b, c = a, A, B, C = A) {
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
    Triangle_rs(int a) : Triangle(a, b = a, c = a, A = 60, B = 60, C = 60) {
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
    int a, b, c, d;
    int A, B, C, D;
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

    void print_info(Quadrangle* qgl) {

        Figure::print_info(qgl);
        std::cout << "Стороны: " << std::endl;
        std::cout << "a=" << qgl->get_a() << "; " << "b=" << qgl->get_b() << "; " << "c=" << qgl->get_c() << "; " << "d=" << qgl->get_d() << std::endl;
        std::cout << "Углы: " << std::endl;
        std::cout << "A=" << qgl->get_A() << "; " << "B=" << qgl->get_B() << "; " << "C=" << qgl->get_C() << "; " << "D=" << qgl->get_D() << std::endl;
        std::cout << std::endl;
    }
};

class Parallelogram : public Quadrangle {
public:
    Parallelogram(int a, int b, int A, int B) : Quadrangle(a, b, c = a, d = b, A, B, C = A, D = B) {
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
    Romb(int a, int A, int B) : Parallelogram(a, b = a, A, B) {
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
    Parallel_p(int a, int b) : Parallelogram(a, b, A = 90, B = 90) {
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
    Square(int a) : Parallel_p(a, b = a) {
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

int main()
{
    setlocale(LC_ALL, "Russian");

    Figure f;
    f.print_info(&f);
    std::cout << std::endl;
    
    Triangle t(10, 20, 30, 50, 60, 70);
    t.print_info(&t);
   
    Triangle_p tp(10, 20, 30, 50, 45);
    Triangle* pt_tp = &tp;
    pt_tp->print_info(&tp);

    Triangle_rb trb(10, 20, 40, 80);
    Triangle* pt_trb = &trb;
    pt_trb->print_info(&trb);

    Triangle_rs trs(20);
    Triangle* pt_trs = &trs;
    pt_trs->print_info(&trs);

    Quadrangle q(10, 20, 30, 40, 50, 60, 70, 80);
    q.print_info(&q); 

    Parallel_p pp(10, 20);
    Quadrangle* pt_pp = &pp;
    pt_pp->print_info(&pp); 
    
    Square s(20);
    Quadrangle* pt_s = &s;
    pt_s->print_info(&s);

    Parallelogram p(20, 30, 80, 90);
    Quadrangle* pt_p = &p;
    pt_p->print_info(&p); 
    
    Romb r(30, 60, 120);
    Quadrangle* pt_r = &r;
    pt_r->print_info(&r);

    return 0;
}