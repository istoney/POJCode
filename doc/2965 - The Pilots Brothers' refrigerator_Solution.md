# 2965 题解

标签： POJ 枚举

---

## *2965 The Pilots Brothers' Refrigerator*

### **题意**
一个冰箱的门上有着16个4x4排列handle，每个handle有开、关两种状态。只有当所有handle都处于开状态时冰箱门才能打开。

- 可以改变任意[i,j] (1<=i,j<=4)位置上的handle的状态。
- 改变一个handle的状态时，它所在行和列的所有handle的状态也会改变。

任务是找到最少的操作次数打开冰箱。并输出操作次序。

### **思路**

1.和1753类似，handle操作的顺序对结果没有影响，只需找到需要打开那些handle。
而共有16个handle，即2^16种可能性，可以采用枚举方法。实现方法和1753类似。对于操作序列，可以采用回溯方式记下需要改变状态的handle，用任意顺序输出即可。

- 二进制表示状态，位运算代替翻转操作。
- DFS递归查找最少操作次数。
- 回溯方法查找一个可行操作顺序，并保存。

2.记SWITCH (i,j)操作为对(i,j)进行翻转。
考虑每次SWITCH(i,j)状态，其所在行和列的handle状态都会改变。而如果对其所在行列的所有handle（7个）都SWITCH一次，那么(i,j)状态将改变7次，i行、j列上handle（(i,j)除外）将改变4次，其他handle将改变2次。其效果是只有(i,j)状态改变了。
而偶数次的SWITCH会抵消，因此只需要遍历所有状态为关的handle，对其所在行列的所有handle进行switch操作，并记录下各个handle的SWITCH次数，最后统计次数为奇数的handle就是需要操作的次数。其任意排列就是操作顺序。

### **源代码**
1.枚举
```c++
//Memory:688K	Time94MS
//2015-09-12

#include<iostream>
#include<vector>

using namespace std;

unsigned short int op[] = {
	0xf888, 0xf444, 0xf222, 0xf111,
	0x8f88, 0x4f44, 0x2f22, 0x1f11,
	0x88f8, 0x44f4, 0x22f2, 0x11f1,
	0x888f, 0x444f, 0x222f, 0x111f
};

int seq[16];
int index = 0;
int COUNT = 0;

int f(unsigned short int door, int i, int count){
	if(i==16) return 17;

	unsigned short int door2 = door^op[i];

	if(door2==0) return count + 1;

	return min(f(door, i+1, count), f(door2, i+1, count + 1));
}

bool f2(unsigned short int door, int i, int count){
	if(i==16) return false;

	if(f2(door, i+1, count)) return true;

	unsigned short int door2 = door^op[i];
	seq[index++] = i;
	count++;

	if(door2==0 && count==COUNT) return true;
	else if(f2(door2, i+1, count)) return true;
	else{
		index--;
		return false;
	}
}

int main(){
	unsigned short int door = 0;

	char tmp[32];
	for(int i=0;i<4;i++){
		cin>>tmp;
		for(int j=0;j<4;j++){
			door = door << 1;
			if(tmp[j] == '+') door += 1;
		}
	}

	COUNT = f(door, 0, 0);
	f2(door, 0, 0);

	cout<<COUNT<<endl;
	for(int i=0;i<index;i++){
		cout<<seq[i]/4+1<<" "<<seq[i]%4+1<<endl;
	}

	return 0;
}
```

2.SWITCH统计

```c++
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
```
