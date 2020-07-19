Name Abhi Munnangi
Student ID Number:1275417
Date 4/20/2018

This is zip folder containing my solutions to the first assignments in COEN177 Spring Quarter 2018. The assignment is broken down into four basic tasks.
1. The First task is to create a simple shell, similar to the one Professor Amer presented in his first lecture slide. The shell terminates when the user input "exit. 

The TA, Ryan Cooper, gave most of the code, but the task was given to accept the user inputs.
In order to fulfill this task, I used the function gets. Which reads a line from the specified stream and stores it into the string pointed to by string.

In order to test the first task, I created a simple hello world program and typed in the file name when the running shell prompted me.  

My code for this solution is in shell.c  

2. The Second task is to create eight child processes (not including the initial program itself)

In order to fulfill this task, I used a simple for loop, which looped using a fork. My strategy was to halt the parent process after creation using a break statement and to let the child process continue producing child processes until 8 processes were created. 

This is the visual diagram of how the proccess are creates. 
						  0
						  |
						  0
						  | 
						  0
						  |
						  0
						  |
						  0
						  |
						  0 
						  | 
						  0
						  | 
						  0
						  |
						  0 

My code for this solution is in part2.c  


3. The third task creates twelve child processes.  This time there is a restriction. If a process creates another process, then it must create either two or three processes.

In order to fulfill this task, I produced the following tree model.

                  o
            /     |      \
          o       o       o
        / | \   / | \   / | \ 
        o o o   o o o   o o o

The parent process creates 3 child process, and the child processes create 3 more child processes and then stop producing.

My strategy to fulfills this task is to have 2 variables. Created and depth. Both Created and depth start a 0 but every time a process is created the parent process Created increases by 1 and the child dept increases by 1. If depth is equal to 2, the process halts. And if Created hits 3, then the process halts. Because that means the parent has created 3 child processes, so it stops. But if Depth hits 2 before anything else, then the process stop entirely because we have reached the lowest layer of the tree. 

My code for this solution is in part3.c   


4) The third task creates 17 child processes. there is also a  restriction. If a process creates another process, then it must create either two or three processes. 

	In order to fulfill this task, I created this basic three.   Where the Parent process produces 2 child processes, which create three more children processes. and depending on the side, either halt if the node is on the left side or create 3 more child processes is produced by the right side.  
       
                      o
               /            \  
              o              o       
           /  |  \      /    |    \    
          o   o   o     o    o    o 
                       /|\  /|\  /|\
                       ooo  ooo  ooo 

My strategy to fulfills this task is to have 3  variables. Created,leftchild and depth. Both Created and dept start a 0 but every time a process is created the parent process capacity increases by 1 and the child dept increases by 1 then the process halts depending on what values dept and created are. LeftChild is a boolean statement that checks if the processes is in the left or right side of the parent process. 

If the process is the first one produced by the orginal parent, then leftchild is equal to 0. Once the parent process finished, left child is equal 1, indicating that left side of the tree is now complete and now the right processes are being produced. We can use the dept variables accorindly depending on the state of the left child; If the left child is 1,then the dept limit is 2, if the right child is 0, then the depth is 3. I also used a Created limit 2 for the parent node. Other wise, the Created limited is 3 because if dept is not 0, then it indicates that the process is a childnode .

To identify the parent node, the depth is 0. if dept is 0 by the end of the 1st for loop, then the parent process is hitting the right child. And created will be 2, meaing that the parent has created 2 child processes and will stop according to this booleon condition. 

My code for this solution is in part4.c
  
