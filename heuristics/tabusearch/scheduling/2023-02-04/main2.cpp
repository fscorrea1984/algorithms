#include<iostream>
#include<sstream>
#include<string>
#include<utility>
#include<vector>
#include"classes.h"

using namespace std;

int limit_it;
int limit_best;
int N;
int count = 0;
int it = 0;

vector<int> *r;
vector<int> *d;

int main(int argc,char **argv) {

  string line = " ", dummy;

  getline(cin,line);
  stringstream limitstr(line);
  limitstr >> limit_it >> limit_best;

  getline(cin,line);
  stringstream nstr(line);
  nstr >> N;

  r = new vector<int>[N];
  d = new vector<int>[N];

  for(int i = 1; i <= N; i++) {
    getline(cin,line);
    stringstream jstr(line);
    int a, b;
    jstr >> dummy >>  a >> b;
    r[i-1] = a;
    d[i-1] = b;
  }

  random_device gen;
  mt1337 mt(gen());
  shuffle(r.begin(),r.end(),mt);
  shuffle(d.begin(),d.end(),mt);

  Solution solution(N);
  Tabu tabu(N);

  while(count < limit_best || it < limit_it) {
    tabu.N();
    count++;
    it++;
  }
  
  return 0;
  
}
