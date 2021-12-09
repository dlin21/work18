#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define READ 0
#define WRITE 1

void reverse(char *str);

int main(){
  int fds0[2];
  pipe(fds0);
  int fds1[2];
  pipe(fds1);
  
  int f = fork();

  if(f){
    close(fds0[READ]);
    close(fds1[WRITE]);

    while(1){
      printf("input: \n");
      char buffer[100];
      
      fgets(buffer, sizeof(buffer), stdin);
      write(fds0[WRITE], buffer, sizeof(buffer));

      char out[100];
      read(fds1[READ], out, sizeof(out));
      printf("processed input: %s\n\n", out);
    }
  }

  else{
    close(fds0[WRITE]);
    close(fds1[READ]);

    char in_buff[100];
    while(read(fds0[READ], in_buff, sizeof(in_buff))) {
      reverse(in_buff);
      write(fds1[WRITE], in_buff, sizeof(in_buff));
    }
  }
  return 0;
}

void reverse(char *str){
  int len = strlen(str);
  int i, temp;
  for(i=0; i<len/2; i++){
    temp = str[len-i-1];
    str[len-i-1] = str[i];
    str[i] = temp;
  }
}
