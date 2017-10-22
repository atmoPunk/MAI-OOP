#ifndef IFIGURE_H
#define IFIGURE_H

class IFigure {
    public:
        virtual double Square() = 0;
        virtual void Print() = 0;
        virtual ~IFigure() {};

        // virtual IFigure& operator=() = 0;
        // virtual bool operator==() const = 0;
        // virtual bool operator!=() const = 0;
        // virtual friend std::ostream &operator<<() = 0;
        // virtual friend std::istream& operator>>() = 0;
};

#endif //IFIGURE_H