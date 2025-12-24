#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
    // Screen and donut dimensions
    int width = 40;
    int height = 24;
    float A = 0, B = 0;  // Rotation angles
    float i, j;
    char buffer[1200];
    float zbuffer[1760];
    int k;
    printf("\x1b[2J");

    while (1) {
        // Clear buffers
        memset(buffer, 32, 1200);
        memset(zbuffer, 0, 7040);

        for (j = 0; 6.28 > j; j += 0.07) {
            for (i = 0; 6.28 > i; i += 0.02) {
                float sini = sin(i);
                float cosj = cos(j);
                float sinA = sin(A);
                float sinj = sin(j);
                float cosA = cos(A);
                float cosj2 = cosj + 2;  // Cosine component for 3D projection

                float mess = 1 / (sini * cosj2 * sinA + sinj * cosA + 5);  // Depth calculation
                float cosi = cos(i);
                float cosB = cos(B);
                float sinB = sin(B);
                int x = 40 + 30 * mess * (cosi * cosj2 * cosB - sini * cosj2 * sinA * sinB - sini * sinj * cosB);
                int y = 12 + 15 * mess * (cosi * cosj2 * sinB + sini * cosj2 * sinA * cosB + sini * sinj * sinB);
                int o = x + width * y;
                int N = 8 * ((sinj * sinA - sini * cosj * cosA) * cosB - sini * cosj * sinA * sinB - cosi * cosj2 * cosA * sinB);

                if (height > y && y > 0 && x > 0 && width > x && mess > zbuffer[o]) {
                    zbuffer[o] = mess;
                    buffer[o] = ".,-~:;=!*#$@"[N > 0 ? N : 0];
                }
            }
        }

        // Print the frame
        printf("\x1b[H");
        for (k = 0; 1200 > k; k++)
            putchar(k % width ? buffer[k] : 10);

        A += 0.04;
        B += 0.02;
    }

    return 0;
}
