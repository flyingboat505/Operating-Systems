#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>
//This code creates 12 child processes with the restriction that a process 
//can only create 2-3 processes only. 
//For more details, please refer to 2) of the README FILE.
int main(int argc, char *argv[]){
	int depth=0;
	int status;
	int created=0;
	while(1){
		if(fork()==0){
			printf("I am the child MY PID is =%d. My Parent's ID is=%d\n",(int)getpid(),(int) getppid());
			depth++; //depth increases for each child
			created=0;
			if(depth==2) break;//once depth hits 2, end
		}
		else{
			waitpid(-1,&status,0);
			created++;  //if parent hits 3 for created, we stop producing
			if(created==3) break;
		}
	}	
}

