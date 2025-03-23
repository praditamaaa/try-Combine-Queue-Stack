/* main.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MathValid.h"

#define MAX_EXPR_SIZE 100

void showMenu();
void validateExpression();
void convertToPostfix();

int main() {
    int choice;
    
    do {
        showMenu();
        printf("Pilih menu (1-3): ");
        scanf("%d", &choice);
        getchar(); // Membersihkan buffer
        
        switch (choice) {
            case 1:
                validateExpression();
                break;
            case 2:
                convertToPostfix();
                break;
            case 3:
                printf("Terima kasih telah menggunakan program ini!\n");
                break;
            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }
        
        printf("\n");
    } while (choice != 3);
    
    return 0;
}

void showMenu() {
    printf("======================================\n");
    printf("    VALIDASI EKSPRESI MATEMATIKA     \n");
    printf("======================================\n");
    printf("1. Validasi Ekspresi\n");
    printf("2. Konversi Infix ke Postfix\n");
    printf("3. Keluar\n");
    printf("======================================\n");
}

void validateExpression() {
    char expression[MAX_EXPR_SIZE];
    
    printf("\nMasukkan ekspresi matematika: ");
    fgets(expression, MAX_EXPR_SIZE, stdin);
    
    // Menghapus newline dari fgets
    if (expression[strlen(expression) - 1] == '\n') {
        expression[strlen(expression) - 1] = '\0';
    }
    
    printf("\nValidasi kurung: ");
    if (isBalanced(expression)) {
        printf("VALID\n");
    } else {
        printf("TIDAK VALID - Kurung tidak seimbang\n");
    }
    
    printf("Validasi ekspresi: ");
    if (isValidExpression(expression)) {
        printf("VALID\n");
    } else {
        printf("TIDAK VALID - Format ekspresi salah\n");
    }
}

void convertToPostfix() {
    char infix[MAX_EXPR_SIZE];
    char postfix[MAX_EXPR_SIZE];
    
    printf("\nMasukkan ekspresi infix: ");
    fgets(infix, MAX_EXPR_SIZE, stdin);
    
    // Menghapus newline dari fgets
    if (infix[strlen(infix) - 1] == '\n') {
        infix[strlen(infix) - 1] = '\0';
    }
    
    if (!isBalanced(infix)) {
        printf("Error: Kurung tidak seimbang!\n");
        return;
    }
    
    infixToPostfix(infix, postfix);
    printf("Postfix: %s\n", postfix);
}
