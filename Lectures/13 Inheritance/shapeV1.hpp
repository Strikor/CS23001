// Programmer: Dr. J. Maletic
//
#ifndef SHAPE_HPP_
#define SHAPE_HPP_

#include <iostream>


class shape {
    public:
        shape(int nx=0, int ny=0) : x(nx), y(ny) {};
        virtual ~shape() {}; // Not quite sure why
        void move(int nx, int ny) { x = nx; y = ny; };
        virtual void draw() const = 0; // Pure Virtual //{std::cout << "Shape at: " << x << ", " << y << std::endl; };

        virtual bool isCircle() const = 0;
        virtual bool isTriangle() const = 0;
        virtual bool isRectangle() const = 0;
        virtual bool isSquare() const = 0;


    protected:
        int x, y;    
};

class circle : public shape {
    public:
        circle(int radius=0) : shape(), r(radius) {};
        virtual void draw() const {std::cout << "Circle at: " << x << ", " << y << " with radius " << r <<std::endl; };

        virtual bool isCircle() const {return true};
        virtual bool isTriangle() const {return false};
        virtual bool isRectangle() const {return false};
        virtual bool isSquare() const {return false};
    
    protected:
        int r;
};

class triangle : public shape {
    public:
        triangle(int nb=0, int nh=0) : shape(), w(nb), h(nh) {};
        virtual void draw() const { std::cout << "Triangle at: " << x << ", " << y << " with height, width " << w << ", " << h << std::endl; };

        virtual bool isCircle() const {return false};
        virtual bool isTriangle() const {return true};
        virtual bool isRectangle() const {return false};
        virtual bool isSquare() const {return false};

    protected:
        int h,w;
};

class rectangle : public shape {
    public:
        rectangle(int nh=0, int nw=0) : shape(), h(nh), w(nw) {};
        virtual void draw() const { std::cout << "Rectangle at: " << x << ", " << y << " with height, width " << w << ", " << h << std::endl; };

        virtual bool isCircle() const {return false};
        virtual bool isTriangle() const {return false};
        virtual bool isRectangle() const {return true};
        virtual bool isSquare() const {return false};

    protected:
        int h,w;
};

class square : public rectangle {
    public:
        square(int nw=0) : rectangle(nw, nw) {};
        virtual void draw() const { std::cout << "Square at: " << x << ", " << y << " with width " << w << std::endl; };

        virtual bool isCircle() const {return false};
        virtual bool isTriangle() const {return false};
        virtual bool isRectangle() const {return true};
        virtual bool isSquare() const {return true};

};






#endif