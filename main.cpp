#include <iostream>
using namespace std;

template <class T> struct Node {
  T value;
  Node<T> *next;
};

template <class t> 
class Linklist {
public:
  Node<t> *head;

public:
  
Linklist() { head = NULL; }
  Linklist(t item) {
    Node<t> *node = new Node<t>;
    node->value = item;
    head = node;
    node->next = NULL;
  }

  ~Linklist() {
    while (head != NULL) {
      Node<t> *tmp = head;
      head = head->next;
      delete tmp;
    }

  } // linklist destructor end

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

  Node<t> *firstNode() const { return head; }

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

  Node<t> *findNode(t e) const {
    Node<t> *tmp = head;
    while (tmp != NULL) {
      if (tmp->value == e) {
        return tmp;
      }
      tmp = tmp->next;
    }
    return NULL;
  }

  t getvalue(int pos) {
    Node<t> *node = getNode(pos);
    if (node != NULL) {
      return node->value;
    } else {
      cout << "Value does not exist" << endl;
    }

  } // end getvalue

  void setvalue(int pos, t e) {
    Node<t> *node = getNode(pos);
    if (node != NULL) {
      node->value = e;
    } else {
      cout << "position does not exist" << endl;
    }
  }

  void insert(int pos, t e) {
    Node<t> *node = new Node<t>;
    node->value = e;

    if (pos < 0 || head == NULL) {
      node->next = head;
      head = node;
      // return 0;
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
    // return i + 1;

  } // end insert

  // void push(t val){
  //    Node <t> *node = new Node<t>;
  //   node = head;
  //   if(head->next == NULL)
  //   {
  //     Node <t> *tmp = head;
  //     tmp->value = val;
  //     head->next = tmp;
  //     node = tmp;
  //     node->value = tmp->value;
  //   }
  //   Node <t> *tmp;
  //   tmp = head;
  //   head->next = tmp;
  //   while(tmp != NULL){
  //     tmp = tmp->next;
  //   }
  //     node = tmp;
  // }

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

  void print(Linklist<t> &l) {
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
  // list.remove(1);

  //   if (list.isEmpty()){
  // cout << endl << "true";
  //   }else {cout<< endl << "false";}
  // list.setvalue(2, "chocolate");

  list.print(list);
  // cout << endl << list.getvalue(2) << endl;

  return 0;
}