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

#include "ChangeReportGenerator.h"

ChangeReportGenerator::ChangeReportGenerator()
{
	ab = new AscBehaviour<float>();
	repoAnimalData= new ReportData<float>(ab);
}

ChangeReportGenerator::~ChangeReportGenerator()
{
	delete repoAnimalData;
}

void ChangeReportGenerator::compute()
{
	
	int totalOld = 0;
	int totalNew = 0;
	
	vector<Record*> tempRec;
	
	for(int i = 0; i < yearMap[2011].size(); i++)
	{
		if(yearMap[2011][i]->getRegion() == "CAN")
		{
			totalOld += yearMap[2011][i]->getNumAnimals();
			tempRec.push_back(yearMap[2011][i]);
		}
	}
	
	for(int x = 0; x < yearMap[2016].size(); x++)
	{
		if(yearMap[2016][x]->getRegion() == "CAN")
		{
			totalNew += yearMap[2016][x]->getNumAnimals();
			tempRec.push_back(yearMap[2016][x]);
		}
	}
	
	bool test = false;
	for(int y = 0; y < tempRec.size(); y++)
	{
		
		test = false;
		if(tempRec[y]->getYear() == 2016)
			break;
		for(int z = y; z < tempRec.size(); z++)
		{
			
			if(tempRec[y]->getYear() == tempRec[z]->getYear())
				continue;
			if(tempRec[y]->getAnimal() == tempRec[z]->getAnimal())
			{
				
				string animal = tempRec[y]->getAnimal();
				int oldAnimals = tempRec[y]->getNumAnimals();
				int newAnimals = tempRec[z]->getNumAnimals();
				
				float gg = (oldAnimals/(float)totalOld) * 100;
				float aa = (newAnimals/(float)totalNew) * 100; 
				float difference = aa - gg;
				
				formatData(oldAnimals, newAnimals, difference, animal);
				
				test = true;
				continue;
			}	
		}	
		if(test == false)
		{
			string animal = tempRec[y]->getAnimal();
			int oldAnimals = tempRec[y]->getNumAnimals();
			int newAnimals = 0;
			float gg = (oldAnimals/(float)totalOld) * 100;
			float aa = 0.0f;
			float difference = aa - gg;
			formatData(oldAnimals, newAnimals, difference, animal);
		}
	}
}



void ChangeReportGenerator::formatData(int oldVal, int newVal, float diff, string ani)
{
	stringstream g;
	g << setfill(' ') << setw(15) <<left << ani << setfill(' ') << setw(7) << left << oldVal << setfill(' ') << setw(7) << left << newVal << setprecision(1) << fixed <<setw(4) << diff;   
	string changePercentage = g.str();
	repoAnimalData->add(diff, changePercentage);
}


void ChangeReportGenerator::printReport()
{
	cout << " PERCENTAGE CHANGE FROM 2011 to 2016 " << endl;
	cout << *repoAnimalData;


	ofstream outfile("ChangeGeneratorSubRegion.txt", ios::out);

	if (!outfile) {
		cout << "Error file couldn't be open" << endl;
		exit(1);
	}
	outfile << " PERCENTAGE CHANGE FROM 2011 to 2016 " << endl;
	outfile << "============================================================================" <<endl;
	outfile << *repoAnimalData;
	
	repoAnimalData->cleanRepo();

}





