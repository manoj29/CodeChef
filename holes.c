#include <stdio.h>
#include <stdlib.h>

int main()
{
    int testcases, count;
    scanf("%d", &testcases);
    while(testcases--) {
        char ch;
        count = 0;
        scanf("%c", &ch);
        do {
            if(ch == 'A' || ch == 'D' || ch == 'O' || ch == 'P' || ch == 'Q' || ch == 'R')
                count++;
            else if (ch == 'B')
                count += 2;
        }while (scanf("%c", &ch) && isalpha(ch));
        printf("%d\n",count);
    }
}
