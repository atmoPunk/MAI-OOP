#include "TTrapezoid.h"

TTrapezoid::TTrapezoid() : TTrapezoid(0.0, 0.0, 0.0) {}

TTrapezoid::TTrapezoid(double i, double j, double k) : base1(i), base2(j), height(k) {}

TTrapezoid::TTrapezoid(std::istream &is) {
    std::cout << "Trapezoid:\n";
    do {
        std::cout << "Enter base 1:\n";
        is >> base1;
    } while (base1 < 0.0);
    do {
        std::cout << "Enter base 2:\n";
        is >> base2;
    } while (base2 < 0.0);
    do {
        std::cout << "Enter height:\n";
        is >> height;
    } while (height < 0.0);
}

TTrapezoid::TTrapezoid(const TTrapezoid &original) {
    base1 = original.base1;
    base2 = original.base2;
    height = original.height;
}

TTrapezoid::~TTrapezoid() {}



TTrapezoid& TTrapezoid::operator=(const TTrapezoid &right) {
    if(this == &right) {
        return *this;
    }

    base1 = right.base1;
    base2 = right.base2;
    height = right.height;

    return *this;
}

bool TTrapezoid::operator==(const TTrapezoid &rhs) const {
    return (((this->base1 == rhs.base1 && this->base2 == rhs.base2) || (this->base1 == rhs.base2 && this->base2 == rhs.base1)) && this->height == rhs.height);
}

bool TTrapezoid::operator!=(const TTrapezoid &rhs) const {
    return !(rhs == *this);
}

std::ostream &operator<<(std::ostream &os, const TTrapezoid &trapezoid) {
    os << "Trapezoid  base 1 = " << trapezoid.base1 << ", base 2 = " << trapezoid.base2 << ", height = " << trapezoid.height;
    return os;
}

std::istream &operator>>(std::istream &is, TTrapezoid &trapezoid) {
    is >> trapezoid.base1;
    is >> trapezoid.base2;
    is >> trapezoid.height;
    return is;
}

double TTrapezoid::Square() {
    return (base1 + base2) / 2 * height;
}

void TTrapezoid::Print() {
    std::cout << "Trapezoid" << std::endl;
    std::cout << "base 1 = " << base1 << std::endl;
    std::cout << "base 2 = " << base2 << std::endl;
    std::cout << "heihgt = " << height << std::endl;
}