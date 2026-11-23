# Test cases — Student Result and Grade Analyzer

The expected outputs below describe the key result lines; prompts are omitted for readability. Run each test and record actual output during Lab 1.

## Test 1: Normal case
Input: 3 students: Asha (101): 90 80 70 85 95; Ravi (102): 60 65 70 75 80; Neha (103): 95 96 97 98 99.

Expected:
- Asha: total 420, 84.00%, B, PASS
- Ravi: total 350, 70.00%, C, PASS
- Neha: total 485, 97.00%, A, PASS
- Class average: 83.67%
- Class topper: Neha (Roll 103, 97.00%)

## Test 2: Failed subject despite high total
Input: 1 student, Sam (201): 100 100 100 100 32.

Expected: total 432, 86.40%, F, FAIL; no passing topper; class average 86.40%.

## Test 3: Boundary pass
Input: 1 student, Ira (301): 33 33 33 33 33.

Expected: total 165, 33.00%, E, PASS; topper Ira.

## Test 4: Invalid mark
Input: 1 student, Dev (401). For first mark enter 105, then 85; other marks 75 65 55 45.

Expected: invalid-input message for 105 and re-prompt; total 325, 65.00%, C, PASS.

## Test 5: Invalid student count
Enter 0, then 1. Expected: re-prompt until number is between 1 and 100.

## Actual output record
After running the program in Lab 1, paste terminal output or screenshots here to document observed results. Do not claim tests were run until verified on the lab computer.
