#include<iostream>

using namespace std;

class Node {

  Node *head;
  Node *next;
  Node *prev;
  int key;

public:
  Node() { head = nullptr; }
  Node(int k) { key = k; }
  
  ~Node() {
    Node *x = head;
    Node *y;
    while(x != nullptr) {
      y = x;
      x = x->next;
    delete(y);
    }
  }
  
  Node *search(Node *L,int k) {
    Node *x = L->head;
    while(x != nullptr && x->key != k)
      x = x->next;
    return(x);
  }
  
  void prepend(Node *L,Node *x) {
    x->next = L->head;
    x->prev = nullptr;
    if(L->head != nullptr)
      L->head->prev = x;
    L->head = x;
  }
  
  void insert(Node *x,Node *y) {
    x->next = y->next;
    x->prev = y;
    if(y->next != nullptr)
      y->next->prev = x;
    y->next = x;
  }
  
  void listDelete(Node *L,Node *x) {
    if(x->prev != nullptr)
      x->prev->next = x->next;
    else
      L->head = x->next;
    if(x->next != nullptr)
      x->next->prev = x->prev;
  }

  void printlist(Node *L) {
    Node *x = L->head;
    while(x != nullptr) {
      cout << x->key << " ";
      x = x->next;
    }
    cout << endl;
  }

};

int main(int argc, char **argv) {

  /* --- */

  Node *L = new Node();
  Node *x;
  Node *y;

  x = new Node(1);
  L->prepend(L,x);

  x = new Node(4);
  L->prepend(L,x);

  x = new Node(16);
  L->prepend(L,x);

  x = new Node(9);
  L->prepend(L,x);

  L->printlist(L);

  x = new Node(25);
  L->prepend(L,x);

  L->printlist(L);

  x = new Node(36);
  y = L->search(L,9);
  L->insert(x,y);

  L->printlist(L);

  x = L->search(L,4);
  L->listDelete(L,x);
  delete(x);

  L->printlist(L);

  delete(L);
  
  return 0;

}
