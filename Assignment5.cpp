#include <iostream>
#include <typeinfo>
#include <fstream>
#include "Assignment5.h"

using namespace std;

//////implement it//////
TreeNode::TreeNode()
{
  left = NULL;
  right = NULL;
}

TreeNode::TreeNode(int k)
{
  left = NULL;
  right = NULL;
  key = k;
}

TreeNode::~TreeNode()
{}

/////////////////////////////////////////////////////////
//////implement this Tree//////
template <class T>
BST<T>::BST() //default constructor
{
  root = NULL; //empty tree
}

template <class T>
BST<T>::~BST() //default constructor
{}

template <class T>
vector<int> BST<T>::printTree()
{
  recPrint(root);
  return printingVector;
}

template <class T>
void BST<T>::recPrint(TreeNode *node)
{
  if (node == NULL)
  {
    return;
  }
   recPrint(node->left);
   printingVector.push_back(node->key);
   recPrint(node->right);
}

template <class T>
bool BST<T>::isEmpty()
{
  return (root == NULL);
}

template <class T>
void BST<T>::insertStudent(T object)
{
  //check if value exists, if not continue
  value = object.getStudentID();

  TreeNode *node = new TreeNode(value); //key is now set to value

  if (isEmpty()) //empty tree
  {
    root = node;
  }
  else //not an empty tree, need to find insertion point
  {
    TreeNode *current = root;
    TreeNode *parent; //empty node

    while (true)
    {
      parent = current;

      if (value < current->key)
      {
        current = current->left; //going left

        if (current == NULL) //found our insertion point
        {
          parent->left = node;
          break;
        }
      }
      else //go right
      {
        current = current->right;

        if (current == NULL)
        {
          parent->right = node;
          break;
        }
      }
    }
  }
}

template <class T>
void BST<T>::insertFaculty(T object)
{
  //check if value exists, if not continue
  value = object.getFacultyID();


  TreeNode *node = new TreeNode(value); //key is now set to value

  if (isEmpty()) //empty tree
  {
    root = node;
  }
  else //not an empty tree, need to find insertion point
  {
    TreeNode *current = root;
    TreeNode *parent; //empty node

    while (true)
    {
      parent = current;

      if (value < current->key)
      {
        current = current->left; //going left

        if (current == NULL) //found our insertion point
        {
          parent->left = node;
          break;
        }
      }
      else //go right
      {
        current = current->right;

        if (current == NULL)
        {
          parent->right = node;
          break;
        }
      }
    }
  }
}

template <class T>
bool BST<T>::contains(int value)
{
  if (isEmpty())
  {
    return false;
  }
  else //not an empty tree
  {
    TreeNode *current = root;

    while (current->key != value)
    {
      if (value < current->key) //go left
      {
        current = current->left;
      }
      else
      {
        current = current->right;
      }

      if (current == NULL) //did not find it
      {
        return false;
      }
    }
  }
  return true;
}

template <class T>
bool BST<T>::deleteR(int k)
{
  if(isEmpty())
  {
    return false;
  }

  //check if key/value exists before continuing to delete

  TreeNode *current = root;
  TreeNode *parent = root;
  bool isLeft = true;

  while (current->key != k) //let's look for our node
  {
    parent = current;

    if (k < current->key)
    {
      isLeft = true;
      current = current->left;
    }
    else //rightChild
    {
      isLeft = false;
      current = current->right;
    }

    if (current == NULL)
    {
      return false;
    }
  }

  //at this point, found the node
  //now lets check our cases

  if (current->left == NULL && current->right == NULL) //no children, is leaf node
  {
    if (current == root)
    {
      root = NULL;
    }
    else if (isLeft)
    {
      parent->left = NULL;
    }
    else //right child
    {
      parent->right = NULL;
    }
  }
  //check for nodes that have one child
  else if (current->right == NULL) //no right child, with left child
  {
    if (current == root)
    {
      root = current->left;
    }
    else if (isLeft)
    {
      parent->left = current->left;
    }
    else
    {
      parent->right = current->left;
    }
  }
  else if (current->left == NULL) //no left child, exact opposite of above
  {
    if (current == root)
    {
      root = current->right;
    }
    else if (isLeft)
    {
      parent->left = current->right;
    }
    else
    {
      parent->right = current->right;
    }
  }
  else //the node has two children
  {
    //find the successor of the node to be deleted, which in this case is current
    TreeNode *successor = getSuccessor(current);

    if (current == root)
    {
      root = successor;
    }
    else if (isLeft)
    {
      parent->left = successor;
    }
    else
    {
      parent->right = successor;
    }

    successor->left = current->left;
  }

  return true;
}

template <class T>
TreeNode* BST<T>::getSuccessor(TreeNode *d) //d is the node to be deleted
{
  TreeNode *sp = d; //sp = successor's parent
  TreeNode *successor = d;
  TreeNode *current = d->right; //going to find the smallest value bigger than current to replace current

  while (current != NULL)
  {
    sp = successor;
    successor = current;
    current = current->left;
  }

  if (successor != d->right)
  {
    sp->left = successor->right;
    successor->right = d->right;
  }

  return successor;
}

//////////////////////////////////////////////////////////////////

Student::Student()
{
  this->studentName = "";
  this->studentLevel = "";
  this->studentMajor = "";
  this->studentID = 0;
  this->studentAdvisor = 0;
  this->gpa = 0;
}

Student::Student(int studentID)
{
  this->studentName = "";
  this->studentLevel = "";
  this->studentMajor = "";
  this->studentID = studentID;
  this->studentAdvisor = 0;
  this->gpa = 0;
}

//student setters
void Student::setStudentID(int studentID)
{
  this->studentID = studentID;
}
void Student::setStudentName(string studentName)
{
  this->studentName = studentName;
}
void Student::setStudentLevel(string studentLevel)
{
  this->studentLevel = studentLevel;
}
void Student::setStudentMajor(string studentMajor)
{
  this->studentMajor = studentMajor;
}
void Student::setStudentGPA(double gpa)
{
  this->gpa = gpa;
}
void Student::setStudentAdvisor(int studentAdvisor)
{
  this->studentAdvisor = studentAdvisor;
}

//student getters
int Student::getStudentID()
{
  return studentID;
}
string Student::getStudentName()
{
  return studentName;
}
string Student::getStudentLevel()
{
  return studentLevel;
}
string Student::getStudentMajor()
{
  return studentMajor;
}
double Student::getStudentGPA()
{
  return gpa;
}
int Student::getStudentAdvisor()
{
  return studentAdvisor;
}

//print student info
void Student::printSInfo()
{
  cout << "Student ID: " << studentID << endl;
  cout << "Student Name: " << studentName << endl;
  cout << "Student Level: " << studentLevel << endl;
  cout << "Student Major: " << studentMajor << endl;
  cout << "Student GPA: " << gpa << endl;
  cout << "Student Advisor: " << studentAdvisor << endl;
  cout << "" << endl;
}

//////////////////////////////////////////////////////////////////

Faculty::Faculty()
{
  this->facultyName = "";
  this->facultyLevel = "";
  this->facultyDepartment = "";
  this->facultyID = 0;
  this->facultyAdvisees;
}

Faculty::Faculty(int facultyID)
{
  this->facultyName = "";
  this->facultyLevel = "";
  this->facultyDepartment = "";
  this->facultyID = facultyID;
  this->facultyAdvisees;
}

//faculty setters
void Faculty::setFacultyID(int facultyID)
{
  this->facultyID = facultyID;
}
void Faculty::setFacultyName(string facultyName)
{
  this->facultyName = facultyName;
}
void Faculty::setFacultyLevel(string facultyLevel)
{
  this->facultyLevel = facultyLevel;
}
void Faculty::setFacultyDepartment(string facultyDepartment)
{
  this->facultyDepartment = facultyDepartment;
}
void Faculty::setFacultyAdvisees(vector<int> facultyAdvisees)
{
  this->facultyAdvisees = facultyAdvisees;
}

//faculty getters
int Faculty::getFacultyID()
{
  return facultyID;
}
string Faculty::getFacultyName()
{
  return facultyName;
}
string Faculty::getFacultyLevel()
{
  return facultyLevel;
}
string Faculty::getFacultyDepartment()
{
  return facultyDepartment;
}
vector<int> Faculty::getFacultyAdvisees()
{
  return facultyAdvisees;
}

//print faculty info
void Faculty::printFInfo()
{
  cout << "Faculty ID: " << facultyID << endl;
  cout << "Faculty Name: " << facultyName << endl;
  cout << "Faculty Level: " << facultyLevel << endl;
  cout << "Faculty Department: " << facultyDepartment << endl;
  for (int i = 0; i < facultyAdvisees.size(); i++)
  {
    cout << "Faculty Advisees' IDs: " << facultyAdvisees[i] << endl;
  }
  if (facultyAdvisees.size() == 0)
  {
    cout << "Faculty Advisees' IDs: None" << endl;
  }
  cout << "" << endl;
}

//////////////////////////////////////////////////////////

Runner::Runner()
{
  rollbacksAvailable = 0;
}

Runner::Runner(int rollbacksAvailable)
{
  rollbacksAvailable = 0;
}

void Runner::Run(int option)
{
  BST<Student> masterStudent;
  BST<Faculty> masterFaculty;

  ifstream myFile ("studentTable.txt");
  if (myFile)
  {
    while(getline(myFile, line))
    {
        studentCreator.push_back(line);
    }
  }
  else
  {
    ofstream myFile ("studentTable.txt");
  }

  int size = studentCreator.size()/6;

  for (int i = 0; i < size; i++)
  {
    Student newStudent;
    newStudent.setStudentID(stoi(studentCreator[0]));
    studentCreator.erase(studentCreator.begin());
    newStudent.setStudentName(studentCreator[0]);
    studentCreator.erase(studentCreator.begin());
    newStudent.setStudentLevel(studentCreator[0]);
    studentCreator.erase(studentCreator.begin());
    newStudent.setStudentMajor(studentCreator[0]);
    studentCreator.erase(studentCreator.begin());
    newStudent.setStudentGPA(stod(studentCreator[0]));
    studentCreator.erase(studentCreator.begin());
    newStudent.setStudentAdvisor(stoi(studentCreator[0]));
    studentCreator.erase(studentCreator.begin());

    masterStudent.insertStudent(newStudent);
    studentVector.push_back(newStudent);
  }
  myFile.close();

  ifstream myFile2 ("facultyTable.txt");
  if (myFile2)
  {
    while(getline(myFile2, line))
    {
        facultyCreator.push_back(line);
    }
  }
  else
  {
    ofstream myFile2 ("facultyTable.txt");
  }

  int size2 = facultyCreator.size()/5;

  for (int i = 0; i < size2; i++)
  {
    Faculty newFaculty;
    facultyAdvisees.clear();
    newFaculty.setFacultyID(stoi(facultyCreator[0]));
      facultyCreator.erase(facultyCreator.begin());
    newFaculty.setFacultyName(facultyCreator[0]);
      facultyCreator.erase(facultyCreator.begin());
    newFaculty.setFacultyLevel(facultyCreator[0]);
      facultyCreator.erase(facultyCreator.begin());
    newFaculty.setFacultyDepartment(facultyCreator[0]);
      facultyCreator.erase(facultyCreator.begin());
    int adviseesListLength = (stoi(facultyCreator[0]));
      facultyCreator.erase(facultyCreator.begin());

    for (int i = 0; i < adviseesListLength; i++)
    {
      facultyAdvisees.push_back(stoi(facultyCreator[0]));
      facultyCreator.erase(facultyCreator.begin());
    }
    newFaculty.setFacultyAdvisees(facultyAdvisees);

    masterFaculty.insertFaculty(newFaculty);
    facultyVector.push_back(newFaculty);
  }
  myFile2.close();

  //Print all students and their information (sorted by ascending id #)
  if (option == 1)
  {
    cout << "" << endl;
    studentOrder = masterStudent.printTree();

    while (studentOrder.size() != 0)
    {
      for (int i = 0; i < studentVector.size(); i++)
      {
        if (studentVector[i].getStudentID() == studentOrder[0])
        {
          studentVector[i].printSInfo();
          studentOrder.erase(studentOrder.begin());
        }
      }
    }
  }

  //Print all faculty and their information (sorted by ascending id #)
  if (option == 2)
  {
    cout << "" << endl;
    facultyOrder = masterFaculty.printTree();

    while (facultyOrder.size() != 0)
    {
      for (int i = 0; i < facultyVector.size(); i++)
      {
        if (facultyVector[i].getFacultyID() == facultyOrder[0])
        {
          facultyVector[i].printFInfo();
          facultyOrder.erase(facultyOrder.begin());
        }
      }
    }
  }

  //Find and display student information given the students id
  if (option == 3)
  {
    string answer;
    bool needExit;
    cout << "What is the student's ID?" << endl;
    getline(cin,answer);

    for (int i = 0; i < answer.length(); i++)
    {
        if (isdigit(answer[i]) == false)
        {
          cout << "That is an invalid input" << endl;
          needExit = true;
        }
    }
    if (!needExit)
    {
      bool inTree = masterStudent.contains(stoi(answer));

      if (!inTree)
      {
        cout << "There is no student with that ID number" << endl;
      }
      else
      {
        for (int i = 0; i < studentVector.size(); i++)
        {
          if (studentVector[i].getStudentID() == stoi(answer))
          {
            cout << "" << endl;
            studentVector[i].printSInfo();
            break;
          }
        }
      }
    }

  }

  //Find and display faculty information given the faculty id
  if (option == 4)
  {
    string answer;
    bool needExit;
    cout << "What is the faculty's ID?" << endl;
    getline(cin,answer);

    for (int i = 0; i < answer.length(); i++)
    {
        if (isdigit(answer[i]) == false)
        {
          cout << "That is an invalid input" << endl;
          needExit = true;
        }
    }
    if (!needExit)
    {
      bool inTree = masterFaculty.contains(stoi(answer));

      if (!inTree)
      {
        cout << "There is no faculty with that ID number" << endl;
      }
      else
      {
        for (int i = 0; i < facultyVector.size(); i++)
        {
          if (facultyVector[i].getFacultyID() == stoi(answer))
          {
            cout << "" << endl;
            facultyVector[i].printFInfo();
            break;
          }
        }
      }
    }

  }

  //Given a student’s id, print the name and info of their faculty advisor
  if (option == 5)
  {
    string answer;
    bool needExit;
    int advisorID;
    cout << "What is the student's ID?" << endl;
    getline(cin,answer);

    for (int i = 0; i < answer.length(); i++)
    {
        if (isdigit(answer[i]) == false)
        {
          cout << "That is an invalid input" << endl;
          needExit = true;
        }
    }
    if (!needExit)
    {
      bool inTree = masterStudent.contains(stoi(answer));

      if (!inTree)
      {
        cout << "There is no student with that ID number" << endl;
      }
      else
      {
        for (int i = 0; i < studentVector.size(); i++)
        {
          if (studentVector[i].getStudentID() == stoi(answer))
          {
            cout << "" << endl;
            advisorID = studentVector[i].getStudentAdvisor();
            for (int i = 0; i < facultyVector.size(); i++)
            {
              if (facultyVector[i].getFacultyID() == advisorID)
              {
                cout << "" << endl;
                facultyVector[i].printFInfo();
                break;
              }
            }
            break;
          }
        }
      }
    }

  }

  //Given a faculty id, print ALL the names and info of his/her advisees
  if (option == 6)
  {
    string answer;
    bool needExit;
    vector<int> adviseeIDs;
    cout << "What is the faculty's ID?" << endl;
    getline(cin,answer);

    for (int i = 0; i < answer.length(); i++)
    {
        if (isdigit(answer[i]) == false)
        {
          cout << "That is an invalid input" << endl;
          needExit = true;
        }
    }
    if (!needExit)
    {
      bool inTree = masterFaculty.contains(stoi(answer));

      if (!inTree)
      {
        cout << "There is no faculty with that ID number" << endl;
      }
      else
      {
        for (int i = 0; i < studentVector.size(); i++)
        {
          if (studentVector[i].getStudentAdvisor() == stoi(answer))
          {
            cout << "" << endl;
            studentVector[i].printSInfo();
          }
        }
      }
    }

  }

  //Add a new student
  if (option == 7)
  {
    Student addStudent;
    string answer;
    bool needExit;

    cout << "What is this new student's ID? " << endl;
    getline (cin, answer);

    for (int i = 0; i < answer.length(); i++)
    {
        if (isdigit(answer[i]) == false)
        {
          cout << "That is an invalid input" << endl;
          needExit = true;
        }
    }
    if (!needExit)
    {
      bool inTree = masterStudent.contains(stoi(answer));

      if (inTree)
      {
        cout << "There is already a student with that ID number" << endl;
      }
      else
      {
        addStudent.setStudentID(stoi(answer));

        cout << "What is this new student's Name? " << endl;
        getline (cin, answer);
        addStudent.setStudentName(answer);

        cout << "What is this new student's Level? " << endl;
        getline (cin, answer);
        addStudent.setStudentLevel(answer);

        cout << "What is this new student's Major? " << endl;
        getline (cin, answer);
        addStudent.setStudentMajor(answer);

        cout << "What is this new student's GPA? " << endl;
        getline (cin, answer);
        for (int i = 0; i < answer.length(); i++)
        {
            if (isdigit(answer[i]) == false && answer[i] != '.')
            {
              cout << "That is an invalid input" << endl;
              needExit = true;
            }
        }
        if (!needExit)
        {
          addStudent.setStudentGPA(stod(answer));

          cout << "What is this new student's Advisor's ID? " << endl;
          getline (cin, answer);
          for (int i = 0; i < answer.length(); i++)
          {
              if (isdigit(answer[i]) == false && answer[i] != '.')
              {
                cout << "That is an invalid input" << endl;
                needExit = true;
              }
          }
          if (!needExit)
          {
            bool inTree = masterFaculty.contains(stoi(answer));

            if (!inTree)
            {
              cout << "There is no faculty with that ID number" << endl;
            }
            else
            {
              addStudent.setStudentAdvisor(stoi(answer));

              cout << "" << endl;

              masterStudent.insertStudent(addStudent);
              studentVector.push_back(addStudent);

              vector<string> reader;
              ifstream myFile ("studentTable.txt");
              while(getline(myFile, line))
              {
                reader.push_back(line);
              }

              if (rollbacksAvailable == 0)
              {
                for (int i = 0; i < reader.size(); i++)
                {
                  RollBack5.push_back(reader[i]);
                }
                rollbacksAvailable++;
                rollbackFiles.push_back("s");
              }
              else if (rollbacksAvailable == 1)
              {
                for (int i = 0; i < reader.size(); i++)
                {
                  RollBack4.push_back(reader[i]);
                }
                rollbacksAvailable++;
                rollbackFiles.push_back("s");
              }
              else if (rollbacksAvailable == 2)
              {
                for (int i = 0; i < reader.size(); i++)
                {
                  RollBack3.push_back(reader[i]);
                }
                rollbacksAvailable++;
                rollbackFiles.push_back("s");
              }
              else if (rollbacksAvailable == 3)
              {
                for (int i = 0; i < reader.size(); i++)
                {
                  RollBack2.push_back(reader[i]);
                }
                rollbacksAvailable++;
                rollbackFiles.push_back("s");
              }
              else if (rollbacksAvailable == 4)
              {
                for (int i = 0; i < reader.size(); i++)
                {
                  RollBack1.push_back(reader[i]);
                }
                rollbacksAvailable++;
                rollbackFiles.push_back("s");
              }
              else if (rollbacksAvailable > 4)
              {
                RollBack5 = RollBack4;
                RollBack4 = RollBack3;
                RollBack3 = RollBack2;
                RollBack2 = RollBack1;

                for (int i = 0; i < reader.size(); i++)
                {
                  RollBack1.push_back(reader[i]);
                }
                rollbacksAvailable++;
                rollbackFiles.push_back("s");
              }

              reader.push_back(to_string(addStudent.getStudentID()));
              reader.push_back(addStudent.getStudentName());
              reader.push_back(addStudent.getStudentLevel());
              reader.push_back(addStudent.getStudentMajor());
              reader.push_back(to_string(addStudent.getStudentGPA()));
              reader.push_back(to_string(addStudent.getStudentAdvisor()));
              ofstream myFileSWrite ("studentTable.txt");
              for (int i = 0; i < reader.size(); i++)
              {
                myFileSWrite << reader[i] << endl;
              }

            }

          }
        }
      }
    }

  }

  //Delete a student given the id
  if (option == 8)
  {
    string answer;
    bool needExit;

    vector<int> studentList = masterStudent.printTree();

    cout << "What is this student's ID? " << endl;
    getline(cin,answer);

    for (int i = 0; i < answer.length(); i++)
    {
        if (isdigit(answer[i]) == false)
        {
          cout << "That is an invalid input" << endl;
          needExit = true;
        }
    }
    if (!needExit)
    {
      bool inTree = masterStudent.contains(stoi(answer));

      if (!inTree)
      {
        cout << "There is no student with that ID number" << endl;
      }
      else
      {
        vector<string> reader;
        ifstream myFile2 ("studentTable.txt");

        while(getline(myFile2, line))
        {
          reader.push_back(line);
        }

        if (rollbacksAvailable == 0)
        {
          for (int i = 0; i < reader.size(); i++)
          {
            RollBack5.push_back(reader[i]);
          }
          rollbacksAvailable++;
          rollbackFiles.push_back("s");
        }
        else if (rollbacksAvailable == 1)
        {
          for (int i = 0; i < reader.size(); i++)
          {
            RollBack4.push_back(reader[i]);
          }
          rollbacksAvailable++;
          rollbackFiles.push_back("s");
        }
        else if (rollbacksAvailable == 2)
        {
          for (int i = 0; i < reader.size(); i++)
          {
            RollBack3.push_back(reader[i]);
          }
          rollbacksAvailable++;
          rollbackFiles.push_back("s");
        }
        else if (rollbacksAvailable == 3)
        {
          for (int i = 0; i < reader.size(); i++)
          {
            RollBack2.push_back(reader[i]);
          }
          rollbacksAvailable++;
          rollbackFiles.push_back("s");
        }
        else if (rollbacksAvailable == 4)
        {
          for (int i = 0; i < reader.size(); i++)
          {
            RollBack1.push_back(reader[i]);
          }
          rollbacksAvailable++;
          rollbackFiles.push_back("s");
        }
        else if (rollbacksAvailable > 4)
        {
          RollBack5 = RollBack4;
          RollBack4 = RollBack3;
          RollBack3 = RollBack2;
          RollBack2 = RollBack1;

          for (int i = 0; i < reader.size(); i++)
          {
            RollBack1.push_back(reader[i]);
          }
          rollbacksAvailable++;
          rollbackFiles.push_back("s");
        }

        masterStudent.deleteR(stoi(answer));

        for (int i = 0; i < studentVector.size(); i++)
        {
          if (studentVector[i].getStudentID() == stoi(answer))
          {
            if (i > 0)
            {
              studentVector.erase(studentVector.begin()+i-1);
            }
            else
            {
              studentVector.erase(studentVector.begin());
            }
          }
        }

        vector<int> studentList2 = masterStudent.printTree();
        cout << "" << endl;

        BST<Student> masterStudent2;
        for (int i = studentList.size(); i < studentList2.size(); i++)
        {
          masterStudent2.insertStudent(studentList2[i]);
        }

        masterStudent = masterStudent2;

        vector<int> studentList3 = masterStudent.printTree();

        vector<string> studentCreate;
        studentVector.clear();
        ifstream myFile ("studentTable.txt");

        if (myFile)
        {
          while(getline(myFile, line))
          {
            studentCreate.push_back(line);
          }
        }

        int size = studentCreate.size()/6;

        for (int i = 0; i < size; i++)
        {
          Student newStudent;
          newStudent.setStudentID(stoi(studentCreate[0]));
          studentCreate.erase(studentCreate.begin());
          newStudent.setStudentName(studentCreate[0]);
          studentCreate.erase(studentCreate.begin());
          newStudent.setStudentLevel(studentCreate[0]);
          studentCreate.erase(studentCreate.begin());
          newStudent.setStudentMajor(studentCreate[0]);
          studentCreate.erase(studentCreate.begin());
          newStudent.setStudentGPA(stod(studentCreate[0]));
          studentCreate.erase(studentCreate.begin());
          newStudent.setStudentAdvisor(stoi(studentCreate[0]));
          studentCreate.erase(studentCreate.begin());

          studentVector.push_back(newStudent);
        }
        myFile.close();


        for (int i = 0; i < studentVector.size(); i++)
        {
          if (studentVector[i].getStudentID() == stoi(answer))
          {
            if (i > 0)
            {
              studentVector.erase(studentVector.begin()+i);
            }
            else
            {
              studentVector.erase(studentVector.begin());
            }
          }
        }

        vector<string> writer;

        ofstream myFileSWrite ("studentTable.txt");
        for (int i = 0; i < studentVector.size(); i++)
        {
          writer.push_back(to_string(studentVector[i].getStudentID()));
          writer.push_back(studentVector[i].getStudentName());
          writer.push_back(studentVector[i].getStudentLevel());
          writer.push_back(studentVector[i].getStudentMajor());
          writer.push_back(to_string(studentVector[i].getStudentGPA()));
          writer.push_back(to_string(studentVector[i].getStudentAdvisor()));
        }

        ofstream myFileSWrite2 ("studentTable.txt");
        for (int i = 0; i < writer.size(); i++)
        {
          myFileSWrite2 << writer[i] << endl;
        }

      }
    }
  }

  //Add a new faculty member
  if (option == 9)
  {
    Faculty addFaculty;
    string answer;
    bool needExit;
    vector<int> adviseeList;
    bool loop;

    cout << "What is this new faculty's ID? " << endl;
    getline(cin,answer);

    for (int i = 0; i < answer.length(); i++)
    {
        if (isdigit(answer[i]) == false)
        {
          cout << "That is an invalid input" << endl;
          needExit = true;
        }
    }
    if (!needExit)
    {
      bool inTree = masterFaculty.contains(stoi(answer));

      if (inTree)
      {
        cout << "There is already a faculty with that ID number" << endl;
      }
      else
      {
        addFaculty.setFacultyID(stoi(answer));

        cout << "What is this new faculty's Name? " << endl;
        getline(cin,answer);
        addFaculty.setFacultyName(answer);

        cout << "What is this new faculty's Level? " << endl;
        getline(cin,answer);
        addFaculty.setFacultyLevel(answer);

        cout << "What is this new faculty's Department? " << endl;
        getline(cin,answer);
        addFaculty.setFacultyDepartment(answer);

        while(loop)
        {
          cout << "What is this new faculty's Advisees' IDs? " << endl;
          cout << "(One ID at a time. Enter 'F' when finished.)" << endl;
          getline(cin,answer);

          for (int i = 0; i < answer.length(); i++)
          {
            string toLower;
            toLower += tolower(answer[i]);
            answer = toLower;
          }

          if (answer != "f")
          {
            for (int i = 0; i < answer.length(); i++)
            {
                if (isdigit(answer[i]) == false)
                {
                  cout << "That is an invalid input" << endl;
                  needExit = true;
                  loop = false;
                }
            }
            if (!needExit)
            {
              bool inTree = masterStudent.contains(stoi(answer));

              if (!inTree)
              {
                cout << "There is no student with that ID number" << endl;
                loop = false;
              }
              else
              {
                adviseeList.push_back(stoi(answer));

                cout << "" << endl;
              }
            }
          }
          else
          {
            loop = false;
            addFaculty.setFacultyAdvisees(adviseeList);
            masterFaculty.insertFaculty(addFaculty);
            facultyVector.push_back(addFaculty);

            vector<string> reader2;
            ifstream myFile ("facultyTable.txt");
            while(getline(myFile, line))
            {
              reader2.push_back(line);
            }

            if (rollbacksAvailable == 0)
            {
              for (int i = 0; i < reader2.size(); i++)
              {
                RollBack5.push_back(reader2[i]);
              }
              rollbacksAvailable++;
              rollbackFiles.push_back("f");
            }
            else if (rollbacksAvailable == 1)
            {
              for (int i = 0; i < reader2.size(); i++)
              {
                RollBack4.push_back(reader2[i]);
              }
              rollbacksAvailable++;
              rollbackFiles.push_back("f");
            }
            else if (rollbacksAvailable == 2)
            {
              for (int i = 0; i < reader2.size(); i++)
              {
                RollBack3.push_back(reader2[i]);
              }
              rollbacksAvailable++;
              rollbackFiles.push_back("f");
            }
            else if (rollbacksAvailable == 3)
            {
              for (int i = 0; i < reader2.size(); i++)
              {
                RollBack2.push_back(reader2[i]);
              }
              rollbacksAvailable++;
              rollbackFiles.push_back("f");
            }
            else if (rollbacksAvailable == 4)
            {
              for (int i = 0; i < reader2.size(); i++)
              {
                RollBack1.push_back(reader2[i]);
              }
              rollbacksAvailable++;
              rollbackFiles.push_back("f");
            }
            else if (rollbacksAvailable > 4)
            {
              RollBack5 = RollBack4;
              RollBack4 = RollBack3;
              RollBack3 = RollBack2;
              RollBack2 = RollBack1;

              for (int i = 0; i < reader2.size(); i++)
              {
                RollBack1.push_back(reader2[i]);
              }
              rollbacksAvailable++;
              rollbackFiles.push_back("f");
            }

            reader2.push_back(to_string(addFaculty.getFacultyID()));
            reader2.push_back(addFaculty.getFacultyName());
            reader2.push_back(addFaculty.getFacultyLevel());
            reader2.push_back(addFaculty.getFacultyDepartment());

            vector<int> countAdvisees = addFaculty.getFacultyAdvisees();
            int numberAdvisees = countAdvisees.size();

            reader2.push_back(to_string(numberAdvisees));

            for (int i = 0; i < countAdvisees.size(); i++)
            {
              reader2.push_back(to_string(countAdvisees[i]));
            }

            ofstream myFileSWrite ("facultyTable.txt");
            for (int i = 0; i < reader2.size(); i++)
            {
              myFileSWrite << reader2[i] << endl;
            }
          }
        }
      }
    }
  }

  //Delete a faculty member given the id
  if (option == 10)
  {
    string answer;
    bool needExit;
    vector<int> facultyList = masterFaculty.printTree();

    cout << "What is this faculty's ID? " << endl;
    getline(cin,answer);

    for (int i = 0; i < answer.length(); i++)
    {
        if (isdigit(answer[i]) == false)
        {
          cout << "That is an invalid input" << endl;
          needExit = true;
        }
    }
    if (!needExit)
    {
      bool inTree = masterFaculty.contains(stoi(answer));

      if (inTree)
      {
        vector<string> reader2;
        ifstream myFile ("facultyTable.txt");
        while(getline(myFile, line))
        {
          reader2.push_back(line);
        }

        if (rollbacksAvailable == 0)
        {
          for (int i = 0; i < reader2.size(); i++)
          {
            RollBack5.push_back(reader2[i]);
          }
          rollbacksAvailable++;
          rollbackFiles.push_back("f");
        }
        else if (rollbacksAvailable == 1)
        {
          for (int i = 0; i < reader2.size(); i++)
          {
            RollBack4.push_back(reader2[i]);
          }
          rollbacksAvailable++;
          rollbackFiles.push_back("f");
        }
        else if (rollbacksAvailable == 2)
        {
          for (int i = 0; i < reader2.size(); i++)
          {
            RollBack3.push_back(reader2[i]);
          }
          rollbacksAvailable++;
          rollbackFiles.push_back("f");
        }
        else if (rollbacksAvailable == 3)
        {
          for (int i = 0; i < reader2.size(); i++)
          {
            RollBack2.push_back(reader2[i]);
          }
          rollbacksAvailable++;
          rollbackFiles.push_back("f");
        }
        else if (rollbacksAvailable == 4)
        {
          for (int i = 0; i < reader2.size(); i++)
          {
            RollBack1.push_back(reader2[i]);
          }
          rollbacksAvailable++;
          rollbackFiles.push_back("f");
        }
        else if (rollbacksAvailable > 4)
        {
          RollBack5 = RollBack4;
          RollBack4 = RollBack3;
          RollBack3 = RollBack2;
          RollBack2 = RollBack1;

          for (int i = 0; i < reader2.size(); i++)
          {
            RollBack1.push_back(reader2[i]);
          }
          rollbacksAvailable++;
          rollbackFiles.push_back("f");
        }

          masterFaculty.deleteR(stoi(answer));

          for (int i = 0; i < facultyVector.size(); i++)
          {
            if (facultyVector[i].getFacultyID() == stoi(answer))
            {
              if (i > 0)
              {
                facultyVector.erase(facultyVector.begin()+i);
              }
              else
              {
                facultyVector.erase(facultyVector.begin());        }
            }
          }

          vector<int> facultyList2 = masterFaculty.printTree();
          cout << "" << endl;

          BST<Faculty> masterFaculty2;
          for (int i = facultyList.size(); i < facultyList2.size(); i++)
          {
            masterFaculty2.insertFaculty(facultyList2[i]);
          }

          masterFaculty = masterFaculty2;

          vector<int> facultyList3 = masterFaculty.printTree();

          vector<string> writer2;

          for (int i = 0; i < facultyVector.size(); i++)
          {
            writer2.push_back(to_string(facultyVector[i].getFacultyID()));
            writer2.push_back(facultyVector[i].getFacultyName());
            writer2.push_back(facultyVector[i].getFacultyLevel());
            writer2.push_back(facultyVector[i].getFacultyDepartment());

            vector<int> countAdvisees2 = facultyVector[i].getFacultyAdvisees();
            int numberAdvisees2 = countAdvisees2.size();

            writer2.push_back(to_string(numberAdvisees2));

            for (int i = 0; i < countAdvisees2.size(); i++)
            {
              writer2.push_back(to_string(countAdvisees2[i]));
            }
          }

          ofstream myFileFWrite ("facultyTable.txt");
          for (int i = 0; i < writer2.size(); i++)
          {
            myFileFWrite << writer2[i] << endl;
          }
        }
        else
        {
          cout << "There is no faculty with that ID number" << endl;
        }
      }
    }

  //Change a student’s advisor given the student id and the new faculty id
  if (option == 11)
  {
    string answer;
    string answer2;
    bool needExit;
    cout << "What is the student's ID?" << endl;
    getline(cin,answer);
    cout << "What is the ID of the student's new advisor?" << endl;
    getline(cin,answer2);

    for (int i = 0; i < answer.length(); i++)
    {
        if (isdigit(answer[i]) == false)
        {
          cout << "That is an invalid input" << endl;
          needExit = true;
        }
    }
    for (int i = 0; i < answer2.length(); i++)
    {
        if (isdigit(answer2[i]) == false)
        {
          cout << "That is an invalid input" << endl;
          needExit = true;
        }
    }
    if (!needExit)
    {
      bool inTree = masterStudent.contains(stoi(answer));
      bool inTree2 = masterFaculty.contains(stoi(answer2));

      if (!inTree)
      {
        cout << "There is no student with that ID number" << endl;
      }
      if (!inTree2)
      {
        cout << "There is no faculty with that ID number" << endl;
      }
      if (inTree && inTree2)
      {
        vector<string> reader;
        ifstream myFile2 ("studentTable.txt");
        while(getline(myFile2, line))
        {
          reader.push_back(line);
        }

        if (rollbacksAvailable == 0)
        {
          for (int i = 0; i < reader.size(); i++)
          {
            RollBack5.push_back(reader[i]);
          }
          rollbacksAvailable++;
          rollbackFiles.push_back("s");
        }
        else if (rollbacksAvailable == 1)
        {
          for (int i = 0; i < reader.size(); i++)
          {
            RollBack4.push_back(reader[i]);
          }
          rollbacksAvailable++;
          rollbackFiles.push_back("s");
        }
        else if (rollbacksAvailable == 2)
        {
          for (int i = 0; i < reader.size(); i++)
          {
            RollBack3.push_back(reader[i]);
          }
          rollbacksAvailable++;
          rollbackFiles.push_back("s");
        }
        else if (rollbacksAvailable == 3)
        {
          for (int i = 0; i < reader.size(); i++)
          {
            RollBack2.push_back(reader[i]);
          }
          rollbacksAvailable++;
          rollbackFiles.push_back("s");
        }
        else if (rollbacksAvailable == 4)
        {
          for (int i = 0; i < reader.size(); i++)
          {
            RollBack1.push_back(reader[i]);
          }
          rollbacksAvailable++;
          rollbackFiles.push_back("s");
        }
        else if (rollbacksAvailable > 4)
        {
          RollBack5 = RollBack4;
          RollBack4 = RollBack3;
          RollBack3 = RollBack2;
          RollBack2 = RollBack1;

          for (int i = 0; i < reader.size(); i++)
          {
            RollBack1.push_back(reader[i]);
          }
          rollbacksAvailable++;
          rollbackFiles.push_back("s");
        }

        for (int i = 0; i < studentVector.size(); i++)
        {
          if (studentVector[i].getStudentID() == stoi(answer))
          {
            cout << "" << endl;
            studentVector[i].setStudentAdvisor(stoi(answer2));
            studentVector[i].printSInfo();
          }

          vector<string> writer;

          ofstream myFileSWrite ("studentTable.txt");
          for (int i = 0; i < studentVector.size(); i++)
          {
            writer.push_back(to_string(studentVector[i].getStudentID()));
            writer.push_back(studentVector[i].getStudentName());
            writer.push_back(studentVector[i].getStudentLevel());
            writer.push_back(studentVector[i].getStudentMajor());
            writer.push_back(to_string(studentVector[i].getStudentGPA()));
            writer.push_back(to_string(studentVector[i].getStudentAdvisor()));
          }

          ofstream myFileSWrite2 ("studentTable.txt");
          for (int i = 0; i < writer.size(); i++)
          {
            myFileSWrite2 << writer[i] << endl;
          }
        }
      }
    }
  }

  //Remove an advisee from a faculty member given the ids
  if (option == 12)
  {
    string answer;
    string answer2;
    bool needExit;
    bool adviseeFound;
    vector<int> adviseeIDs;
    cout << "What is the faculty's ID?" << endl;
    getline(cin,answer);
    cout << "What is the ID of the advisee to remove?" << endl;
    getline(cin,answer2);

    for (int i = 0; i < answer.length(); i++)
    {
        if (isdigit(answer[i]) == false)
        {
          cout << "That is an invalid input" << endl;
          needExit = true;
        }
    }
    for (int i = 0; i < answer2.length(); i++)
    {
        if (isdigit(answer2[i]) == false)
        {
          cout << "That is an invalid input" << endl;
          needExit = true;
        }
    }
    if (!needExit)
    {
      bool inTree = masterFaculty.contains(stoi(answer));

      if (!inTree)
      {
        cout << "There is no faculty with that ID number" << endl;
      }
      else
      {
        vector<string> reader2;
        ifstream myFile ("facultyTable.txt");
        while(getline(myFile, line))
        {
          reader2.push_back(line);
        }

        if (rollbacksAvailable == 0)
        {
          for (int i = 0; i < reader2.size(); i++)
          {
            RollBack5.push_back(reader2[i]);
          }
          rollbacksAvailable++;
          rollbackFiles.push_back("f");
        }
        else if (rollbacksAvailable == 1)
        {
          for (int i = 0; i < reader2.size(); i++)
          {
            RollBack4.push_back(reader2[i]);
          }
          rollbacksAvailable++;
          rollbackFiles.push_back("f");
        }
        else if (rollbacksAvailable == 2)
        {
          for (int i = 0; i < reader2.size(); i++)
          {
            RollBack3.push_back(reader2[i]);
          }
          rollbacksAvailable++;
          rollbackFiles.push_back("f");
        }
        else if (rollbacksAvailable == 3)
        {
          for (int i = 0; i < reader2.size(); i++)
          {
            RollBack2.push_back(reader2[i]);
          }
          rollbacksAvailable++;
          rollbackFiles.push_back("f");
        }
        else if (rollbacksAvailable == 4)
        {
          for (int i = 0; i < reader2.size(); i++)
          {
            RollBack1.push_back(reader2[i]);
          }
          rollbacksAvailable++;
          rollbackFiles.push_back("f");
        }
        else if (rollbacksAvailable > 4)
        {
          RollBack5 = RollBack4;
          RollBack4 = RollBack3;
          RollBack3 = RollBack2;
          RollBack2 = RollBack1;

          for (int i = 0; i < reader2.size(); i++)
          {
            RollBack1.push_back(reader2[i]);
          }
          rollbacksAvailable++;
          rollbackFiles.push_back("f");
        }

        for (int i = 0; i < facultyVector.size(); i++)
        {
          if (facultyVector[i].getFacultyID() == stoi(answer))
          {
            adviseeIDs = facultyVector[i].getFacultyAdvisees();

            for (int j = 0; j < adviseeIDs.size(); j++)
            {
              if (adviseeIDs[j] == stoi(answer2))
              {
                if (j > 0)
                {
                  adviseeIDs.erase(adviseeIDs.begin()+j);
                  adviseeFound = true;
                }
                else
                {
                  adviseeIDs.erase(adviseeIDs.begin());
                  adviseeFound = true;
                }
              }
            }

            facultyVector[i].setFacultyAdvisees(adviseeIDs);
            cout << "" << endl;
            facultyVector[i].printFInfo();
          }

          vector<string> writer2;

          for (int i = 0; i < facultyVector.size(); i++)
          {
            writer2.push_back(to_string(facultyVector[i].getFacultyID()));
            writer2.push_back(facultyVector[i].getFacultyName());
            writer2.push_back(facultyVector[i].getFacultyLevel());
            writer2.push_back(facultyVector[i].getFacultyDepartment());

            vector<int> countAdvisees2 = facultyVector[i].getFacultyAdvisees();
            int numberAdvisees2 = countAdvisees2.size();

            writer2.push_back(to_string(numberAdvisees2));

            for (int i = 0; i < countAdvisees2.size(); i++)
            {
              writer2.push_back(to_string(countAdvisees2[i]));
            }
          }

          ofstream myFileFWrite2 ("facultyTable.txt");
          for (int i = 0; i < writer2.size(); i++)
          {
            myFileFWrite2 << writer2[i] << endl;
          }

        }

        if (!adviseeFound)
        {
          cout << "There is no advisee with that ID number assigned to that faculty member" << endl;
        }

      }
    }
  }

  //Rollback
  if (option == 13)
  {
    ofstream rollbackWriteS ("studentTable.txt");
    ofstream rollbackWriteF ("facultyTable.txt");

    if (!RollBack1.empty())
    {
      string pop = rollbackFiles.back();
      rollbackFiles.pop_back();
      if (pop == "s")
      {
        for (int i = 0; i < RollBack1.size(); i++)
        {
          rollbackWriteS << RollBack1[i] << endl;
        }
      }
      else if (pop == "f")
      {
        for (int i = 0; i < RollBack1.size(); i++)
        {
          rollbackWriteF << RollBack1[i] << endl;
        }
      }
      cout << "The last change to the database was undone." << endl;
    }
    else if (!RollBack2.empty())
    {
      string pop = rollbackFiles.back();
      rollbackFiles.pop_back();
      if (pop == "s")
      {
        for (int i = 0; i < RollBack2.size(); i++)
        {
          rollbackWriteS << RollBack2[i] << endl;
        }
      }
      else if (pop == "f")
      {
        for (int i = 0; i < RollBack2.size(); i++)
        {
          rollbackWriteF << RollBack2[i] << endl;
        }
      }
      cout << "The last change to the database was undone." << endl;
    }
    else if (!RollBack3.empty())
    {
      string pop = rollbackFiles.back();
      rollbackFiles.pop_back();
      if (pop == "s")
      {
        for (int i = 0; i < RollBack3.size(); i++)
        {
          rollbackWriteS << RollBack3[i] << endl;
        }
      }
      else if (pop == "f")
      {
        for (int i = 0; i < RollBack3.size(); i++)
        {
          rollbackWriteF << RollBack3[i] << endl;
        }
      }
      cout << "The last change to the database was undone." << endl;
    }
    else if (!RollBack4.empty())
    {
      string pop = rollbackFiles.back();
      rollbackFiles.pop_back();
      if (pop == "s")
      {
        for (int i = 0; i < RollBack4.size(); i++)
        {
          rollbackWriteS << RollBack4[i] << endl;
        }
      }
      else if (pop == "f")
      {
        for (int i = 0; i < RollBack4.size(); i++)
        {
          rollbackWriteF << RollBack4[i] << endl;
        }
      }
      cout << "The last change to the database was undone." << endl;
    }
    else if (!RollBack5.empty())
    {
      string pop = rollbackFiles.back();
      rollbackFiles.pop_back();
      if (pop == "s")
      {
        for (int i = 0; i < RollBack5.size(); i++)
        {
          rollbackWriteS << RollBack5[i] << endl;
        }
      }
      else if (pop == "f")
      {
        for (int i = 0; i < RollBack5.size(); i++)
        {
          rollbackWriteF << RollBack5[i] << endl;
        }
      }
      cout << "The last change to the database was undone." << endl;
    }
    else
    {
      cout << "There were no changes to the database to be undone." << endl;
    }
  }
}
