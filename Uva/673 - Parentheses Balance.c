#include<stdio.h>

int empty(char c[140]) {
    int i;
    for(i=0; c[i]!= '\n'; i++){
        if(c[i]=='('||c[i]==')'||c[i]=='['||c[i]==']') return 0;
    }
    return 1;
}

void no( ){
    printf("No\n");
}

int main()
{
    int t;
    scanf("%d", &t);
    getchar();

    while(t--) {
        char p[140], open[140];
        fgets(p, 140, stdin);

        if(empty(p) == 1) {
            printf("Yes\n");
            continue;
        }

        int i, b = 0, o = 0;

        for(i=0; p[i]!= '\n'; i++) {
            if(p[i]=='(') {
                open[o++] = p[i];
            }

            else if(p[i]=='[') {
                open[o++] = p[i];
            }

            else if(p[i]==')') {
                if (o == 0 ) {
                    no();
                    b = 1;
                    break;
                }
                if(open[o-1] == '(' ) o--;
                else {
                    no();
                    b = 1;
                    break;
                }
            }

            else if(p[i]==']') {
                if(o == 0) {
                    no();
                    b = 1;
                    break;
                }
                else if(open[o-1] == '[' ) o--;
                else {
                    no();
                    b = 1;
                    break;
                }
            }
        }

        if (b==1) continue;
        else if(o>0) no();

        else printf("Yes\n");
    }

    return 0;
}
