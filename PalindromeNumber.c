int isPalindrome(int x) {
    if (x < 0)
        return 0;

    int original = x;
    int rev = 0;

    while (x != 0) {
        int digit = x % 10;

        // Overflow check
        if (rev > 214748364 || (rev == 214748364 && digit > 7))
            return 0;

        rev = rev * 10 + digit;
        x /= 10;
    }

    return original == rev;
}
