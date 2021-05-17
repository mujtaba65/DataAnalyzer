#ifndef CONTROL_H
#define CONTROL_H

#include <string>
using namespace std;
#include <vector>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <algorithm>
#include <cstdlib>
#include <sstream>
#include <fstream>

#include "Record.h"
#include "Map.h"
#include "ReportGenerator.h"
#include "ReportData.h"
#include "ReportGeneratorSubRegion.h"
#include "ChangeReportGenerator.h"
#include "FarmReportGenerator.h"
#include "View.h"


class Control
{
  public:
  	void launch();
  	Control();
  	~Control();
 	
		
  private:

	vector<ReportGenerator*> vect;
	ReportGeneratorSubRegion* sg; 
	FarmReportGenerator* fd;
	ChangeReportGenerator* rx;
	View v;
	
	
};

#endif
