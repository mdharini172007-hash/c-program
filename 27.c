int removeElement(int* nums, int numsSize, int val){
    int i = 0; // Pointer for position of next non-val element

    for (int j = 0; j < numsSize; j++) {
        if (nums[j] != val) {
            nums[i] = nums[j];
            i++;
        }
    }

    return i; // Number of elements not equal to val
}
