#include <iostream>
#include "Package.h"

using std::cout; using std::endl;

int main()
{
	Package package1("Lou Brown", "Boston","Mary Smith", "New York", 8.5, .5 );
	TwoDayPackage package2("Lisa Klein", "Somerville",
			"Bob George", "Cambridge", 10.5, .65, 2.0 );
	OvernightPackage package3("E Lewis", "Boston", "Don Kelly", "Denver",
		12.25, .7, .25 );
	package1.print();
	cout<< "\n\n";
	package2.print();
	cout<< "\n\n";
	package3.print();
	cout<< "\n\n";
	return 0;
}
