#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main() {

    int t, i,j,k=0, len, num, caseno=0;

    char en[200], temp[4], c;

    scanf("%d", &t);

    while(t--) {

        scanf("%s", en);

        printf("Case %d: ", ++caseno);

        for (i=0; en[i]!='\0'; i) {

            c = en[i];

            i++;

            while(en[i] >= '0' && en[i] <= '9') temp[k++] = en[i++];


            temp[k] = '\0';
            num = atoi(temp); k = 0;

            while(num--) printf("%c", c);
        }
        printf("\n");
    }

    return 0;
}
