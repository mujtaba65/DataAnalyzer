#ifndef MAP_H
#define MAP_H


#include <iostream>
using namespace std;
#include <vector>

#include "Record.h"

/*
This class is a Template class. The purpose of this template class is to represent a map which takes the key as a parameter of type T, to add flexibility. The key stores the corresponding vector record as pointers. The keys are stored in a vector, however the values are stored in a vector of vector of record pointers. The keys and values are stored in such a manner that they represent a parallel array structure. It has an add function to add keys and values in it. It also uses subscript overloaded operator to return the record. 

*/


template <class T>
class Map
{
  public:
	vector<T>& getKey();
	vector<Record*>& operator[](T);
	void add(T, Record*);
	int getNumKeys();
	
	
  private:
  	vector<T> key;
  	vector<vector<Record*>> value;

};



template <class T>
void Map<T>::add(T k, Record* rec)
{

		if(key.size() == 0)
		{
			key.push_back(k);
			vector<Record*> tempRec; //to initialize new vectors where values can be added in 
			tempRec.push_back(rec);
			value.push_back(tempRec);
			return;
		}
		for(int i = 0; i < key.size(); i++)
		{
			if(key[i] == k)
			{			
				value[i].push_back(rec);
				return;
			}	
		}
		key.push_back(k);
		vector<Record*> tempRec; //to initialize new vectors where values can be added in 
		tempRec.push_back(rec);
		value.push_back(tempRec);
		return;
}

template <class T>
int Map<T>::getNumKeys()
{
	return key.size();
}

template <class T>
vector<T>& Map<T>::getKey()
{
	return key;
}

template <class T>
vector<Record*>& Map<T>::operator[](T k)
{
	try
	{
		for(int i = 0; i < key.size(); i++)
		{
	 
		  	if(key[i] == k)
		  	{
		  		return value[i];
		  	}
		}
		throw "Error not possible";
	}		
	catch(const char* x) 
	{
		throw(x);
	}
}

#endif



