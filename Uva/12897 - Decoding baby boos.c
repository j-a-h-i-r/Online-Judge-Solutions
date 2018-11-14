#include <stdio.h>
#include <string.h>
char s[1048576];
int main() {
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);*/

	int t, n, i, j;
	scanf("%d", &t);
	/*//printf("%d\n", t);*/
	getchar();

	while (t--) {
		scanf("%s", s);
		/*//printf("s = %s\n", s);*/
		getchar();
		scanf("%d", &n);
		/*//printf("n = %d\n", n);*/
		getchar();

		char R[128], a, b;
		for (i = 'A'; i <='Z'; i++) R[i] = i;

		while(n--) {
            /*//printf("%d\n", n);*/
            scanf("%c %c", &a, &b);
            getchar();
            /*//printf("c = %c %c\n",a, b);*/

            /*for (i = 'A'; i <= 'Z'; i++) {
                R[b] = a;
            }*/

            for(j = 'A'; j<='Z'; j++) {
                if(R[j] == b ) {
                    R[j] = a;
                }
            }
           /*// printf("c = %c %c  --  ",a, b);*/
            /*for (i = 0; s[i]; i++)
                (s[i]=='_')? printf("_") : printf("%c", R[s[i]]);
            printf("\n");*/
		}

		for (i = 0; s[i]; i++)
			(s[i]=='_')? printf("_") : printf("%c", R[s[i]]);
		printf("\n");

    }
    return 0;
}

