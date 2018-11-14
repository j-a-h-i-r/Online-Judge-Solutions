#include<stdio.h>
#include<string.h>
int main()
{
    int n, j;
    char s[50];

    int x[50];
    memset(x, 0, sizeof(x));

    scanf("%s", s);

    for(j=0; s[j]; j++) x[s[j]-'0'] = 1;

    scanf("%d", &n);

    while(n--) {
        char t[50];


        scanf("%s", t);

        int i, cor = 0, incor = 0;

        for(i=0; s[i]; i++) {
            if(s[i]==t[i]) cor++;
            else {
                if(x[t[i] - '0'] == 1) incor++;
            }
        }

        printf("%d %d\n", cor, incor);
    }

    return 0;
}
