#include <iostream>
#define ALPHABET_SIZE 26
using namespace std;

struct Node {
  Node *children[ALPHABET_SIZE];
  bool isEnd=false;   //if word end be true
};

class Trie{
  Node *root;
public:
  Node *getNode(void) {
    Node *t = new Node;
    for (int i = 0; i < ALPHABET_SIZE; ++i)
      t->children[i] = NULL;
    return t;
  }
  Trie() {root = getNode();}
  void insert(string key) {
    Node *t = root;
    for (int i = 0; i < key.length(); ++i) {
      int index = key[i] - 'a';
      if (t->children[index] == NULL)
        t->children[index] = getNode();
      t = t->children[index];
    }
    t->isEnd = true;
  }
  bool search(string key) {
    Node *t = root;
    for (int i = 0; i < key.length(); ++i) {
      int index = key[i] - 'a';
      if (t->children[index] == NULL) return false;
      t = t->children[index];
    }
    return t->isEnd;
  }
};

int main() {
  Trie T;
  T.insert("the");
  cout << boolalpha << T.search("the") << endl;
  cout << T.search("then");
  return 0;
}
