#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	double x = -0.38, y = -0.665, s = 2, m = 1000;
	char outfile[100];
	char argument[100];

	int i;
	for (i=0; i<50; i++) {
		sprintf(outfile, "mandel%d.bmp", i+1);
		sprintf(argument, "./mandel -x %lf -y %lf -s %lf -m %lf -o %s", x, y, s, m, outfile);

		s = s - 0.04;

		int pid = fork();

		if (pid == 0) {
            // inside child
            // do not call system(argument);
            char s_c[10], x_c[10], y_c[10], m_c[10];
            sprintf(s_c, "%lf", s);
            sprintf(x_c, "%lf", x);
            sprintf(y_c, "%lf", y);
            sprintf(m_c, "%lf", m);
            //execlp("./mandel", "mandel", "-x", x_c, "-y", y_c, "-s", s_c, "-m", m_c, "-o", outfile, NULL);
            system(argument);
		}
	}
	return 0;
}

