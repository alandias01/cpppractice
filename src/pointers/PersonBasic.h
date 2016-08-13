#pragma once
#include<iostream>
#include<string>
#include "resource.h"
#include "person.h"

using namespace std;

class PersonBasic
{
public:
	string Name;

	PersonBasic(string n):Name(n)
	{
		cout<<"person constructor run for "<<Name<<endl;
	}
	~PersonBasic(void)
	{
		cout<<"person destructor run for "<<Name<<endl;		
	}
};