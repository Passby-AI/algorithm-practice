#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EXPR_SIZE 100


struct Stack{
    int top;
    unsigned capacity;
    char* array;
};

struct Stack* createStack(unsigned capacity)
{
    struct  Stack* stack=(struct Stack*)malloc(sizeof(struct Stack));
    if(!stack)  return NULL;
    stack->top=-1;
    stack->capacity=capacity;
    stack->array=(char*) malloc(stack->capacity*sizeof(char));
    if(!stack->array)   return NULL;
    return stack;
}

//Check whether the stack is empty
int isEmpty(struct Stack*stack)
{
    return stack->top==-1;
}

char peak(struct Stack* stack){
    if(!isEmpty(stack))
        return stack->array[stack->top];
    return '$';
}

char pop(struct Stack*stack){
    if(!isEmpty(stack))
        return stack->array[stack->top--];
    return '$';
}

void push(struct Stack* stack,char op){
    stack->array[++stack->top]=op;
}

int getPrecedence(char ch){
    switch(ch){
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case'^':
            return 3;
        }
    return -1;
}

void infixToPostfix(char* infix)
{
    int i,k;
    struct Stack* stack = createStack(strlen(infix));
    if(!stack) {
        printf("Fail to malloc the roam\n");
    }

    char postfix[MAX_EXPR_SIZE];

    for(i=0,k=-1;infix[i];i++){
        if(isalnum(infix[i])){
            postfix[++k]=infix[i];
        }
        else if (infix[i]=='('){
            push(stack,infix[i]);
        }
        else if (infix[i]==')'){
            while(!isEmpty(stack)&&peak(stack)!='('){
                    postfix[++k]=pop(stack);
                    }
            if(isEmpty(stack) || peak(stack)!='('){
            printf("Invalid expression\n");
            return;
            }
            else{
            pop(stack);
            }
        }

        else{
            while(!isEmpty(stack)&&getPrecedence(infix[i])<=getPrecedence(peak(stack)))
            {
                postfix[++k]=pop(stack);
            }
            push(stack,infix[i]);
                    }
            }

            while(!isEmpty(stack)){
            postfix[++k]=pop(stack);

            }
            postfix[++k]='\0';
            printf("%s\n",postfix);
            
            free(stack->array);
            free(stack);
            }
int main(){
    char infix[MAX_EXPR_SIZE];
    printf("Please put in\n");
    scanf("%s",infix);

    infixToPostfix(infix);
    return 0;
}
