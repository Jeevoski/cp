#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int val) {
    stack[++top] = val;
}

int pop() {
    if (top == -1) {
        printf("Error: Stack underflow\n");
        exit(1);
    }
    return stack[top--];
}

int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

// Evaluate prefix expression
int evaluatePrefix(char* expr) {
    int i;
    int len = strlen(expr);

    // Traverse from right to left
    for (i = len - 1; i >= 0; i--) {
        char ch = expr[i];

        if (isspace(ch))
            continue;

        if (isdigit(ch)) {
            push(ch - '0'); // Convert char to int
        }
        else if (isOperator(ch)) {
            int op1 = pop();
            int op2 = pop();
            int result;

            switch (ch) {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': result = op1 / op2; break;
                case '^': result = pow(op1, op2); break;
                default:
                    printf("Invalid operator: %c\n", ch);
                    exit(1);
            }
            push(result);
        }
        else {
            printf("Invalid character in expression: %c\n", ch);
            exit(1);
        }
    }

    return pop();
}

// ---------- MAIN FUNCTION ----------
int main() {
    char prefix[MAX];

    printf("Enter a prefix expression (single-digit operands): ");
    fgets(prefix, MAX, stdin);
    prefix[strcspn(prefix, "\n")] = '\0'; // remove newline

    int result = evaluatePrefix(prefix);
    printf("Result of prefix evaluation: %d\n", result);

    return 0;
}
