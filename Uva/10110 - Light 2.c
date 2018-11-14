#include<stdio.h>
#include<math.h>
int main()
{
    long long n;
    while(scanf("%lld", &n) && n!=0){
        long long root = (long long)sqrt(n);
        if(root*root == n) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
