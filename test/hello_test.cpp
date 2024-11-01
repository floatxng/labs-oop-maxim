#include <gtest/gtest.h>
#include "../include/lib.h"

TEST(PolygonTest, GetCenter) {
    Vector2 edges[4] = { {0, 0}, {2, 0}, {2, 2}, {0, 2} }; 
    Polygon polygon(edges, 4); 

    Vector2 center = polygon.getCenter();
    EXPECT_DOUBLE_EQ(center.x, 1.0);
    EXPECT_DOUBLE_EQ(center.y, 1.0);
}

TEST(RhombTest, GetCenter) {
    Vector2 edges[4] = { {0, 0}, {1, 0}, {1, 1}, {0, 1} }; 
    Rhomb rhomb(edges[0], edges[1], edges[2], edges[3]);
    
    Vector2 center = rhomb.getCenter();
    EXPECT_DOUBLE_EQ(center.x, 0.5);
    EXPECT_DOUBLE_EQ(center.y, 0.5);
}

TEST(PentagonTest, GetCenter) {
    Vector2 edges[5] = { {0, 0}, {1, 0}, {1, 1}, {0, 1}, {0.5, 1.5} }; 
    Pentagon pentagon(edges[0], edges[1], edges[2], edges[3], edges[4]);
    
    Vector2 center = pentagon.getCenter();
    EXPECT_DOUBLE_EQ(center.x, 0.5);
    EXPECT_DOUBLE_EQ(center.y, 0.7); 
}

TEST(RhombTest, CastToDouble) {
    Vector2 edges[4] = { {0, 0}, {1, 0}, {1, 1}, {0, 1} }; 
    Rhomb rhomb(edges[0], edges[1], edges[2], edges[3]);
    
    double area = static_cast<double>(rhomb);
    EXPECT_DOUBLE_EQ(area, 1.0); 
}

TEST(PentagonTest, CastToDouble) {
    Vector2 edges[5] = { {0, 0}, {1, 0}, {1, 1}, {0, 1}, {0.5, 1.5} }; 
    Pentagon pentagon(edges[0], edges[1], edges[2], edges[3], edges[4]);
    
    double area = static_cast<double>(pentagon);
    EXPECT_DOUBLE_EQ(area, 0.75); 
}

TEST(TrapezoidTest, CastToDouble) {
    Vector2 edges[4] = { {0, 0}, {2, 0}, {1.5, 1}, {0.5, 1} }; 
    Trapezoid trapezoid(edges[0], edges[1], edges[2], edges[3]);

    double area = static_cast<double>(trapezoid);
    EXPECT_DOUBLE_EQ(area, 1.5); 
}