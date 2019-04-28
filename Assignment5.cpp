#include <iostream>
#include <typeinfo>
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
{
  //research this
}

/////////////////////////////////////////////////////////
//////implement this Tree//////
template <class T>
BST<T>::BST() //default constructor
{
  root = NULL; //empty tree
}

template <class T>
BST<T>::~BST() //default constructor
{
  //iterate and delete
  //research
}

template <class T>
void BST<T>::printTree()
{
  recPrint(root);
}

template <class T>
void BST<T>::recPrint(TreeNode *node)
{
  if (node == NULL)
  {
    return;
  }
   recPrint(node->left);
   cout << node->key << endl;
   recPrint(node->right);
}

template <class T>
bool BST<T>::isEmpty()
{
  return (root == NULL);
}

template <class T>
void BST<T>::insert(T object)
{
  //check if value exists, if not continue

  if (typeid(object) == typeid(Student))
  {
    value = object.getStudentID();
  }
  if (typeid(object) == typeid(Faculty))
  {
    value = object.getFacultyID();
  }

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
          current->left = node;
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

  while (current->key != k) //let's looky for our node
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

  //at this point, we found our node
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
void Student::printSInfo()//(Student student)
{
  cout << "Student ID: " << studentID << endl;
  cout << "Student Name: " << studentName << endl;
  cout << "Student Level: " << studentLevel << endl;
  cout << "Student Major: " << studentMajor << endl;
  cout << "Student GPA: " << gpa << endl;
  cout << "Student Advisor" << studentAdvisor << endl;
  cout << "" << endl;
}

//////////////////////////////////////////////////////////////////

Faculty::Faculty()
{
  this->facultyName = "";
  this->facultyLevel = "";
  this->facultyDepartment = "";
  this->facultyID = 0;
}

Faculty::Faculty(int facultyID)
{
  this->facultyName = "";
  this->facultyLevel = "";
  this->facultyDepartment = "";
  this->facultyID = facultyID;
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

//print faculty info
void Faculty::printFInfo()//(Faculty Faculty)
{
  cout << "Faculty ID: " << facultyID << endl;
  cout << "Faculty Name: " << facultyName << endl;
  cout << "Faculty Level: " << facultyLevel << endl;
  for (int i = 0; i < facultyAdvisees.size(); i++)
  {
    cout << "Faculty Advisees:" << facultyAdvisees[i] << endl;
  }
  cout << "" << endl;
}

//////////////////////////////////////////////////////////

Runner::Runner()
{

}

Runner::Runner(bool loopCondition)
{
  loop = loopCondition;
}

void Runner::Run(string fileName, string fileName2)
{

}
