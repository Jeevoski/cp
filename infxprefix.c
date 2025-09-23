#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

// Stack for characters
char stack[MAX];
int top = -1;

void push(char ch) {
    stack[++top] = ch;
}

char pop() {
    if (top == -1) return -1;
    return stack[top--];
}

char peek() {
    return stack[top];
}

int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

int precedence(char ch) {
    if (ch == '^') return 3;
    if (ch == '*' || ch == '/' || ch == '%') return 2;
    if (ch == '+' || ch == '-') return 1;
    return 0;
}

int isRightAssociative(char op) {
    return op == '^';
}

int isOperand(char ch) {
    return isalpha(ch) || isdigit(ch);
}

// Reverse a string
void reverse(char* exp) {
    int len = strlen(exp);
    for (int i = 0; i < len / 2; i++) {
        char temp = exp[i];
        exp[i] = exp[len - i - 1];
        exp[len - i - 1] = temp;
    }
}

// Swap '(' and ')' in a string
void swapBrackets(char* exp) {
    for (int i = 0; exp[i]; i++) {
        if (exp[i] == '(')
            exp[i] = ')';
        else if (exp[i] == ')')
            exp[i] = '(';
    }
}

// Convert Infix to Postfix
void infixToPostfix(char* infix, char* postfix) {
    int j = 0;
    for (int i = 0; infix[i]; i++) {
        char ch = infix[i];

        if (isOperand(ch)) {
            postfix[j++] = ch;
        }
        else if (ch == '(') {
            push(ch);
        }
        else if (ch == ')') {
            while (top != -1 && peek() != '(')
                postfix[j++] = pop();
            pop(); // remove '('
        }
        else if (isOperator(ch)) {
            while (top != -1 && isOperator(peek()) &&
                   (precedence(peek()) > precedence(ch) ||
                    (precedence(peek()) == precedence(ch) && !isRightAssociative(ch)))) {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }

    while (top != -1)
        postfix[j++] = pop();
    
    postfix[j] = '\0';
}

// Infix to Prefix
void infixToPrefix(char* infix, char* prefix) {
    char revInfix[MAX], postfix[MAX];

    strcpy(revInfix, infix);
    reverse(revInfix);
    swapBrackets(revInfix);
    top = -1; // reset stack
    infixToPostfix(revInfix, postfix);
    reverse(postfix);
    strcpy(prefix, postfix);
}

// ---------- MAIN FUNCTION ----------
int main() {
    char infix[MAX], prefix[MAX];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPrefix(infix, prefix);

    printf("Prefix expression: %s\n", prefix);

    return 0;
} write algorithm for main code and functions
