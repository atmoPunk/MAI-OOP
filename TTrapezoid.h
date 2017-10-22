#ifndef TTRAPEZOID_H
#define TTRAPEZOID_H

#include "IFigure.h"
#include <iostream>
#include <cstdlib>

class TTrapezoid : public IFigure {
    public:
        TTrapezoid();
        TTrapezoid(double i, double j, double k);
        TTrapezoid(std::istream &is);
        TTrapezoid(const TTrapezoid& original);
        virtual ~TTrapezoid() override;
    
        TTrapezoid& operator=(const TTrapezoid &original);
        bool operator==(const TTrapezoid &rhs) const;
        bool operator!=(const TTrapezoid &rhs) const;
        friend std::ostream &operator<<(std::ostream &os, const TTrapezoid &trapezoid);
        friend std::istream& operator>>(std::istream &is, TTrapezoid &trapezoid);
    
        double Square() override;
        void Print() override;

    private:
        double base1;
        double base2;
        double height;
};

#endif //TTRAPEZOID_H