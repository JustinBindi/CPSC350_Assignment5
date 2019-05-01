#include <iostream>
#include <vector>

using namespace std;

//Node Class
class TreeNode
{
public:
  TreeNode();
  TreeNode(int k);
  virtual ~TreeNode();

  int key;
  TreeNode *left; //left child
  TreeNode *right; //right child
};

//Tree Class
template <class T>
class BST
{
  public:
    BST();
    virtual ~BST();
    void insertStudent(T object);
    void insertFaculty(T object);

    bool contains(int value); //AKA search
    bool deleteR(int k);
    TreeNode* getSuccessor(TreeNode* d);

    TreeNode* getMin();
    TreeNode* getMax();
    bool isEmpty();
    vector<int> printTree();
    void recPrint(TreeNode *node); //recursive print

  private:
    TreeNode *root;
    int value;
    vector<int> printingVector;
};

//Student Class
class Student
{
  public:
    Student();
    Student(int studentID);

    void printSInfo();
    void setStudentID(int studentID);
    void setStudentName(string studentName);
    void setStudentLevel(string studentLevel);
    void setStudentMajor(string studentMajor);
    void setStudentGPA(double gpa);
    void setStudentAdvisor(int studentAdvisor);
    int getStudentID();
    string getStudentName();
    string getStudentLevel();
    string getStudentMajor();
    double getStudentGPA();
    int getStudentAdvisor();

    string studentName;
    string studentLevel;
    int studentID;
    string studentMajor;
    double gpa;
    int studentAdvisor;
};

//Faculty Class
class Faculty
{
  public:
    Faculty();
    Faculty(int facultyID);

    void printFInfo();
    void setFacultyID(int facultyID);
    void setFacultyName(string facultyName);
    void setFacultyLevel(string facultyLevel);
    void setFacultyDepartment(string facultyDepartment);
    void setFacultyAdvisees(vector<int> facultyAdvisees);
    int getFacultyID();
    string getFacultyName();
    string getFacultyLevel();
    string getFacultyDepartment();
    vector<int> getFacultyAdvisees();

    string facultyName;
    string facultyLevel;
    int facultyID;
    string facultyDepartment;
    vector<int> facultyAdvisees;
};

//Class that runs the different options
class Runner
{
  public:
    Runner();
    Runner(int rollbacksAvailable);
    bool loop;

    void Run(int option);
    string line;
    string substring;
    int rollbacksAvailable;
    vector<string> RollBack1;
    vector<string> RollBack2;
    vector<string> RollBack3;
    vector<string> RollBack4;
    vector<string> RollBack5;
    vector<string> rollbackFiles;
    vector<string> studentCreator;
    vector<string> facultyCreator;
    vector<Student> studentVector;
    vector<Faculty> facultyVector;
    vector<int> studentOrder;
    vector<int> facultyOrder;
    vector<int> facultyAdvisees;
};
