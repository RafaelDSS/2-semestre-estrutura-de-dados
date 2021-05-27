#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


void decimal_to_bin(int decimal, Stack *p1);
void decimal_to_oct(int decimal, Stack *p1);
void decimal_to_hex(int decimal, Stack *p1);

int main(void) {
    Stack *p1 = init_stack();
    int number;
    char option;


    printf(
        "Digite uma opção do meu.\n"
        "\t[a] = Decimal para Binário.\n"
        "\t[b] = Decimal para Octal.\n"
        "\t[c] = Decimal para Hexadecimal.\n"
        ">>> "
    );
    scanf("%c", &option);

    printf("Digite um valor decimal: ");
    scanf("%d", &number);

    switch(option) {
        case 'a':
            decimal_to_bin(number, p1);
            break;
        case 'b':
            decimal_to_oct(number, p1);
            break;
        case 'c':
            decimal_to_hex(number, p1);
            break;
    }

    return 0;
}
void decimal_to_bin(int decimal, Stack *p1) {
    int value;
    int length_stack;

    while (decimal > 0) {
        push(p1, (decimal % 2));
        decimal = decimal / 2;
    }

    length_stack = size_stack(p1);
    printf("Binário: ");
    for (int i = 0; i < length_stack; i++) {
        value = pop(p1);
        printf("%d", value);
    }
    printf("\n");
}

void decimal_to_oct(int decimal, Stack *p1) {
    int value;
    int length_stack;

    while (decimal > 0) {
        push(p1, (decimal % 8));
        decimal = decimal / 8;
    }

    length_stack = size_stack(p1);
    printf("Octal: ");
    for (int i = 0; i < length_stack; i++) {
        value = pop(p1);
        printf("%d", value);
    }
    printf("\n");

}

void decimal_to_hex(int decimal, Stack *p1) {
    int value;
    int length_stack;

    while (decimal > 0) {
        int res = decimal % 16;

        decimal = decimal / 16;
        if (res <= 9)
            push(p1, (res + 48));
        else
            push(p1, (res + 87));
    }

    length_stack = size_stack(p1);
    printf("Hexadecimal: 0x");
    for (int i = 0; i < length_stack; i++) {
        value = pop(p1);
        printf("%c", value);
    }
    printf("\n");
}
