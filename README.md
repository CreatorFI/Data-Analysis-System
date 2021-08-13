# A simple Data Analysis System 

This application is made for better understanding structure and FILE in c/cpp programming!

## Usage

First the program will read info from the given text file. You have to create a text document containing information in the following format.
Rename the text file to "students.txt" (The repo has the demo file). 

```bash

id 1 
name abc  
total_gpa 9.550000   
hsc 4.550000   
ssc_gpa 5.000000 

id 2 
name def  
total_gpa 9.550000   
hsc 5.000000   
ssc_gpa 4.550000 

id 3 
name xyz  
total_gpa 9.60000   
hsc 5.000000   
ssc_gpa 4.60000

id 4 
name pqr  
total_gpa 10  
hsc 5.000000   
ssc_gpa 5.0000 

id 5 
name ali  
total_gpa 9.670000   
hsc 4.670000   
ssc_gpa 5.0000                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
```

## Run the program
After executing the program you will see output in the following manner. The program will also give you analysis of SSC and HSC GPA's of the students. 

Analysis will sort out the GPA in descending order alongside with the ID and Names of the students. 
```c

  ...Total GPA ANALYSIS...
============================    
Total GPA = 10.00 
ID: 4 
Name: pqr
Total GPA = 9.67                  
ID: 5                             
Name: ali
Total GPA = 9.60                  
ID: 3                             
Name: xyz
Total GPA = 9.55                  
ID: 2                             
Name: def                         
ID: 1                             
Name: abc
                                                                                                           
```

## Check and Modify as your NEEDS!!!
NB: The program works for 5 students but you sure can take the number of students by adding a simple Scanf :)
```c

Happy Coding!!!

Created By Fatin Ishraq
