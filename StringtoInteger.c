int myAtoi(char* s) {
    int i = 0;
    int sign = 1;
    int result = 0;

    // 1. Ignore leading whitespaces
    while (s[i] == ' ') {
        i++;
    }

    // 2. Check sign
    if (s[i] == '+' || s[i] == '-') {
        if (s[i] == '-')
            sign = -1;
        i++;
    }

    // 3. Convert digits
    while (s[i] >= '0' && s[i] <= '9') {
        int digit = s[i] - '0';

        // 4. Check overflow before multiplying
        if (result > 214748364 ||
           (result == 214748364 && digit > 7)) {
            return sign == 1 ? 2147483647 : -2147483648;
        }

        result = result * 10 + digit;
        i++;
    }

    return sign * result;
}
