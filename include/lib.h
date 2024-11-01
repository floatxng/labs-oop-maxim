#pragma once

#include <initializer_list>
#include <string>
#include <iostream>
#include <cmath> 
#include <cstring>

struct Vector2 {
    double x; 
    double y;
};

class Figure {
protected:
    virtual double getArea() const = 0;
    virtual void print(std::ostream& stream) const = 0;
    virtual void input(std::istream& stream) = 0; 

public:
    virtual Vector2 getCenter() = 0;

    explicit operator double() const {
        return getArea();
    }

    friend std::ostream& operator<< (std::ostream& stream, const Figure& figure);
    friend std::istream& operator>> (std::istream& stream, Figure& figure);
};

class Polygon : public Figure {
protected:
    Vector2* edges;
    int edgesCount;

    void print(std::ostream& stream) const override;
    double getArea() const override;
    virtual void input(std::istream& stream) override;

public:
    Polygon(Vector2* edges, int edgesCount);

    Vector2 getCenter() override;
};

class Trapezoid : public Polygon {
public:
    Trapezoid();
    Trapezoid(Vector2 v1, Vector2 v2, Vector2 v3, Vector2 v4);
    void input(std::istream& stream) override;
};

class Rhomb : public Polygon {
public:
    Rhomb();
    Rhomb(Vector2 v1, Vector2 v2, Vector2 v3, Vector2 v4);
    void input(std::istream& stream) override;
};

class Pentagon : public Polygon {
public:
    Pentagon();
    Pentagon(Vector2 v1, Vector2 v2, Vector2 v3, Vector2 v4, Vector2 v5);
    void input(std::istream& stream) override;
};
