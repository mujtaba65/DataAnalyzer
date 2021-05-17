#ifndef RECORD_H
#define RECORD_H

#include <string>
using namespace std;
/*
The purpose of this class is to represent each record in farms.dat, each record has year, region, subregion, animal type, farm number and number of of animals. This has couple of getter functions to return the data members mentioned above.

*/

//open 3.6 
class Record
{
	friend ostream& operator<<(ostream&, Record&);
	public:
		Record(int = 0, string = "", string = " ", string = " ", int = 0 ,int = 0);
		int getYear();
		string getRegion();
		string getSubRegion();
		string getAnimal();
		int getFarmNumber();
		int getNumAnimals();
		
	private:
		int year;
		string region;
		string subRegion;
		string animal;
		int farmNumber;
		int numAnimals;	

};
#endif
