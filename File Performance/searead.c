#include <stdio.h> 
#include <string.h>
//this function randomly goes through the bits in the file using randomly generating values using Fseek
//argc counts the number of parameters in file 
int main(int argc,char *argv[]){
    //char buffer[1000];
	
	if(argc==1){
		printf("No file found");
		return 0;
	}
	//creating a file pointer fp 
	FILE *fp;
	fp=fopen(argv[1],"r"); //opening file and having fp pointing to it.
	if(fp==NULL){
		printf("File does not exit");
		return 0;
	}
	fseek(fp, 0, SEEK_SET);//Seek to the beginning of the file
	//while( fread(buffer, 1, 1, fp) !=0);
	while( fgetc(fp)!=EOF);
	fclose(fp);
	return(0);
}
	
