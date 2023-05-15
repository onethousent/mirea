#include "cone.h"
#include <cmath>
#include<iostream>

void Cone::input()
{
	cout << "Ââåäèòå êîîðäèíàòû öåíòðà (x, y, z): ";
	cin >> x >> y >> z;
	cout << "Ââåäèòå ðàäèóñ è âûñîòó: ";
	cin >> radius >> height;
}

void Cone::output()
{
	cout << "Êîîðäèíàòû öåíòðà: (" << x << ", " << y << ", " << z << ")" << endl;
	cout << "Ðàäèóñ îñíîâàíèÿ: " << radius << endl;
	cout << "Âûñîòà: " << height << endl;
}

double Cone::surfaceArea()
{
	return pi * radius * (radius + sqrt(pow(height, 2) + pow(radius, 2)));
}

double Cone::volume()
{
	return pi * pow(radius, 2) * height / 3;
}

double Cone::getRadius()
{
	return radius;
}

double Cone::getHeight()
{
	return height;
}

istream& operator>>(istream& input, Cone& c)
{
	c.input();
	return input;
}

ostream& operator<<(ostream& output, Cone& c)
{
	c.output();
	return output;
}

istream& operator>>(istream& input, TruncatedCone& tc)
{
	tc.input();
	cout << "Ââåäèòå ðàäèóñ âåðõíåãî îñíîâàíèÿ: ";
	cin >> tc.topRadius;
	return input;
}

ostream& operator<<(ostream& output, TruncatedCone& tc)
{
	tc.output();
	cout << "Ðàäèóñ âåðõíåãî îñíîâàíèÿ: " << tc.topRadius << endl;
	return output;
}

double TruncatedCone::surfaceArea()
{
	double l = sqrt(pow(getRadius() - topRadius, 2) + pow(getHeight(), 2));
	return pi * (pow(getRadius(), 2) + pow(topRadius, 2) + getRadius() * topRadius * l);
}

double TruncatedCone::volume()
{
	return pi * getHeight() * (pow(getRadius(), 2) + getRadius() * topRadius + pow(topRadius, 2)) / 3;
}
