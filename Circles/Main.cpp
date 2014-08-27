#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <math.h>

using std::cout;
using std::cin;
using std::endl;
using std::vector;


class Point{
public:
	int x;
	int y;
	double distance(Point) const;
private:
};

class Circle{
public:
	bool isInCircle(Point);
	bool circleIntersect(Circle) const;
	Point center;
	double radius;
	friend std::ostream & operator << (std::ostream &lhs, const Circle &rhs);
private:
};

std::ostream & operator<<(std::ostream &lhs, const Circle &rhs)
{
	lhs << "(" << rhs.center.x << ", "
			<< rhs.center.y << ") Radius: " << rhs.radius;
	return lhs;
}

double Point::distance(Point endPoint) const
{
	double deltaX = endPoint.x - x;
	double deltaY = endPoint.y - y;
	double val = (deltaX*deltaX)+(deltaY*deltaY);
	double z 	= sqrt(val);
	return z;
}
bool Circle::circleIntersect(Circle intCirc) const {
	double totRad = radius + intCirc.radius;
	if (center.distance(intCirc.center) > totRad) {
		return false;
	}
	return true;
}

bool Circle::isInCircle(Point calcPoint) {

	if (center.distance(calcPoint) > radius) {
		return false;
	}
	return true;
}
int rand(int min, int max)
{
	int range = max - min + 1;
	int num = std::rand() % range;
	num += min;
	return num;
}

void genCircle(std::vector<Circle> &circles)
{
	int choice;
	double radius;
	int circleCount = 10;
	int x;
	int y;

	int min_rad = 0;
	int max_rad = 10;

	int min_point = -5;
	int max_point = 5;

	for (int i = 0; i < circleCount; i++)
	{
		Circle cir;
		Point newPoint;
		newPoint.x 		= rand(min_point, max_point);
		newPoint.y 		= rand(min_point, max_point);
		cir.center  = newPoint;
		cir.radius 	= rand(min_rad, max_rad);
		circles.push_back(cir);
	}
}

void intersectionCount(const vector<Circle> &circles)
{
	int i;
	int j;
	for (i = 0; i < circles.size(); i++)
	{
		for (j = i+1; j < circles.size(); j++)
		{
			if (circles[i].circleIntersect(circles[j]) == true)
			{
				cout << "Circle at " << circles[i]  << " intersects circle at " << circles[j] << "." << endl;
			}
		}
	}
}
int main()
{
	vector<Circle> circles;

	int runCount = 1000;
	int i;

	for (i = 0; i < 1000; i++)
	{
		genCircle(circles);
		intersectionCount(circles);
	}


	return 0;
}
