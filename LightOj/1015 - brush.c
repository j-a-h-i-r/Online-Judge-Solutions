#include<stdio.h>
int main()
{
    int t, dust,caseno=0,total=0,students;
    scanf("%d", &t);

    while(t--) {
        scanf("%d", &students);

        while(students--) {
            scanf("%d", &dust);
            if(dust>0) {
                total+=dust;
            }
        }
        printf("Case %d: %d\n", ++caseno, total);
        total=0;
    }
    return 0;
}
