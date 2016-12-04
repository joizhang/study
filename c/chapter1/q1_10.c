#include <stdio.h>

int main()
{
    char c;
    while ((c = getchar()) != 27) {

        if (c == '\t')  {
            putchar('\\');
            putchar('t');
        } else if (c == '\b') {
              putchar('\\');
              putchar('b');
        } else if (c = '\\') {
            putchar('\\');
            putchar('\\');
        } else
            putchar(c);
    }
}