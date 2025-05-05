#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node *next;  // Corrected to use `struct Node *` instead of `void *`
    int data;
} Node;

Node *head = NULL;

Node *addNode(int data) {
    Node *newNode = NULL;  // Changed variable name from 'new' to 'newNode'

    if (head == NULL) {
        newNode = malloc(sizeof(Node));
        if (newNode == NULL) return NULL;
        
        newNode->data = data;
        head = newNode;
        newNode->next = NULL;
    } else {
        newNode = malloc(sizeof(Node));
        if (newNode == NULL) return NULL;
        
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }
    return newNode;
}

int removeNode(int data) {
    Node *current = head;
    Node *prev = NULL;

    while (current != NULL) {
        if (current->data == data) {
            if (current == head) {
                head = current->next;  // Removing the head node
            } else {
                prev->next = current->next;  // Re-linking the previous node
            }
            free(current);
            return 1;  // Node removed successfully
        }
        prev = current;
        current = current->next;
    }
    return 0;  // Node with the given data not found
}

Node *insertNode(int data, int position) {
    Node *current = head;
    Node *newNode;

    // If the position is 0, we are inserting at the head
    if (position == 0) {
        newNode = malloc(sizeof(Node));
        if (newNode == NULL) return NULL;
        newNode->data = data;
        newNode->next = head;
        head = newNode;
        return newNode;
    }

    // Traverse the list until we find the correct position or reach the end
    while (current != NULL && --position > 0) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Position is out of bounds.\n");
        return NULL;
    }

    newNode = malloc(sizeof(Node));
    if (newNode == NULL) return NULL;

    newNode->data = data;
    newNode->next = current->next;
    current->next = newNode;

    return newNode;
}

void printList() {
    Node *current = head;
    while (current != NULL) {
        printf("%d->", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void printMenu() {
    printf("You can do the following options:\n");
    printf("\t1. Add a node\n");
    printf("\t2. Remove a node\n");
    printf("\t3. Insert a node\n");
    printf("\t4. Print the list\n");
    printf("\t5. Quit\n");
}

int main() {
    int option = -1;
    int option2 = 0;

    while (option != 5) {
        printMenu();
        int num_received = scanf("%d", &option);
        if (num_received == 1 && option > 0 && option <= 4) {
            switch (option) {
                case 1:
                    printf("What data should you insert?: ");
                    scanf("%d", &option);
                    addNode(option);
                    break;
                case 2:
                    printf("What data should you remove?: ");
                    scanf("%d", &option);
                    if (!removeNode(option)) {
                        printf("Element not found!\n");
                    }
                    break;
                case 3:
                    printf("What data should you like to insert?: ");
                    scanf("%d", &option);
                    printf("At what position?: ");
                    scanf("%d", &option2);
                    if (insertNode(option, option2) == NULL) {
                        printf("Failed to complete operation.\n");
                    }
                    break;
                case 4:
                    printList();
                    break;
            }
        }
    }

    return 0;
}
