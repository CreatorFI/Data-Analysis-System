#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//AUTHOR : K.M. Fatin Ishraq //

const char *STUDENT_FORMAT_IN = "\n%*s %d %*s %s %*s %lf %*s %lf %*s %lf\n";

typedef struct Student Student;

struct Student
{
    int id;
    char name[20];
    double totalGPA;
    double hscGPA;
    double sscGPA;
    Student()
    {
        ;
    }
};
void findSameTotalGPAHolders(Student *Student, int i);
void findSameSSCGpaHolders(Student *Student, int i);
void findSameHSCCGpaHolders(Student *Student, int n);
void appendFiles(char source[],
                 char destination[]);
void printAllInformations(Student Student);
void readInformations(Student *Student1)
{
    FILE *fp;
    fp = fopen("students.txt", "r");
    int i = 0;
    if (fp == NULL)
    {
        printf("File not found \n"); 
    }
    else
    {
        //!feof(fp)
        while (fscanf(fp, STUDENT_FORMAT_IN, &Student1[i].id, &Student1[i].name, &Student1[i].totalGPA, &Student1[i].hscGPA, &Student1[i].sscGPA) == 5)
        {

            i++;
        }
    }
    fclose(fp);
}
void findSameTotalGPAHolders(Student *Student, int n)
{
    FILE *fp;
    fp = fopen("total_gpa_analysis.txt", "w");
    fprintf(fp, "\n...Total GPA ANALYSIS...\n");

    fprintf(fp, "============================\n");
    int i, j;
    double temp;
    char tempName[100];
    int tempID;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (Student[i].totalGPA < Student[j].totalGPA)
            {
                temp = Student[i].totalGPA;
                Student[i].totalGPA = Student[j].totalGPA;
                Student[j].totalGPA = temp;
                strcpy(tempName, Student[i].name);
                strcpy(Student[i].name, Student[j].name);
                strcpy(Student[j].name, tempName);
                tempID = Student[i].id;
                Student[i].id = Student[j].id;
                Student[j].id = tempID;
            }
        }
    }
    double currentValue = 0;
    double previousValue = 0;
    double nextValue = 0;
    double last = -1.0;
    for (i = 0; i < n; i++)
    {
        if (Student[i].totalGPA == last)
        {
            continue;
        }
        fprintf(fp, "\nTotal GPA = %.2f\n", (float)Student[i].totalGPA);
        last = Student[i].totalGPA;
        for (j = i; j < n; j++)
        {
            if (last == Student[j].totalGPA)
            {
                fprintf(fp, "ID: %d\n", Student[j].id);
                fprintf(fp, "Name: %s\n", Student[j].name);
            }
            else if (Student[j].totalGPA < last)
                break;
        }
    }
    fclose(fp);
};

void findSameSSCGpaHolders(Student *Student, int n)
{
    FILE *fp;
    fp = fopen("ssc_gpa_analysis.txt", "w");
    int i, j;
    double temp;
    char tempName[100];
    int tempID;
    fprintf(fp, "\n...SSC GPA ANALYSIS...\n");
    fprintf(fp, "============================\n");
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (Student[i].sscGPA < Student[j].sscGPA)
            {
                temp = Student[i].sscGPA;
                Student[i].sscGPA = Student[j].sscGPA;
                Student[j].sscGPA = temp;
                strcpy(tempName, Student[i].name);
                strcpy(Student[i].name, Student[j].name);
                strcpy(Student[j].name, tempName);
                tempID = Student[i].id;
                Student[i].id = Student[j].id;
                Student[j].id = tempID;
            }
        }
    }
    double last = -1.0;
    for (i = 0; i < n; i++)
    {
        if (Student[i].sscGPA == last)
        {
            continue;
        }
        fprintf(fp, "\nSSC GPA = %.2f\n", (float)Student[i].sscGPA);
        fprintf(fp, "============================\n");
        last = Student[i].sscGPA;
        for (j = i; j < n; j++)
        {
            if (last == Student[j].sscGPA)
            {
                fprintf(fp, "\nID: %d\n", Student[j].id);
                fprintf(fp, "Name: %s\n", Student[j].name);
            }
            else if (Student[j].sscGPA < last)
                break;
        }
    }
    fclose(fp);
}
void findSameHSCCGpaHolders(Student *Student, int n)
{
    FILE *fp;
    fp = fopen("hsc_gpa_analysis.txt", "w");
    int i, j;
    double temp;
    char tempName[100];
    int tempID;
    fprintf(fp, "\n...HSC GPA ANALYSIS...\n");
    fprintf(fp, "============================\n");
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (Student[i].hscGPA < Student[j].hscGPA)
            {
                temp = Student[i].hscGPA;
                Student[i].hscGPA = Student[j].hscGPA;
                Student[j].hscGPA = temp;
                strcpy(tempName, Student[i].name);
                strcpy(Student[i].name, Student[j].name);
                strcpy(Student[j].name, tempName);
                tempID = Student[i].id;
                Student[i].id = Student[j].id;
                Student[j].id = tempID;
            }
        }
    }
    double last = -1.0;
    for (i = 0; i < n; i++)
    {
        if (Student[i].hscGPA == last)
        {
            continue;
        }
        fprintf(fp, "\nHSC GPA = %.2f\n", (float)Student[i].hscGPA);
        fprintf(fp, "============================\n");
        last = Student[i].hscGPA;
        for (j = i; j < n; j++)
        {
            if (last == Student[j].hscGPA)
            {
                fprintf(fp, "\nID: %d\n", Student[j].id);
                fprintf(fp, "Name: %s\n", Student[j].name);
            }
            else if (Student[j].hscGPA < last)
                break;
        }
    }
    fclose(fp);
}
void appendFiles(char source[],
                 char destination[])
{
    FILE *pFile;
    FILE *pFile2;
    char buffer[256];

    pFile = fopen(source, "r");
    pFile2 = fopen(destination, "a");
    if (pFile == NULL)
    {
        perror("Error opening file.");
    }
    else
    {
        while (fgets(buffer, sizeof(buffer), pFile))
        {
            fprintf(pFile2, "%s", buffer);
        }
    }
    fclose(pFile);
    fclose(pFile2);
}
void printAllInformations(Student *Student){
    FILE *fptr =  fopen("students.txt", "r");
    char buffer[256];
    if (fptr == NULL)
    {
        printf("Cannot open file \n");
        exit(0);
    }
  
    // Read contents from file
    while (fgets(buffer,256,fptr))
    {
       printf("%s",buffer);
    }
    
  
    fclose(fptr);
    printf("\n*********************************** Thank You ***********************************\n\t\t\tCreated By Fatin Ishraq\n");
    }

int main()
{
    int n = 5;
    
    Student *Student1;
    Student1 = (Student *)calloc(n, sizeof(Student));

    readInformations(Student1);
    findSameTotalGPAHolders(Student1, 5);
    readInformations(Student1);
    findSameSSCGpaHolders(Student1, 5);
    readInformations(Student1);
    findSameHSCCGpaHolders(Student1, 5);

    char source[] = "total_gpa_analysis.txt",destination[] = "students.txt";
    appendFiles(source, destination);
    appendFiles("ssc_gpa_analysis.txt", destination);
    appendFiles("hsc_gpa_analysis.txt", destination);
   
    printAllInformations(Student1);
    
    return 0;
}