// Student Attendance System (Fixed Version)
// Created by Praneeth Kadiyala

#include <stdio.h>
#include <string.h>

struct Student {
    int id;
    char name[50];
    int attended;
    int total;
};

struct Student s[100];
int n = 0;

// Save to file
void saveToFile() {
    FILE *fp = fopen("data.txt", "w");
    int i;

    for (i = 0; i < n; i++) {
        fprintf(fp, "%d %s %d %d\n", s[i].id, s[i].name, s[i].attended, s[i].total);
    }

    fclose(fp);
}

// Load from file
void loadFromFile() {
    FILE *fp = fopen("data.txt", "r");

    if (fp == NULL)
        return;

    while (fscanf(fp, "%d %s %d %d", &s[n].id, s[n].name, &s[n].attended, &s[n].total) != EOF) {
        n++;
    }

    fclose(fp);
}

// Add student
void addStudent() {
    printf("\nEnter ID: ");
    scanf("%d", &s[n].id);

    printf("Enter Name: ");
    scanf("%s", s[n].name);

    s[n].attended = 0;
    s[n].total = 0;

    n++;

    printf("✅ Student added successfully!\n");
}

// Mark attendance
void markAttendance() {
    int id, found = 0, i;

    printf("\nEnter ID: ");
    scanf("%d", &id);

    for (i = 0; i < n; i++) {
        if (s[i].id == id) {
            s[i].attended++;
            s[i].total++;
            found = 1;
            printf("✅ Attendance marked!\n");
        }
    }

    if (!found)
        printf("❌ Student not found!\n");
}

// View students
void viewStudents() {
    int i;

    printf("\n--- Student Records ---\n");

    for (i = 0; i < n; i++) {
        float percent = 0;

        if (s[i].total != 0)
            percent = (s[i].attended * 100.0) / s[i].total;

        printf("ID: %d | Name: %s | Attendance: %d/%d (%.2f%%)\n",
               s[i].id, s[i].name, s[i].attended, s[i].total, percent);
    }
}

// Search student
void searchStudent() {
    int id, found = 0, i;

    printf("\nEnter ID to search: ");
    scanf("%d", &id);

    for (i = 0; i < n; i++) {
        if (s[i].id == id) {
            printf("Found: %s (Attendance: %d/%d)\n",
                   s[i].name, s[i].attended, s[i].total);
            found = 1;
        }
    }

    if (!found)
        printf("❌ Student not found!\n");
}

// Delete student
void deleteStudent() {
    int id, found = 0, i, j;

    printf("\nEnter ID to delete: ");
    scanf("%d", &id);

    for (i = 0; i < n; i++) {
        if (s[i].id == id) {
            for (j = i; j < n - 1; j++) {
                s[j] = s[j + 1];
            }
            n--;
            found = 1;
            printf("🗑️ Student deleted!\n");
            break;
        }
    }

    if (!found)
        printf("❌ Student not found!\n");
}

// Main function
int main() {
    int choice;

    loadFromFile();

    while (1) {
        printf("\n==============================\n");
        printf("  STUDENT ATTENDANCE SYSTEM\n");
        printf("==============================\n");
        printf("1. Add Student\n");
        printf("2. Mark Attendance\n");
        printf("3. View Records\n");
        printf("4. Search Student\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                markAttendance();
                break;
            case 3:
                viewStudents();
                break;
            case 4:
                searchStudent();
                break;
            case 5:
                deleteStudent();
                break;
            case 6:
                saveToFile();
                printf("💾 Data saved. Exiting...\n");
                return 0;
            default:
                printf("❌ Invalid choice!\n");
        }
    }

    return 0;
}