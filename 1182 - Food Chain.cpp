/* 
 ======================================================================================
 *      File Name: 1182 - Food Chain.cpp
 *    Description: http://poj.org/problem?id=1182
 *         Author: Stoney
 *
 *        Version: 1.0
 *    Submit Time: 2016-01-12 23:27:21
 * Solving Method: Union-find set to store the pairs which relationship is settled.
 *                 Addtional r for each node indicates the relationship to parent node.
 *                 When compress path, update it's r to relation with root(new parent).
 *       Compiler: c++
 *         Memory: 570K	
 *           Time: 266MS
 ======================================================================================
 */

#include<cstdio>

using namespace std;

const int MAX_N = 50002;

int par[MAX_N];	//parent node 
int r[MAX_N];	//relation with parent, 0 - same type, 1 - eaten by parent, 2 - eat parent

void init(int n){
  for(int i=0;i<n;i++){
    par[i] = i;
    r[i] = 0;
  }
}

int find(int x){
  if(par[x] == x) return x;
  
  int p = par[x];
  par[x] = find(par[x]);	//compress path, change parent to root
  r[x] = (r[x] + r[p]) % 3;	//p is child of root now, r[p] is the relation between p and root
  return par[x];
}

//d is the true relation x->y
void unite(int d, int x, int y){
  int px = find(x);	//parent of x, root
  int py = find(y);	//parent of y, root
  
  par[py] = px;
  r[py] = (r[x] + d - r[y]  + 3)%3;	//in c++ result of -1%3 is -1, addtional plus 3 to make sure result is nonegtive
}

int main(){
  int N, K;
  scanf("%d %d", &N, &K);
  init(N);

  int d, x, y, count=0;
  while(K--){
    scanf("%d %d %d", &d, &x, &y);
    x--;y--;
    
    if(x<0 || x>N-1 || y<0 || y>N-1 || (d==2 && x==y)) count++;
    else if(find(x) == find(y)){
    	if((r[x]+d-1)%3 != r[y])	//make sure r[x] and r[y] are in range of [0, 3)
    		count++;
    } else unite(d-1, x, y);
  }
  
  printf("%d\n", count);
  return 0;
}
