#include <inttypes.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

uint64_t descendingOrder(uint64_t n)
{
    int num_digits = log10(n) + 1;
    int *arr = calloc(num_digits, sizeof(int));

    for (int i = 0; i < num_digits; ++i)
    {
        arr[i] = n % 10;
        n /= 10;
    }
    
    for (int i = 0; i < num_digits - 1; i++) {
        for (int j = 0; j < num_digits - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    uint64_t result = 0;
    for (int i = 0; i < num_digits; ++i) {
        result = result * 10 + arr[i];
    }
    free(arr);

    return result;
}

int main() {
    uint64_t num = 123456789    ;
    printf("Result: %" PRIu64 "\n", descendingOrder(num));
    return 0;
}
