#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <unistd.h>

 struct Race{
     char name[10];
     char weakness[10];
     int base_dmg;
     int base_def;

 };

 struct Type{
    char name[10];
    int str;
    int agl;
    int intel;
 };

 void Race_details(struct Race rce){
    printf("\nYou are a %s.\n", rce.name);
    printf("Your weakness is a %s. \n", rce.weakness);
    printf("A base damage of %d. \n", rce.base_dmg);
    printf("And you have a base defense of %d.", rce.base_def);
 }
 void Type_details(struct Type typ){
    printf("\nYou are a %s type.\n", typ.name);
    printf("You have a base strenght of %d.\n", typ.str);
    printf("A base agility of %d.\n", typ.agl);
    printf("And a base intelligence of %d.\n", typ.intel);
}



int main()
{
    char race[10];
    char type[10];
    char cont = 'y';

struct Race races[] = {
    {"Gnome", "Knight", 17, 40},
    {"Knight", "Wizard", 26, 34},
    {"Wizard", "Gnome", 35, 16}
};

struct Type types[] = {
    {"Range", 14, 25, 16},
    {"Magic", 15, 13, 26},
    {"Melee",  28, 18, 12}
};


   printf("WELCOME!!\n");
   printf("Warning: Case Sensitive!!\n");
   sleep(1);

   while (cont == 'y') {
   printf("Select your race\n");
   printf("Gnome, Knight, Wizard\n");
   scanf("%s", race);
   printf("Select the type\n");
   printf("Range, Melee, Magic\n");
   scanf("%s", type);
   sleep(1);

   struct Race slct_Race = {"", "", 0, 0};
    for (int i = 0; i < sizeof(races) / sizeof(races[0]); i++) {
        if (strcmp(race, races[i].name) == 0) {
            slct_Race = races[i];
            break;
        }
    }
    if (strlen(slct_Race.name) == 0) {
        printf("ERRORRRRR???\n");
        return 1;
    }
    Race_details(slct_Race);

    struct Type slct_Type = {"", 0, 0, 0};
        for (int i = 0; i < sizeof(types) / sizeof(types[0]); i++) {
            if (strcmp(type, types[i].name) == 0){
            slct_Type = types[i];
            break;
            }
        }
    if (strlen(slct_Type.name) == 0) {
            printf("ERROR");
            return 1;
        }
    Type_details(slct_Type);

    sleep(2);

    char yn;
    printf("\nWrite to txt?? y/n:\n");
    scanf(" %c", &yn);

    if(yn == 'y' || yn == 'Y'){
        printf("Writing to file...");
        sleep(2);

        FILE *fpointer = fopen("Character.txt", "w");
            if(fpointer == NULL) {
                printf("Trouble Writing.. ERROR");
                return 1;}

        fprintf(fpointer, "CHARACTER SETTINGS:\n");
        fprintf(fpointer, "Race: %s\n", race);
        fprintf(fpointer, "Type: %s\n", type);
        fprintf(fpointer, "STATS:\n");
        fprintf(fpointer, "Base Damage: %d\n", slct_Race.base_dmg);
        fprintf(fpointer, "Base Defense: %d\n", slct_Race.base_def);
        fprintf(fpointer, "Strenght: %d\n", slct_Type.str);
        fprintf(fpointer, "Agility: %d\n", slct_Type.agl);
        fprintf(fpointer, "Intelligence: %d\n", slct_Type.intel);
        fclose(fpointer);
        printf("\nWritten to file successfuly");
    }

    else{
        printf("Terminating...");
        sleep(1);
    }

    printf("\nRead written file? y/n:\n");
    scanf(" %c", &yn);
    sleep(1);

    char line[300];
    if(yn == 'y' || yn == 'Y'){
        FILE *fpointer = fopen("Character.txt", "r");
        fgets(line, 300, fpointer);
        printf("%s", line);
        fgets(line, 300, fpointer);
        printf("%s", line);
        fgets(line, 300, fpointer);
        printf("%s", line);
        fgets(line, 300, fpointer);
        printf("%s", line);
        fgets(line, 300, fpointer);
        printf("%s", line);
        fgets(line, 300, fpointer);
        printf("%s", line);
        fgets(line, 300, fpointer);
        printf("%s", line);
        fgets(line, 300, fpointer);
        printf("%s", line);
        fgets(line, 300, fpointer);
        printf("%s", line);
        fclose(fpointer);
    }
    printf("\nRetry? y/n\n");
    scanf("%s", &cont);
   }


    return 0;
}
