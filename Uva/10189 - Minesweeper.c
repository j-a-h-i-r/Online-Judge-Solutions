#include<stdio.h>
int main()
{
    int row, col, k, t = 0;
    int x[] = {1, 0, -1, 0, 1, -1, -1, 1};
    int y[] = {0, 1, 0, -1, 1, 1, -1, -1};

    while(scanf("%d%d", &row, &col) && row!=0 && col !=0 ){
        if(t!=0) printf("\n");
        char field[110][110];
        int i, j;
        for(i=0; i<row; i++){
            scanf("%s", field[i]);
        }

        for(i=0; i<row; i++){
            for(j=0; j<col; j++){
                if(field[i][j] == '*' ){
                    for(k = 0; k<8; k++){
                        int nx = i+x[k], ny = j+y[k];
                        if(nx>=0 && nx<row && ny>=0 && ny<col) {
                            if(field[nx][ny] == '.') {
                                field[nx][ny] = '1';
                            }
                            else if (field[nx][ny] == '*') { /*do nthing */}
                            else field[nx][ny] += 1;
                        }
                    }
                }
            }
        }

        printf("Field #%d:\n", ++t);
        for(i = 0; i<row; i++){
            for(j = 0; j<col; j++){
                if(field[i][j] == '.') printf("0");
                else printf("%c", field[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
