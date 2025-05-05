#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    void *next;
    int data;
} Node ;

Node *head = NULL;

Node *addNode(int data){
     Node *new = NULL;

    if(head == NULL){
        new = malloc(sizeof(Node));
        if(new == NULL)
        return NULL;
    
    new->data = data;
    head = new;
    new->next = NULL;
    } else{
        new = malloc(sizeof(Node));
        if(new == NULL)
        return NULL;
    
    new->data = data;
    new->next = head;
    head = new;
    }
    return new;
}

int removeNode(int data){
    Node *current = head;
    Node *prev = head;
    while(current != NULL){
        if(current->data == data){
            if(current == head){
                head = current->next;
            } else{
                prev->next = current->next;
                free(current);
                current = NULL;
            }

            return 1;
        }
        prev = current;
        current = current->next;
    }

    return 0;
}

Node *insertNode(int data, int position){
    Node *current = head;
    while(current != NULL && position != 0){
        position--;
    }

    if(position != 0){
        printf("Requested too far into list\n");
        return NULL;
    }

    Node *new = malloc(sizeof(Node));
    if(new == NULL)
        return NULL;
    
    new->data = data;
    new->next = current->next;
    current->next = new;

    return new;
}

void printList(){
    Node *current = head;
    while(current != NULL){
        printf("%d->", current->data);
        current = current->next;
    }
    printf("\n");
    return;
}

void printMenu(){
    printf("You can do the following options:\n");
    printf("\t1. Add a node\n");
    printf("\t2. Remove a node\n");
    printf("\t3. Insert a node\n");
    printf("\t4. Print the list\n");
    printf("\t5. Quit\n");
    return;
}


int main(int argc, char **argv){
    
    int option = -1;
    int option2 = 0;
    while(option != 5){
        printMenu();
        int num_received = scanf("%d", &option);
        if(num_received == 1 && option > 0 && option <= 4){
            switch ((option))
            {
            case 1:
                printf("What data should you insert?: ");
                scanf("%d", &option);
                Node *new = addNode(option);
                break;
            case 2:
                printf("What data should you remove?: ");
                scanf("%d", &option);
                int success = removeNode(option);
                if(!success)
                printf("Element not found!");
                break;
            case 3:
                printf("What data should you like to insert?: ");
                scanf("%d", &option);
                printf("What position?: \n");
                scanf("%d", &option2);
                Node *new = insertNode(option, option2);
                if(new == NULL){
                    printf("Failed to complete operation");
                }
                break;
            case 4:
            printList();
                break;
            case 5:
                break;
            }
        }
    }
    return 0;
}