#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int stack[300];
int count = 0;


void push(int x ){
    if(count == 300) {
        fprintf(stderr,"Error with count");
        return;
    }
    stack[count] = x;
    count++;
}

int pop(){
    if(count == 0){
        fprintf(stderr, "Nothing to pop\n");
        return -1;
    }
    int result = stack[count - 1];
    count--;
    return result;
}
int main()
{
    push("VOID");
    push("MSDA");






    return 0;
}
