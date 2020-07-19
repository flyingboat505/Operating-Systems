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
 
    int pageRequest, pageTableIndex = 0, numRequest = 0, numMisses = 0,i,index;
    int *pageTable = (int *) malloc(sizeof(int)*tableSize);
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

       //     printf("Page %d caused a page fault\n", pageRequest);
            numMisses++;
            if(pageTableIndex < tableSize) {
                pageTable[pageTableIndex++] = pageRequest;
            } 
            else {
	          index=findIndex(pageRequest, pageTable, tableSize);
		 for(i=index;i<tableSize-1;++i){
		     pageTable[i]=pageTable[i+1];
		 }
		pageTable[tableSize-1]=pageRequest;

	    }
	 }
	 
	else {
	      index=findIndex(pageRequest, pageTable, tableSize); //find the index 
	      for(i=index;i<tableSize-1;++i){
		  pageTable[i]=pageTable[i+1];
	      }
		pageTable[tableSize-1]=pageRequest;
	}
	
	int x;
	/*for(x = 0; x < tableSize; x++) {
	    printf("%d ",pageTable[x]);
	  } */
    } 
  //  printf("Hit rate = %f\n", (numRequest-numMisses)/(double)numRequest);
    fprintf(stderr,"Hit rate = %f\n", (numRequest-numMisses)/(double)numRequest);
    
    free(input);
    free(pageTable);
    return 0;
}
