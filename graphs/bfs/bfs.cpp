#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<limits>
#include<queue>
#include<vector>

using namespace std;

const int inf = std::numeric_limits<int>::max();

class Adj {

public:

  int v;
  Adj *next;

  Adj(int x) : v(x) {
    next = nullptr;

  }
  ~Adj() {}
  
};

class Node {

public:

  char color;
  int n;
  int d;
  int pi;

  Node() { //constructor
    color = 'w';
    n = 0;
    d = 0;
    pi = -1;
  }
  Node(char c, int x, int y, int z) : color(c), n(x), d(y), pi(z) {} //constructor
  ~Node () {}
  Node(const Node& node) { //copy constructor
    color = node.color;
    n = node.n;
    d = node.d;
    pi = node.pi;
  }  
  Node operator=(const Node& node) { //copy assignment
    if(this != &node) {
      color = node.color;
      n = node.n;
      d = node.d;
      pi = node.pi;
    }
    return(*this);
  }

};

int main(int argc, char **argv) {

  // begin input pre-processing
  
  string line;
  ifstream ifile;

  ifile.open("input.file",ifstream::in);

  int N, M;

  for(int i = 0; i < 1; i++) {
    getline(ifile,line);
    stringstream arc(line);
    arc >> N >> M;
  }

  vector<string> gifts(N,"");
  
  for(int i = 0; i < 1; i++) {
    getline(ifile,line);
    for(int j = 0; j < N; j++) {
      stringstream arc(line);
      arc >> gifts[j];
    }
  }

  vector<Adj *> adj_list(N,nullptr);
  vector<Adj *> last_adj(N,nullptr);
  
  for(int i = 0; i < N; i++) {
    getline(ifile,line);
    stringstream arc(line);
    int a, b;
    arc >> a >> b;
    --a;
    --b;
    if(adj_list[a] == nullptr) {
      adj_list[a] = new Adj(b);
      last_adj[a] = adj_list[a];
    }
    else {
      last_adj[a]->next = new Adj(b);
      last_adj[a] = last_adj[a]->next;
    }
    if(adj_list[b] == nullptr){
      adj_list[b] = new Adj(a);
      last_adj[b] = adj_list[b];
    }
    else {
	last_adj[b]->next = new Adj(a);
	last_adj[b] = last_adj[b]->next;
      }
    //  last_adj[a]->inv = last_adj[b];
    //  last_adj[b]->inv = last_adj[a];
  }

  ifile.close();

  // end input pre-processing
  
  // BFS

  //vector<Pair<bool,bool>> visited(N,false);
  string str(argv[1]);
  
  int s = stoi(argv[1],nullptr,10);
  --s;

  vector<Node> nodes(N);
  
  for(int i = 0; i < N; i++)
    if(i == s)
      nodes[s] = {'g',i,0,-1};
    else
      nodes[i] = {'w',i,0,-1};      

    queue<int> Q;

    Q.push(nodes[s].n);

    while(!Q.empty()) {
      int u = Q.front();
      Q.pop();
      Adj *current = adj_list[u];
      while(current != nullptr) {
	int v = current->v;
	if(nodes[v].color == 'w') {
	  nodes[v].color = 'g';
	  nodes[v].d = (nodes[u].d)+1;
	  nodes[v].pi = nodes[u].n;
	  Q.push(nodes[v].n);
	}
	current = current->next;
      }
      nodes[u].color = 'b';  
    }

  // test

  for(int i = 0; i < N; i++)
    cout << "| " << i << " | " << nodes[i].color << " | " << nodes[i].d << " | " << nodes[i].pi << " |" << endl;

  return 0;
  
}
