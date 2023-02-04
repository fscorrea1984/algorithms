#include<iostream>
//#include<algorithm> we'll uncoment this when needed. or remove the line if no need arise up to the end.
//#include<array> for now a vector of vector will implement the nxn matrix.
#include<sstream>
#include<string>
//#include<tuple> just in case we decided to use tuple instead of pair
#include<utility>
#include<vector>

using namespace std;

int limit_it;
int limit_best;
int N;
int count = 0;
int it = 0;
bool flag = false;
vector<int> *r;
vector<int> *d;

int main(int argc,char **argv) {

  /** --- **/

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

  //randomize vectors r and d

  random_device gen;
  mt1337 mt(gen());
  shuffle(r.begin(),r.end(),mt);
  shuffle(d.begin(),d.end(),mt);

  //create solution and tabu objects

  Solution solution(N);
  Tabu tabu(N);

  while(count < limit_best || it < limit_it || !flag) {
    tabu.N();
    count++;
    it++
  }
  
  return 0;
  
}
