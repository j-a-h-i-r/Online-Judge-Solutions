#include<stdio.h>
#include<ctype.h>

int isVowel(int c){
    if(c=='A'||c=='E'||c=='I'||c=='O'||c=='U'||
       c=='a'||c=='e'||c=='i'||c=='o'||c=='u') return 1;
    else return 0;
}

int main()
{
    freopen("in.txt", "r", stdin);

    int c, fchar ='.', fc = 1, cnt = 0;
    while( (c=getchar()) != EOF){
      if(!isalpha(c)) {
            if (fchar != '.'){
                putchar(fchar);
                fchar = '.';
            }
            if(cnt == 1){
                printf("ay");
                cnt = 0;
            }
            putchar(c);
            fc = 1;
        }

        else if(isalpha(c)) {
            if(fc==1){
                fc = 0; cnt = 1;
                if(isVowel(c)==1) {
                    putchar(c);
                }
                else{
                    fchar = c;
                }
            }
            else{
                putchar(c);
            }
        }
    }
    return 0;
}
