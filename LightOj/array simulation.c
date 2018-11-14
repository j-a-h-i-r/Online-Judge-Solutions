#include<stdio.h>
int main()
{
    int ara[100], m,n,caseno=0,t,number,x,y,i,temp;
    char command;

    scanf("%d", &t);

    while(t--) {
        scanf("%d %d", &m, &n);

        for(i=0; i<m; i++) {
            scanf("%d", &ara[i]);
        }

        while(n--) {

            scanf(" %c", &command);

            switch(command) {
                case 'S':
                    scanf("%d", &number);

                    for(i=0; i<m; i++) {
                        ara[i] = ara[i] + number;
                    }
                    break;
                case 'M':
                    scanf("%d", &number);

                    for(i=0; i<m; i++) {
                        ara[i] = ara[i]*number;
                    }
                    break;
                case 'R':
                   for(i=0, j=m-1; i<j ; i++, j--) {
                        temp = ara[i];
                        ara[i] = ara[j];
                        ara[j] = temp;
                    }
                    break;
                case 'P':
                    scanf("%d %d", &x,&y);

                    temp = ara[x];
                    ara[x] = ara[y];
                    ara[y] = temp;
            }
        }
    }
}
