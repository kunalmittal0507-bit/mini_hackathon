#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define SUBJECTS 5
#define PASS_MARK 33

typedef struct {
    char name[60];
    int roll;
    int marks[SUBJECTS];
    int total;
    float percentage;
    char grade;
    int passed;
} Student;

int readInt(const char *prompt, int min, int max) {
    int value, result;
    char extra;
    while (1) {
        printf("%s", prompt);
        result = scanf("%d", &value);
        if (result == 1 && value >= min && value <= max) {
            while ((extra = getchar()) != '\n' && extra != EOF) {}
            return value;
        }
        printf("Invalid input. Enter a number from %d to %d.\n", min, max);
        while ((extra = getchar()) != '\n' && extra != EOF) {}
    }
}

char calculateGrade(float p, int passed) {
    if (!passed) return 'F';
    if (p >= 90) return 'A';
    if (p >= 75) return 'B';
    if (p >= 60) return 'C';
    if (p >= 45) return 'D';
    return 'E';
}

int main(void) {
    Student students[MAX_STUDENTS];
    int n, i, j, topper = -1;
    double classTotal = 0;
    n = readInt("Enter number of students (1-100): ", 1, MAX_STUDENTS);
    for (i = 0; i < n; i++) {
        printf("\nStudent %d\n", i + 1);
        printf("Enter name (no spaces): ");
        scanf("%59s", students[i].name);
        students[i].roll = readInt("Enter roll number (1-999999): ", 1, 999999);
        students[i].total = 0;
        students[i].passed = 1;
        for (j = 0; j < SUBJECTS; j++) {
            char prompt[80];
            sprintf(prompt, "Enter marks for subject %d (0-100): ", j + 1);
            students[i].marks[j] = readInt(prompt, 0, 100);
            students[i].total += students[i].marks[j];
            if (students[i].marks[j] < PASS_MARK) students[i].passed = 0;
        }
        students[i].percentage = students[i].total / (float)SUBJECTS;
        students[i].grade = calculateGrade(students[i].percentage, students[i].passed);
        classTotal += students[i].percentage;
        if (students[i].passed && (topper == -1 || students[i].total > students[topper].total)) topper = i;
    }
    printf("\n================ STUDENT RESULTS ================\n");
    printf("%-15s %-8s %-8s %-10s %-7s %s\n", "Name", "Roll", "Total", "Percent", "Grade", "Status");
    for (i = 0; i < n; i++) {
        printf("%-15s %-8d %-8d %-10.2f %-7c %s\n", students[i].name, students[i].roll,
               students[i].total, students[i].percentage, students[i].grade,
               students[i].passed ? "PASS" : "FAIL");
    }
    printf("\nClass average: %.2f%%\n", classTotal / n);
    if (topper >= 0) printf("Class topper: %s (Roll %d, %.2f%%)\n", students[topper].name, students[topper].roll, students[topper].percentage);
    else printf("Class topper: No student passed all subjects.\n");
    printf("Pass criterion: at least %d marks in EACH subject.\n", PASS_MARK);
    return 0;
}
