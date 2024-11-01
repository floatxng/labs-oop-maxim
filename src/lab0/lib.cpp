#include "lib.h"

std::istream& operator>> (std::istream& stream, Figure& figure) {
    figure.input(stream);
    return stream;
}

std::ostream& operator<< (std::ostream& stream, const Figure& figure) {
    figure.print(stream);
    return stream;
}

void Polygon::print(std::ostream& stream) const {
    stream << "Polygon with " << edgesCount << " edges:" << std::endl;
    for (int i = 0; i < edgesCount; i++) {
        stream << "Edge #" << i + 1 << ": (" << edges[i].x << ", " << edges[i].y << ")" << std::endl;
    }
}

double Polygon::getArea() const {
    double area = 0.;
    for (int i = 0; i < edgesCount; ++i) {
        int next = (i + 1) % edgesCount;
        area += edges[i].x * edges[next].y;
        area -= edges[next].x * edges[i].y;
    }
    return std::abs(area) / 2.;
}

Polygon::Polygon(Vector2* edges, int edgesCount) : edgesCount(edgesCount) {
    this->edges = new Vector2[edgesCount];
    std::memcpy(this->edges, edges, edgesCount * sizeof(Vector2));
}

Vector2 Polygon::getCenter() {
    double eXSum = 0, eYSum = 0;
    for (int i = 0; i < edgesCount; i++) {
        eXSum += edges[i].x;
        eYSum += edges[i].y;
    }
    return Vector2{eXSum / edgesCount, eYSum / edgesCount};
}

void Polygon::input(std::istream& stream) {
    std::cout << "Enter " << edgesCount << " vertices (x y):\n";
    for (int i = 0; i < edgesCount; i++) {
        stream >> edges[i].x >> edges[i].y;
    }
}

// Other class implementations...

Trapezoid::Trapezoid() : Polygon(new Vector2[4]{ {0, 0}, {0, 0}, {0, 0}, {0, 0} }, 4) {}

Trapezoid::Trapezoid(Vector2 v1, Vector2 v2, Vector2 v3, Vector2 v4) : Polygon(new Vector2[4]{ v1, v2, v3, v4 }, 4) {}

void Trapezoid::input(std::istream& stream) {
    std::cout << "Enter 4 vertices for trapezoid (x y):\n";
    for (int i = 0; i < edgesCount; ++i) {
        stream >> edges[i].x >> edges[i].y;
    }
}

Rhomb::Rhomb() : Polygon(new Vector2[4]{ {0, 0}, {0, 0}, {0, 0}, {0, 0} }, 4) {}

Rhomb::Rhomb(Vector2 v1, Vector2 v2, Vector2 v3, Vector2 v4) : Polygon(new Vector2[4]{ v1, v2, v3, v4 }, 4) {}

void Rhomb::input(std::istream& stream) {
    std::cout << "Enter 4 vertices for rhomb (x y):\n";
    for (int i = 0; i < edgesCount; ++i) {
        stream >> edges[i].x >> edges[i].y;
    }
}

Pentagon::Pentagon() : Polygon(new Vector2[5]{ {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0} }, 5) {}

Pentagon::Pentagon(Vector2 v1, Vector2 v2, Vector2 v3, Vector2 v4, Vector2 v5) : Polygon(new Vector2[5]{ v1, v2, v3, v4, v5 }, 5) {}

void Pentagon::input(std::istream& stream) {
    std::cout << "Enter 5 vertices for pentagon (x y):\n";
    for (int i = 0; i < edgesCount; ++i) {
        stream >> edges[i].x >> edges[i].y;
    }
}
