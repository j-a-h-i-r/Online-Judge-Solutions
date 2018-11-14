#include<stdio.h>
#include<string.h>
int main()
{
    freopen("in.text", "r", stdin);

    int t;
    char num[2][4] = {"one", "two"};
    scanf("%d", &t);

    while(t--) {
        char a[6];
        int i, k = 0;
        scanf("%s", a);

        if(strlen(a)==5) {
            printf("3aa\n");
            continue;
        }

        for(k = 0; k<2; k++) {
            int c = 0;
            for(i=0; a[i]; i++) {

                if(num[k][i] == a[i]) {
                    c++;
                }
            }

            if(c == strlen(a)-1) {
                    printf("%d\n", k+1);
            }

        }
    }
    return 0;
}
