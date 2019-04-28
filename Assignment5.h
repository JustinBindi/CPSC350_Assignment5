#include <iostream>
#include <vector>

using namespace std;

class TreeNode
{
public:
  TreeNode();
  TreeNode(int k);
  virtual ~TreeNode(); //why a virtual destructor

  int key;
  TreeNode *left; //left child
  TreeNode *right; //right child
};

//////let's define our Tree Class//////

template <class T>
class BST
{
  public:
    BST();
    virtual ~BST();
    void insert(T object);
    bool contains(int value); //AKA search
    bool deleteR(int k);
    TreeNode* getSuccessor(TreeNode* d);

    TreeNode* getMin();
    TreeNode* getMax();
    bool isEmpty();
    void printTree();
    void recPrint(TreeNode *node); //recursive print

  private:
    TreeNode *root;
    int value;
};

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
    double getFacultyAdvisees();

    string facultyName;
    string facultyLevel;
    int facultyID;
    string facultyDepartment;
    vector<int> facultyAdvisees;
};

class Runner
{
  public:
    Runner();
    Runner(bool loopCondition);
    bool loop;

    void Run(string fileName, string fileName2);
};
