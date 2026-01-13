int lengthOfLongestSubstring(char* s) {
    int lastIndex[256];
    for (int i = 0; i < 256; i++) {
        lastIndex[i] = -1;
    }

    int maxLen = 0;
    int start = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        unsigned char c = s[i];

        if (lastIndex[c] >= start) {
            start = lastIndex[c] + 1;
        }

        lastIndex[c] = i;

        int currLen = i - start + 1;
        if (currLen > maxLen) {
            maxLen = currLen;
        }
    }

    return maxLen;
}
