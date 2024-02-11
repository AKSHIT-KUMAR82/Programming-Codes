/*
23) W.A.P to store value of student using structure.
Name - Saurabh Kumar
Student ID - 2321808
*/

#include <stdio.h>
struct Student {
    int rollNumber;
    int studentID;
    char name[30];
};

int main() {

    struct Student myStudent;
    printf("Enter Roll Number: ");
    scanf("%d", &myStudent.rollNumber);
    printf("Enter Student ID: ");
    scanf("%d", &myStudent.studentID);
    printf("Enter name : ");
    scanf("%s", &myStudent.name);

    printf("\nStudent Information:\n");
    printf("Name : %s\n", myStudent.name);
    printf("Roll Number: %d\n", myStudent.rollNumber);
    printf("Student ID: %d\n", myStudent.studentID);

    return 0;
}
