#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<algorithm>

using namespace std;

class simple
{ 
public:
	simple() {	}
	int a;
};

/* NOTES

constexpr
*/


class basics01
{
public:
	basics01();
	~basics01();

	void arrays01();
	void iterateThroughAColllection();
	void rangeBasedFor();
	void rangeBasedFor_each();
	void algorithms01();

private:

};

basics01::basics01()
{
	arrays01();
	iterateThroughAColllection();
	
}

basics01::~basics01()
{
}


void basics01::arrays01()
{
	int a[] = {1,2,3,4};	//c++ 11 initialization list
	
	//Below doesn't work if you pass to a function, then ayou will get size of the pointer
	cout << sizeof(a) << endl;	//gives bytes occupied by array
	cout << sizeof(a)/sizeof(a[0]) << endl; //gives num of elements


	

	//prefer vector to get count since it has built in functions
}

void basics01::iterateThroughAColllection()
{
	vector<int> v = {1,2,3,4,5,6,7};

	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
		cout << *it << endl;
	}

}


//Banefits of range based for over for_each.. Range based for allows break and continue
void basics01::rangeBasedFor()
{
	//BAD
	int x[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
		
	// Access by value using a copy declared as a specific type.  Not preferred.
	for (int y : x) { 
		cout << y << " ";
	}
	cout << endl;

	/*---The auto keyword causes type inference to be used. Preferred. ---*/

	//Copy of 'x', almost always undesirable
	for (auto y : x) { 
		cout << y << " ";
	}
	cout << endl;

	// Type inference by reference. Observes and/or modifies in-place. Preferred when modify is needed.
	for (auto &y : x) { 
		cout << y << " ";
	}
	cout << endl;

	// Type inference by reference. Observes in-place. Preferred when no modify is needed.
	for (const auto &y : x) { 
		cout << y << " ";
	}
	cout << endl;


	// Range-based for loop to iterate through the vector, observing in-place.
	vector<double> v;
	for (int i = 0; i < 10; ++i) {
		v.push_back(i + 0.14159);
	}

	for (const auto &j : v) {
		cout << j << " ";
	}
	cout << endl;
	cout << "end of vector test" << endl;
}

//Benefits of range based for_each over for. For_each allows you to pick range
void basics01::rangeBasedFor_each()
{

}

void basics01::algorithms01() 
{
	//When iterating, use non member begin and end

	vector<int> v = { 1,2,3,4,5,6,7 };
	int x = 3, y = 5;
	auto i = find_if(begin(v), end(v), [=](int i) { return i > x && i < y; });

	list<int> n = {1,2,3,4,5};

	const list<int>::const_iterator result = find_if(n.begin(), n.end(), [](int a) { return (a % 2) == 0; });

	if (result != n.end())
	{
		cout << "The first even number in the list is " << (*result) << "." << endl;
	}

	else
	{
		cout << "The list contains no even numbers." << endl;
	}

	auto fi = find_if(begin(n), end(n), [](int a) { return (a % 2) == 0; });


}