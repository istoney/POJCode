//Problem: 1006		User: vcc
//Memory: 248K		Time: 125MS
//Language: C++		Result: Accepted

#include<iostream>
using namespace std;
int main()
{
	//23,28,33
	int p,e,i,d,d2;
	unsigned case_num = 1;
	
	cin>>p>>e>>i>>d;
	while(p>=0)
	{
		//对三个周期的开始时间进行预处理，编程最接近于零的负数
		p = p%23 - 23;
		e = e%28 - 28;
		i = i%33 - 33;

		if((d-p)%23==0 && (d-e)%28==0 && (d-i)%33==0)
			d2=d+21252;
		else if((d-i)%33==0)
			d2=d;
		else d2=d + 33 - (d-i)%33;
		while(true)
		{
			if((d2-i)%33==0)
				if((d2-e)%28==0)
					if((d2-p)%23==0)
						break;
			d2=d2+33;
		}
		cout<<"Case "<<case_num++<<": the next triple peak occurs in "
			   <<d2-d<<" days."<<endl;
		cin>>p>>e>>i>>d;
	}
	return 0;
}
