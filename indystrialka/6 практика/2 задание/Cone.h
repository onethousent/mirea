#include<iostream>

using namespace std;

const double pi = 3.14159;
class Cone {
private:
    double x;
    double y;
    double z;
    double radius;
    double height;
public:
    Cone() : x(0), y(0), z(0), radius(0), height(0) {}
    Cone(double r, double h) : x(0), y(0), z(0), radius(r), height(h) {}
    Cone(double X, double Y, double Z, double r, double h) : x(X), y(Y), z(Z), radius(r), height(h) {}

    void input();
    void output();
    double surfaceArea();
    double volume();
    double getRadius();
    double getHeight();
    friend istream& operator>>(istream& input, Cone& c);
    friend ostream& operator<<(ostream& output, Cone& c);
};

class TruncatedCone : public Cone {
private:
    double topRadius;
public:
    TruncatedCone() : topRadius(0) {}
    TruncatedCone(double tr) : topRadius(tr) {}
    TruncatedCone(double X, double Y, double Z, double r, double h, double tr) : Cone(X, Y, Z, r, h), topRadius(tr) {}

    double surfaceArea();
    double volume();
    friend istream& operator>>(istream& input, TruncatedCone& tc);
    friend ostream& operator<<(ostream& output, TruncatedCone& tc);
};
