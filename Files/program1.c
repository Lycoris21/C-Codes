/* 

Program 1: Write a program that will create a file containing at least 3 student records
-Name of the physical file will be inputted from the keyboard
-Display on screen the contents of the student record before writing to the file (the fuction will display the given student record in 1 LINE ONLY)
-Suggestion: create/declare an array of student records and initialize it to contain at least 3 student records

Program 2: Write a program that will read and display the contents of the physical file whose name is inputted by the user.

 */

#include <stdio.h>

typedef struct{
    char FName[24];
    char MI;
    char LName[16];
    char course[8];
    int year;
}Studtype;

void display(Studtype );

int main(){
    Studtype arr[] = {{"Christine", 'P', "Dejito", "BSCS", 2},
                       {"Zophia", 'A', "Roca", "BSCS", 2},
                       {"Myles", 'Q', "Oncines", "BSIT", 2}
                      };
    int size = sizeof(arr)/sizeof(arr[0]);
    char fileName[20];
    scanf("%s", fileName);
    FILE *fp = fopen(fileName, "wb");
    if(fp==NULL){
        printf("Cannot open the file.\n");
    }else{
        int x;
        for(x=0; x < size; x++){
            display(arr[x]);
            fwrite(arr+x, sizeof(Studtype), 1, fp);
        }
        fclose(fp);
    }
    
    return 0;
}

void display(Studtype stud){
    printf("%-24s ", stud.FName);
    printf("%c ", stud.MI);
    printf("%-16s ", stud.LName);
    printf("%-8s ", stud.course);
    printf("%d\n", stud.year);
}
