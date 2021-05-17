#include <string>
using namespace std;
#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <cstdlib>
#include <fstream>

#include "ReportGenerator.h"
#include "Record.h"

vector<Record*> ReportGenerator::primaryRec;
Map<int> ReportGenerator::yearMap;
Map<string> ReportGenerator::regionMap;
Map<string> ReportGenerator::animalMap;


ReportGenerator::~ReportGenerator()
{
	//cout << "in report generator dtor" << endl;
}
void ReportGenerator::initialize()
{
	int yrr, farmNum, numAnimals;
	string reg, subReg, animalType; 

	ifstream infile("farms.dat", ios::in);
	if (!infile) {
		cout << "Error: could not open file" << endl;
		exit(1);
	}
	
	while(infile >> yrr >> reg >> subReg >> animalType >> farmNum >> numAnimals)
	{
		primaryRec.push_back(new Record(yrr, reg, subReg, animalType, farmNum,numAnimals));
	} 
	
	for(int i = 0; i < primaryRec.size(); i++)
	{
		yearMap.add(primaryRec[i]->getYear(), primaryRec[i]);
		regionMap.add(primaryRec[i]->getRegion(), primaryRec[i]);
		animalMap.add(primaryRec[i]->getAnimal(), primaryRec[i]);
	}	
}


void ReportGenerator::cleanup()
{
	for(int i = 0; i < primaryRec.size(); i++)
	{
		delete primaryRec[i];
	}
}






