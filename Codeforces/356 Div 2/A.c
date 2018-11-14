#include<stdio.h>
int main()
{
    int t[6], sum = 0, i, j;

    for(i=0; i<5; i++) {
        scanf("%d", &t[i]);
        sum = sum + t[i];
    }

    int m = 0, c=0;

    for(i=0; i<4; i++) {
        c = 1;
        for(j=i+1; j<5; j++) {
            if(t[i] == t[j]) c++;
        }

        if(c>3) c = 3;

        if(c>=2 && (t[i]*c) > m ) m = t[i]*c;
    }

    printf("%d\n", sum - m);

    return 0;

}
