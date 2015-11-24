/** TDM-GCC x64 4.7.1 **/


#include <stdio.h>
#include <stdlib.h>

#define N 4

/*Function to Push*/
void push(int element);
/*Function to Pop*/
int pop(void);

/*Function to Display stack*/
void display(void);

/*Global declarations*/
static int stackar[N], top = -1;

int main() {
    char choice, ch;
    int n, po; //this is local to main()
    do {
        printf("\n********************\n");
        printf("A.PUSH\nB.POP\nD.DISPLAY\nE.EXIT\n");
        printf("GIVE CHOICE: ");
        choice = getchar();
        fflush(stdin); //clear any extra characters or whitespaces typed in after "choice"
        printf("\n");

        switch (choice) {
            case 'A':
            case 'a':
                printf("push number?: ");
                scanf("%d", &n);
                fflush(stdin);
                push(n);
                if (top != (N - 1))
                    printf("%d PUSHED!\n\n", stackar[top]);
                break;
            case 'B':
            case 'b':
                po = pop();
                if (top != -1)
                    printf("%d POPED!\n\n", po);
                break;
            case 'D':
            case 'd':
                display();
                break;
            case 'E':
            case 'e':
                printf("PROGRAM WILL EXIT__");
                exit(0); //exits all loops

            default:
                printf("INCORRECT CHOICE! TRY AGAIN!!\n\n");

        }
    } while (choice != 'e' || choice != 'E');

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
    int n;

    if (top <= -1)
        printf("\nOPERATION FAILED.\nTHE STACK IS EMPTY!!\n\n");
    else {
        n = stackar[top];
        top--;
        return (n);
    }
}

void display(void) {
    int i;
    printf("\n#THE STACK#\n\n");
    /*shows empty*/
    for (i = 0; i < N - (top + 1); i++) {
        printf("    |   |\n");
        printf("     ___ \n");
    }
    /*shows elements*/
    for (i = 0; i <= top; i++) {
        printf("    |%3d|", stackar[top - i]);
        if (i == 0) printf("<--TOP");
        printf("\n");
        printf("     ___ \n");
    }
}
