#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1. Define the Student structure
struct student {
    char name[50];
    int age;
    char degree[50];
    float marks;
};

// 2. Global variables
struct student db[100];
int count = 0;

// 3. Function to Add Student
void addStudent() {
    if (count >= 100) {
        printf("\nDatabase full!\n");
        return;
    }
    printf("\nEnter Name: ");
    scanf("%s", db[count].name);
    printf("Enter Age: ");
    scanf("%d", &db[count].age);
    printf("Enter Degree: ");
    scanf("%s", db[count].degree);
    printf("Enter Marks: ");
    scanf("%f", &db[count].marks);
    count++;
    printf("Student added!\n");
}

// 4. Function to View Students
void viewStudents() {
    if (count == 0) {
        printf("\nNo students found.\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        printf("\n%d. Name: %s | Marks: %.2f", i + 1, db[i].name, db[i].marks);
    }
    printf("\n");
}

// 5. Function to Search Student
void searchStudent() {
    char searchName[50];
    int found = 0;
    if (count == 0) {
        printf("\nNothing to search.\n");
        return;
    }
    printf("\nEnter Name to search: ");
    scanf("%s", searchName);
    for (int i = 0; i < count; i++) {
        if (strcmp(db[i].name, searchName) == 0) {
            printf("\nFound! Name: %s, Age: %d\n", db[i].name, db[i].age);
            found = 1;
            break;
        }
    }
    if (!found) printf("\nStudent not found.\n");
}

// 6. The Main Function
int main() {
    int choice;
    while(1) {
        printf("\n1. Add\n2. View\n3. Search\n4. Exit\nChoice: ");
        if (scanf("%d", &choice) != 1) {
            while(getchar() != '\n');
            continue;
        }
        if (choice == 1) addStudent();
        else if (choice == 2) viewStudents();
        else if (choice == 3) searchStudent();
        else if (choice == 4) break;
        else printf("Invalid!\n");
    }
    return 0; 
}
