// Copyright 2024 MamedovKenan

#ifndef INCLUDE_CIRCLE_H_
#define INCLUDE_CIRCLE_H_
#include <cstdint>

class Circle {
private:
    double radius;
    double ference;
    double area;

    void updateFerence() {
        ference = 2 * 3.141592653589793 * radius;
    }

    void updateArea() {
        area = 3.141592653589793 * radius * radius;
    }

    void updateRadiusFromFerence() {
        radius = ference / (2 * 3.141592653589793);
    }

    void updateRadiusFromArea() {
        radius = std::sqrt(area / 3.141592653589793);
    }

public:
    Circle(double r) : radius(r) {
        updateFerence();
        updateArea();
    }

    void setRadius(double r) {
        radius = r;
        updateFerence();
        updateArea();
    }

    void setFerence(double f) {
        ference = f;
        updateRadiusFromFerence();
        updateArea();
    }

    void setArea(double a) {
        area = a;
        updateRadiusFromArea();
        updateFerence();
    }

    double getRadius() const {
        return radius;
    }

    double getFerence() const {
        return ference;
    }

    double getArea() const {
        return area;
    }
};

#endif  // INCLUDE_CIRCLE_H_
