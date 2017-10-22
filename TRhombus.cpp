#include "TRhombus.h"

TRhombus::TRhombus() : TRhombus(0.0, 0.0) {}

TRhombus::TRhombus(double i, double j) : side(i), angle(j) {}

TRhombus::TRhombus(std::istream &is) {
    std::cout << "rhombus:\n";
    do {
        std::cout << "Enter side:\n";
        is >> side;
    } while (side < 0.0);
    do {
        std::cout << "Enter lesser angle:\n";
        is >> angle;
    } while (angle < 0.0 && angle > PI/2);
}

TRhombus::TRhombus(const TRhombus& original) {
    side = original.side;
    angle = original.angle;
}

TRhombus::~TRhombus() {}



TRhombus& TRhombus::operator=(const TRhombus &right) {
    if(this == &right) {
        return *this;
    }

    side = right.side;
    angle = right.angle;

    return *this;
}

bool TRhombus::operator==(const TRhombus &rhs) const {
    return (this->side == rhs.side && this->angle == rhs.angle);
}

bool TRhombus::operator!=(const TRhombus &rhs) const {
    return !(rhs == *this);
}

std::ostream &operator<<(std::ostream &os, const TRhombus &rhombus) {
    os << "rhombus  side = " << rhombus.side << ", angle = " << rhombus.angle;
    return os;
}

std::istream &operator>>(std::istream &is, TRhombus &rhombus) {
    is >> rhombus.side;
    is >> rhombus.angle;
    return is;
}



double TRhombus::Square() {
    return side * side * sin(angle);
}

void TRhombus::Print() {
    std::cout << "Rhombus" << std::endl;
    std::cout << "side = " << side << std::endl;
    std::cout << "angle = " << angle << std::endl;
}