#include<stdio.h>
int main()
{
   /* freopen("in.txt", "r", stdin);*/

    char keypad[][10] = {"  "," .,?\"", " abc", " def", " ghi", " jkl", " mno", " pqrs", " tuv", " wxyz"};

    int t;
    scanf("%d", &t);

    while(t--) {
        int key[120], press, i, l;
        scanf("%d", &l);

        for(i=0; i<l; i++) {
            scanf("%d", &key[i]);
        }

        for(i=0; i<l; i++) {
            scanf("%d", &press);

            printf("%c", keypad[key[i]][press]);
        }
        printf("\n");
    }
    return 0;
}
