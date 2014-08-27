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

int intersectionCount(const vector<Circle> &circles)
{
    int i;
    int j;
    double count = 0;
    for (i = 0; i < circles.size(); i++)
    {
        for (j = i + 1; j < circles.size(); j++)
        {
            if (circles[i].circleIntersect(circles[j]) == true)
            {
//				cout << "Circle at " << circles[i]  << " intersects circle at " << circles[j] << "." << endl; // DEBUG LINE <- Show's all intersections.
                count++;
            }
        }
    }
    return count;
}

double averageIntersections(int calc, vector<Circle> &cir, double count)
{
    int i = 0;
    double dub = 0;
    double r = 0;
    vector<double> rads;

    if (calc == 0)
    {
        dub = count / cir.size();
        return dub;
    }
    else if (calc == 1)
    {
        for (i = 0; i < cir.size(); i++)
        {
            r = cir[i].radius;
            if (r == 1)
            {
                rads.push_back(cir[i].radius);
            }
            for (i = 0; i < rads.size(); i++)
            {
                dub = dub + rads[i];
            }
            rads.clear();
            return dub / cir.size();
        }
    }
    else if (calc == 2)
    {
        for (i = 0; i < cir.size(); i++)
        {
            r = cir[i].radius;
            if (r == 2)
            {
                rads.push_back(cir[i].radius);
            }
            for (i = 0; i < rads.size(); i++)
            {
                dub = dub + rads[i];
            }
            rads.clear();
            return dub / cir.size();
        }
    }
    else if (calc == 3)
    {
        for (i = 0; i < cir.size(); i++)
        {
            r = cir[i].radius;
            if (r == 3)
            {
                rads.push_back(cir[i].radius);
            }
            for (i = 0; i < rads.size(); i++)
            {
                dub = dub + rads[i];
            }
            rads.clear();
            return dub / cir.size();
        }

    }
    else if (calc == 4)
    {
        for (i = 0; i < cir.size(); i++)
        {
            r = cir[i].radius;
            if (r == 4)
            {
                rads.push_back(cir[i].radius);
            }
            for (i = 0; i < rads.size(); i++)
            {
                dub = dub + rads[i];
            }
            rads.clear();
            return dub / cir.size();
        }

    }
    else if (calc == 5)
    {
        for (i = 0; i < cir.size(); i++)
        {
            r = cir[i].radius;
            if (r == 5)
            {
                rads.push_back(cir[i].radius);
            }
            for (i = 0; i < rads.size(); i++)
            {
                dub = dub + rads[i];
            }
            rads.clear();
            return dub / cir.size();
        }

    }
    else if (calc == 6)
    {
        for (i = 0; i < cir.size(); i++)
        {
            r = cir[i].radius;
            if (r == 6)
            {
                rads.push_back(cir[i].radius);
            }
            for (i = 0; i < rads.size(); i++)
            {
                dub = dub + rads[i];
            }
            rads.clear();
            return dub / cir.size();
        }

    }
    else if (calc == 7)
    {
        r = cir[i].radius;
        if (r == 7)
        {
            rads.push_back(cir[i].radius);
        }
        for (i = 0; i < rads.size(); i++)
        {
            dub = dub + rads[i];
        }
        rads.clear();
        return dub / cir.size();
    }
    else if (calc == 8)
    {
        r = cir[i].radius;
        if (r == 8)
        {
            rads.push_back(cir[i].radius);
        }
        for (i = 0; i < rads.size(); i++)
        {
            dub = dub + rads[i];
        }
        rads.clear();
        return dub / cir.size();

    }
    else if (calc == 9)
    {
        r = cir[i].radius;
        if (r == 9)
        {
            rads.push_back(cir[i].radius);
        }
        for (i = 0; i < rads.size(); i++)
        {
            dub = dub + rads[i];
        }
        rads.clear();
        return dub / cir.size();

    }
    else if (calc == 10)
    {
        r = cir[i].radius;
        if (r == 10)
        {
            rads.push_back(cir[i].radius);
        }
        for (i = 0; i < rads.size(); i++)
        {
            dub = dub + rads[i];
        }
        rads.clear();
        return dub / cir.size();

    }
    else
    {
        cout << "Fail." << endl;
        return 0;
    }
    return 0;
}

int main()
{
    vector<Circle> circles;

    int runCount = 1000;
    int i;

    for (i = 0; i < runCount; i++)
    {
        genCircle(circles);
    }
    int count = intersectionCount(circles);
    cout << "Total Circle Intersections  : " << count << endl;
    cout << "Average Total Intersections   : "<< averageIntersections(0, circles, ((double) count)) << endl;
    cout << "Average Intersection at Rad  1: "<< averageIntersections(1, circles, ((double) count)) << endl;
    cout << "Average Intersection at Rad  2: "<< averageIntersections(2, circles, ((double) count)) << endl;
    cout << "Average Intersection at Rad  3: "<< averageIntersections(3, circles, ((double) count)) << endl;
    cout << "Average Intersection at Rad  4: "<< averageIntersections(4, circles, ((double) count)) << endl;
    cout << "Average Intersection at Rad  5: "<< averageIntersections(5, circles, ((double) count)) << endl;
    cout << "Average Intersection at Rad  6: "<< averageIntersections(6, circles, ((double) count)) << endl;
    cout << "Average Intersection at Rad  7: "<< averageIntersections(7, circles, ((double) count)) << endl;
    cout << "Average Intersection at Rad  8: "<< averageIntersections(8, circles, ((double) count)) << endl;
    cout << "Average Intersection at Rad  9: "<< averageIntersections(9, circles, ((double) count)) << endl;
    cout << "Average Intersection at Rad 10: "<< averageIntersections(10, circles, ((double) count)) << endl;
    return 0;
}
