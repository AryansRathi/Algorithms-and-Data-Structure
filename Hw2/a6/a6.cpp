#include <fstream>
#include <iostream>
#include <map>
using namespace std;
int main()
{
  map<string, string> birthday;

  ifstream myfile;
  myfile.open("data.txt", ios::in);
  if (!myfile)
  {
    cout << "Error" << endl;
  }

  string name;
  string birth;
  while (!myfile.eof())
  {
    getline(myfile, name);
    getline(myfile, birth);
    birthday.insert(pair<string, string>(name, birth));
  }
  map<string, string>::iterator itr;

  for (itr = birthday.begin(); itr != birthday.end(); itr++)
  {
    cout << itr->first << " " << itr->second << endl;
  }

  string newname;
  cout << "Enter name" << endl;
  getline(cin, newname);

  if (birthday.find(newname) == birthday.end())
  {
    cout << "Name not found!" << endl;
  }
  else
  {
    cout << "Name found" << endl;
    cout << birthday.find(newname)->second;
  }

  return 0;
}
