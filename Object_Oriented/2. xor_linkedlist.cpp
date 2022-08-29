#include <iostream>
using namespace std;

struct Node {
  int data;
  Node *next = NULL;   //double
};

class XorLinkedList {
  int length;
  Node *head;
  Node *tail;
public:
  XorLinkedList(): length(0) {head = NULL; tail = NULL;}
  Node* XOR(Node *a, Node *b) {
    return (Node*)((unsigned  long long)a ^ (unsigned  long long)b);
  }
  
  void insert(int d, bool is_front) {
    Node *t = new Node;
    t->data = d;
    if (length == 0) head = tail = t;
    else {
      if (is_front) {
        t->next = head;
        head->next = XOR(t, head->next);
        head = t;
      } else{
        t->next = tail;
        tail->next = XOR(t, tail->next);
        tail = t;
      }
    }
    length++;
  }
  void display() {
    Node* current = head;
    Node *prev = NULL, *n;
    for (int i = 0; i < length; ++i) {
      cout << current->data << " ";
      n = XOR(current->next, prev);
      prev = current;
      current = n;
    }
    cout << endl;
  }
};

int main() {
  XorLinkedList xl;
  xl.insert(1, true);
  xl.insert(2, false);
  xl.insert(3, false);
  xl.insert(4, false);
  xl.insert(5, false);
  xl.insert(0, true);
  xl.display();
  return 0;
}
