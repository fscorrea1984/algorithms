#include<iostream>
#include<limits>
#include<utility>
#include<vector>

using namespace std;

const int inf = std::numeric_limits<int>::max();
const int neg_inf = std::numeric_limits<int>::min();

class Tabu;

class Solution {

  friend class Tabu;

  vector<int> *s;

  vector<int> *best;

 public:
  Solution(int);
  ~Solution();
  int check_s(void);
  int ILmax;
  int fbest;
  int nn;
  
};

class Tabu {

  friend class Solution;

  vector<vector<int> *> *L;
  vector<Pair <Pair <int,int> , int >> top(5);
  vector<int> sol;

 public:
  Tabu(int);
  ~Tabu();
  void N(void);
  int F(vector<int> *);
  int Lmax;
  int nn;
  
};
