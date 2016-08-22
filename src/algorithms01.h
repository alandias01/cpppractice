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





class algorithms01
{
public:
	
	algorithms01()
	{		
		//findif();
	}

	void fp01(void(*f)(int))
	{
		(*f)(3);
	}

	void fp02(void(algorithms01::*f)(int x))
	{
		
	}
	void useme(int x)
	{
		cout << "Im being used" << endl;
	}

	

	void findif()
	{
		//When iterating, use non member begin and end

		vector<int> v = { 1,2,3,4,5,6,7 };
		int x = 3, y = 5;
		auto i = find_if(begin(v), end(v), [=](int i) { return i > x && i < y; });

		
		list<int> n = { 1,2,3,4,5 };

		auto fi = find_if(begin(n), end(n), [](int a) { return (a % 2) == 0; });
	}


};

