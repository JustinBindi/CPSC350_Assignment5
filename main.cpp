#include "Assignment5.cpp"
#include <iostream>
#include <vector>

using namespace std;

int main (int argc, char **argv)
{
  Runner toRun;
  bool looping = true;
  string input;

  while (looping)
  {
    cout << "" << endl;
    cout << "1. Print all students and their information (sorted by ascending id #)." << endl;
    cout << "2. Print all faculty and their information (sorted by ascending id #)." << endl;
    cout << "3. Find and display student information given the students id." << endl;
    cout << "4. Find and display faculty information given the faculty id." << endl;
    cout << "5. Given a student’s id, print the name and info of their faculty advisor." << endl;
    cout << "6. Given a faculty id, print ALL the names and info of his/her advisees." << endl;
    cout << "7. Add a new student." << endl;
    cout << "8. Delete a student given the id." << endl;
    cout << "9. Add a new faculty member." << endl;
    cout << "10. Delete a faculty member given the id." << endl;
    cout << "11. Change a student’s advisor given the student id and the new faculty id." << endl;
    cout << "12. Remove an advisee from a faculty member given the ids." << endl;
    cout << "13. Rollback" << endl;
    cout << "14. Exit" << endl;
    cout << "" << endl;
    cout << "Please enter the number option that you would like to run." << endl;

    getline(cin,input);

    if (input == "1")
    {
      toRun.Run(1);
    }
    else if (input == "2")
    {
      toRun.Run(2);
    }
    else if (input == "3")
    {
      toRun.Run(3);
    }
    else if (input == "4")
    {
      toRun.Run(4);
    }
    else if (input == "5")
    {
      toRun.Run(5);
    }
    else if (input == "6")
    {
      toRun.Run(6);
    }
    else if (input == "7")
    {
      toRun.Run(7);
    }
    else if (input == "8")
    {
      toRun.Run(8);
    }
    else if (input == "9")
    {
      toRun.Run(9);
    }
    else if (input == "10")
    {
      toRun.Run(10);
    }
    else if (input == "11")
    {
      toRun.Run(11);
    }
    else if (input == "12")
    {
      toRun.Run(12);
    }
    else if (input == "13")
    {
      toRun.Run(13);
    }
    else if (input == "14")
    {
      looping = false;
    }
    else
    {
      cout << "" << endl;
      cout << "That is an invalid input." << endl;
    }
  }
  return 0;
}
