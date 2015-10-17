//Memory:232K	Time:0MS
//2013-08-08 18:29:35

#include<iostream>
using namespace std;
int main()
{
	unsigned N;
	cin>>N;
	for(int i=0;i<N;i++)
	{
		double X,Y,pi=3.141592653589793,res;
		unsigned res_int;
		cin>>X>>Y;
		res = (X*X+Y*Y)*0.5*pi/50.0;
		res_int = (unsigned)res/1;
		cout<<"Property "<<i+1<<": This property will begin eroding in year ";
		if((double)res_int<res) cout<<res_int+1<<"."<<endl;
		else cout<<res_int<<"."<<endl;
	}
	cout<<"END OF OUTPUT."<<endl;
	return 0;
}
