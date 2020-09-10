#include "numlist.h"
#include <iostream>
#include <fstream>
#include <ostream>
using namespace std;

int main()
{
  ifstream ifs;
  NumList nums;
  string file;
  int temp;

  //GET FILE NAME
  cout << "ENTER NAME OF FILE:: "<<endl;
  cin >> file;

  //READ FROM FILE
  ifs.open(file.c_str());
  nums.load_from_file(ifs);
  ifs.close();
  nums.see_all();

  //ADDS 3 NUMBERS TO LIST "nums"
  cout << "Enter three numbers to add to the list "<<endl;
  cin >> temp;
  nums.insert(temp);
  cin >> temp;
  nums.insert(temp);
  cin >> temp;
  nums.insert(temp);

  //SORT AND OUTPUT NUMBERS
  nums.b_sort();
  nums.see_all();
  nums.b_sort();

  //SAVE SORTED LIST TO NEW FILE
  int locate = file.find(".");
  file.insert(locate, "sorted");
  ofstream ofs(file.c_str());
  nums.save_to_file(ofs);
  ofs.close();
  return (0);
}
