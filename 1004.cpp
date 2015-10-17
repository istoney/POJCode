//Memory:220K	Time:16MS
//2013-08-08 00:46:32

#include<iostream>
using namespace std;

int main()
{
	double tmp,sum=0;
	for(int i=0;i<12;i++)
	{
		cin>>tmp;
		sum += tmp;
	}
	printf("$%.2f\n", sum/12);
	return 0;
}
