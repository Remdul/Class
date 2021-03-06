#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include "math.h"

using std::cout;
using std::cin;
using std::endl;
using std::vector;

class Point
{
public:
    int x;
    int y;
    double distance(Point) const;
private:
};

class Circle
{
public:
    bool isInCircle(Point);
    bool circleIntersect(Circle) const;
    Point center;
    double radius;
    friend std::ostream & operator <<(std::ostream &lhs, const Circle &rhs);
private:
};

std::ostream & operator<<(std::ostream &lhs, const Circle &rhs)
{
    lhs << "(" << rhs.center.x << ", " << rhs.center.y << ") Radius: "
            << rhs.radius;
    return lhs;
}

double Point::distance(Point endPoint) const
{
    double deltaX = endPoint.x - x;
    double deltaY = endPoint.y - y;
    double val = (deltaX * deltaX) + (deltaY * deltaY);
    double z = sqrt(val);
    return z;
}
bool Circle::circleIntersect(Circle intCirc) const
{
    double totRad = radius + intCirc.radius;
    if (center.distance(intCirc.center) > totRad)
    {
        return false;
    }
    return true;
}

bool Circle::isInCircle(Point calcPoint)
{

    if (center.distance(calcPoint) > radius)
    {
        return false;
    }
    return true;
}

void genCircle(std::vector<Circle> &circles)
{
    int choice;
    double radius;
    int circleCount = 10;
    int x;
    int y;
    srand(time(NULL));

    int min_rad = 0;
    int max_rad = 10;

    int min_point = -5;
    int max_point = 5;
    for (int i = 0; i < circleCount; i++)
    {
        Circle cir;
        Point newPoint;
        newPoint.x = rand() % 11 + (-5);
        newPoint.y = rand() % 11 + (-5);
        cir.center = newPoint;
        cir.radius = rand() % 10 + 1;
        circles.push_back(cir);
//		cout << cir << endl; // DEBUG LINE <- Show's all circle's.
    }
}

int intersectionCount(int rad, const vector<Circle> &circles)
{
    int i;
    int j;
    double count = 0;
    if (rad == 0)
    {
        for (i = 0; i < circles.size(); i++)
        {
            for (j = i + 1; j < circles.size(); j++)
            {
                if (circles[i].circleIntersect(circles[j]) == true)
                {
                    count++;
                }
            }
        }
    }
    else
    {
        for (i = 0; i < circles.size(); i++)
        {
            for (j = i + 1; j < circles.size(); j++)
            {
                if ((circles[i].circleIntersect(circles[j]) == true)
                        && circles[i].radius == rad)
                {
                    /*                    cout << "Circle at " << circles[i]
                     << " intersects circle at " << circles[j] << "."
                     << endl; // DEBUG LINE <- Show's all intersections.*/
                    count++;
                }
            }
        }

    }
    return count;
}

int main()
{
    vector<Circle> circles;
    vector<double> rads;
    int runCount = 100;
    int i;
    int j;
    int k;
    int maxrad = 11;
    double aver = 0;
    double aver1 = 0;
    double total = 0;
    double ttotal = 0;
    for (i = 0; i < runCount; i++)
    {
        genCircle(circles);
    }
    /*USED TO OUTPUT ALL RADI*/
        for (j = 0; j < circles.size(); j++)
     {
     cout << "#" << j << " ::Radius:: " << circles[j].radius << endl;
     }

    for (i = 0; i < maxrad; i++)
    {
        rads.clear();
        aver = 0;
        total = 0;
        aver1 = 0;
        if (i == 0)
        {
            ttotal = intersectionCount(i, circles);
            cout << "Total Intersections This Iteration: " << ttotal << endl
                    << endl;

        }
        else
        {
            total = intersectionCount(i, circles);
            cout << "Total Intersections at   " << i << ": " << total << endl;

        }
        for (j = 0; j < circles.size(); j++)
        {
            if (circles[j].radius == i)
            {
                aver++;
            }
        }
        aver = total / ttotal * 100;
        if (i == 0)
        {
        }
        else
        {

            cout << "Average Intersections at " << i << ": " << aver << "%"
                    << endl << endl;
        }
    }

    return 0;
}
