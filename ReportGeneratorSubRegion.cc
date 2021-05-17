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

#include "ReportGeneratorSubRegion.h"

ReportGeneratorSubRegion::ReportGeneratorSubRegion()
{
	db = new DescBehaviour<int>();
	repoData= new ReportData<int>(db);

}

ReportGeneratorSubRegion::~ReportGeneratorSubRegion()
{
	delete repoData;
}

void ReportGeneratorSubRegion::compute()
{

	int max = 0;
	int curNum = 0;
	string region = "";
	string subRegion = "";
	string prevSubRegion = "";
	for(int i = 0; i < regionMap.getNumKeys(); i++)
	{
		max = 0;
		curNum = 0;
		region = "";
		subRegion = "";
		prevSubRegion = "";
		
		if(regionMap.getKey()[i] == "CAN")
			continue;
		for(int x = 0; x < animalMap["Horses-Ponies"].size(); x++)
		{	
			
			if(animalMap["Horses-Ponies"][x]->getSubRegion() == "All" || animalMap["Horses-Ponies"][x]->getYear() == 2011)
			{
				continue;
			}
			if(animalMap["Horses-Ponies"][x]->getRegion() == regionMap.getKey()[i] && max <= animalMap["Horses-Ponies"][x]->getNumAnimals())
			{ 
				max = animalMap["Horses-Ponies"][x]->getNumAnimals();
				region = animalMap["Horses-Ponies"][x]->getRegion();
				subRegion = animalMap["Horses-Ponies"][x]->getSubRegion();
				continue;
			}
		}
		if(max == 0)
		{
			region = regionMap.getKey()[i];
		}
		
		formatData(max, region, subRegion);
	
	}
}


void ReportGeneratorSubRegion::formatData(int maxi, string reg, string sub)
{
	stringstream x;
	x<<reg << "   " << setfill(' ') << setw(30) <<left << sub << "   " <<setfill(' ') << setw(30) <<left  << maxi;
	string y = x.str();
	repoData->add(maxi, y);
}



void ReportGeneratorSubRegion::printReport()
{
	cout << "SUB-REGIONS WITH THE MOST HORSES/PONIES BY SUBREGION" << endl;
	cout << *repoData;	
	
	ofstream outfile("ReportGeneratorSubRegion.txt", ios::out);

	if (!outfile) {
		cout << "Error file couldn't be open" << endl;
		exit(1);
	}
	outfile <<  "SUB-REGIONS WITH THE MOST HORSES/PONIES BY SUBREGION" << endl;
	outfile << "============================================================================" <<endl;
	outfile << *repoData;
	outfile<< endl;

	repoData->cleanRepo();

}










