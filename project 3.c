#include <stdio.h>

struct Student {
    int rollNo;
    char name[50];
    float cutoff;
    char city[50];
    char dream[50];
};

int main() {
    int n, i;

    printf("Enter the total number of students: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid student count! Please enter a positive number.\n");
        return 1;
    }

    struct Student students[n];

    printf("\n--- Enter Student Details ---\n");
    for (i = 0; i < n; i++) {
        printf("\nStudent %d:\n", i + 1);
        
        printf("Enter Roll Number: ");
        scanf("%d", &students[i].rollNo);
        
        while (getchar() != '\n');

        printf("Enter Full Name: ");
        scanf("%[^\n]%*c", students[i].name);

        printf("Enter Cut-off Mark: ");
        scanf("%f", &students[i].cutoff);

        while (getchar() != '\n');

        printf("Enter City: ");
        scanf("%[^\n]%*c", students[i].city);

        printf("Enter Dream (Career Ambition): ");
        scanf("%[^\n]%*c", students[i].dream);
    }

    printf("\n\n========================================\n");
    printf("         STUDENT DETAILS REPORT         \n");
    printf("========================================\n");

    for (i = 0; i < n; i++) {
        printf("\nStudent %d Details:\n", i + 1);
        printf("  Roll Number   : %d\n", students[i].rollNo);
        printf("  Name          : %s\n", students[i].name);
        printf("  Cut-off Mark  : %.2f\n", students[i].cutoff);
        printf("  City          : %s\n", students[i].city);
        printf("  Dream         : %s\n", students[i].dream);
        printf("----------------------------------------\n");
    }

    return 0;
}

OUTPUT

Enter the total number of students: 50

--- Enter Student Details ---

Student 1:
Enter Roll Number: 101
Enter Full Name: Rahul Sharma
Enter Cut-off Mark: 92.5
Enter City: Chennai
Enter Dream (Career Ambition): Software Engineer

Student 2:
Enter Roll Number: 102
Enter Full Name: Priya Patel
Enter Cut-off Mark: 95.8
Enter City: Bengaluru
Enter Dream (Career Ambition): Data Scientist

... [Inputs continue for Students 3 through 49] ...

Student 50:
Enter Roll Number: 150
Enter Full Name: Vikram Iyer
Enter Cut-off Mark: 89.4
Enter City: Coimbatore
Enter Dream (Career Ambition): Cyber Security Analyst


========================================
        STUDENT DETAILS REPORT         
========================================

Student 1 Details:
  Roll Number   : 101
  Name          : Rahul Sharma
  Cut-off Mark  : 92.50
  City          : Chennai
  Dream         : Software Engineer
----------------------------------------

Student 2 Details:
  Roll Number   : 102
  Name          : Priya Patel
  Cut-off Mark  : 95.80
  City          : Bengaluru
  Dream         : Data Scientist
----------------------------------------

... [Reports continue for Students 3 through 49] ...

Student 50 Details:
  Roll Number   : 150
  Name          : Vikram Iyer
  Cut-off Mark  : 89.40
  City          : Coimbatore
  Dream         : Cyber Security Analyst
----------------------------------------