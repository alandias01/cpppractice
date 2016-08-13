#pragma once
#include<iostream>
#include<string>

using namespace std;

class resource
{
public:
	string handle;

	resource(void)
	{
		cout<<"Resource constructor run no handle"<<endl;
	}
	resource(string h):handle(h)
	{
		cout<<"Resource constructor run "<<handle<<endl;
	}
	~resource(void)
	{
		cout<<"Resource destructor run "<<handle<<endl;
	}

	void showHandle()
	{
		cout<<"Handle: "<<handle<<endl;
	}
	
	
};

