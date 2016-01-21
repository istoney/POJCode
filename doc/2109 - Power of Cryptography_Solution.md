#2109 题解

标签： POJ 高精度 二分

---
<script type="text/javascript" src="http://cdn.mathjax.org/mathjax/latest/MathJax.js?config=default"></script>

## *2109 Power of Cryptography*

### **题意**
输入整数n和p，求解整数k使$$k^n=p$$，其中1<=n<=200，1<=p<10^101
### **思路**
### **源码**
##### 1. 对double开n次方

```c++
#include<iostream>
#include<math.h>
using namespace std;

int main(){
	/* 浮点数比较
	*          精确度      范围
	* float    7位         3e38
	* double   15-16位     1.7e308
	*/
	double n, p;
	while(cin>>n>>p){
		cout<<pow(p, 1/n)<<endl;
	}
}

```

##### 2. 高精度+二分
```c++
#include <stdio.h>
#include <string.h>
#include <math.h>

#define LENGTH         110
#define LAST LENGTH-2
#define GREATER        1
#define EQUAL          0
#define LESS          -1

//大整数相乘
char* IntegerMultiplication(const char *a, const char *b, char *product){
	int i, j, k = LAST, first, value, temp[LENGTH];
	memset(temp, 0, sizeof(temp));

	for (i = strlen(a)-1; i >= 0; i--){
		first = k--;
		value = a[i] - '0';
		for (j = strlen(b)-1; j >= 0; j--){
			temp[first--] += value * (b[j] - '0');
		}
	}

	for (i = LAST; i >= first; i--){
		product[i] = temp[i] % 10 + '0';
		temp[i-1] += temp[i] / 10;
	}
	while (product[first] == '0' && first < LAST){
		first++;
	}
	return &product[first];
}

//比较两个字符串所表示数值的大小
int Compare(char *numA, char *numB){
	//去除前导'0'
	for (; *numA == '0'; numA++);
	for (; *numB == '0'; numB++);
	int lenNumA = strlen(numA);
	int lenNumB = strlen(numB);
	if (lenNumA == lenNumB){
		return strcmp(numA, numB);
	}
	if (lenNumA > lenNumB){
		return GREATER;
	}
	return LESS;
}

//求base^exp，结果存放在res中，pRes指向结果的首位数字的位置
char* Power(char *base, int exp, char *res){
	res[LAST] = '1';
	char *pRes = &res[LAST], *temp = base;
	while (exp != 0){
		if (exp % 2 == 1){
			pRes = IntegerMultiplication(base, pRes, res);
		}
		exp /= 2;
		if (exp != 0){
			base = IntegerMultiplication(base, base, temp);
		}
	}
	return pRes;
}

int main(void){
	char p[LENGTH], res[LENGTH], cMid[LENGTH];
	unsigned int n, lenP, lenRoot, i, min, max, mid;

	while (scanf("%d %s", &n, &p) != EOF){
		//根据n和p的倍数关系，得到k的范围的min值和max值
		lenP = strlen(p);
		lenRoot = (int)ceil((double)lenP / n);

		for (i = 1, min = 1; i < lenRoot; i++){
			min *= 10;
		}
		for (i = 1, max = 9; i < lenRoot; i++){
			max *= 10;
			max += 9;
		}

		//二分法寻找k值
		bool finish = false;
		while (!finish){
			mid = (min + max) / 2;
			if (min >= max){
				break;
			}
			sprintf(cMid, "%d", mid);
			memset(res, 0, sizeof(res));
			switch (Compare(Power(cMid, n, res), p)){
			case LESS: min = mid + 1; break;
			case EQUAL: finish = true; break;
			case GREATER: max = mid - 1; break;
			default: break;
			}
		}
		//由于题目所给数据会有不满足k^n=p的情况
		//下面是为了得到一个最大的k，满足k^n<=p
		sprintf(cMid, "%d", mid);
		if (Compare(Power(cMid, n, res), p) == GREATER){
			mid--;
		}
		printf("%d\n", mid);
	}
	return 0;
}
```
