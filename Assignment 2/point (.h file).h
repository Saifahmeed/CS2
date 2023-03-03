/*Name: Saif Ahmed Elsayed Abd Elfattah, ID: 900225535
Question statement: A cluster of points in 2-D space is a collection of points with different coordinates (x,y) but group together in one collection. The coordinates (x,y) may represent features of an object like (weight, height).
*/
#ifndef POINT_H
#define POINT_H

#include <cmath> // for square root and power functions

class point
{
    private:
    float x;
    float y;
public:
    // Default constructor. Sets x and y to 0.
    point();

    // Constructor. Initializes both x and y.
    point(float X, float Y);

    // Set x value
    void setX(float X);

    // Set y value
    void setY(float Y);

    // Get x value
    float getX() const;

    // Get y value
    float getY() const;

    // Display point as (x, y)
    void display() const;

    // Distance between current point object and another point p
    float distance(const point &p) const;


};

#endif // POINT_H
