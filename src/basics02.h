#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<algorithm>
#include "simple.h"

using namespace std;


/* NOTES

constexpr
*/





class basics02
{
public:
	basics02();
	~basics02();

	void arrays01();

	void templates();
	template<class T>
	void templates01(T v);

	template<class U>
	void templates02(U& args);
		
	void iterateThroughACollection01();
	void iterateThroughACollection02();
	void rangeBasedFor();
	void rangeBasedFor_each();
		

private:

};

basics02::basics02()
{		
	templates();
	
}

basics02::~basics02()
{
}


void basics02::arrays01()
{
	int a[] = {1,2,3,4};	//c++ 11 initialization list
	
	//Below doesn't work if you pass to a function, then ayou will get size of the pointer
	cout << sizeof(a) << endl;	//gives bytes occupied by array
	cout << sizeof(a)/sizeof(a[0]) << endl; //gives num of elements

	//prefer vector to get count since it has built in functions
}

inline void basics02::templates()
{
	int x = 3;
	templates01(x);

	vector<simple> v = { simple(1),simple(2) };
	templates02(v);
}

template<class T>
void basics02::templates01(T v)
{
	cout << v << endl;
}

template<class U>
void basics02::templates02(U& args)
{
	for (auto it : args)
	{
		
	}
}


void basics02::iterateThroughACollection01()
{
	vector<int> v = {1,2,3,4,5,6,7};

	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
		cout << *it << endl;
	}
	
}

void basics02::iterateThroughACollection02()
{
	list<int> n = { 1,2,3,4,5 };

	const list<int>::const_iterator result = find_if(n.begin(), n.end(), [](int a) { return (a % 2) == 0; });

	if (result != n.end())
	{
		cout << "The first even number in the list is " << (*result) << "." << endl;
	}

	else
	{
		cout << "The list contains no even numbers." << endl;
	}
}



//Benefits of range based for over for_each.. Range based for allows break and continue
void basics02::rangeBasedFor()
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
void basics02::rangeBasedFor_each()
{
	vector<int> v = { 1,2,3 };
	
	for_each(begin(v), end(v), [](int x)
	{
		cout << x << endl;
	});

}




