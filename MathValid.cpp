/* MathExpressionValidator.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MathValid.h"

/* Fungsi untuk memeriksa apakah tanda kurung seimbang */
int isBalanced(char* expression) {
    Stack bracketStack;
    initStack(&bracketStack);
    
    int i = 0;
    while (expression[i] != '\0') {
        if (expression[i] == '(' || expression[i] == '[' || expression[i] == '{') {
            push(&bracketStack, expression[i]);
        } else if (expression[i] == ')' || expression[i] == ']' || expression[i] == '}') {
            if (isStackEmpty(&bracketStack)) {
                clearStack(&bracketStack);
                return 0; // Tidak seimbang, ada kurung tutup tanpa kurung buka
            }
            
            char top = peek(&bracketStack);
            if ((expression[i] == ')' && top == '(') ||
                (expression[i] == ']' && top == '[') ||
                (expression[i] == '}' && top == '{')) {
                pop(&bracketStack);
            } else {
                clearStack(&bracketStack);
                return 0; // Tidak seimbang, kurung tidak cocok
            }
        }
        i++;
    }
    
    int result = isStackEmpty(&bracketStack);
    clearStack(&bracketStack);
    
    return result; // Seimbang jika stack kosong di akhir
}

/* Fungsi untuk memeriksa apakah operator valid */
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

/* Fungsi untuk memeriksa apakah karakter adalah operand (angka atau huruf) */
int isOperand(char ch) {
    return ((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'));
}

/* Fungsi untuk mendapatkan prioritas operator */
int precedence(char input) {
    switch (input) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return -1;
    }
}

/* Fungsi untuk validasi ekspresi matematika lengkap */
int isValidExpression(char* expression) {
    // Periksa kurung seimbang
    if (!isBalanced(expression)) {
        return 0;
    }
    
    int i = 0;
    int operandCount = 0;
    int operatorCount = 0;
    int prevIsOperator = 1; // Untuk memeriksa apakah ada dua operator berturut-turut
    
    while (expression[i] != '\0') {
        if (isOperand(expression[i])) {
            operandCount++;
            prevIsOperator = 0;
        } else if (isOperator(expression[i])) {
            if (prevIsOperator) {
                return 0; // Dua operator berturut-turut
            }
            operatorCount++;
            prevIsOperator = 1;
        } else if (expression[i] == '(' || expression[i] == '[' || expression[i] == '{') {
            prevIsOperator = 1; // Reset flag setelah kurung buka
        } else if (expression[i] == ')' || expression[i] == ']' || expression[i] == '}') {
            prevIsOperator = 0; // Reset flag setelah kurung tutup
        } else if (expression[i] != ' ') {
            return 0; // Karakter tidak valid
        }
        i++;
    }
    
    // Ekspresi valid jika jumlah operand = jumlah operator + 1
    return operandCount == operatorCount + 1 && !prevIsOperator;
}

/* Fungsi untuk mengubah ekspresi infix menjadi postfix */
void infixToPostfix(char* infix, char* postfix) {
    Stack stack;
    initStack(&stack);
    Queue queue;
    initQueue(&queue);
    
    int i = 0;
    int j = 0;
    
    while (infix[i] != '\0') {
        if (isOperand(infix[i])) {
            enqueue(&queue, infix[i]);
        } else if (infix[i] == '(') {
            push(&stack, infix[i]);
        } else if (infix[i] == ')') {
            while (!isStackEmpty(&stack) && peek(&stack) != '(') {
                enqueue(&queue, pop(&stack));
            }
            
            if (!isStackEmpty(&stack) && peek(&stack) == '(') {
                pop(&stack); // Buang kurung buka
            }
        } else if (isOperator(infix[i])) {
            while (!isStackEmpty(&stack) && peek(&stack) != '(' && 
                   precedence(infix[i]) <= precedence(peek(&stack))) {
                enqueue(&queue, pop(&stack));
            }
            push(&stack, infix[i]);
        }
        i++;
    }
    
    // Pop semua operator yang tersisa
    while (!isStackEmpty(&stack)) {
        enqueue(&queue, pop(&stack));
    }
    
    // Queue ke string postfix
    while (!isQueueEmpty(&queue)) {
        postfix[j++] = dequeue(&queue);
    }
    postfix[j] = '\0';
    
    clearStack(&stack);
    clearQueue(&queue);
}
