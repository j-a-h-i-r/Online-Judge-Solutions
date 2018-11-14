#include<stdio.h>
#include<string.h>

int stringType(char s[] , char mir[]) {
    int l = strlen(s);
    int i, j, pal = 1, rev = 1;

    for(i=0, j=l-1; i<=j; i++, j--) {
        if(s[i] == s[j]) {
            if( ! (mir[s[i]] == s[j])  ) rev = 0;
        }

        else {
            pal = 0;
            if( !(mir[s[i]] == s[j]) ) {
                rev = 0;
                return 1;
            }
        }
    }

    if(pal == 1 && rev==1) return 4;
    else if(pal==1 && rev==0) return 3;
    else if(pal==0 && rev ==1) return 2;
    else return 1;
}

int main()
{
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);*/

    int i;
    char mir[256];
    for(i=0; i<256; i++) mir[i] = '.';

    mir['E'] = '3'; mir['J'] = 'L';
    mir['S'] = '2'; mir['Z'] = '5';
    mir['3'] = 'E'; mir['L'] = 'J';
    mir['2'] = 'S'; mir['5'] = 'Z';
    mir['A'] = 'A'; mir['H'] = 'H';
    mir['I'] = 'I'; mir['M'] = 'M';
    mir['O'] = 'O'; mir['T'] = 'T';
    mir['U'] = 'U'; mir['V'] = 'V';
    mir['W'] = 'W'; mir['X'] = 'X';
    mir['Y'] = 'Y'; mir['1'] = '1';
    mir['8'] = '8';

    char str[30];

    while(scanf("%s", str) != EOF) {
        int n = stringType(str, mir);

        if(n==1) printf("%s -- is not a palindrome.",str);
        else if(n==2) printf("%s -- is a mirrored string.", str);
        else if(n==3) printf("%s -- is a regular palindrome.", str);
        else if(n==4) printf("%s -- is a mirrored palindrome.", str);

        printf("\n\n");
    }

    return 0;
}
