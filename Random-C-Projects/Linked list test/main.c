#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>

typedef struct Node
{
    struct Node *nextNode;
    char* data;
} Node;

Node *head = NULL;

Node* addNode(char* data)
{
    Node* new = NULL;
    
    if(head == NULL)
    {
        new = malloc(sizeof(Node));
        if(new == NULL) {return NULL;}

        new->data = strdup(data);
        head = new;
        new->nextNode = NULL;
    }
    else
    {
        new = malloc(sizeof(Node));
        if(new == NULL) {return NULL;}

        new->data = strdup(data);
        new->nextNode = head;
        head = new;
    }  

    return new;
}

int removeNode(char* data)
{
    Node *current = head;
    Node *prev = head;

    while(current != NULL)
    {
        if(strcmp(current->data, data) == 0)
        {
            if(current == head)
            {
                head = current->nextNode;
            }
            else
            {
                prev->nextNode = current->nextNode;
                
            }
            free(current);
            return 1;
        }
        prev = current;
        current = current->nextNode;
    
    }
    return 0;
}

Node* insertNode(char* data, int position)
{

    if (position < 0) {
        printf("Invalid position.\n");
        return NULL;
    }

    Node *new = malloc(sizeof(Node));
    if (new == NULL) return NULL;

    new->data = strdup(data); 
    new->nextNode = NULL;

    if (position == 0) {
        new->nextNode = head;
        head = new;
        return new;
    }

    Node *current = head;
    for (int i = 0; i < position - 1 && current != NULL; i++) {
        current = current->nextNode;
    }

    if (current == NULL) {
        printf("Position is out of bounds.\n");
        free(new);
        return NULL;
    }

    new->nextNode = current->nextNode;
    current->nextNode = new;

    return new;

}

void printList()
{
    Node* current = head;

    while(current != NULL)
    {
        printf("[%s], ", current->data);
        current = current->nextNode;
    }
    
}

void printMenu()
{
    printf("Current list: \n");
    printf("{");
    printList();
    printf("}\n\n");
    printf("|1. Add a Node|\n|2.Remove a Node|\n|3.Insert a Node|\n|4.Quit|\n");
    printf("INPUT: ");

}

char* removeNewline(char * string)
{
    
    size_t len = strlen(string);
    if (len > 0 && string[len - 1] == '\n') {
        string[len - 1] = '\0';
    }

    return string;
}

int main(int argc, char* *argv)
{
    int num_received;
    char* option[100];
    int option2 = 0;

    printf("This is a  Singly Linked list test with strings.\n");
    while(1){

        
        printMenu();
        scanf("%d", &num_received);
        getchar();
        Sleep(250);

       

        switch ((num_received))
        {
            case 1:
                printf("What data should you add?: ");
                fgets(option, sizeof(option), stdin);
                removeNewline(option); 
                
                Node *new = addNode(option);
                Sleep(450);
                break;

            case 2:
                printf("What data should you remove?: ");
                fgets(option, sizeof(option), stdin);
                removeNewline(option); 

                int success = removeNode(option);
                if(!success) {printf("\nElement not found!");}
                Sleep(450);
                break;

            case 3:
                printf("What data should you like to insert?: ");
                fgets(option, sizeof(option), stdin);
                removeNewline(option); 

                do
            {
                printf("What position?: (index starts at 0) \n");
                scanf("%d", &option2);
                getchar();

                new = insertNode(option, option2);
            } while(new == NULL);

                if(new == NULL){
                    printf("\nFailed to complete operation\n");
                }
            
                
                Sleep(450);
                break;
           
            case 4:
                exit(0);
                break;

            default:
                printf("INVALID INPUT!");
                Sleep(450);
                break;
        }
        
    }
    return 0;
}