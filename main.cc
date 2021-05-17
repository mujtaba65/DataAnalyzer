#include <iostream>
using namespace std;
#include <string>

#include "ReportData.h"
#include "Record.h"
#include "Map.h"
#include "ReportGenerator.h"
#include "ReportGeneratorSubRegion.h"
#include "ChangeReportGenerator.h"
#include "FarmReportGenerator.h"

#include  "Control.h"

#include "CompareBehaviour.h"
#include "ReportGenerator.h"


/*

The purpose of this program is to generate a set of reports based on the data from Statistics Canada other livestock data. The census in farm.dat represent data for years 2011 and 2016. The data includes multiple things, and to get this data, we use Record class and Map class to store the data after reading them from the file through file operators. The format of data is as follows: year region subRegion animalType numFarms numAnimals. The 3 derived report generator classes read the data according to set the criteria and calls the format data to store this data in rows using Report Row and the order is is defined as well, orders include ascending and descending comparsion this is implemented through the help of CompareBehaviour.


*/

int main()
{
	Control c;
	c.launch();
   	return 0;
}
