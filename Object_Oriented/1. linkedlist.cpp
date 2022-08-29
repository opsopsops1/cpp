#include <iostream>
using namespace std;

struct Node{
  int data;
  Node* next = NULL;
};

class LinkedList{
  int length;
  Node* head;
public:
  LinkedList():length(0) {head = NULL;}
  
  void print_list() {
    if (length == 0) {
      cout << "List is empty" << endl;
      return;
    }
    Node* current = head;
    while (current != NULL) {
      cout << current->data << " ";
      current = current->next;
    }
    cout << endl;
  }
  push_front(int d) {
    Node* t = new Node;
    t->data = d;
    t->next = head;
    head = t;
    length++;
  }
  push_back(int d) {
    Node* t = new Node;
    t->data = d;
    if (length == 0) {
      head = t;
    } else {
      Node* current = head;
      while (current->next != NULL) {
        current = current->next;
      }
      current->next = t;
    }
    length++;
  }
};

int main() {
  LinkedList ll;
  
  ll.push_back(5);
  ll.push_back(6);
  ll.push_front(4);
  ll.print_list();
  return 0;
}
