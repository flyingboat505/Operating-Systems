#include <stdio.h>
#include <stdlib.h>

int parseArguments(int argc, char *argv[]) {
    int tableSize;
    if(argc == 2 && (tableSize = atoi(argv[1]))) {
        return tableSize;
    }
    fprintf(stderr, "Wrong arguments. Pass tableSize as an argument\n");
    exit(-1);
}

int isInMemory(int pageRequest, int *pageTable, int tableSize) {
    int i;
    for(i = 0; i < tableSize; i++) {
        if(pageRequest == pageTable[i]) {
            return 1;
        }
    }
    return 0;
}

int findIndex(int pageRequest, int *pageTable, int tableSize) {
    int i;
    for(i = 0; i < tableSize; i++) {
        if(pageRequest == pageTable[i]) {
			return i;
        }
    }
    return 0;
}

int main(int argc, char *argv[]) {
    int tableSize = parseArguments(argc, argv);    
    int pageRequest, pageTableIndex = 0, numRequest = 0, numMisses = 0,headIndex=0,flag=1,index,x;
    int *pageTable = (int *) malloc(sizeof(int)*tableSize);
    int *chanceTable = (int *) malloc(sizeof(int)*tableSize);
    
    char *input = NULL;
    size_t inputAllocated = 0;
    ssize_t bytesRead;
    
    while((bytesRead = getline(&input, &inputAllocated, stdin)) != -1) {
        pageRequest = atoi(input);
        if(pageRequest == 0) {
			continue;
        }
        numRequest++;
        if(!isInMemory(pageRequest, pageTable, tableSize)) {
           // printf("Page %d caused a page fault\n", pageRequest);
            numMisses++;
            if(pageTableIndex < tableSize) {
                pageTable[pageTableIndex++] = pageRequest;
            } 

            else {
              	while(flag!=0){
		 	    	if(chanceTable[headIndex]>0){ //if values used more than once, reset to 0
		    	    	chanceTable[headIndex]=0;
		        		headIndex=(headIndex+1)%tableSize;
		    		}
		    		else {
		         		pageTable[headIndex]=pageRequest;
			     		chanceTable[headIndex]=0;
		         		flag=0; //breakout of while loop
		         		headIndex=(headIndex+1)%tableSize;
		    		}
		  		}
				flag=1;
            }
        } 
        
        else{
	    	index=findIndex(pageRequest, pageTable, tableSize);
	    	chanceTable[index]++;
		}
	//Prints out the table values 
/*	for(x = 0; x < tableSize; x++) {
	    printf("%d ",pageTable[x]);
	  }
	  printf("\n ",pageTable[x]);
	for(x = 0; x < tableSize; x++) {
	    printf("%d ",chanceTable[x]);
	  }  
	   printf("\n ",pageTable[x]);
	  printf("Head index is %d",headIndex);
	 */
    } 
		
    fprintf(stderr,"Hit rate = %f\n", (numRequest-numMisses)/(double)numRequest);
    //fprintf(stderr,"Wrong");
    
    free(input);
    free(pageTable);
    return 0;
}
