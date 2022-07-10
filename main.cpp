// This program is a demonstration of what was learned in my progrmming course 
// DataStructures and Algorithms @ Borough of Manhattan Community College &
// Pace University
// This program's usage is to create a simple Data Structure known as a linked list
// that will allow users to allocate memory (using pointers) to create an efficient 
// way of storing DATA using minimum CPU processing, minimum RAM usage and minimum Storage usage.   


#include <iostream>
using namespace std;

// template<class T> is used to create an abstract data-type(ADT) 
// this allows users to ctreate a list with any data-type 
// used is c++ or user defined classes

template <class T> struct Node {
  T value;
  Node<T> *next;
};

template <class t> 
class Linklist {
public:
  Node<t> *head;

public:
  
  // default constructor
Linklist() { head = NULL; }
// Overloaded Constructor 
// user defines initial value in the list upon creation
  Linklist(t item) {
    Node<t> *node = new Node<t>;
    node->value = item;
    head = node;
    node->next = NULL;
  }

  // Destructor used to destroy 
  // the memory allocation of the list
  ~Linklist() {
    while (head != NULL) {
      Node<t> *tmp = head;
      head = head->next;
      delete tmp;
    }

  } // linklist destructor end

// size member function gets the size of the list
  int size() const {
    int count = 0;
    Node<t> *tmp = head;
    while (tmp != NULL) {
      count++;
      tmp = tmp->next;
    }
    return count;
  } // size function end

  // if the head of the list is empty, return true

  bool isEmpty() const { return head == NULL; }

// first node is the head of the list
  Node<t> *firstNode() const { return head; }
// Gives the last node in the linked list
  Node<t> *lastNode() const {
    if (head == NULL) {
      return NULL;
    }
    // if the address of tmp->next is = to NULL then you have reached the end of
    // the list therefore the Node tmp object would point to the last Node in
    // the list

    Node<t> *tmp = head;
    while (tmp->next != NULL) {
      tmp = tmp->next;
    }
    return tmp;
  } // end of function lastNode

  
// Enter the position ypu would like to search for 
// to get the node
  Node<t> *getNode(int pos) const {
    if (pos < 0 || head == NULL) {
      return NULL;
    }
    int i = 0;
    Node<t> *tmp = head;
    while (tmp->next != NULL && i < pos) {
      tmp = tmp->next;
      i++;
    }
    return tmp;
  } // end of getNode
// find the node in the list with the same value in the 
// the argument
  Node<t> *findNode(t val) const {
    Node<t> *tmp = head;
    while (tmp != NULL) {
      if (tmp->value == val) {
        return tmp;
      }
      tmp = tmp->next;
    }
    return NULL;
  }

// Get the value given the position
  t getvalue(int pos) {
    Node<t> *node = getNode(pos);
    if (node != NULL) {
      return node->value;
    } else {
      cout << "Value does not exist" << endl;
    }

  } // end getvalue

  // Sets the value given the position
  void setvalue(int pos, t val) {
    Node<t> *node = getNode(pos);
    if (node != NULL) {
      node->value = val;
    } else {
      cout << "position does not exist" << endl;
    }
  }
// inserts the value given the position
  void insert(int pos, t val) {
    Node<t> *node = new Node<t>;
    node->value = val;

    if (pos < 0 || head == NULL) {
      node->next = head;
      head = node;
    }

    int i = 0;
    Node<t> *tmp = head;
    while (tmp->next != NULL && i < pos - 1) {
      tmp = tmp->next;
      i++;
    }

    node->next = tmp->next;
    tmp->next = node;
    cout << "node inserted" << endl;
  } // end insert

void push(t val){
    this->insert(this->size(),val);
  }
 
// Removes the whole node given the position
  t remove(int pos) {
    if (pos < 0 || head == NULL) {
      cout << "position does not exist" << endl;
    }

    if (pos == 0) {
      Node<t> *tmp = head;
      head = head->next;

      t value = tmp->value;
      delete tmp;
      return value;
    }
    int i = 0;
    Node<t> *tmp = head;
    while (tmp->next != NULL && i < (pos - 1)) {
      tmp = tmp->next;
      i++;
    }

    if (tmp != NULL) {
      Node<t> *node = tmp->next;
      if (node == NULL) {
        cout << "end of list" << endl;
      } else {
        tmp->next = node->next;
        t value = node->value;
        delete node;
        return value;
      }
    } else {
      cout << "error";
      return 0;
    }

  } // end remove

// Prints the contents of the list 
  void print() {
    Node<t> *tmp = head;
    while (tmp != NULL) {
      cout << tmp->value << " ";

      tmp = tmp->next;
    }
  }

}; // Linklist class end

int main() {
  Linklist<string> list("I");
  list.insert(1,"like");
  list.insert(2, "vanilla");
  list.insert(3, "ice");
  list.insert(4, "cream");
  list.push("and");
  list.push("Coding");
  cout << endl << "Here is the size of the string list: " << list.size() << endl;
  cout << "string list contents: ";
   list.print();
  cout << endl;
  list.setvalue(2, "Chocolate");
  cout << "Removed 1 item string list new contents: ";
  list.print();
  cout << endl;
  if (list.isEmpty())
  {cout << endl << "True or False list is empty?  true" << endl;}
  else {cout<< endl << "True or False list is empty? false" << endl;}
  cout << endl << "Get Value: "<< list.getvalue(2) << endl;
  cout << "First node content: "<<list.firstNode()->value << endl;
  cout << "Last node content: "<<list.lastNode()->value << endl;
  cout << "Get node content: "<<list.getNode(4)->value << endl;
  cout << "Find node address: "<<list.findNode("ice") << endl;


  return 0;
}