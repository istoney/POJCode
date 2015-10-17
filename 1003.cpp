//Memory:228K	Time:0MS
//2013-08-08 00:31:29

#include<iostream>
using namespace std;

int main()
{
	double c;
	cin>>c;
	while(c!=0)
	{
		double tmp = 0;
		int i;
		for(i=2;tmp<c;i++)
			tmp += (double)1/i;
		cout<<i-2<<" card(s)"<<endl;
		cin>>c;
	}
	return 0;
}

