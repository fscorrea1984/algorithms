#include<iostream>

using namespace std;

class Node {

  Node *next;
  Node *prev;
  int key;

public:
  Node *nil;
  Node() {
    next = this;
    prev = this;
  }
  Node(int k) {
    key = k;
    next = this;
    prev = this;
  }
  
  ~Node() {};

  void listDelete(Node *x) {
    x->prev->next = x->next;
    x->next->prev = x->prev;
  }
  
  void insert(Node *x,Node *y) {
    x->next = y->next;
    x->prev = y;
    y->next->prev = x;
    y->next = x;
  }
  
  Node *search(Node *L,int k) {
    L->nil->key = k;
    Node *x = L->nil->next;
    while(x->key != k)
      x = x->next;
    if(x == L->nil)
      return(nullptr);
    else
      return(x);
  }

  void printlist(Node *L) {
    Node *x = L->nil->next;
    while(x != L->nil) {
      cout << x->key << " ";
      x = x->next;
    }
    cout << endl;
  }

};

int main(int argc, char **argv) {

  /* --- */

  Node *L = new Node();
  L->nil = new Node();
  Node *x;
  Node *y;

  x = new Node(1);
  L->insert(x,L->nil);

  x = new Node(4);
  L->insert(x,L->nil);

  x = new Node(16);
  L->insert(x,L->nil);

  x = new Node(9);
  L->insert(x,L->nil);

  L->printlist(L);

  x = new Node(25);
  L->insert(x,L->nil);

  L->printlist(L);

  x = L->search(L,1);
  L->listDelete(x);
  delete(x);

  L->printlist(L);

  x = new Node(36);
  y = L->search(L,9);
  L->insert(x,y);

  L->printlist(L);
  
  delete(L);
  
  return 0;

}
