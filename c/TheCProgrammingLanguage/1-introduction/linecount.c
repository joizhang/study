#include <stdio.h>

int main(int argc, char const *argv[])
{
    int nl;
    char c;
    nl = 0;
    /**
    *getchar有一个int型的返回值.当程序调用getchar时.程序就等着用户按键.用
    *户输入的字符被存放在键盘缓冲区中.直到用户按回车为止(回车字符也放在缓冲区中).
    *当用户键入回车之后,getchar才开始从stdio流中每次读入一个字符.getchar
    *函数的返回值是用户输入的第一个字符的ASCII码,如出错返回-1,且将用户输
    *入的字符回显到屏幕.如用户在按回车之前输入了不止一个字符,其他字符会
    *保留在键盘缓存区中,等待后续getchar调用读取.也就是说,后续的getchar调
    *用不会等待用户按键,而直接读取缓冲区中的字符,直到缓冲区中的字符读完
    *为后,才等待用户按键.
    */
    char cc = getchar();
    printf("%c\n", cc);
    printf("\n");
    printf("%d\n", cc == '\n');
    /*while((c = getchar()) != 27) 
    {
        printf("%d\n", c == '\n');
        if (c == '\n')
            ++nl;
    }
        
    printf("%d\n", nl);
    printf("%d\n", c);*/
    return 0;
}