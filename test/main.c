#include <stdio.h>
#include <math.h>
#include <string.h>

int scoreOfString(char s);

int main(){
    char a = "Hello";

    scoreOfString(a);
    return 0;
}

int scoreOfString(char s) {
    int score = 0;
    int n = strlen(s);

    for (int i = 1; i < n; i++) {
        score += abs(s[i] - s[i - 1]);
    }

    return score;
}
