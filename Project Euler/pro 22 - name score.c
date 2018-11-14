#include<stdio.h>
#include <string.h>
int main()
{
    FILE *names;
    char c;
    char name[5163][12];
    char temp[12];
    int count=0;
    int i=0,j=0;
    int wordSum=0;
    unsigned long int posSum=0;
    unsigned long long int total=0;

    names = fopen("names.txt", "r");    //opening file for reading
    while( (c = fgetc(names)) != EOF ) {
        if (c == '"' ) {        // if " is encountered, start copying letter in string

            while( (c = fgetc(names)) != '"' ) {        // keep copying until 2nd " is found
                name[i][j++] = c;
            }
            name[i][j] = '\0';

            j=0;
            i++;    //index barao
        }
    }
    for(i=0; i<5162; i++) {
        for( j=i+1; j<5163; j++ ) {
            if( strcmp(name[i], name[j]) >0 ) {
                strcpy(temp, name[i]);
                strcpy(name[i], name[j]);
                strcpy(name[j], temp);
            }
        }
    }

    for(i=0; i<5163; i++) {
        for(j=0; name[i][j]!='\0'; j++ ) {
           wordSum = wordSum + ( name[i][j] -'A'+1);
        }
        posSum = wordSum*(i+1);
        total += posSum;
        wordSum = 0;
    }
    printf("%llu ", total);


    fclose(names);
}
