#include "Assignment5.cpp"
#include <iostream>
#include <vector>

using namespace std;

int main (int argc, char **argv)
{
  string fileName = "facultyTable.txt";
  string fileName2 = "studentTable.txt";
  Runner toRun;


  toRun.Run(fileName, fileName2);

  return 0;
}
