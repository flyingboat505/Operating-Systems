Name: Abhi Munnangi 
Date Friday, May 4, 2018 

The first task of this lab is to make sure to print out the copyright message upon boot following the copy write message.
In order to do this, located the file main.c in the kernel directory. Once I located the copywrite message I used a printf 
statement,  printf(" Part 1 of the lab complete") and it printed upon reboot. 

the line number of the modificaiton is at 278 

The second assignment was slow down the processing schedling algrothim. 
Previously, the kernal used a round robin algorithim in order to implement process selection. 

This algorithim is in proc.c, with proc being short for "process".
To modify this assignment,  I created a random variable called testRand. And assigned a number from 0 to 10. If the random number
is 7 and the priority queue is greater than or equal to 3, than I made the scheduler pick a random process. 
Therfore, about every 10th selection, the shcedule will just pick a random process , significantly slowing down the reboot. 
I avoid changing processes with priority less than 3 because according to the TA,Ryan Cooper, the shceudler will significantly slow down and will take an even longer time. 

I modified all this in the pick_proc function because that is the function to pick processes. 
Here is my for loop. 
  for (q=0; q < NR_SCHED_QUEUES; q++) {	
		testRand=rand()%(10);
     	if(q>=3 & testRand==7){
	 	q=rand()% (NR_SCHED_QUEUES-q)+q;
	 }
	
	if(!(rp = rdy_head[q])) {
		TRACE(VF_PICKPROC, printf("queue %d empty\n", q););
		continue;
	}
Line numbers are 1307 to 1322 in the pick_proc function. 

