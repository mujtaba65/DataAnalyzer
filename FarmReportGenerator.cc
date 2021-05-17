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

#include "FarmReportGenerator.h"
#include "Map.h"

FarmReportGenerator::FarmReportGenerator()
{
	ax = new DescBehaviour<float>();
	repoFarmData= new ReportData<float>(ax);
}

FarmReportGenerator::~FarmReportGenerator()
{
	delete repoFarmData;
}

void FarmReportGenerator::compute()
{
	vector<string> animals;
	int counter = 0;
	vector<int> totalCounter;
	for(int i = 0; i < animalMap.getNumKeys(); i++) // these set of for loops find the animals, and iterates over each animal to calulcate their total.
	{
		counter = 0;
		animals.push_back(animalMap.getKey()[i]);
		for(int m = 0; m < animalMap[animalMap.getKey()[i]].size(); m++)
		{	
			if(animalMap[animalMap.getKey()[i]][m]->getYear() == 2011 || animalMap[animalMap.getKey()[i]][m]->getSubRegion()!= "All" || animalMap[animalMap.getKey()[i]][m]->getRegion() == "CAN")
				continue;
			counter += animalMap[animalMap.getKey()[i]][m]->getFarmNumber();	
		}
		totalCounter.push_back(counter);
	}

	vector<int> numFarms; // by regionwise
	int totalNumFarms = 0;
	int totalFarmNumbers = 0;
	for(int y = 0; y < regionMap.getNumKeys(); y++)//these set of for loops calculate the total number of farms region wise.
	{
		totalNumFarms = 0;
		if(regionMap.getKey()[y] == "CAN")
		{
			continue;
		}
		for(int j = 0; j < regionMap[regionMap.getKey()[y]].size(); j++)
		{	
			if(regionMap[regionMap.getKey()[y]][j]->getYear() == 2011 || regionMap[regionMap.getKey()[y]][j]->getSubRegion() != "All" )
			{
				continue;
			}
			for(int b = 0; b < animals.size(); b++)
			{
				if(regionMap[regionMap.getKey()[y]][j]->getAnimal() == animals[b])
				{
					totalNumFarms += regionMap[regionMap.getKey()[y]][j]->getFarmNumber();				
					break;
				}
			}	
		}
		numFarms.push_back(totalNumFarms);
		totalFarmNumbers += totalNumFarms;
	}

	vector<float> remainders;
	int tempTotal = 0;
	for(int y = 0; y < regionMap.getNumKeys(); y++) //these set of for loops calculates the ratios.
	{
		tempTotal = 0;
		vector<float> remainders;
		if(regionMap.getKey()[y] == "CAN")
		{
			continue;
		}
		for(int j = 0; j < regionMap[regionMap.getKey()[y]].size(); j++)
		{	
			if(regionMap[regionMap.getKey()[y]][j]->getYear() == 2011 || regionMap[regionMap.getKey()[y]][j]->getSubRegion() != "All" )
				continue;
			for(int b = 0; b < animals.size(); b++)
			{
				if(regionMap[regionMap.getKey()[y]][j]->getAnimal() == animals[b])
				{
					tempTotal += regionMap[regionMap.getKey()[y]][j]->getFarmNumber();
					float ratio = ((regionMap[regionMap.getKey()[y]][j]->getFarmNumber())/(float) totalCounter[b]) * 100;
					remainders.push_back(ratio);
					break;
				}
			}	
		}
		float finalRatio = (tempTotal/(float) totalFarmNumbers) * 100;
		remainders.push_back(finalRatio);
		string regionName = regionMap.getKey()[y];
		formatData(remainders, regionName);
	}		
}



void FarmReportGenerator::formatData(vector<float>& outcome,string ss)
{

	stringstream output;
	output << ss ;
	for(int i = 0; i < outcome.size(); i++)
	{	
		output << setfill(' ') << setw(10) << setprecision(1) << fixed  <<outcome[i] ;
	}
	string farmRow = output.str();
	float key = outcome[outcome.size() - 1]; 
	repoFarmData->add(key, farmRow);
}



void FarmReportGenerator::printReport()
{
	cout << " Percentage of farms by region in 2016 " << endl;
	cout << setfill(' ') << setw(14) << "Horses" << setfill(' ') << setw(10) << "Goats" << setfill(' ') << setw(10) << "Llamas" << setfill(' ') << setw(10) << "Rabbits" << setfill(' ') << setw(10) << "Bison" << setfill(' ') << setw(10) << "Elk" << setfill(' ') << setw(10)  << "Deer" << setfill(' ') << setw(10) << "Mink" << setfill(' ') << setw(10) << "Totals" << endl;
	cout << *repoFarmData;
	
	ofstream outfile("FarmerGeneratorSubRegion.txt", ios::out);

	if (!outfile) {
		cout << "Error file couldn't be open" << endl;
		exit(1);
	}
	outfile << " PERCENTAGE CHANGE FROM 2011 to 2016 " << endl;
	outfile << "============================================================================" <<endl;
	outfile << *repoFarmData;

	repoFarmData->cleanRepo();
}

