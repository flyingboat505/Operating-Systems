Abhi Munnangi
Fri,May 18th, 2018
Lab 3, COEN177


Introduction

In this lab, we are investing a time the performance of a computer’s file system to help give perspective on I/0 speed. 

Specifically by using the cat /dev/urandom command to generate random values into various sized files: 1G,5G, and 2500 M files and reading the file 1 character at a time. 
The two Program searead and randread,respectively read the file sequentially and randomly 
Searead Implementation: 
The implementation of Searead was simple. Using the function fgetc, 1 character was read at a time until the end of file was reached. Once the file was finished, then the program ended and the time to complete was recorded. 

RandRead Implementation:
The Implementation of Randread was to read the file randomly. Hence, the function Fseek was used to randomly find a location in the file.  The random value generated and passed into Fseek , was continuously tested until it fits the file size. Once the value is generated, the function Fread, was used to read the single character. This proceeded until the file size was reached.


Results

RandRead

1G:Average time= 6.45 seconds
6.47 seconds 
6.54 seconds 
6.354 seconds 

2500M Average time is 15.350 seconds
15.343 seconds 
15.251 seconds 
15.456 seconds 

5G Average time is  31.171 seconds 
31.260 seconds 
31.195 seconds 
31.059 seconds 

SeqRead 

1G Average time is 57 Minutes and 44 seconds 
57 min 41 seconds 
57 min 33 seconds 
57 min 58 seconds 

2500M Average time is 195 minutes and 11 seconds 
193 min 23 sec 
195 min 8.8
196.48.918

5G Average time is 328 and 18 seconds 
338 m 51.738 
300 m 17.18 
305. 27 sec
RandRead Disclaimer.

In hindsight there were ways that i could have improved the time of RandRead( the times will still linearly scale in accordance to filesize)
First of all, I should have used Fgetc, which is a lot faster than fread and d oesn’t even need a buffer. 

Also although I generate random values, the program tested the values until the values were  inside the file size itself. This is extremely inefficient because it’s a similar to a spin lock. I should have moded the randomly generated values in order to guarantee that value for fseek was in the file size. 

Needless to say, the results are consistent to the necessary conclusions for this lab.

CONCLUSIONS

1.From this data, the readrate, regardless if it’s random or sequential, is linearly dependent on file size.For example the read rate from a 5G file size is approximately 5 times more the readread of a 1 G file. 

2. Also reading randomly takes a significantly longer time because I used fseek, which is a system call. System calls are several magnitude slower than function calls due to context switches, which is why it’s significantly slower than reading sequentially. 

Explanation of variances
1. There are several reasons why the times for reading the files aren’t perfect multiples of each other.
Since I am randomly generating values, until the value is in the filesize, the number of tries will vary, but will still hit a certain variance because the randomly generated values are independent variables so they  will plot of a normalized graph will have a consistent variance due to
Gaussian Distribution Law. 

2. Additionally for the times in 2500M  and the 330 times in 5G, t someone else might of been using the computer for another task at the same time so the time was a little longer than anticipated. 


