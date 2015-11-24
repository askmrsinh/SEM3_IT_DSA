/** TDM-GCC x64 4.7.1 **/


#include <stdio.h>
#include <ctype.h>

#define N 50

int stackar[N];
int element, top = -1;

void push(int element);
int pop(void);

int main() {
    char ch, postfix[N + 1];

    printf("enter valid POSTFIX expresson: ");
    gets(postfix);
    int i = 0, op1, op2;

    while ((ch = postfix[i++]) != '\0') {
        if (isdigit(ch))
            push(ch - '0'); //Push the operand
        else {
            /*Operator,pop two operands*/
            op2 = pop();
            op1 = pop();
            switch (ch) {
                case '+':push(op1 + op2);
                    break;
                case '-':push(op1 - op2);
                    break;
                case '*':push(op1 * op2);
                    break;
                case '/':push(op1 / op2);
                    break;
                case '%':push(op1 % op2);
                    break;
            }
        }
    }

    printf("\n Given Postfix Expn: %s\n", postfix);
    printf("\n Result after Evaluation: %d\n", stackar[top]);

    return (0);
}

void push(int element) {
    if (top >= N - 1)
        printf("\nOPERATION FAILED.\nTHE STACK IS FULL!!\n\n");
    else {
        ++top;
        stackar[top] = element;
    }

}

int pop(void) {
    if (top <= -1)
        printf("\nOPERATION FAILED.\nTHE STACK IS EMPTY!!\n\n");
    else {
        return (stackar[top--]);
    }
}
