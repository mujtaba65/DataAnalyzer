#include <iostream>
using namespace std;
#include <string>

#include "Control.h"


Control::Control()
{
	sg = new ReportGeneratorSubRegion();
	fd = new FarmReportGenerator();
	rx = new ChangeReportGenerator();
	vect.push_back(sg);
	vect.push_back(rx);
	vect.push_back(fd);
}


Control::~Control()
{
	for( int i = 0; i < vect.size(); i++)
	{
		delete vect[i];
	}
	ReportGenerator::cleanup();
}

void Control::launch()
{

	ReportGenerator::initialize();
	int choice;
	bool x = true;
	while(x)
	{
		v.showMenu(choice);
		if(choice==0){
			x = false;
		}
		else if(choice == 1)
		{
			fd->compute();
			fd->printReport();
		}
		else if(choice == 2)
		{
			rx->compute();
			rx->printReport();
		}
		else if(choice == 3)
		{
			sg->compute();
			sg->printReport();
		}
	}	
}




