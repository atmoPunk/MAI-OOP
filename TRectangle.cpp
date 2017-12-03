#include "TRectangle.h"

TRectangle::TRectangle() : TRectangle(0.0, 0.0) {}

TRectangle::TRectangle(double i, double j) : side_a(i), side_b(j) {}

TRectangle::TRectangle(std::istream &is) {
    std::cout << "Rectangle:\n";
    do {
        std::cout << "Enter side a:\n";
        is >> side_a;
    } while (side_a < 0.0);
    do {
        std::cout << "Enter side b:\n";
        is >> side_b;
    } while (side_b < 0.0);
}

TRectangle::TRectangle(const TRectangle& original) {
    side_a = original.side_a;
    side_b = original.side_b;
}

TRectangle::~TRectangle() {}



TRectangle& TRectangle::operator=(const TRectangle &right) {
    if(this == &right) {
        return *this;
    }

    side_a = right.side_a;
    side_b = right.side_b;

    return *this;
}

bool TRectangle::operator==(const TRectangle &rhs) const {
    return ((this->side_a == rhs.side_a && this->side_b == rhs.side_b) || (this->side_a == rhs.side_b && this->side_b == rhs.side_a));
}

bool TRectangle::operator!=(const TRectangle &rhs) const {
    return !(rhs == *this);
}

std::ostream &operator<<(std::ostream &os, const TRectangle &rectangle) {
    os << "Rectangle  side a = " << rectangle.side_a << ", side b = " << rectangle.side_b;
    return os;
}

std::istream &operator>>(std::istream &is, TRectangle &rectangle) {
    is >> rectangle.side_a;
    is >> rectangle.side_b;
    return is;
}



double TRectangle::Square() {
    return side_a * side_b;
}

void TRectangle::Print() {
    std::cout << "Rectangle, square: "  << Square() << std::endl;
}