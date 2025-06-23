#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_STACKS 8

typedef struct 
{
    int capacity;
    int currentSize;
    int *collection;
}Stack;

typedef struct 
{
    char stackName[64];
    Stack *stack;
}VariableStack;


Stack *createStack(int capacity);
void *deleteStack(Stack *stack);
bool isFull(Stack *stack);
bool isEmpty(Stack *stack);
bool push(Stack *stack, int element);
bool pop(Stack *stack, int *element);
bool peek(Stack *stack, int *element);

int main()
{
    char *inputName[64];
    int action = 0, stackCap = 0, stackCount = 0, element = 0;
    char *option[64];
    VariableStack stackInstance[MAX_STACKS];

    while(action != 6)
    {
        printf("=================================\n1.Create New Stack | 2. Delete Stack | 3. Push to Stack | 4. Pop a Stack | 5. Peek a Stack | 6. Exit\n=================================\n:");
        scanf("%d", &action);

        switch (action)
        {
        case 1:
            {
                printf("Name the Stack(No Spaces): ");
                scanf("%s", inputName);
                printf("Enter Stack Capacity: ");
                scanf("%d", &stackCap);

                strcpy(stackInstance[stackCount].stackName, inputName);
                stackInstance[stackCount].stack = createStack(stackCap);
                if(stackInstance[stackCount].stack == NULL) return 1;
                stackCount++;

                printf("Stack successfully created!\n\n");
                break;
            }
        case 2:
            {
                bool stackDeleted = false;
                printf("What stack would you like to delete?:\n");
                for(int i = 0; i < MAX_STACKS; i++)
                {
                    printf("%s , ", stackInstance[i]);
                }
                printf("\n\n");
                scanf("%s", option);

                for(int i = 0; i < MAX_STACKS; i++)
                {
                   if(strcmp(stackInstance[i].stackName, option) == 0)
                   {
                    deleteStack(stackInstance[i].stack);
                    strcpy(stackInstance[i].stackName, "");
                    printf("Stack Successfully Destroyed!\n\n");
                    stackDeleted = true;
                    stackCount--;
                    break;
                   }
                }

                if(stackDeleted == false) printf("Invalid Stack or Could not be deleted\n\n");
                break;
            }
        case 3:
        {
            printf("Select a Stack:\n");
            for(int i = 0; i < MAX_STACKS; i++)
            {
                printf("%s , ", stackInstance[i].stackName);
            }
            printf("\n\n");
            scanf("%s", &option);
            printf("Enter a value: ");
            scanf("%d", &element);

            for(int i = 0; i < MAX_STACKS; i++)
            {
                if(strcmp(stackInstance[i].stackName, option) == 0)
                {
                    bool tryPush = push(stackInstance[i].stack, element);
                    if(tryPush == 1) {printf("Successfully pushed %d to Stack: %s\n\n", element, stackInstance[i].stackName);}
                    else{printf("Could not push to Stack or Stack is full\n\n");}
                    break;
                }
            }
            break;
        }
        case 4:
        {
            printf("Select a Stack:\n");
            for(int i = 0; i < MAX_STACKS; i++)
            {
                printf("%s , ", stackInstance[i].stackName);
            }
            printf("\n\n");
            scanf("%s", &option);

            for(int i = 0; i < MAX_STACKS; i++)
            {
                if(strcmp(stackInstance[i].stackName, option) == 0)
                {
                    bool tryPop = pop(stackInstance[i].stack, &element);
                    if(tryPop == 1) {printf("Successfully popped %d on Stack-%s\n\n", element, stackInstance[i].stackName);}
                    else{printf("Could not pop Stack or Stack is Empty\n\n");}
                    break;
                }
            }
            break;
        }
        case 5:
        {
            printf("Select a Stack:\n");
            for(int i = 0; i < MAX_STACKS; i++)
            {
                printf("%s , ", stackInstance[i].stackName);
            }
            printf("\n\n");
            scanf("%s", &option);

            for(int i = 0; i < MAX_STACKS; i++)
            {
                if(strcmp(stackInstance[i].stackName, option) == 0)
                {
                    bool tryPeek = peek(stackInstance[i].stack, &element);
                    if(tryPeek == 1) {printf("%d is on top of Stack-%s\n\n", element, stackInstance[i].stackName);}
                    else{printf("Could not peek at Stack or Stack is Empty\n\n");}
                    break;
                }
            }
            break;
        }
        default:
            printf("Invalid Input!\n\n");
            break;
        }
    }

   for (int i = 0; i < stackCount; i++)
    {
        if (stackInstance[i].stack != NULL)
        {
            stackInstance[i].stack = deleteStack(stackInstance[i].stack);
        }
    }
    exit(0);
}

Stack *createStack(int capacity)
{
    if(capacity <= 0) return NULL;

    Stack *stack = malloc(sizeof(Stack));
    if(stack == NULL) return NULL;

    stack->collection = malloc(sizeof(int) * capacity);
    if (stack->collection == NULL)
    {
        free(stack);
        return NULL;
    }

    stack->capacity = capacity;
    stack->currentSize = 0;
    
    return stack;
}

void *deleteStack(Stack *stack)
{
    free(stack->collection);
    free(stack);
}

bool isFull(Stack *stack)
{
    return stack->capacity == stack->currentSize;
}

bool isEmpty(Stack *stack)
{
    return stack->currentSize == 0;
}

bool push(Stack *stack, int element)
{
    if(isFull(stack))
    {
        printf("Stack is Full!\n");
        return false;
    }

    stack->collection[stack->currentSize] = element;
    stack->currentSize++;
    return true;
}

bool pop(Stack *stack, int *element)
{
    if(isEmpty(stack))
    {
        printf("Stack is Empty!\n");
        return false;
    }

    stack->currentSize--;
    *element = stack->collection[stack->currentSize];
    return true;
}

bool peek(Stack *stack, int *element)
{
    if(isEmpty(stack))
    {
        printf("Stack is Empty!\n");
        return false;
    }

    *element = stack->collection[stack->currentSize - 1];
    return true;
}