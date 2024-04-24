#include <stdio.h>

// Assume binarySearch function is defined somewhere in your code
int binarySearch(int target, int arr[], int size) {
    // Implementation of binary search algorithm
    // This is just a placeholder, replace it with your actual implementation
    return -1;
}

int main(void) {
    int case1[] = { 0 };
    int result1 = binarySearch(0, case1, 1);
    (result1 == 0) ? printf("Case #1 by [STUDENT’S FIRST NAME & LAST NAME] PASSED\n") : printf("Case #1 by [STUDENT’S FIRST NAME & LAST NAME] FAILED\n");

    int case2[] = { 1, 2, 3, 4, 5 };
    int result2 = binarySearch(3, case2, 5);
    (result2 == 2) ? printf("Case #2 by [STUDENT’S FIRST NAME & LAST NAME] PASSED\n") : printf("Case #2 by [STUDENT’S FIRST NAME & LAST NAME] FAILED\n");

    // Test case 3
    int case3[] = { 1, 3, 5, 7, 9 };
    int result3 = binarySearch(7, case3, 5);
    (result3 == 3) ? printf("Case #3 by [STUDENT’S FIRST NAME & LAST NAME] PASSED\n") : printf("Case #3 by [STUDENT’S FIRST NAME & LAST NAME] FAILED\n");

    // Test case 4
    int case4[] = { 2, 4, 6, 8, 10 };
    int result4 = binarySearch(5, case4, 5);
    (result4 == -1) ? printf("Case #4 by [STUDENT’S FIRST NAME & LAST NAME] PASSED\n") : printf("Case #4 by [STUDENT’S FIRST NAME & LAST NAME] FAILED\n");

    // Test case 5
    int case5[] = { 10, 20, 30, 40, 50 };
    int result5 = binarySearch(10, case5, 5);
    (result5 == 0) ? printf("Case #5 by [STUDENT’S FIRST NAME & LAST NAME] PASSED\n") : printf("Case #5 by [STUDENT’S FIRST NAME & LAST NAME] FAILED\n");

    // Test case 6
    int case6[] = { 5, 15, 25, 35, 45 };
    int result6 = binarySearch(25, case6, 5);
    (result6 == 2) ? printf("Case #6 by [STUDENT’S FIRST NAME & LAST NAME] PASSED\n") : printf("Case #6 by [STUDENT’S FIRST NAME & LAST NAME] FAILED\n");

    // Test case 7
    int case7[] = { 100, 200, 300, 400, 500 };
    int result7 = binarySearch(100, case7, 5);
    (result7 == 0) ? printf("Case #7 by [STUDENT’S FIRST NAME & LAST NAME] PASSED\n") : printf("Case #7 by [STUDENT’S FIRST NAME & LAST NAME] FAILED\n");

    // Test case 8
    int case8[] = { 10, 20, 30, 40, 50 };
    int result8 = binarySearch(60, case8, 5);
    (result8 == -1) ? printf("Case #8 by [STUDENT’S FIRST NAME & LAST NAME] PASSED\n") : printf("Case #8 by [STUDENT’S FIRST NAME & LAST NAME] FAILED\n");

    // Test case 9
    int case9[] = { 5, 15, 25, 35, 45 };
    int result9 = binarySearch(20, case9, 5);
    (result9 == -1) ? printf("Case #9 by [STUDENT’S FIRST NAME & LAST NAME] PASSED\n") : printf("Case #9 by [STUDENT’S FIRST NAME & LAST NAME] FAILED\n");

    // Test case 10
    int case10[] = { 100, 200, 300, 400, 500 };
    int result10 = binarySearch(600, case10, 5);
    (result10 == -1) ? printf("Case #10 by [STUDENT’S FIRST NAME & LAST NAME] PASSED\n") : printf("Case #10 by [STUDENT’S FIRST NAME & LAST NAME] FAILED\n");

    return 0;
}

