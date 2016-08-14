#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include "resource.h"
#include "person.h"
#include<memory>


#include "PersonBasic.h"

using namespace std;

class PointersAndRef
{
public:
	
	PointersAndRef()
	{
		ModernPointerPrac();
		
	}

	/*
	When you set pointer to nullptr,  You can run delete on it as many times as you want
	What delete does is say, if this is nullptr, just ignore it, else deallocate memory
	If you delete momory that has already been cleaned up, you get unexpected behavior, error
	Thats why its useful to set a pointer to nullptr after you delete it so that if you accidently 
	try to delete it again, you won't get unexpected behavior
	Just remember, setting a pointer to nullptr doesn't free the memory your pointer points to
	If you do this  int* p=new int; p=nullptr;  You have a memory leak since p is not pointing to the 
	memory location anymore.  Delete the pointer first and then set it to nullptr
	*/

	/*
	Why use pointers with new (dynamic allocation) vs standard object creation on the stack?
	It outlives the scope, which are the curly braces.  You may not want it to end after the function ends
	You may easily fill the memory allocated to the stack.  Dynamic memory is on the heap 
	*/


	void PassingPointersAndRefs()
	{
		PersonBasic p1("Alan");		

		PassingPointersAndRefs_RefParam(p1);
		cout<<p1.Name<<endl;
		
		PassingPointersAndRefs_PointerParam(&p1);
		cout<<p1.Name<<endl;
	}

	void PassingPointersAndRefs_RefParam(PersonBasic& p)
	{
		p.Name="RefParam";
	}
	
	void PassingPointersAndRefs_PointerParam(PersonBasic* p)
	{
		p->Name="PointerParam";
	}

	void LegacyPointerPrac()
	{
		//Local objects(not pointers) have destructor run when the object goes out of scope
		//Objects go out of scope when they reach the curly brace
		resource r("local");	
		resource* pr=&r;
		pr->handle="local1";
		pr->showHandle();
		r.showHandle();	
	}

	//Dangling pointer is when you are pointing to a memory location that has already benn cleaned up
	void LegacyPointerPracAvoidDanglingPointer()
	{
		//  This creates a dangling pointer p2
	
		//int* p=new int;		//Allocated area in memory
		//int* p2=p;			//p2 points to the new area
		//*p2=5;
		//
		//cout<<*p<<endl;
		//cout<<*p2<<endl;

		//delete p;			//Deallocate the memory.  Now p points to nothing. p and p2 still point to that area! p and p2 are DANLGING!
		//p=nullptr;			//You remove the address and now it points to nowhere.  Doesn't really dangle anymore
		//

		////delete p2;			//FYI.  If you do this, CRASH!.  You are deallocating memory that has already been freed. Set p2=nullptr so crash won't happen
		//
		//
		//cout<<p<<endl;	//00000000
		//cout<<p2<<endl;	//002A7A70
		

		int* p=nullptr;
		p=new int;

		if(p!=nullptr)		//Test it first
		{
			*p=10;			//then assign it
			cout<<*p<<endl;
			delete p;		//Free memory
			p=nullptr;		//Set to nullptr to be testable again
		}
	}

	//showing a memory leak and how to fix
	void LegacyPointerPracMemoryLeaks()
	{
		//when you want an object to live longer than its scope
		resource* pr=new resource("pointer");
	
		delete pr;
		/*
		resource* pr2=pr;
		delete pr;
		pr=nullptr;
		delete pr;
		delete pr;
		*/
	}

	void LegacyPointerInsideAnotherClassPrac()
	{
		person p("local");
		p.AddResource();
	
		//Shallow vs deep copies
		//Shallow copy will copy all fields over to new object.  If you don't have pointers, its fine
		//If you do, the pointer gets copied over and now both objects have a pointer that points to the same memory location
		//New memory doesn't get allocated for the new object like you may think
		//What happens is when the destructor for the first object gets run, it deallocated the memory for the resource pointer
		//When the destructor for the second object gets run, it tries to deallocate that memory thats already been freed.  CRASH!
	
		person p2=p;	//This calls copy constructor.  If you don't have one, default one gets generated.  CRASH!	You will have to create copy constructor for DEEP COPY!	
		//person p2;
		//p2=p;			//This is assignment operator.	CRASH!  You will have to overload the = operator
	}

	void ModernPointerPrac()
	{
		//Note the many different ways to init a shared_ptr
		
		//Preferred way
		auto p1 = make_shared<PersonBasic>("alan1");
		
		//Less efficient
		shared_ptr<PersonBasic> p2(new PersonBasic("alan2"));

		// When initialization must be separate from declaration, e.g. class members,  
		// initialize with nullptr to make your programming intent explicit.
		shared_ptr<PersonBasic> p3(nullptr);
		p3 = make_shared<PersonBasic>("alan3");

		vector<shared_ptr<PersonBasic>> v1;
		v1.push_back(p1);
		v1.push_back(make_shared<PersonBasic>("Alan04"));
		
	}

	

	void VectorOfSmartPointers()
	{
		//PBVector.push_back(shared_ptr<PersonBasic>("d"));
	}


private:

};