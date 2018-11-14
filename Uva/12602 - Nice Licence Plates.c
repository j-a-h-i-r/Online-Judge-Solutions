#include<stdio.h>
#include<math.h>
int main()
{
    int t;
    scanf("%d", &t);
    getchar();
    while(t--) {
        char alpha[5], a, b, c, d;
        int num;
        scanf("%c%c%c%c", &a,&b,&c,&d);
        alpha[0] = a; alpha[1] = b;
        alpha[2] = c; alpha[3] = '\0';
        scanf("%d", &num);
        getchar();

        int alphaSum = (alpha[0]-'A')*676 +
            (alpha[1]-'A')*26 + (alpha[2]-'A');

        if (abs(num-alphaSum)<=100) printf("nice\n");
        else printf("not nice\n");
    }
    return 0;
}
