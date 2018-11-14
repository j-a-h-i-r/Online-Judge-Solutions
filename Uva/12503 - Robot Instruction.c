#include<stdio.h>
int main()
{
    int t;
    scanf("%d", &t);
    getchar();

    while(t--) {
        int n, i, x = 0;
        scanf("%d", &n);
        int move[n+1];
        getchar();

        char ins[20];

        for(i=0; i<n; i++) {

            fgets(ins, 20, stdin);

            if(ins[0]=='L') {
                move[i] = -1;
                x--;
            }
            else if(ins[0]=='R') {
                move[i] = 1;
                x++;
            }
            else{
                int step;
                char *a, *b;
                sscanf(ins, "%*s %*s %d", &step);

                x = x + move[step-1];
                move[i] = move[step-1];
            }
        }

        printf("%d\n", x);
    }

    return 0;
}
