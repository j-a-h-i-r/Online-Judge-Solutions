#include<stdio.h>
#include<string.h>

int vowel(char c){
    if(c=='A'||c=='E'||c=='I'||c=='O'||c=='U'|| c=='Y'
       ||c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='y'){
        return 1;
    }
    else return 0;
}

int upper(char c){
    if (c>='A' && c<='Z') return 1;
    else return 0;
}

int main()
{
    char a[120];
    scanf("%s", a);

    int i;

    for(i=0; a[i]; i++){
        if(vowel(a[i])) continue;
        else{
            putchar('.');
            if (upper(a[i])) putchar(a[i]+32);
            else putchar(a[i]);
        }
    }
    //putchar('\n');
    return 0;
}
