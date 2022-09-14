#include <stdio.h>

int main(int argc, char const *argv[])
{
    int space = 0;
    char c;
    //char cc = void;
    while ((c = getchar()) != EOF) {
        //printf("%d\n", c != ' ');
        if (c == ' ')
            space++;
        if(space <= 1)  
            putchar(c);
        if (space == 2)
            space = 0;
    }
    return 0;
}
