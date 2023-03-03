/*Name: Saif Ahmed Elsayed Abd Elfattah, ID: 900225535
Question statement: A cluster of points in 2-D space is a collection of points with different coordinates (x,y) but group together in one collection. The coordinates (x,y) may represent features of an object like (weight, height).
*/
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include "point.h"
using namespace std;

    // Default Constructor, sets X = Y = 0
    point::point() {
        x = 0;
        y = 0;
    }
    // Constructor. Initializes both X and Y.
    point::point(float X, float Y) {
        x = X;
        y = Y;
    }
    // Set X value
    void point::setX(float X) {
        x = X;
    }
    // Set Y value
    void point::setY(float Y) {
        y = Y;
    }
    // Get X value
    float point::getX()const {
        return x;
    }
    // Get Y value
    float point::getY() const{
        return y;
    }
    // Display point as (X , Y)
    void point::display() const{
        cout << "(" << x << ", " << y << ")" << endl;
    }
    // Distance between current point object and another point p
    float point::distance(const point &p) const{
        float dx = x - p.getX();
        float dy = y - p.getY();
        return sqrt(dx*dx + dy*dy);
    }

// Computes the center point of an array of points
point Center(point C[], int n) {
    float sumX = 0, sumY = 0;

    // Calculate the sum of x and y coordinates of all points
    for (int i = 0; i < n; i++) {
        sumX += C[i].getX();
        sumY += C[i].getY();
    }

    // Calculate the average x and y coordinates
    float avgX = sumX / n;
    float avgY = sumY / n;

    // Create a new point at the center
    point center(avgX, avgY);
    return center;
}

// Determines to which cluster center a given point is closest
char closestCluster(point Acenter, point Bcenter, point p) {
    float distToA = p.distance(Acenter);
    float distToB = p.distance(Bcenter);

    // Compare distances to the two cluster centers and return the closest one
    if (distToA < distToB) {
        return 'A';
    } else {
        return 'B';
    }
}

int main() {
    // Generate n random points for cluster A
    const int n = 200;
    point *A = new point[n];
    for (int i = 0; i < n; i++) {
        float x = 70.0 + (float)rand() / RAND_MAX * 20.0;
        float y = 70.0 + (float)rand() / RAND_MAX * 20.0;
        A[i].setX(x);
        A[i].setY(y);
    }

    // Generate n random points for cluster B
    point *B = new point[n];
    for (int i = 0; i < n; i++) {
        float x = 20.0 + (float)rand() / RAND_MAX * 20.0;
        float y = 20.0 + (float)rand() / RAND_MAX * 20.0;
        B[i].setX(x);
        B[i].setY(y);
    }

    // Generate m random points
    const int m = 20;
    point *P = new point[m];
    for (int i = 0; i < m; i++) {
        float x = 5.0 + (float)rand() / RAND_MAX * 95.0;
        float y = 5.0 + (float)rand() / RAND_MAX * 95.0;
        P[i].setX(x);
        P[i].setY(y);
    }

    // Determine to which cluster each of the m points belongs
    for (int i = 0; i < m; i++) {
        point p = P[i];
        point centerA = Center(A, n);
        point centerB = Center(B, n);

        if (p.distance(centerA) < p.distance(centerB)) {
            cout << "Point " << i+1 << " belongs to cluster A\n";
        } else {
            cout << "Point " << i+1 << " belongs to cluster B\n";
        }
    }

    // Free memory
    delete[] A;
    delete[] B;
    delete[] P;

    return 0;
}

   
