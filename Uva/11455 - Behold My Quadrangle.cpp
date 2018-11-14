#include<cstdio>
#include<algorithm>
int main()
{
  //freopen("in.txt", "r", stdin);
   //freopen("out.txt", "w", stdout);

    int t;
    scanf("%d", &t);

    while(t--) {
        long long int l[4];
        int i;

        for(i=0; i<4; i++) {
            scanf("%lld", &l[i]);
        }

        std::sort(l, l+4);

        if(l[0] == l[3]) printf("square\n");
        else if(l[0] == l[1] && l[2]== l[3]) printf("rectangle\n");
        else if( l[0]+l[1]+l[2] >= l[3] ) printf("quadrangle\n");
        else printf("banana\n");
    }
    return 0;
}

