#ifndef TRECTANGLE_H
#define TRECTANGLE_H

#include "IFigure.h"
#include <iostream>
#include <cstdlib>

class TRectangle : public IFigure {
    public:
        TRectangle();
        TRectangle(double i, double j);
        TRectangle(std::istream &is);
        TRectangle(const TRectangle &original);
        virtual ~TRectangle() override;
        
        TRectangle& operator=(const TRectangle &original);
        bool operator==(const TRectangle &rhs) const;
        bool operator!=(const TRectangle &rhs) const;
        friend std::ostream &operator<<(std::ostream &os, const TRectangle &rectangle);
        friend std::istream& operator>>(std::istream &is, TRectangle &rectangle);
        
        double Square() override;
        void Print() override;
    private:
        double side_a;
        double side_b;
};

#endif //TRECTANGLE_H