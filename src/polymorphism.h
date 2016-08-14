#pragma once
#include<iostream>
#include<string>
#include<vector>

using namespace std;

/* 
When you put at least 1 pure virtual function in a class, the class becomes abstract
meaning, you can't instantiate it

The purpose of an abstract class is to provide an appropriate base class from which 
other classes can inherit.

C++ interfaces are implemented using abstract classes
*/


class Shape {
protected:
	int width, height;
public:
	Shape(int a=0, int b=0):width(a),height(b)
	{
		cout << "Shape constructor run" << endl;
	}
	void area() { cout << "Parent class area :" << endl; }

	virtual void areav() { cout << "Parent class virtual area :" << endl; }

	virtual void areava() = 0;

};

class Triangle : public Shape {
public:
	Triangle(int a , int b) :Shape(a, b) 
	{
		cout << "Triangle constructor run" << endl;
	}
	void area() { cout << "Triangle class area" << endl; }

	void areav() { cout << "Triangle class virtual area" << endl; }

	void areava() { cout << "Triangle class pure virtual area" << endl; }
};


class polym
{
public:
	polym()
	{
		Shape *shape;		
		Triangle  tri(10, 5);		
		shape = &tri;	// store the address of Triangle		
		shape->area();	// shows parent area
		shape->areav();	// shows triangle area
		shape->areava();	// shows triangle  pure virtual area.  function must be implemented
	}

	void do01(vector<Triangle>& v)
	{
		v[0].area();
	}

};