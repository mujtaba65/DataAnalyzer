#ifndef FARMREPORTGENERATOR_H
#define FARMREPORTGENERATOR_H

#include <string>
using namespace std;
#include <vector>
#include <iostream>

#include "ReportGenerator.h"
#include "ReportData.h"

/*
his a concrete report generator class, derived from report generator base class, this class also implements the compute function from base class, however this a bit long and tedious, so first it computes the total for each animal in all provinces covered, then it computes the total number of farms in each province and the total number of farms in all the provinces combined. It then computes the ratio for each number of farm. The format data takes a vector of, ratios region wise. The format data uses stringstream to make a string to represent the information and then it is added into the report data and it has a printReport() function to print the whole report.
*/


class FarmReportGenerator : public ReportGenerator
{
	public:
		FarmReportGenerator();
		virtual ~FarmReportGenerator();
		virtual void compute();
		
		void formatData(vector<float>& , string);
		void printReport();	
	
	
	private:
		DescBehaviour<float>* ax;
		ReportData<float>* repoFarmData;



};
#endif
