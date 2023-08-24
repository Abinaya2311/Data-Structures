#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

// Structure for the stack
struct Stack {
    int top;
    char items[MAX_SIZE];
};

// Function to initialize the stack
void initialize(struct Stack* stack) {
    stack->top = -1;
}

// Function to push an item onto the stack
void push(struct Stack* stack, char item) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
        exit(1);
    }
    stack->items[++(stack->top)] = item;
}

// Function to pop an item from the stack
char pop(struct Stack* stack) {
    if (stack->top == -1) {
        printf("Stack underflow\n");
        exit(1);
    }
    return stack->items[(stack->top)--];
}

// Function to return the top item from the stack without popping
char peek(struct Stack* stack) {
    return stack->items[stack->top];
}

// Function to check if a character is an operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Function to get the precedence of an operator
int getPrecedence(char ch) {
    switch (ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

// Function to convert infix expression to postfix expression
void infixToPostfix(char infix[], char postfix[]) {
    struct Stack stack;
    initialize(&stack);
    int i, j = 0;

    for (i = 0; infix[i] != '\0'; ++i) {
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {
            push(&stack, infix[i]);
        } else if (infix[i] == ')') {
            while (stack.top != -1 && peek(&stack) != '(') {
                postfix[j++] = pop(&stack);
            }
            if (stack.top == -1 || peek(&stack) != '(') {
                printf("Invalid expression\n");
                exit(1);
            }
            pop(&stack); // Pop '('
        } else if (isOperator(infix[i])) {
            while (stack.top != -1 && peek(&stack) != '(' &&
                   getPrecedence(peek(&stack)) >= getPrecedence(infix[i])) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, infix[i]);
        }
    }

    while (stack.top != -1) {
        if (peek(&stack) == '(') {
            printf("Invalid expression\n");
            exit(1);
        }
        postfix[j++] = pop(&stack);
    }

    postfix[j] = '\0';
}

// Function to evaluate a postfix expression
int evaluatePostfix(char postfix[]) {
    struct Stack stack;
    initialize(&stack);
    int i, operand1, operand2;

    for (i = 0; postfix[i] != '\0'; ++i) {
        if (isdigit(postfix[i])) {
            push(&stack, postfix[i] - '0');
        } else if (isOperator(postfix[i])) {
            operand2 = pop(&stack);
            operand1 = pop(&stack);
            switch (postfix[i]) {
                case '+':
                    push(&stack, operand1 + operand2);
                    break;
                case '-':
                    push(&stack, operand1 - operand2);
                    break;
                case '*':
                    push(&stack, operand1 * operand2);
                    break;
                case '/':
                    push(&stack, operand1 / operand2);
                    break;
            }
        }
    }

    return pop(&stack);
}

int main() {
    char infix[MAX_SIZE], postfix[MAX_SIZE];
    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    int result = evaluatePostfix(postfix);
    printf("Result of evaluation: %d\n", result);

    return 0;
}
