# 1753 题解

标签： POJ 枚举

-----
#*1753 Flip Game*
### **题意**
Flip Game 就是在一个4x4的正方形中放置16个piece。每个piece有黑白两种状态，任意时刻处于两种状态的一种。
每次翻牌：

- 从16个piece中任选一个
- 将与所选piece相邻的上下左右的piece也翻转

任务是找到最少的操作次数，将所有piece全部翻转为黑，或全部为白。

### **思路**
每个piece有两种状态，如果一个piece翻转两次将不发生状态改变，因此各个piece的翻转顺序对结果没有影响。只需判断有哪些piece需要翻转。16个piece共有2^16中可能性。可以采用枚举方法.

- 每个piece有两种状态，可以用二进制来表示，总共16个piece，就是一个16位的二进制数。
- 使用位操作（亦或）进行翻转操作，提高操作效率。
- 采用递归方式进行枚举。

### **源代码**

```c++
//Memory:680K	Time:47MS
//2015-04-24

#include<iostream>
using namespace std;

unsigned short int op[] = {
	0xc800, 0xe400, 0x7200, 0x3100,
	0x8c80, 0x4e40, 0x2720, 0x1310,
	0x08c8, 0x04e4, 0x0272, 0x0131,
	0x008c, 0x004e, 0x0027, 0x0013
};


int f(unsigned short int map, int i, int count){
	if(i==16) return 17;
	unsigned short int map2 = map^op[i];
	if(map2==0 || map2==0xffff)
		return count+1;
	else return min(f(map, i+1, count), f(map2, i+1, count+1));
}

int main(){
	unsigned short int map = 0;
	char tmp[16];
	for(int i=0;i<4;i++){
		cin >> tmp;
		for(int j=0;j<4;j++){
			map = map << 1;
			if(tmp[j] == 'b') map += 1;
		}
	}

	if(map==0 || map==0xffff)
		cout<<0<<endl;
	else{
		int res = f(map, 0, 0);
		if(res == 17) cout<<"Impossible"<<endl;
		else cout<<res<<endl;
	}
	return 0;
}
```
