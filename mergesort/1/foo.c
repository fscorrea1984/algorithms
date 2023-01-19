#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

void merge(int A[], int p, int q, int r) {

  int nL = (q - p) + 1; // length of A[p : q]
  int nR = r - q; // length of A[q+1 : r]

  int L[nL];
  int R[nR];

  for(int i = 0; i < nL; i++)
    L[i] = A[p + i];

  for(int j = 0; j < nR; j++)
    R[j] = A[(q + 1) + j];

  int i = 0;
  int j = 0;
  int k = p;

  while(i < nL && j < nR) {
    if(L[i] <= R[j]) {
      A[k] = L[i];
      i++;
    }
    else {
      A[k] = R[j];
      j++;
    }
    k++;
  }

  while(i < nL) {
    A[k] = L[i];
    i++;
    k++;
  }

  while(j < nR) {
    A[k] = R[j];
    j++;
    k++;
  }
  
}

void mergesort(int A[], int p, int r) {
  if(p >= r)
    return;
  int q = floor((p + r)/2);
  mergesort(A,p,q);
  mergesort(A,q+1,r);
  merge(A,p,q,r); // merge A[p : q] and A[q + 1 : r] into A[p : r]
}

int main(int argc, char **argv) {
  int p, r;
  time_t t;
  
  srand(time(&t));
  
  int A[] = { ((rand()%10)+1), ((rand()%10)+1), ((rand()%10)+1), ((rand()%10)+1), ((rand()%10)+1), ((rand()%10)+1), ((rand()%10)+1), ((rand()%10)+1),
	  ((rand()%10)+1), ((rand()%10)+1), ((rand()%10)+1), ((rand()%10)+1), ((rand()%10)+1), ((rand()%10)+1), ((rand()%10)+1), ((rand()%10)+1),
	  2, 4, 6, 7, 1, 2, 3, 5,
	  ((rand()%10)+1), ((rand()%10)+1), ((rand()%10)+1), ((rand()%10)+1), ((rand()%10)+1), ((rand()%10)+1), ((rand()%10)+1), ((rand()%10)+1) };

  p = 0;
  r = 31;
  
  for(int i = 0; i < 4; i++)
    for(int j = 0; j < 8; j++) {
      printf("%d", A[(i*8)+j]);
      int c = (j == 7) ? '\x0A' : '\x20';
      fputc(c,stdout);
    }

  mergesort(&A[0],p,r);

  for(int i = 0; i < 4; i++)
    for(int j = 0; j < 8; j++) {
      printf("%d", A[(i*8)+j]);
      int c = (j == 7) ? '\x0A' : '\x20';
      fputc(c,stdout);
    }
  
  return 0;
  
}
