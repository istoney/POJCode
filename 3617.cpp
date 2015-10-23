//POJ 3617
//最小字典序问题，采用贪心发解决
//1.从头或尾选择较小的字母
//2.当遇到相同的字母时，选择能使下一个字母较小的，依次类推
 
//Memory:716K	Time:0MS
//2015-10-23 10:41:30

#include<iostream>

using namespace std;

int main(){
	int N;
	cin>>N;
	
	char cows[N];
	for(int i=0;i<N;i++){
		cin>>cows[i];
	}
	
	int b=0, e=N-1, index=0;
	while(b<=e){
		bool left = false;
		for(int i=0;i<=e-b;i++){
			if(cows[b+i]<cows[e-i]){
				left = true;
				break;
			}
			else if(cows[b+i]>cows[e-i]){
				left = false;
				break;
			}
		}
		
		if(left) cout<<cows[b++];
		else cout<<cows[e--];
		if(++index == 80){
			cout<<endl;
			index=0;
		}
	}
	cout<<endl;
	return 0;
}
