#include<stdio.h>

int opBr(char a);
int clBr(char b);
int brType(char c, char d);

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    char br[3050];
    while(fgets(br, 3050, stdin) != NULL) {
        char open[3010];

        int count = 0;

        if( clBr(br[0])) {
            printf("NO 1\n");
            continue;
        }
        else if(br[0]=='*' && br[1] == ')') {
            printf("NO 1\n");
            continue;
        }

        //printf("%s\n", br);

        int i=0, j, starBracket = 0;

        for(j = 0; br[j]!='\n'; j++) {

            count++;

            if ( opBr(br[j]) == 1 ) {
                open[i++] = br[j];
            }

            else if( br[j] == '*' ) {
                //printf("%d %d\n", j, i);
                //printf("%c\n", open[i-1]);

                // three possibilities
                // 1. this is an opening star bracket
                // 2. this (with a ) ) is a closing bracket
                // 3. this is just an operand

                //printf("%c %c\n",open[i-1], br[j+1]);


                if(br[j-1] == '(' ) {
                    // interpret it as star bracket
                        open[i-1] = '*';
                        ++starBracket;
                        count--;
                }

                else if ( br[j+1] == ')' ) {
                    // now it;s a closing bracket;

                    if(i==0) {
                        i=-1;
                        break;
                    }

                    else if(open[i-1] == '*') {
                        i--;
                        j++;
                        ++starBracket;
                    }

                    else {
                        // it is indeed a closing bracket but
                        // the previous bracket is not a star bracket
                        // so this is invalid
                        i = -1;
                        break;
                    }
                }

                else {
                    // this is just a normal stara;
                }
            }

            else if ( clBr(br[j]) == 1 ) {

                if(i==0) {
                    i = -1;
                    break;
                }

                else if( brType(open[i-1], br[j]) == 1 ) {
                    // no conflict
                    --i;
                }
                else {
                    //printf("NO %d\n", j +1 - starBracket);
                    //printf("%c\n", br[j]);
                    i = -1;
                    break;
                }
            }

            }

        if(i>0) count++;

        //if(br[j]=='\n' && i==0 ) printf("YES\n");
        if(i==0 && br[j] == '\n' ) printf("YES\n");
        //else printf("NO %d\n", j+1 - starBracket);
        else printf("NO %d\n", count);

        //printf("%s %d\n", open, i);
        //printf("%d %d\n", j, starBracket);
    }

    return 0;
}


int opBr(char c) {
    if(c=='<' || c=='{' || c=='[' || c == '(') return 1;
    else return 0;
}

int clBr(char c) {
    if(c=='>' || c=='}' || c==']' || c==')' ) return 1;
    else return 0;
}

int brType(char a, char b) {
    if(a=='<' && b=='>') return 1;
    else if(a=='[' && b==']') return 1;
    else if(a=='{' && b=='}') return 1;
    else if(a=='(' && b==')') return 1;

    else return 0;
}
