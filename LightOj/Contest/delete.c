#include<stdio.h>
char arr[]={'a','b','c','d'};
vector&lt;char&gt;result;
int taken[20]={0};
void call()
{
	if(result.size()==4)
	{
		for(int i=0;i&lt;4;i++)
		printf("%c",result[i]);
		puts("");
		return;
	}
	for(int i=0;i&lt;4;i++)
	{
		if(taken[i]==0)
		{
			taken[i]=1; result.push_back(arr[i]);
			call();
			taken[i]=0; result.pop_back();
		}
	}
}
int main()
{
	call();
}
