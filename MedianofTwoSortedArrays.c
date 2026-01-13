double findMedianSortedArrays(int* nums1, int m, int* nums2, int n) {
    // Ensure nums1 is the smaller array
    if (m > n)
        return findMedianSortedArrays(nums2, n, nums1, m);

    int low = 0, high = m;

    while (low <= high) {
        int partitionX = (low + high) / 2;
        int partitionY = (m + n + 1) / 2 - partitionX;

        int maxLeftX  = (partitionX == 0) ? -1000000000 : nums1[partitionX - 1];
        int minRightX = (partitionX == m) ?  1000000000 : nums1[partitionX];

        int maxLeftY  = (partitionY == 0) ? -1000000000 : nums2[partitionY - 1];
        int minRightY = (partitionY == n) ?  1000000000 : nums2[partitionY];

        if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
            // Correct partition
            if ((m + n) % 2 == 0) {
                int leftMax = (maxLeftX > maxLeftY) ? maxLeftX : maxLeftY;
                int rightMin = (minRightX < minRightY) ? minRightX : minRightY;
                return (leftMax + rightMin) / 2.0;
            } else {
                return (maxLeftX > maxLeftY) ? maxLeftX : maxLeftY;
            }
        }
        else if (maxLeftX > minRightY) {
            high = partitionX - 1;
        }
        else {
            low = partitionX + 1;
        }
    }

    return 0.0; // Will never reach here
}
