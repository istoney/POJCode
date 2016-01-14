/* 
 ======================================================================================
 *      File Name: 3255 - RoadBlocks.cpp
 *    Description: http://poj.org/problem?id=3255
 *         Author: Stoney
 *
 *        Version: 1.0
 *    Submit Time: 2016-01-14 21:59:08 
 *       Compiler: c++
 *       Run Time: 204MS
 *         Memory: 2812K
 *      Solutions: Based on Dijkstra, choose the shortest vertex from un-setteled set
 *                 to update all it's adjacent vertexes' shortest and second shortest.
 *                 If ony any update(shortest or second shortest) succeed, push the 
 *                 result to queue. 
 *                 Use priority queue to improve shortest vertex seletion performance.
 ======================================================================================
 */

#include<cstdio>
#include<iostream>
#include<queue>
#include<vector>

using namespace std;

const int MAX_N = 5002;
const int INF = 0x7fffffff;

struct edge{int to, cost;}; 
typedef pair<int, int> P;

int R, N;
int dist[MAX_N];
int dist2[MAX_N];

int main(){
	vector<edge> G[MAX_N];
	
	scanf("%d %d", &N, &R);
	
	int c, x, y;
	for(int i=0;i<R;i++){
		scanf("%d %d %d", &x, &y, &c);
		x--;y--;
		
		edge e;e.to=y;e.cost=c;
		G[x].push_back(e);	//vector push_back is value reference
		edge e2;e2.to=x;e2.cost=c;
		G[y].push_back(e2);
	}
	
	fill(dist, dist+N, INF);
	fill(dist2, dist2+N, INF);
	
	//priority_queue make sure the largest on the top
	//first value of pair is used in comparition
	priority_queue<P, vector<P>, greater<P> > Q;
	Q.push(make_pair(0,0));
	dist[0] = 0;
	
	while(!Q.empty()){
		P p = Q.top();Q.pop();
		int u = p.second;
		int d = p.first;
		if(d > dist2[u]) continue;
		
		for(int i=0;i<G[u].size();i++){
			edge e = G[u][i];
			int tmp = d + e.cost;
			
			//最短路和次短路的更新分开,只要更新成功就将更新结果放入优先队列 
			if(tmp < dist[e.to]){
				swap(dist[e.to], tmp);	//较大的值用于后面更新次短 
				Q.push(make_pair(dist[e.to], e.to));
			} 
			
			//if tmp==dist[e.to], continue
			if(tmp < dist2[e.to] && tmp > dist[e.to]){
				dist2[e.to] = tmp;
				Q.push(make_pair(dist2[e.to], e.to));
			}
		}
	}
	
	printf("%d\n", dist2[N-1]);
	return 0;
}
