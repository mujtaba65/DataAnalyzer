#ifndef REPORTGENERATOR_H
#define REPORTGENERATOR_H

#include <string>
using namespace std;
#include <vector>
#include <iostream>

#include "Record.h"
#include "Map.h"
#include "ReportData.h"
#include "CompareBehaviour.h"

/*
This is an abstract class, and the purpose of this abstract class is to initialize the static maps and the vector of record pointers, through the help of initialize function. It has a virtual destructor and a virtual compute function so that the derived classes can implement their own behaviour. This also has a cleanup function which clears the memory by freeing the primary records vector.
*/


class ReportGenerator
{
	public:
		static void initialize();
		static void cleanup();
		virtual ~ReportGenerator();
		virtual void compute() = 0;
	
	protected:
		static vector<Record*> primaryRec;
		static Map<int> yearMap;
		static Map<string> regionMap;
		static Map<string> animalMap;
		
		
};
#endif
