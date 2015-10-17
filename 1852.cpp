
#include<stdio.h>
#include<iostream>

using namespace std;

int main(){
	int C, L, n;
	//int ants[1000000];
	
	cin>>C;
	
	for(int c=0;c<C;c++){
		cin>>L>>n;
		int ants[n];
		
		for(int i=0;i<n;i++){
			scanf("%d", &ants[i]);
		}
		
		int minT = 0;
		for(int i=0;i<n;i++){
			minT = max(minT, min(ants[i], L-ants[i]));
		}
		
		int maxT = 0;
		for(int i=0;i<n;i++){
			maxT = max(maxT, max(ants[i], L-ants[i]));
		}
		
		cout<<minT<<" "<<maxT<<endl;
	}
	return 0;
}
