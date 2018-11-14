#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    char b[100];
    while((scanf("%s", b))!=EOF){
        int len = strlen(b), i;
        if(len == 1 && b[0]=='0') break;
        int p = len;
        long long d = 0;
        for(i=0; i<len; i++) {
            if(b[i] == '1' || b[i]=='2'){
                d += (pow(2, p--)-1)*(b[i]-'0');
            }
            else p--;
        }
        printf("%lld\n", d);
    }
    return 0;
}
