# Student Result and Grade Analyzer

**Mini Hackathon — C Programming | Problem 3**

  
**Batch:** [21]  
**Members:** [Hardik] , [Kunal] , [Akshaj]

## Problem statement
Develop a result-processing program that calculates student performance across multiple subjects. Accept marks for five subjects for multiple students, calculate total, percentage, grade and pass/fail status, and display the class topper and class average.

## Features
- Processes 1–100 students, each with five subjects.
- Validates number of students, roll numbers, and marks (0–100).
- Computes total out of 500 and percentage.
- Marks a student as failed if **any** subject is below 33.
- Assigns grades A/B/C/D/E to passing students; F to failing students.
- Reports the highest-scoring passing student and the class average percentage.

## Assumptions
The guidelines do not specify a pass mark or grade bands. For this implementation, the team uses **33/100 in every subject** to pass. Passing grades: A >=90%, B >=75%, C >=60%, D >=45%, E <45%. Any failed subject gives grade F. The topper is the passing student with the highest total; ties are resolved by first entry. Names are single words; data is held in memory for one run.

## Algorithm
1. Read and validate the number of students.
2. For each student, read name, roll number, and five subject marks.
3. Sum marks; set fail status if any subject mark is below 33.
4. Calculate percentage = total / 5. Assign grade based on pass status and percentage.
5. Track the highest-scoring passing student; accumulate class percentages.
6. Print each student's result, class average, and topper.

## C concepts
Structures, arrays, loops, conditional statements, functions, strings, formatted I/O, and input validation.

## Compile and run
```bash
gcc -std=c11 -Wall -Wextra student_grade_analyzer.c -o analyzer
./analyzer
```
On Windows, run `analyzer.exe` instead of `./analyzer`.

## Sample test cases
See [TEST_CASES.md](TEST_CASES.md) for inputs, expected results, and verification guidance.

## Team contribution plan
- Member 1: Input handling and validation.
- Member 2: Grade, pass/fail, percentage and topper logic.
- Member 3: Testing, README, GitHub upload and demonstration.
All members must understand and be able to explain the complete program.
