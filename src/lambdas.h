#pragma once
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class lambdas
{
public:
	lambdas();
	~lambdas();

	void Lambda01();
	void Lambda02();		

private:
	
};

lambdas::lambdas()
{
	Lambda01();
}

lambdas::~lambdas(){}

void lambdas::Lambda01()
{
	//[] Capture clause 
	//() Parameter list
	//{} Body
	auto x1 = []() {cout << "hi" << endl; };
	x1();

	auto x2 = [](int i) {return i>6; };
	cout << x2(3) << endl;

	//[&] captures any variable you use inside body as reference. [=] captures by value
	int a = 1;
	cout << a << endl;
	auto x3 = [&]() {a = 2; };
	x3();
	cout << a << endl;


}


void lambdas::Lambda02()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	for_each(begin(v), end(v), [](int x)
	{
		cout << x << endl;
	});

}
