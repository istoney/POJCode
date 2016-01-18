//Memory:732K	Time:79MS
//2015-09-10

#include<iostream>
#include<vector>

using namespace std;

const int N = 4;

class pos{
	public:
		int x;
		int y;
		
		pos(int x, int y){
			this->x = x;
			this->y = y;
		}
};

int main(){
	char door[N][N];
	vector<pos> singulars;
	int Ans[N][N] = {0};
	
	for(int i=0;i<N;i++){
		cin>>door[i];
		for(int j=0;j<N;j++){
			if(door[i][j] == '+'){
				singulars.push_back(pos(i, j));
			}
		}
	}
	
	for(int k=0;k<singulars.size();k++){
		int x = singulars[k].x;
		int y = singulars[k].y;
		
		//do the flip at every in the row
		for(int j=0;j<N;j++){
			Ans[x][j]++;
		}
		
		for(int i=0;i<N;i++){
			if(i==x) continue;
			Ans[i][y]++;
		}
	}
	
	singulars.clear();
	int count = 0;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(Ans[i][j]%2 == 1){
				count++;
				singulars.push_back(pos(i,j));
			}
		}
	}
	
	cout<<count<<endl;
	for(int i=0;i<singulars.size();i++){
		cout<<singulars[i].x + 1<<" "<<singulars[i].y + 1<<endl;
	}
	
	return 0;
}
