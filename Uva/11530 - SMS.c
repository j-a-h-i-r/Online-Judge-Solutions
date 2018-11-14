#include<stdio.h>
int main()
{
    int s[] = { 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3,
     1, 2, 3, 4, 1, 2, 3, 1, 2, 3, 4};

    int t, c = 0;
    char word[120];
    scanf("%d", &t);
    getchar();

    while(t--) {

        fgets(word, 120, stdin);

        int i, sum = 0;

        for(i=0; word[i] != '\n'; i++) {
            if(word[i]==' ') sum += 1;
            else sum += s[ word[i]-'a'];
        }

        printf("Case #%d: %d\n",++c, sum);
    }
    return 0;
}
