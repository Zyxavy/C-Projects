#include <stdio.h>

int isPalindrome(int num);

int main() {
    int largestPalindrome = 0;
    int factor1, factor2;

    for (int i = 100; i <= 999; i++) {  // Loop over first 3-digit number
        for (int j = 100; j <= 999; j++) {  // Loop over second 3-digit number
            int product = i * j;
            if (isPalindrome(product)) {  // Check if the product is a palindrome
                if (product > largestPalindrome) {  // Store the largest palindrome found
                    largestPalindrome = product;
                    factor1 = i;
                    factor2 = j;
                }
            }
        }
    }

    printf("\nLargest Palindrome: %d (from %d x %d)\n", largestPalindrome, factor1, factor2);
    return 0;
}

// Function to check if a number is a palindrome
int isPalindrome(int num) {
    int reversed = 0, original = num;

    while (num > 0) {
        int remainder = num % 10;
        reversed = reversed * 10 + remainder;
        num /= 10;
    }

    return original == reversed;
}




