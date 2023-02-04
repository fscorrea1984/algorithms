#include<iostream>
#include<vector>

using namespace std;

const int nkeys = 128;

class Node {
  int key;
  int data;
};

class Table {
  vector<Node *> T(nkeys,nullptr);
public:
  Table() {};
  ~Table() {};

  void insert(Node *x) {
    T[x->key] = x;
  }
  void tableDelete(Node *x) {
    T[x->key] = nullptr;
  }
  Node *search(int k) {
    return(T[k]);
  }
  
};

int main(int argc, char **argv) {

  /* --- */
  
  return 0;
}
