#include <iostream>
using namespace std;
#include <string>

#include "View.h"

void View::showMenu(int& choice)
{
  int numOptions = 3;

  cout << endl << endl;
  cout << "What would you like to do:"<< endl;
  cout << "  (1) Percentage Distribution of farms by provivnce for year 2016" << endl;
  cout << "  (2) Percentage Change of Animals, by province for years 2011 and 2016" << endl;
  cout << "  (3) Sub-region with the highest number of horses by province for year 2016" << endl;
  cout << "  (0) Exit" << endl<<endl;

  cout << "Enter your selection: ";
  cin >> choice;

  while (choice < 0 || choice > numOptions) {
    cout << "Enter your selection: ";
    cin >> choice;
  }

}

void View::printStr(string str)
{
  cout << str;
}

void View::readInt(int& n)
{
  cin >> n;
}

void View::readStr(string& str)
{
  cin >> str;
}



