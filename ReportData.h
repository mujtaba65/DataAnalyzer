#ifndef REPORTDATA_H
#define REPORTDATA_H

#include <iostream>
using namespace std;
#include <cstdlib>
#include <string>
#include <vector>
#include "CompareBehaviour.h"

/*

This is a template class. The purpose of this template class is to store a vector of Report Row objects, report row is nested inside report data, and each row has a key and a row, to represent the data. It also has-a composition relation with compareBehaviour, so that each row's key can be compared while adding and the order is either ascending or descending. It also has a stream insertion operator to print out the each row.

*/


template <class T>
class ReportData
{
	template <class V>
	friend ostream& operator<<(ostream&, ReportData<V>&);
	
	private:
		template <class V>
		class ReportRow
		{
			public:
				ReportRow(V t, string detail)
				{
					key = t;
					row = detail;
				}
				V key;
				string row;
				
		};
		vector<ReportRow<T>> reportObjs;
		CompareBehaviour<T>* compareB;
	
	public:
		ReportData(CompareBehaviour<T>*);
		~ReportData();
		void add(T, string);
		void cleanRepo();


};

template <class T>
ReportData<T>::ReportData(CompareBehaviour<T>* cp)
{
	compareB = cp;	
}

template <class T>
ReportData<T>::~ReportData()
{
	delete compareB;
}

template <class T>
void ReportData<T>::add(T k, string row)
{
	typename vector<ReportRow<T>>::iterator itr;
	if(reportObjs.size() == 0)
	{
		
		ReportRow<T> rr(k, row);
		reportObjs.push_back(rr);
		return;
	}
	for (itr = reportObjs.begin(); itr != reportObjs.end(); ++itr)
	{
		bool cp = compareB->compare(itr->key, k);
		if(cp == true)
		{
			ReportRow<T> rw(k, row);
			reportObjs.insert(itr, rw);
			return;
		}

	}
	ReportRow<T> re(k, row);
	reportObjs.push_back(re);
	return;
}

template <class T>
void  ReportData<T>::cleanRepo()
{
	reportObjs.clear();
}

template <class T>
ostream& operator<<(ostream& output, ReportData<T>& rd)
{
	for (int i = 0; i < rd.reportObjs.size(); ++i)
	{
		output<< rd.reportObjs[i].row << endl;
	}    
	return output;
}



#endif
