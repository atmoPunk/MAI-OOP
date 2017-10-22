#ifndef TRHOMBUS_H
#define TRHOMBUS_H

#include "IFigure.h"
#include <iostream>
#include <cstdlib>
#include <cmath>

const double PI = 3.1415;

class TRhombus : public IFigure {
public:
    TRhombus();
    TRhombus(double i, double j);
    TRhombus(std::istream &is);
    TRhombus(const TRhombus &original);
    virtual ~TRhombus() override;
    
    TRhombus& operator=(const TRhombus &original);
    bool operator==(const TRhombus &rhs) const;
    bool operator!=(const TRhombus &rhs) const;
    friend std::ostream &operator<<(std::ostream &os, const TRhombus &rhombus);
    friend std::istream& operator>>(std::istream& is, TRhombus& rhombus);
    
    double Square() override;
    void Print() override;
    
private:
    double side;
    double angle;
};

#endif //TRHOMBUS_H