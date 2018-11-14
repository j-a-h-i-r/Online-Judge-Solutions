#include<stdio.h>
#include<string.h>
int main()
{
    int t, caseno=0,i=1,visitFlag=1;

    char links[101][51], url[51], command[10];

    strcpy(links[0], "Ignored");
    strcpy(links[1], "http://www.lightoj.com/");

    scanf("%d", &t);

    while(t--) {
        scanf("%s",command);
        getchar();


        printf("Case %d:\n", ++caseno);

        while( strcmp(command, "QUIT") ) {

            if( !strcmp(command, "VISIT")) { // GETS COMMAND TO VISIT LINK
                gets(url);                      // get url
                strcpy( links[++i], url);       // save it in array
                visitFlag = 1;                  // visited a new page, so change visitFlag to positive

                printf("%s\n", links[i]);
            }

            else if( !strcmp(command, "BACK") ) {
                if(i>1) {
                    printf("%s\n", links[--i]);

                    visitFlag--;
                }
                else {
                    printf("%s\n", links[0]);
                }
            }

            else if( !strcmp(command, "FORWARD") ) {
                if(visitFlag < 1 ) {
                    printf("%s\n", links[++i]);

                    visitFlag++;
                }

                else printf("%s\n", links[0]);
            }

            scanf("%s",command);
            getchar();

        }
        visitFlag = 1;
        i=1;
    }
}

