#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Record.h"

Record::Record(int yr, string rg, string subrg, string a,int f,int numAni)
{
	year = yr;
	region = rg;
	subRegion = subrg;
	animal = a;
	farmNumber = f;
	numAnimals = numAni;	
}

int Record::getYear()
{
	return year;
}


string Record::getSubRegion()
{
	return subRegion;
}
string Record::getAnimal()
{
	return animal;
}

int Record::getFarmNumber()
{
	return farmNumber;
}

int Record::getNumAnimals()
{
	return numAnimals;
}


string Record::getRegion()
{
	return region;
}
		
ostream& operator<<(ostream& output, Record& r)
{
  output<<setfill('0')<<setw(4)<< r.year<<" : "
      <<setfill(' ')<<setw(2)<< r.region<<" : "
      <<setfill(' ')<<setw(15)<< right << r.subRegion<<" : "
      <<setfill(' ')<<setw(15)<< right << r.animal<<" : " 
      <<setfill('0')<<setw(2)<< r.farmNumber<<" : " 
      <<setfill('0')<<setw(2)<< r.numAnimals;

  return output;
}		
		

