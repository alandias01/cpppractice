
#include "filedir.h"
#include "pointers\PointersAndRef.h"
#include "lambdas.h"

#include "basics02.h"
#include "polymorphism.h"
#include "algorithms01.h"


void passme(int x)
{
	cout << x << endl;
}

int main(int argc, TCHAR *argv[])
{
	cout << "Hello" << endl;
	//filedir fd;	fd.showFilesInDir();

	algorithms01 a;	
	a.fp01(passme);
	a.fp01([](int x) {cout << x << endl; });


	

	
};