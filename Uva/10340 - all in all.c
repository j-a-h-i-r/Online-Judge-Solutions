#include<stdio.h>
#include<stdlib.h>

int main()
{
    int c, size = 15000, i = 0;
    char *a;

    a =(char*)malloc(size*sizeof(char));

    while( (c = getchar()) != EOF ) {

        i++;

        if(i == size-5) {
            size = size*2;

            a = realloc(a, size);
        }

        if(c == ' ') {

            int j = 0;
            a[i-1] = '\0';

            while((c=getchar()) != '\n' && i!=j && c!=EOF ) {
                if(c == a[j]) {
                    j++;
                }
            }

            if(a[j]=='\0') printf("Yes\n");
            else printf("No\n");

            free(a);
            size = 15000;
            a = (char*)malloc(size*sizeof(char));
            i = 0;
        }

        else {
            a[i-1] = c;
        }
    }

    return 0;
}
