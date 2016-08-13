#include "lambdas.h"



lambdas::lambdas()
{
}

lambdas::~lambdas()
{
}

void lambdas::Lambda01()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	for_each(begin(v), end(v)
		, []
		(int x)
	{
		cout << x << endl;
	});
}

void lambdas::Lambda02()
{
	auto x = [](int i) {return i>6; };
}
