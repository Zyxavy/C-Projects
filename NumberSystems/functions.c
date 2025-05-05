#include "functions.h"

void displayMenu(){
    char choice[3];

    do{
        printf("***********************************************************************************************\n\t\t\t\t\tNumber System Converter!\n");
        printf("\t1. Binary to Decimal      |\t 2. Binary to Hexadecimal        |\t 3. Binary to Octal\n");
        printf("\t4. Decimal to Binary      |\t 5. Decimal to Hexadecimal       |\t 6. Decimal to Octal\n");
        printf("\t7. Hexadecimal to Decimal |\t 8. Hecadecimal to Binary        |\t 9. Hexadecimal to Octal\n");
        printf("\t10. Octal to Decimal      |\t 11. Octal to Hexadecimal        |\t 12. Octal to Binary\n");
        printf("\t0. to quit\n");
        printf("***********************************************************************************************\n");
        printf("Enter Prompt: ");
        scanf("%2s", &choice);

        int choiceNum = atoi(choice);
        
        switch (choiceNum)
        {
        case 1:
            printf("Enter a binary number: ");
            scanf("%lld", &binary);

            if (isBinary(binary)) {
                printf("Decimal: %lld", binaryToDecimal(binary));
            } else {
                printf("Invalid binary number!\n");
            }

            sleep(2);
            printf("\n\n\n");
            break;
        
        case 2:
            printf("Enter a binary number: ");
            scanf("%lld", &binary);

            if (isBinary(binary)) {
                binaryToHexadecimal(binary);
            } else {
                printf("Invalid binary number!\n");
            }

            sleep(2);
            printf("\n\n\n");
            break;

        case 3: 
            printf("Enter a binary number: ");
            scanf("%lld", &binary);

            if (isBinary(binary)) {
                printf("Octal: %llo\n", binaryToDecimal(binary));
            } else {
                printf("Invalid binary number!\n");
            }

            sleep(2);
            printf("\n\n\n");
            break;

        case 4:
            printf("Enter a decimal number: ");
            scanf("%ld", &decimal);
            printf("Binary: %lld\n", decimalToBinary(decimal));
            sleep(2);
            printf("\n\n\n");
            break;


        case 5: 
            printf("Enter a decimal number: ");
            scanf("%ld", &decimal);
            decimalToHexadecimal(decimal);
            sleep(2);
            printf("\n\n\n");
            break;

        
        case 6:           
            printf("Enter a decimal number: ");
            scanf("%ld", &decimal);
            decimalToOctal(decimal);
            sleep(2);
            printf("\n\n\n");
            break;
        
        case 7:          
            printf("Enter a hexadecimal number: ");
            scanf("%s", hex);
            printf("Decimal: %d\n", hexadecimalToDecimal(hex));
            sleep(2);
            printf("\n\n\n");
            break;
        
        case 8:             
            printf("Enter a hexadecimal number: ");
            scanf("%s", hex);
            hexadecimalToBinary(hex);
            sleep(2);
            printf("\n\n\n");
            break;
        
        case 9:             
            printf("Enter a hexadecimal number: ");
            scanf("%s", hex);
            hexadecimalToOctal(hex);
            sleep(2);
            printf("\n\n\n");
            break;
        
        case 10:           
            printf("Enter an octal number: ");
            scanf("%s", &octal);

            if (isOctal(octal)) {
                printf("Decimal: %d\n", octalToDecimal(octal));
            } else {
                printf("Invalid octal number!\n");
            }
        
            sleep(2);
            printf("\n\n\n");
            break;
        
        case 11:
            printf("Enter an octal number: ");
            scanf("%s", &octal);
           
            if (isOctal(octal)) {
                octalToHexadecimal(octal);
            } else {
                printf("Invalid octal number!\n");
            }

            sleep(2);
            printf("\n\n\n");
            break;
        
        case 12: 
            printf("Enter an octal number: ");
            scanf("%s", &octal);

            if (isOctal(octal)) {
                octalToBinary(octal);
            } else {
                printf("Invalid octal number!\n");
            }

            sleep(2);
            printf("\n\n\n");
            break;
        
        case 0:
                exit(0);
                break;
        default:
            printf("Invalid operation!\n");
            sleep(1);
            break;
        }


    } while(choice);
}

bool isBinary(long long binary) {
    while (binary > 0) {
        int digit = binary % 10;
        if (digit != 0 && digit != 1) {
            return false;
        }
        binary /= 10;
    }
    return true;
}

bool isOctal(const char *octal) {
    for (int i = 0; octal[i] != '\0'; i++) {
        if (octal[i] < '0' || octal[i] > '7') {
            return false;
        }
    }
    return true;
}


long long binaryToDecimal(long long binary) {
    long long decimal = 0, base = 1;
    while (binary > 0) {
        int lastDigit = binary % 10;
        decimal += lastDigit * base;
        binary /= 10;
        base *= 2;
    }
    return decimal;
}

void binaryToHexadecimal(long long binary) {
    long long decimal = binaryToDecimal(binary);
    printf("Hexadecimal: %lX\n", decimal);
}

long long decimalToBinary(long decimal) {
    long long binary = 0;
    int base = 1;
    while (decimal > 0) {
        int remainder = decimal % 2;
        binary += remainder * base;
        decimal /= 2;
        base *= 10;
    }
    return binary;
}

void decimalToHexadecimal(long decimal) {
    printf("Hexadecimal: %X\n", decimal);
}

void decimalToOctal(long decimal) {
    printf("Octal: %o\n", decimal);
}

long hexadecimalToDecimal(const char *hex) {
    long decimal = 0;
    sscanf(hex, "%x", &decimal);
    return decimal;
}

void hexadecimalToBinary(const char *hex) {
    long decimal = hexadecimalToDecimal(hex);
    printf("Binary: %lld\n", decimalToBinary(decimal));
}

void hexadecimalToOctal(const char *hex) {
    long decimal = hexadecimalToDecimal(hex);
    printf("Octal: %o\n", decimal);
}

long octalToDecimal(const char *octal) {
    long decimal = 0;
    sscanf(octal, "%o", &decimal);
    return decimal;
}

void octalToHexadecimal(const char *octal) {
    long decimal = octalToDecimal(octal);
    printf("Hexadecimal: %X\n", decimal);
}

void octalToBinary(const char *octal) {
    long decimal = octalToDecimal(octal);
    decimalToBinary(decimal);
}