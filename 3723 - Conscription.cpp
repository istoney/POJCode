/* 
 ===============================================================================================
 *      File Name: 3723 - Conscription.cpp
 *    Description: http://poj.org/problem?id=3723 
 *         Author: Stoney
 *
 *        Version: 1.0
 *    Submit Time: 2016-01-18 16:47:18
 *       Compiler: c++
 *       Run Time: 454MS
 *         Memory: 912K
 *      Solutions: 1.利用节点之间的关系减少费用，关系值减少的越多，结果为 10000*(N+M) - 关系之和 
 *                 2.对所有边排序，从大到小选取边，若边上的节点未连接，添加该边，构造最大权森林
 *                 3.使用并查集判断节点是否连接，同一棵树上的节点属于同一个组 
 ===============================================================================================
 */
 
 #include<cstdio>
 #include<iostream>
 #include<algorithm>
 using namespace std;
 
 const int MAX_N = 20002;
 const int MAX_R = 50002;
 
 struct edge {
 	int u, v, cost;
 	edge(){}
 	edge(int x, int y, int c):u(x),v(y),cost(c){}
};
 edge es[MAX_R];
 bool comp(edge a, edge b){ return a.cost > b.cost;} 
 
 //union_find_set
 int par[MAX_N];
 int rank[MAX_N];
 
 void init(int n){
 	for(int i=0;i<n;i++){
 		par[i] = i;
 		rank[i] = 0;
 	}
 }
 
 int find(int x){
 	if(par[x] == x) return x;
 	
 	par[x] = find(par[x]);
 	return par[x];
 }
 
 void unite(int x, int y){
 	x = find(x);
 	y = find(y);
 	
 	if(x == y) return;
 	if(rank[x] < rank[y]){
 		par[x] = y;
 	} else {
 		par[y] = x;
 		if(rank[x] == rank[y]) rank[x]++;
 	}
 }
 
 bool same(int x, int y){
 	return find(x) == find(y);
 }
 
 int main(){
 	int T, N, M, R;
 	scanf("%d", &T);getchar();
 	while(T--){
 		scanf("%d %d %d", &N, &M, &R);
 		int x, y, r;
 		for(int i=0;i<R;i++){
 			scanf("%d %d %d", &x, &y, &r);
 			es[i] = edge(x, y+N, r);
 		}
 		
 		sort(es, es+R, comp);
 		init(N+M);
 		int res = 0;
 		for(int i=0;i<R;i++){
 			if(!same(es[i].u, es[i].v)) {
 				unite(es[i].u, es[i].v);
				res += es[i].cost;
 			}
 		}
 		
 		printf("%d\n", 10000*(N+M) - res);
 		getchar();
 	}
 	
 	return 0;
 } 
