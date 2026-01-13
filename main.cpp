// Name: Rishit Srinivas 
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <ctime> 
using namespace std;

class Shape {
protected:
    int serialNum;
public:
    Shape(int serialNumber = 0) : serialNum(serialNumber) {}
    ~Shape() {}

    virtual void draw() const = 0; // pure virtual function
};

class Circle : public Shape {
protected:
    int radius;
public:
    Circle(int serialNumber = 0, int radiusValue = 0)
        : Shape(serialNumber), radius(radiusValue) {}

    void draw() const override {
        cout << "Circle Serial " << serialNum
             << ", Radius = " << radius << "\n";

        int xPosition = radius, yPosition = radius;
        int maxY = yPosition + radius;
        int minY = yPosition - radius;

        for (int i = minY; i <= maxY; i++) {
            if (i >= 0) {
                for (int j = -radius; j <= radius; j++) {
                    int a = xPosition + j;
                    int b = i;

                    if (a >= 0) {
                        double distance = sqrt((a - xPosition) * (a - xPosition) +
                                               (b - yPosition) * (b - yPosition));
                        if (distance <= radius) 
                            cout << "* ";
                        else
                            cout << "  ";
                    }
                }
                cout << endl;
            }
        }
        cout << endl;
    }
};

class Rectangle : public Shape {
protected:
    int width, height;
public:
    Rectangle(int serialNumber = 0, int rectWidth = 0, int rectHeight = 0)
        : Shape(serialNumber), width(rectWidth), height(rectHeight) {}

    void draw() const override {
        cout << "Rectangle Serial " << serialNum
             << ", Width = " << width
             << ", Height = " << height << "\n";
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++)
                cout << "* ";
            cout << endl;
        }
        cout << endl;
    }
};

class Square : public Rectangle {
public:
    Square(int serialNumber = 0, int sideLength = 0)
        : Rectangle(serialNumber, sideLength, sideLength) {}

    void draw() const override {
        cout << "Square Serial " << serialNum
             << ", Side = " << width << "\n";
        for (int i = 0; i < width; i++) {
            for (int j = 0; j < width; j++)
                cout << "* ";
            cout << endl;
        }
        cout << endl;
    }
};

class Spray : public Shape {
protected:
    int radius;
    int density;
public:
    Spray(int serialNumber = 0, int sprayRadius = 0, int sprayDensity = 0)
        : Shape(serialNumber), radius(sprayRadius), density(sprayDensity) {}

    void draw() const override {
        cout << "Spray Serial " << serialNum
             << ", Radius = " << radius
             << ", Density = " << density << "%\n";

        int xPosition = radius, yPosition = radius;
        int maxY = yPosition + radius;
        int minY = yPosition - radius;

        for (int i = minY; i <= maxY; i++) {
            if (i >= 0) {
                for (int j = -radius; j <= radius; j++) {
                    int a = xPosition + j;
                    int b = i;

                    if (a >= 0) {
                        double distance = sqrt((a - xPosition) * (a - xPosition) +
                                               (b - yPosition) * (b - yPosition));
                        if (distance <= radius) {
                            if (rand() % 100 < density)
                                cout << "* ";
                            else
                                cout << "  ";
                        } else {
                            cout << "  ";
                        }
                    }
                }
                cout << endl;
            }
        }
        cout << endl;
    }
};

class mgrShape {
private:
    static const int MAX_SHAPES = 99; // static class constant
    Shape* shapes[MAX_SHAPES];
    int shapeCount;

public:
    mgrShape() : shapeCount(0) {
        for (int i = 0; i < MAX_SHAPES; i++)
            shapes[i] = nullptr;
        populateShapeData();
    }

    ~mgrShape() {
        for (int i = 0; i < MAX_SHAPES; i++)
            delete shapes[i];
    }

    void populateShapeData() {
        ifstream inputFile("shaperecords.txt");
        if (!inputFile) {
            cout << "Error: Could not open shaperecords.txt\n";
            return;
        }

        char shapeType;
        int serialNumber, value1, value2;

        while (inputFile >> shapeType >> serialNumber >> value1 >> value2) {
            if (shapeCount >= MAX_SHAPES) break;

            switch (shapeType) {
                case 'C':
                    shapes[shapeCount++] = new Circle(serialNumber, value1);
                    break;
                case 'R':
                    shapes[shapeCount++] = new Rectangle(serialNumber, value1, value2);
                    break;
                case 'Q':
                    shapes[shapeCount++] = new Square(serialNumber, value1);
                    break;
                case 'S':
                    shapes[shapeCount++] = new Spray(serialNumber, value1, value2);
                    break;
                default:
                    cout << "Unknown shape type: " << shapeType << endl;
            }
        }

        inputFile.close();
    }

    void displayAll() const {
        cout << "\nDisplaying All Shapes:\n\n";
        for (int i = 0; i < shapeCount; i++) {
            if (shapes[i])
                shapes[i]->draw();
        }
    }
};

int main() {
    srand(static_cast<unsigned int>(time(nullptr))); //seed with current time
    mgrShape shapeManager;
    shapeManager.displayAll();
    return 0;
}
