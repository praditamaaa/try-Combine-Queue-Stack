/* MathExpressionValidator.h */
#ifndef MATH_VALID_H
#define MATH_VALIDH

#include "Stack.h"
#include "Queue.h"

/* Fungsi-fungsi untuk validasi ekspresi matematika */
int isBalanced(char* expression);
int isValidExpression(char* expression);
void infixToPostfix(char* infix, char* postfix);
int precedence(char input);
int isOperator(char ch);
int isOperand(char ch);

#endif
