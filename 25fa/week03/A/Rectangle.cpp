// Rectangle.h code below

class Rectangle {
public:
    Rectangle();
    Rectangle(int w, int h, int xval, int yval);  // explicit-value ctor

    int area() const;

private:
    int width;
    int height;
    // location of upper left corner
    int x;
    int y;
};

// Rectangle.cpp code below

// default ctor
Rectangle::Rectangle() {
    width = height = x = y = 0;
}

Rectangle::Rectangle(int w, int h, int xval, int yval) {
    width = w;
    height = h;
    x = xval;
    y = yval;
}

int Rectangle::area() const {
    return width * height;
}