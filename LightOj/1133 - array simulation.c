#include<stdio.h>
int main()
{
    int ara[100], m,n,caseno=0,t,number,x,y,i,j,temp;
    char command;

    scanf("%d", &t);

    while(t--) {
        scanf("%d %d", &n, &m);

        for(i=0; i<n; i++) {
            scanf("%d", &ara[i]);
        }

        while(m--) {

            scanf(" %c", &command);

            if(command == 'S') {
                    scanf("%d", &number);

                    for(i=0; i<n; i++) {
                        ara[i] = ara[i] + number;
                    }
            }
            else if(command == 'M') {
                    scanf("%d", &number);

                    for(i=0; i<n; i++) {
                        ara[i] = ara[i] * number;
                    }
            }
            else if(command == 'D') {
                    scanf("%d", &number);

                    for(i=0; i<n; i++) {
                        ara[i] = ara[i] / number;
                    }
            }
            else if(command == 'R') {
                   for(i=0, j=n-1; i<j ; i++, j--) {
                        temp = ara[i];
                        ara[i] = ara[j];
                        ara[j] = temp;
                    }
            }
            else if(command == 'P') {
                    scanf("%d %d", &x,&y);

                    temp = ara[x];
                    ara[x] = ara[y];
                    ara[y] = temp;
            }
        }

        printf("Case %d:\n", ++caseno);

        for(i=0; i<n-1; i++) {
            printf("%d ", ara[i]);
        }
        printf("%d\n", ara[i]);
    }
}
