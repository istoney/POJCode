//Memory: 772K	Time: 94MS
//2015-09-22 

#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;

typedef struct{
	double left;
	double right;
} range;

int cmp(const void *a, const void *b){
	return ((range *)a)->right > ((range*)b)->right ? 1 : -1;
}

int main(){
	int c = 1;
	int N, D;
	
	
	while(cin>>N>>D && N){
		range *islands = new range[N];
		int count;
		bool no_solution = false;//记得每次循环重置flag 
		
		int x, y;
		for(int i=0;i<N;i++){
			cin>>x>>y;
			if(y > D){
				no_solution = true;
				//即使已知该组数据没有答案，也要把数据读完，否则会影响下一组测试 
			}
			
			double offset = sqrt(double(D*D - y*y));
			islands[i].left = x - offset;
			islands[i].right = x + offset;
		}
		
		if(!no_solution){
			qsort(islands, N, sizeof(range), cmp);
			
			count = 1;
			double radar = islands[0].right;
			
			for(int i=1;i<N;i++){
				if(islands[i].left - radar > 1e-5){
					radar = islands[i].right;
					count++;
				}
			}
		}
		
		if(no_solution)
			cout<<"Case "<<c++<<": "<<-1<<endl;
		else cout<<"Case "<<c++<<": "<<count<<endl;
		
		delete[] islands;
	}
	return 0;
}
