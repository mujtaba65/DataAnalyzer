#ifndef REPORTGENERATORSUBREGION_H
#define REPORTGENERATORSUBREGION_H

#include <string>
using namespace std;
#include <vector>
#include <iostream>

#include "ReportGenerator.h"
#include "ReportData.h"

/*
This a concrete report generator class, derived from report generator base class, this is third report which computes the data by sub region and uses it to find the horse-ponies the maximum number of horses in each sub region of each province. The format data uses stringstream to make a string to represent the information and then it is added into the report data and it has a printReport() function to print the whole report.

*/


class ReportGeneratorSubRegion : public ReportGenerator
{
	public:
		ReportGeneratorSubRegion();
		virtual ~ReportGeneratorSubRegion();
		virtual void compute();
		
		void formatData(int, string, string);
		void printReport();
	
	private:
		DescBehaviour<int>* db;
		ReportData<int>* repoData;
};

#endif
