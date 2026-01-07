#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char name[50];
    int age;
    char degree[50];
    float marks;
};

struct Student db[100];
int count = 0;

void saveToFile() {
    FILE *fp = fopen("students.txt", "w");
    if (fp == NULL) {
        printf("Error saving data!\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        fprintf(fp, "%s %d %s %f\n", db[i].name, db[i].age, db[i].degree, db[i].marks);
    }
    fclose(fp);
}

void loadFromFile() {
    FILE *fp = fopen("students.txt", "r");
    if (fp == NULL) return;
    while (fscanf(fp, "%s %d %s %f", db[count].name, &db[count].age, db[count].degree, &db[count].marks) != EOF) {
        count++;
    }
    fclose(fp);
}

void addStudent() {
    printf("Enter Name: ");
    scanf("%s", db[count].name);
    printf("Enter Age: ");
    scanf("%d", &db[count].age);
    printf("Enter Degree: ");
    scanf("%s", db[count].degree);
    printf("Enter Marks: ");
    scanf("%f", &db[count].marks);
    count++;
    saveToFile();
    printf("Student added!\n");
}

void viewStudents() {
    if (count == 0) {
        printf("\nNo students found.\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        printf("%d. Name: %s | Age: %d | Degree: %s | Marks: %.2f\n", i + 1, db[i].name, db[i].age, db[i].degree, db[i].marks);
    }
}

void searchStudent() {
    char name[50];
    printf("Enter Name to search: ");
    scanf("%s", name);
    for (int i = 0; i < count; i++) {
        if (strcmp(db[i].name, name) == 0) {
            printf("Found! Name: %s, Age: %d, Degree: %s\n", db[i].name, db[i].age, db[i].degree);
            return;
        }
    }
    printf("Student not found.\n");
}

void deleteStudent() {
    char deleteName[50];
    int found = 0;
    if (count == 0) {
        printf("\nNothing to delete.\n");
        return;
    }
    printf("\nEnter Name to delete: ");
    scanf("%s", deleteName);
    for (int i = 0; i < count; i++) {
        if (strcmp(db[i].name, deleteName) == 0) {
            for (int j = i; j < count - 1; j++) {
                db[j] = db[j + 1];
            }
            count--;
            found = 1;
            printf("Student record deleted!\n");
            saveToFile();
            break;
        }
    }
    if (!found) printf("\nStudent not found.\n");
}

int main() {
    loadFromFile();
    int choice;
    while (1) {
        printf("\n--- STUDENT SYSTEM ---\n");
        printf("1. Add\n2. View\n3. Search\n4. Delete\n5. Exit\nChoice: ");
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            continue;
        }
        if (choice == 1) addStudent();
        else if (choice == 2) viewStudents();
        else if (choice == 3) searchStudent();
        else if (choice == 4) deleteStudent();
        else if (choice == 5) {
            saveToFile();
            break;
        }
        else printf("Invalid choice!\n");
    }
    return 0;
}