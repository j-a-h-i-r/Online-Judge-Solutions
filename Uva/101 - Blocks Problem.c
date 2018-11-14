#include<stdio.h>
#include<string.h>
int main()
{
   /* freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout); */

    int n, i, j, k;
    char dot = '.';
    scanf("%d", &n);
    getchar();

    int grid[30][30], index[30][2];
    for(i=0; i<n; i++) {
        index[i][0] = n-1;
        index[i][1] = i;
    }
    for(i = 0; i<=25; i++) {
        for(j=0; j<=25; j++) {
            grid[i][j] = -1;
        }
    }
    for(i=0; i<n; i++) {
        grid[n-1][i] = i;
        /* why n-1 ??
            because the blocks start from 0
            so they end in  | n-1 |
        */
        /* placing the blocks in their initial position */
    }

    char cmd[5], opt[5], line[25];
    int a, b;

    while( (fgets(line, 25, stdin)) != NULL ) {

        if(line[0] == 'q') break;

        sscanf(line, "%s %d %s %d\n", cmd, &a, opt, &b);

        /* printf("%s %d %s %d\n", cmd, a, opt, b); */

        if(a==b) {continue;}

        int bi = index[b][0], bj = index[b][1];
        int ai = index[a][0], aj = index[a][1];

        if(aj == bj) {continue;}

       /* printf("ai = %d  aj =%d  ||  bi = %d  bj = %d\n",ai, aj, bi, bj); */

/*------------------------------  START EXAMINING COMMNDS  ------------------------------------ */

        if(opt[1] == 'n') {
            /*
            //printf("onto\n");
            // have to do onto
            // claear everything above b;
            // lets get position of b
            //int bi = index[b][0], bj = index[b][1]; */

            for(i = bi-1; grid[i][bj]!=-1; i--) {
                /* getting up from b; */
                k = grid[i][bj]; /* getting block over b */
                grid[n-1][k] = k;    /* moving to init pos  */
                grid[i][bj] = -1; /* empty now  */
                index[k][0] = n-1; index[k][1] = k; /* recording index; */
            }

            if(cmd[0] == 'm') {
                /*// have to MOVE
                 lets return all block above a to their origin
                 lets get pos of a

                int ai = index[a][0], aj = index[a][1];*/

                for(i=ai-1; grid[i][aj]!=-1; i--) {
                   /* // getting up from a;*/
                    k = grid[i][aj]; /*// getting block over b*/
                    grid[n-1][k] = k;   /* // moving to init pos*/
                    grid[i][aj] = -1; /*// empty now*/
                    index[k][0] = n-1;   index[k][1] = k; /*// recording index;*/
                }

                /*// okaay moving blocks from over of a done;
                // lets take a and put it onto b;*/
               /* printf("%d %d\n", ai, aj);*/
                grid[ai][aj] = -1;  /*// moved a. now its previous pos is empty*/
                grid[bi-1][bj] = a;  /* // put it onto b*/
                index[a][0] = bi-1;     index[a][1]=bj; /*// remember its index*/
            }

            else if(cmd[0]=='p') {
                /*// have to PILE
                // so no need to remove blocks above a;
                // move a and all above a

                // get pos of a
                //int ai = index[a][0], aj = index[a][1];*/
                for(i = ai; grid[i][aj]!=-1; i--) {
                    /*// go upwrad starting from a*/
                    k = grid[i][aj];
                    grid[i][aj] = -1;
                    grid[--bi][bj] = k;
                    index[k][0] = bi;     index[k][1] = bj;

                }
            }
        }

        else if(opt[1]=='v') {
            /*printf("over\n");*/
/*             // have to do OVER
 *             // go to the toppest position of B
 *             //int bi = index[b][0], bj = index[b][1];
 */

            for(i=bi; grid[i][bj]!=-1; i--) {
/*                // start climbing*/
            }
            /*// sob par hoye empty position e eshe porsi
            // ekhon ami er nicher pos ta save kore rakhbo*/
            bi = i+1;   /*// bj same e thakbe*/

            if(cmd[0] == 'm') {
                /*// have to move A
                //int ai = index[a][0], aj = index[a][1];*/

                for(i=ai-1; grid[i][aj]!=-1; i--) {
                    /*// getting up from a;*/
                    k = grid[i][aj]; /*// getting block over b*/
                    grid[n-1][k] = k;   /* // moving to init pos*/
                    grid[i][aj] = -1; /*// empty now*/
                    index[k][0] = n-1;   index[k][1] = k; /*// recording index;*/
                }

                /*// okaay moving blocks from over of a done;
                // lets take a and put it onto b;*/
                grid[ai][aj] = -1;  /*// moved a. now its previous pos is empty*/
                grid[bi-1][bj] = a;  /* // put it onto b*/
                index[a][0] = bi-1;     index[a][1]=bj; /*// remember its index*/
            }
            else if(cmd[0] == 'p') {
                /*// have to PILE
                // so no need to remove blocks above a;
                // move a and all above a

                // get pos of a
                //int ai = index[a][0], aj = index[a][1];*/
                for(i = ai; grid[i][aj]!=-1; i--) {
                /*    // go upwrad starting from a*/
                    k = grid[i][aj];
                    grid[i][aj] = -1;
                    grid[--bi][bj] = k;
                    index[k][0] = bi;     index[k][1] = bj;
                }
            }
        }

        /* -- PRINT THE GRID IN EACH  STEP  --- **

        printf("GRID NOW\n\n");
        for(i = 0; i<n; i++) {
            for(j=0; j<n; j++) {
                if(grid[i][j]==-1) printf("%2c ", dot);
                else printf("%2d ", grid[i][j]);
            }
            printf("\n");
        }
        printf("\n\n\n");

        */

    }

    for(i=0; i<n; i++) {
        printf("%d:", i);
        for(j=n-1; j>=0; j--) {
            if(grid[j][i] == -1) break;
            printf(" %d", grid[j][i]);
        }
        printf("\n");
    }

    return 0;
}
