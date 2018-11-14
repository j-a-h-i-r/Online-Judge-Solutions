#include<stdio.h>

char correct(char c){
    if(c=='1') return '`';
    else if(c=='0') return '9';
    else if(c>='2' && c<='9') return c-1;

    switch(c){
        case 'W': return 'Q';
        case 'E': return 'W';
        case 'R': return 'E';
        case 'T': return 'R';
        case 'Y': return 'T';
        case 'U': return 'Y';
        case 'I': return 'U';
        case 'O': return 'I';
        case 'P': return 'O';
        case '[': return 'P';
        case ']': return '[';
        case '\\': return ']';
        case 'S': return 'A';
        case 'D': return 'S';
        case 'F': return 'D';
        case 'G': return 'F';
        case 'H': return 'G';
        case 'J': return 'H';
        case 'K': return 'J';
        case 'L': return 'K';
        case ';': return 'L';
        case '\'': return ';';
        case 'X': return 'Z';
        case 'C': return 'X';
        case 'V': return 'C';
        case 'B': return 'V';
        case 'N': return 'B';
        case 'M': return 'N';
        case ',': return 'M';
        case '-': return '0';
        case '=': return '-';
        case '.': return ',';
        case '/': return '.';
        case ' ': return ' ';
        case '\n': return '\n';
        case '\0': return '\0';
    }
}

int main()
{
    int c;

    while((c = getchar())!=EOF){
        printf("%c", correct(c));
    }
}
