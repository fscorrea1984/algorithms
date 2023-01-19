#include<stdio.h>
#include<stdlib.h>

void insertionsort(int A[], int n) {
  for(int i = 1; i < n; i++) {
    int key = A[i];
    int j = i-1;
    while(j >= 0 && A[j] > key) {
      A[j+1] = A[j];
      j--;
      A[j+1] = key;
    }
  }
}

int main(int argc, char **argv) {
  int n = 6, a[] = { 5, 2, 4, 6, 1, 3 };
  int *pa = a;
  insertionsort(pa, n);
  fputs("{",stdout);
  for(int i = 0; i < n-1; i++)
    printf(" %d,", a[i]);
  printf(" %d }\n", a[n-1]);
  return 0;
}
