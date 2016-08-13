#pragma once
#include<iostream>
#include<string>

using namespace std;
//
class person
{
public:
	string handle;
	resource* pResource;

	person(void)
	{
		cout<<"person constructor run no handle"<<endl;
	}

	person(string h) : handle(h), pResource(nullptr)
	{
		cout<<"person constructor run "<<handle<<endl;
	}


	person(const person& p) : handle(p.handle), pResource(new resource(p.pResource->handle))
	{}

	~person(void)
	{
		cout<<"person destructor run "<<handle<<endl;
		delete pResource;
	}

	
	void showHandle()
	{
		cout<<"Handle: "<<handle<<endl;
	}
	
	void AddResource()
	{
		delete pResource;
		pResource=new resource("pointer for "+handle);
	}

	
	
};