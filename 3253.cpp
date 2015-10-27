//POJ 3253
//贪心问题，逆向角度，从最后切割的plank考虑，选择最短的两只留在最后切割
//最后两支选定后，将其组合，此时共有N-1支，对此N-1支重复步骤1

//Memory:776K	Time:407MS
//2015-10-27 23:14:48
 
#include<iostream> 
#include<algorithm>

using namespace std;

int cmp(const void * a, const void * b){
	return *((int *)a) - *((int *)b);
};

void plank_insert(int planks[], int s, int e, int v){
	int i = s;
	while(i<e && planks[i] < v){
		planks[i-1] = planks[i];
		i++;
	}
	
	planks[i-1] = v;
};

int main(){
	int N;
	cin>>N;
	
	int planks[N];
	for(int i=0;i<N;i++) cin>>planks[i];
	
	qsort(planks, N, sizeof(int), cmp);
	
	//结果总和数量级为20000*50000=1000000000 
	long long ans = 0;
	int index = 0;
	while(index<=N-2){
		int u = planks[index] + planks[index+1];
		ans += u;
		
		plank_insert(planks, index+2, N, u);
		index++;
	}
	
	cout<<ans;
	return 0;
}
