#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define READ 0
#define WRITE 1

int main(){
  char in[1000];
  
  int fds0[2];
  pipe(fds0);
  
  int fds1[2];
  pipe(fds1);
  
  
  int f = fork();
  if(f){
    close(fds0[READ]);
    close(fds1[WRITE]);
    
    printf("I am the parent. Please provide an input: \n");
    fgets(in, 1000, sizeof(in);
  }
  
}
