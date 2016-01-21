#include<iostream>
#include<math.h>
using namespace std;

int main(){
	/* 浮点数比较
	*					精确度				范围
	* float		7位					3e38
	* double	15-16位			1.7e308
	*/
	double n, p;
	while(cin>>n>>p){
		cout<<pow(p, 1/n)<<endl;
	}
}
