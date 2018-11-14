#include <stdio.h>
int main()
{

freopen("input.txt", "r", stdin);

int T;
scanf("%d", &T);
int m=T;
int n=T;
int ara[T];

while(T>0) {
scanf("%d", &ara[T]);
T--;
}

int i=1;
int j=0;

while(i<=m) {
printf("%d %d\n", j, (ara[n]));
i++;
n--;
}
}
