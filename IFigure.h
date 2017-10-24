#ifndef IFIGURE_H
#define IFIGURE_H

class IFigure {
    public:
        virtual double Square() = 0;
        virtual void Print() = 0;
        virtual ~IFigure() {};
};

#endif //IFIGURE_H
