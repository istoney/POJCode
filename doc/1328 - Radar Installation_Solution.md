# 1328 题解

标签： POJ 贪心

---

## *POJ 1328 Radar Installation*
### **题意**
在海边有一些小岛，现在需要在海岸线上安装雷达，覆盖所有的小岛。假设海岸线是一条直线，且以海岸线为x轴，垂直海岸线向大海方向是y轴，给出小岛的数量和坐标，以及雷达的覆盖距离，计算覆盖所有小岛需要的最少雷达数。

### **解题思路**
设x轴负方向为左，正方向为右。

1. 首先的思路是对所有小岛按照x坐标排序（y无关，且当y坐标大于雷达距离D时无解），然后从左向右（x轴正方向）遍历所有小岛。每个雷达的位置都选取可能的最右的位置，从而使其可以覆盖最多的小岛。遍历每个小岛是判断上一雷达是否覆盖，若覆盖跳过，若不覆盖新建一个雷达（在最右位置）。

2. 思路1的问题是默认认为x坐标小的小岛的雷达范围（判断基准为雷达可行范围的最右位置）就一定靠左。其实不然。如下图所示，C点的x坐标小于D点的x左边，但是C点的雷达位置比D点的雷达位置更靠右。
![此处输入图片的描述][1]

因此，正确的思路：
- 对每一个小岛，计算其可行的雷达范围（最左最右），然后按照最右位置进行排序。
- 从最左的小岛开始，在其可行的最右位置建雷达。
- 遍历所有小岛，如果其最左位置小于上个雷达的位置（该小岛可被覆盖），继续；否则，在该小岛的最右位置新建一个雷达。

### **源码**
```c++
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

			//计算可以cover该岛的radar范围（最左最右）
			//之后根据最右进行排序，不可根据岛的x坐标排序，因为x坐标小的最右可能大
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
```


  [1]: https://raw.githubusercontent.com/istoney/poj_code/master/res/1328.png
