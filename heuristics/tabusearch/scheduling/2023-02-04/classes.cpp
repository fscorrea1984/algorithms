#include<iostream>
#include<algorithm>
#include<random>
#include<utility>
#include<vector>
#include"classes.h"

using namespace std;

Solution::Solution(int n) {

  nn = n;
  ILmax = 0;
  
  s = new vector<int>[n];
  
  for(int i = 1; i <= n; i++)
    s.at(i-1) = i;
  
  random_device gen;
  mt1337 mt(gen());
  shuffle(s.begin(),s.end(),mt);
  
  while((fbest = check_s()) == -1)
    shuffle(s.begin(),s.end(),mt);

  best = new vector<int>[n];
  for(vector<int>::iterator it = best.begin(); it != best.end(); ++it)
    for(vector<int>::iterator sit = s.begin(); sit != s.end(); ++sit)
      *it = *sit;  
  
}

Solution::~Solution() {
  
  delete[] best;
  delete[] s;
  
}

int Solution::check_s() {

  int t = 1;
  
  for(vector<int>::iterator::it = s.begin(); it != s.end(); ++it) {
    if(r.at(*it - 1) > t) {
      cerr << "This tentative solution is not feasible" << endl;
      return(-1);
    }
    else
      t++;
  }

    t = 1;

    for(vector<int>::iterator::it = s.begin(); it != s.end(); ++it) {
      if(d.at(*it - 1) < t) {
	ILmax += t - d.at(*vit - 1);
	t++;
      }
    }
    
    return(inf - ILmax);
    
}

Tabu::Tabu(int n) {

  nn = n;

  L = new vector< vector<int> * >[n];
  
  for(int i = 0; i < n; i++)
    L[i] = new vector<int>[n];

  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      L[i][j] = neg_inf;

  sol = new vector<int>[n];
  
}

Tabu::~Tabu() {

  for(int i = 0; i < nn; i++)
    delete[] L.at(i);

  delete[] L;
  
}

void Tabu::N() {

  int a = 1;
  int b = 2;
  int ia,ib;
  vector<int> ss = *(solution.s);
  vector<int> T(5,0);

  for(i = 1; i < n-1; i++)
    for(int j = i + 1; j < n; j++) {
      for(int k = 0; k < n; k++)
	*sol[k] = ss[k];

      if(sol[i - 1] == a)
	ia = i -1;
      if(sol[i - 1] == b)
	ib = i - 1;
      L[i-1][j-1] = 0;
      swap(*sol[ia],*sol.[ib]);	

      int tmp = F(sol);
      if(tmp == inf) {
	flag = true;
	return;
      }
      int inc = tmp - F(solution->s);
      Pair<int,int> p(ia,ib);
      for(int k = 0; k < 5; k++) {
	top[k].first = make_pair(-1,-1);
	top[k].second = neg_inf;
      }
      int l  = 4
	while(inc > (top.[l].second) && l >= 0) {
	  if(l < 4)
	    top.at(l+1) = top.at(l);
	  (top[l]).first = p;
	  (top[l]).second = inc;
	  l--;
	}
    }

  for(int i = 0; i < 5; i++) {
    if(T[i] == 0) {
      ia = top[i].first.first;
      ib = top[i].first.second;
      swap(*sol[ia],*sol.[ib]);
      T[i] = 3;
      if(F(sol) > solution.fbest) {
	solution.fbest = f(sol);
	solution->s = sol;
	count = 0;
      }
    }
    else {
      if(F(sol) > solution.fbest) {
	solution.fbest = f(sol);
	solution->s = sol;
	count = 0;
      }
      else {
	if(i == 4){
	  T.push_back(0);
	  Pair<int,int> pp(-1,-1);
	  top.push_back(pp,neg_inf);
	}
      }
    }
  }

}

int Tabu::F(vector<int> *V) {

  vector<int> v = *V;
  int t = 1;

  for(vector<int>::iterator::vit = v.begin(); vit != v.end(); ++vit) {
    if(r.at(*vit - 1) > t) {
      cerr << "This tentative solution is not feasible" << endl;
      return(-1);
    }
    else
      t++;
  }

  t = 1;

  for(vector<int>::iterator::vit = v.begin(); vit != v.end(); ++vit) {
    if(d.at(*vit - 1) < t) {
      Lmax += t - d.at(*vit - 1);
      t++;
    }
  }

  return(inf - Lmax);
  
}
