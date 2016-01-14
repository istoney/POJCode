/* 
 ======================================================================================
 *      File Name: 2431 - Expedition.cpp
 *    Description: http://poj.org/problem?id=2431
 *         Author: Stoney
 *
 *        Version: 1.0
 *    Submit Time: 2016-01-02 16:09:28
 *       Compiler: c++
 *       Run Time: 47MS
 *         Memory: 372K
 *      Solutions: Sort + Priority_Queue(Greedy), Loop for every stop.
 ======================================================================================
 */

#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

const int MAX_N = 10000;
pair<int, int> stop[MAX_N + 2];
int N, L, P;

int main(){
	scanf("%d", &N);
	int d, f;
	for(int i=1;i<=N;i++){
		scanf("%d %d", &d, &f);
		stop[i] = pair<int, int>(d, f);
	}
	
	//the town is the final stop
	stop[0] = pair<int, int>(0, 0);
	
	//input data is not in order
	sort(stop, stop+N+1);
	
	scanf("%d %d", &L, &P);
	int count = 0;
	priority_queue<int> PQ;
	for(int i=N;i>=0 && count>=0;i--){
		int delta = L - stop[i].first;
		P -= delta;
		
		while(P<0){
		//**loop until get enough fuel
		
			if(PQ.empty()){
				count = -1;break;
			}
			else{
				P += PQ.top();
				PQ.pop();
				count++;
			}
		}
		
		L = stop[i].first;
		PQ.push(stop[i].second);
	}
	
	if(count>= 0) printf("%d\n", count);
	else puts("-1");
	
	return 0;
}
