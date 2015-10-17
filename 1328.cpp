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
		bool no_solution = false;//�ǵ�ÿ��ѭ������flag 
		
		int x, y;
		for(int i=0;i<N;i++){
			cin>>x>>y;
			if(y > D){
				no_solution = true;
				//��ʹ��֪��������û�д𰸣�ҲҪ�����ݶ��꣬�����Ӱ����һ����� 
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
