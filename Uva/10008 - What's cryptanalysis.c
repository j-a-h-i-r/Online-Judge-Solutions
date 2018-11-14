#include<stdio.h>
#include<ctype.h>
int main()
{
    int t, i;
    int alpha[26];
    for(i = 0; i<26; i++) alpha[i] = i;
    int count[26];
    for(i =0 ; i<26; i++) count[i] = 0;

    scanf("%d", &t);
    int c;
    while( (c=getchar() ) != EOF) {
        if(isalpha(c)) {
            if(c>='A' && c <= 'Z') count[c-'A']++;
            else count[c-'a']++;
        }
    }

    int j;

    for(i=0; i<25; i++) {

        for(j=i+1; j<26; j++) {
            if(count[i]<count[j]) {
                int temp = count[i];
                count[i] = count[j];
                count[j] = temp;

                temp = alpha[i];
                alpha[i] = alpha[j];
                alpha[j] = temp;
            }
            else if( (count[i] == count[j]) && (alpha[i]>alpha[j])) {
                int temp = alpha[i];
                alpha[i] = alpha[j];
                alpha[j] = temp;
            }
        }
    }

    for(i=0;i<26; i++) {
        if(count[i]>0) {
            printf("%c %d\n", alpha[i]+'A', count[i]);
        }
    }
    return 0;
}
