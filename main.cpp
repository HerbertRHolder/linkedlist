#include <iostream>
using namespace std;

template <class T> 
struct Node {
  T Value;
  Node <T> *next;
};

template <class t> 
class Linklist {
private:
  Node <t> *head;

public:
template <t>
  Linklist() { head = NULL; }
   
  ~Linklist() {
    while (head != NULL) {
      Node <t> *tmp = head;
      head = head->next;
      delete tmp;
    }

  } // linklist destructor end
template <t>
  int size() const {
    int count = 0;
    Node <t> *tmp = head;
    while (tmp != NULL) {
      count++;
      tmp = tmp->next;
    }
    return count;
  } // size function end

  // if the head of the list is empty, return true
template <t>
  bool isEmpty() const { return head == NULL; }

template <t>
  Node <t> *firstNode() const { return head; }

template <t>
  Node <t> *lastNode() const {
    if (head == NULL) {
      return NULL;
    }
    // if the address of tmp->next is = to NULL then you have reached the end of
    // the list therefore the Node tmp object would point to the last Node in
    // the list
    
    Node <t> *tmp = head;
    while (tmp->next != NULL) {
      tmp = tmp->next;
    }
    return tmp;
  } // end of function lastNode

}; // Linklist class end

int main() {



  return 0;
}