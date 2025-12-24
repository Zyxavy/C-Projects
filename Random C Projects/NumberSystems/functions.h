#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <stdlib.h>

//Variables
long long binary;
long decimal;
char octal[20];
char hex[20];

// Functions
void displayMenu();
long long binaryToDecimal(long long binary);
void binaryToHexadecimal(long long binary);
long long decimalToBinary(long decimal);
void decimalToHexadecimal(long decimal);
void decimalToOctal(long decimal);
long hexadecimalToDecimal(const char *hex);
void hexadecimalToBinary(const char *hex);
void hexadecimalToOctal(const char *hex);
long octalToDecimal(const char* octal);
void octalToHexadecimal(const char* octal);
void octalToBinary(const char* octal);
bool isBinary(long long binary);
bool isOctal(const char *octal);


#endif // FUNCTIONS_H