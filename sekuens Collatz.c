#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
  int n=0;
  int m=0;
  pid_t pid;
  while(m<=0){
    printf("Masukkan angka yang lebih dari 0\n"); 
    scanf("%d", &m);	
  }
  pid = fork();
  if (pid == 0){
    printf("Proses Child sedang berjalan...\n");
    printf("%d ",m);
    while(m!=1){
      if (m%2 == 0) m=m/2;
      else if (m%2 == 1) m= 3*(m)+1;
      printf("%d ",m);
    }
    printf("\n");
    printf("Proses Child selesai\n");
  }
  else{
    printf("Parents menunggu proses Child...\n");
    wait(NULL);
    printf("Proses Parent selesai\n");
  }
  return 0; 
}
