#include<stdio.h>
#define PI 3.14159265

//lets make an class for shapes as thats a simple example


//our shape needs an method for finding the area
//and for finding the perimeter
struct Shape {
    double (*area)(struct Shape *);
    double (*permimeter)(struct Shape *);
};

typedef struct Shape Shape;
//this is going to be our first polymorphisim
// and to do that it's going to have toa reference
//to the base class that it's inheriting the function or possibly the variables from

struct Circle {
    Shape base;
    double radius;
};

typedef struct Circle Circle;

struct Rectangle {
    Shape base;
    double width;
    double height;
};

typedef struct Rectangle Rectangle;

//two things that we will also need to define
//is the constructor to each object like we would in any other
//classed based langauge

void Rectangle_constructor(Rectangle *shape, double width, double height);
void Circle_constructor(Circle *shape, double radius);
