#include <class.h>

//function definitions to the area of our shape
double circle_area(Shape* shape);
double rectangle_area(Shape* shape);
// function definitions to the permiter of our shape
double circle_perimeter(Shape* shape);
double rectangle_perimeter(Shape* shape);

int main(void) {
    Circle circle;
    Circle_constructor(&circle, 5.0);

    Rectangle rectangle;
    Rectangle_constructor(&rectangle, 10, 5);

    //turn into a shape
    Shape* c1_shape = (Shape*)&circle;
    Shape* r1_shape = (Shape*)&rectangle;
    //now we can perform our polymorphisim function we have declared in our header file

    double r1_area = rectangle_area(r1_shape);
    double r1_perimeter = rectangle_perimeter(r1_shape);

    printf("rectangle area: %lf\n", r1_area);
    printf("rectangle perimeter: %lf\n", r1_perimeter);

    double c1_area = circle_area(c1_shape);
    double c1_perimeter = circle_perimeter(c1_shape);

    printf("circle area: %lf\n", c1_area);
    printf("circle perimeter: %lf\n", c1_perimeter);

    return 0;
}

void Circle_constructor(Circle *shape, double radius)  {
    shape->radius = radius;
    shape->base.area = circle_area;
    shape->base.permimeter = circle_perimeter;
}

void Rectangle_constructor(Rectangle *shape, double width, double height) {
    shape->width = width;
    shape->height = height;
    shape->base.permimeter = rectangle_perimeter;
    shape->base.area = rectangle_area;
}

double circle_area(Shape* shape) {
    Circle* circle = (Circle*)shape;

    return PI * circle->radius * circle->radius;
}

double rectangle_area(Shape* shape) {
    Rectangle* rectangle = (Rectangle*)shape;

    return rectangle->width * rectangle->height;
}

double circle_perimeter(Shape* shape) {
    Circle* circle = (Circle*)shape;

    return 2 * PI * circle->radius;
}

double rectangle_perimeter(Shape* shape) {
    Rectangle* rectangle = (Rectangle*)shape;
    double width = rectangle->width * 2;
    double height = rectangle->height * 2;

    return width + height;
}
