#include <stdio.h>

/* helper function to swap two elements */
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* helper function to reverse array from index start to end */
void reverse(int* nums, int start, int end) {
    while (start < end) {
        swap(&nums[start], &nums[end]);
        start++;
        end--;
    }
}

/* main function required by LeetCode */
void nextPermutation(int* nums, int numsSize) {
    int i = numsSize - 2;

    /* Step 1: find first decreasing element */
    while (i >= 0 && nums[i] >= nums[i + 1]) {
        i--;
    }

    /* Step 2: find element just larger and swap */
    if (i >= 0) {
        int j = numsSize - 1;
        while (nums[j] <= nums[i]) {
            j--;
        }
        swap(&nums[i], &nums[j]);
    }

    /* Step 3: reverse the suffix */
    reverse(nums, i + 1, numsSize - 1);
}
