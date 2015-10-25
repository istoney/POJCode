//POJ 3069
//贪心问题，与POJ1328 Radar Installation类似
//排序后从左向右遍历，选取能覆盖最多的位置放置，并去除已覆盖的位置，循环该步骤
 
//Memory:748K	Time:110MS
//2015-10-25 19:00:02

#include<iostream>
#include<algorithm>

using namespace std;

int cmp(const void * a, const void * b){
	return *((int *)a) - *((int *)b);
}

int main(){
	int R, n;
	while(cin>>R>>n && R>=0){
		int troop[n];
		for(int i=0;i<n;i++) cin>>troop[i];
		
		qsort(troop, n, sizeof(int), cmp);
		
		int count=0;
		for(int i=0;i<n;){
			int s = troop[i];
			//向右寻找最佳位置 
			while(i<n && troop[i]<=s+R) i++;
			
			int p = troop[i-1];
			count++;
			//向右排除可覆盖的位置 
			while(i<n && troop[i]<=p+R) i++;
		}
		
		cout<<count<<endl;
	}
	return 0;
}
