#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>

//this program produces 8 child processes.See the READ ME File for more details. 
//take input from the user and executes it until they type "exit"
int main(int argc, char *argv[]){
	int i;
	int ID;
	for(i=0;i<8;++i){
		if(fork()==0){
			printf("I am the child  MY PID is =%d . My Parent's ID id=%d\n",(int) getpid(), (int) getppid());
		}
		else{ //if parent, wait for child to go and then stop producing. 
			int status;
			waitpid(-1,&status,0);
			break;
		}
    }   
	//sleep(1);
	//printf("After sleep MY PID= %d\n", (int) getpid() );


	return 0;
}
