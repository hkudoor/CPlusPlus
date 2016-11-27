#include<iostream>
#include<hkudoor_utils.hpp>
#include<stdint.h>

class Shape {
private:
    uint8_t mNumSides;
    protected:
    Shape(uint8_t num) {
        mNumSides = num;
    }

    ~Shape() {
       std::cout<<"Deleting Shape\n";
    }
    public:
    virtual float getArea() = 0;
    uint8_t getNumSides() {
        return mNumSides;
    }
};

class Square: public Shape {
private:
    uint8_t mSize;
    
public:
    Square(uint8_t size);
    ~Square();
    void  setSize(uint8_t size) {
        mSize = size;
    }
    uint8_t getSize(uint8_t size) {
     return size;
    }
    float getArea() {
        return mSize*mSize;
    }
};

Square::Square(uint8_t size):
        Shape(2) {
    mSize = size;
    std::cout<<"Creating a square of size = "<<(int)size<<std::endl;
}

Square::~Square() {
    std::cout<<"Deleting Square\n";
}

// main
int main() {
    Square mySquare(5);
    std::cout<<"number of sides in my square = "<<(int)mySquare.getNumSides()<<std::endl;
    std::cout<<"area of my square = "<<mySquare.getArea()<<std::endl;
    return 0;
}

