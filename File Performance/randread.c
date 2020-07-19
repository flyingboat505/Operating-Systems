#include <stdio.h> 
#include <string.h>i
//This function will Sequentionally go through the the file, 1 bit at a time using Fgets
//argc counts the number of parameters in file 
int main(int argc,char *argv[]){
	char buffer[1];
	long long count=0;
	long long randnumber;
	int temp;
	double perc;
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
	
	fseek(fp, 0, SEEK_END)
	long filesize= ftell(fp);
	fseek(fp, 0, SEEK_SET);//Seek to the beginning of the file
		
	while(count<filesize) {
	// randnumber=(randnumber<<32) |rand();    //generate a random 64 bit .
	  
	  while(1){
	    randnumber=rand(); 
	    randnumber=(randnumber<<32) | rand();
	    temp=fseek(fp, randnumber, SEEK_SET);
	    if(temp==0){
	      break;    
	    }
	    
	  };  
	  fread(buffer,1,1, fp); 
	  count++;
	  
	  if(count%1000==0){
	    perc=(count*1.0/filesize *1.0   )*100;
	    printf("Percent Complete is %f \r",perc) ;
	  }  
	  
	}; 
	
	fclose(fp);
	return(0);
}
	
