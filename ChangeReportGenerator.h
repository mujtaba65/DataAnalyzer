#ifndef CHANGEREPORTGENERATOR_H
#define CHANGEREPORTGENERATOR_H

#include <string>
using namespace std;
#include <vector>
#include <iostream>

#include "ReportGenerator.h"
#include "ReportData.h"

/*
This a concrete report generator class, derived from report generator base class, this is the second report which implements the compute from base class, it takes year map and computes the data accordingly. It calculates the difference in each type of animal between 2011 and 2016. The format data uses stringstream to make a string to represent the information and then it is added into the report data and it has a printReport() function to print the whole report.

*/


class ChangeReportGenerator : public ReportGenerator
{
	public:
		ChangeReportGenerator();
		~ChangeReportGenerator();
		virtual void compute();
		
		void formatData(int, int, float, string);
		void printReport();
	
	private:
		AscBehaviour<float>* ab;
		ReportData<float>* repoAnimalData;

};
#endif
