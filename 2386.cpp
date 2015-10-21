//Memory:1300K	Time:47MS
//2015-10-21 09:48:44

//枚举类型题目 
//DFS方式求解
 
#include<iostream>
#include<queue>

using namespace std;

int N, M;
char **field = NULL;

void f(int x, int y){
	field[x][y] = '.';
	
	for(int i=x-1;i<=x+1;i++){
		if(i<0 || i>= N) continue;
		
		for(int j=y-1;j<=y+1;j++){
			if(j<0 || j>= M) continue;
			
			if(field[i][j] == 'W'){
				f(i,j);
			}
		}
	}
}

int main(){
	
	cin>>N>>M;
	field = new char*[N];
	
	for(int i=0;i<N;i++){
		field[i] = new char[M];
		for(int j=0;j<M;j++){
			cin>>field[i][j];
		}
	}
	
	int count = 0;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(field[i][j] == 'W'){
				f(i, j);
				count++;
			}
		}
	}
	cout<<count;
	
	for(int i=0;i<N;i++){
		delete [] field[i];
	}
	delete [] field;
	return 0;
}
