#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>

//this code creates 17 child process with the restriction that a child process,which creates other processes,have to create 2-3 processes.
int main(int argc, char *argv[]){
	int depth=0; //keeps track of depth. Depth 0 is where the parent is at and it increments for each child process created 
	int created=0; //keeps track how many are created
	int LeftSubTree=1;//keeps track if the process creation is in the left sub tree or not, 
	int status;
	while(1){
		if(fork()==0){
			created=0;
			depth++;
			printf("I am the child MY PID is=%d. My Parent's Id Is=%d \n",(int)getpid(), (int)getppid());
			if(LeftSubTree==1 && depth==2){ 
				break;
			}
			if(LeftSubTree==0 && depth==3){
				break;
			}
		}
		else{
			waitpid(-1,&status,0);
			created++;
			if(depth==0){
			   	LeftSubTree=0;	
			}
			if(depth==0 && created==2){
				break;
			}
			else if(created==3){
				break;
			}
	 	}
	}	
}
