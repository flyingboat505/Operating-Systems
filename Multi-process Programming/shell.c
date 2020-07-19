#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>

//take input from the user and executes it until they type "exit"
int main(int argc, char *argv[]){
	char str[20];
	char ext[]="exit";
	while( fgets(str,20,stdin)  ){ //fgets takes the input from stdin and stores it into string str
		str[strlen(str)-1]=0;//In C, I need a null character in order to compelte the string
		printf("%s",str);
		if (strcmp(str,ext)==0) {
			break;
		}
		if(fork() ==0) {
         //child code
			execve(str,NULL,0);//fact, NULL is the same as 0
			break;
		}
		else{
			//parent code
			int status;
			waitpid(-1,&status,0);
		}


	}
	return 0;
}
