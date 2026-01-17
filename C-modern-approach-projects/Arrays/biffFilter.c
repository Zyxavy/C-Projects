/*
The prototypical Intemet newbie is a fellow named BIFF, who has a unique way of writing
messages. Here's a typical B1FF communique:kjihgfedcbaZYXWVUTSRQPONMLKJIHGFEDCBA
H3Y DUD3, C 15 RlLLY C00Ll1!!!i!!!!
Write a “BlFF filler that reads a message entered by the user and translates it into BlFF
speak:
Enter message: Hey dude, C is rilly cool
In BlFF-speak: H3Y DUD3, C 15 RlLLY C00L!!!!!!!!!!
Your program should convert the message to upper-case letters, substitute digits for certain
letters (A ^4. B ^8. E->3,1->1,0 ^ 0 . S~>5). and (hen append 10or so exclamation marks.
Hint: Store the original message in an array ofcharacters, then go back through the array,
translating and printing characters one by one.
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MSG_SIZE strlen(message)
#define MAX_CHARS 100

int main(void)
{
    char message[MAX_CHARS];
    char ch = '!';

    printf("Enter Message: ");
    fgets(message, MAX_CHARS, stdin);

    for(size_t i = 0; i < MSG_SIZE; i++)
    {
        message[i] = toupper(message[i]);
        switch (message[i])
        {
        case 'A': message[i] = '4'; break;
        case 'B': message[i] = '8'; break;
        case 'E': message[i] = '3'; break;
        case 'I': message[i] = '1'; break;
        case 'O': message[i] = '0'; break;
        case 'S': message[i] = '5'; break;
        }
    }

    message[MSG_SIZE - 1] = '!';
    for(size_t j = 0; j < 9; j++) strncat(message, &ch, 1);
    message[MSG_SIZE + 1] = '\0';
    
    printf("In B1FF-speak: ");
    for(size_t i = 0; i < MSG_SIZE; i++) printf("%c", message[i]);
    
    return 0;
}

// TTC: 19:52