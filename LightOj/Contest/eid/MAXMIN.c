char s[100];
char no_space[100];
int j = 0;

cin>>s;

for(int i=0; s[i]!='\0'; i++)
{
    if(s[i]!=' ') {
        no_space[j] = s[i];
        j++;
    }
}

cout<<no_space;
