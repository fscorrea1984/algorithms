#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int main(int argc, char **argv) {
  int p, q, r;
  
  srand(time(NULL));
  
  int A[] = { ((rand()%10)+1), ((rand()%10)+1), ((rand()%10)+1), ((rand()%10)+1), ((rand()%10)+1), ((rand()%10)+1), ((rand()%10)+1), ((rand()%10)+1),
	  ((rand()%10)+1), ((rand()%10)+1), ((rand()%10)+1), ((rand()%10)+1), ((rand()%10)+1), ((rand()%10)+1), ((rand()%10)+1), ((rand()%10)+1),
	  2, 4, 6, 7, 1, 2, 3, 5,
	  ((rand()%10)+1), ((rand()%10)+1), ((rand()%10)+1), ((rand()%10)+1), ((rand()%10)+1), ((rand()%10)+1), ((rand()%10)+1), ((rand()%10)+1) };
  
  for(int i = 0; i < 4; i++)
    for(int j = 0; j < 8; j++) {
      printf("%d", A[(i*8)+j]);
      int c = (j == 7) ? '\x0A' : '\x20';
      fputc(c,stdout);
    }

  return 0;
  
}
