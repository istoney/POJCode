#1009 题解

标签： POJ 跳跃编码

---

## *1009 Edge Detection*

### **题意**
使用一种叫做“run length encoding”的方式来储存大尺寸图片，该方法是通过记录编码值和编码长度的对（value，length）来存储图片。有一种简单的edge detection算法是将图像中的每一个点的值与他周围的八个点求差，然后取绝对值的最大值。

现在的任务就是实现这个算法，输入的图片是以run length encoding的形式表示的，同时也要求转换后的图片也以run length encoding的形式表示。

### **思路**
题意中说明图片的长度为10^9，因此不可能采用暴力计算法。但是输入的pair number不超过1000，数量上是很少的，因此可以采用*跳跃编码*。

- run length encoding编码方法是记录编码值和该值的编码长度，这里长度可以用开始和结束位置代替，结束位置可以用下一个值的开始位置表示。这样就变成记录每一个出现的新值和出现的位置即可。

- 而edge detection中每一个新值的出现都是因为输入图片中新值的出现。因此，只要对输入图片的每一个pair计算这个新值开始位置周围8个像素edge值，并记录位置即可。然后对所有计算的edge值根据位置排序，并且对edge值相同的pair进行合并就是所求结果。

### **异常点处理**
- 上述讲到对于输入图片中每一个新值的周围8个像素点都进行计算，但是当该开始位置位于一行的末尾时是否需要对后续像素计算。答案是需要。下表中第二行第三列的3是一个新值因此需要对周围8个像素计算；而第二行第四列的4也是一个新值，那么就要对该值周围的8个像素，包括其后的三个值（括号里），而它们对应的像素就是绿色圈起来的像素点。
![这里写图片描述](https://raw.githubusercontent.com/istoney/poj_code/master/res/1009_1.jpg)

- 另外一个异常点出现在最后一行，见下图，这是因为最后一行的第一个像素因为没有了下一行而出现变化。
![这里写图片描述](https://raw.githubusercontent.com/istoney/poj_code/master/res/1009_2.jpg)

### **源代码**
```c++
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

const int size = 1000;
int width;
int totle; //input pix length

typedef struct{
	int value;
	int pos;
} Pix;

int in_pairs[size][2];	//input picture, pairs[i][0] is value, pairs[i][1] is run length;
Pix out_pairs[size*8];
int pairs_num = 0;

//pos starts from 0

int get_value(int pos){
	int len=0, i=0;
	while(pos > len-1){
		len += in_pairs[i++][1];
	}
	return in_pairs[i-1][0];
}

int cmp(const void *m, const void *n){
	Pix * a = (Pix *) m;
	Pix * b = (Pix *) n;
	return a->pos - b->pos;
}

int cal_value(int pos){

	int max = 0;
	int value = get_value(pos);

	int row = pos/width;
	int col = pos%width;

	for(int i=row-1;i<row+2;i++){
		for(int j=col-1;j<col+2;j++){

			int tmp_pos = i*width + j;

			if(j<0 || j>=width || i<0 || tmp_pos>=totle)
				continue;

			int tmp_value = get_value(tmp_pos);
			if(abs(value-tmp_value) > max)
				max = abs(value-tmp_value);
		}
	}
	return max;
}

int main(){
	while(cin>>width && width){
		pairs_num = 0;
		totle = 0;

		int val, len;
		while(cin>>val>>len && len){
			in_pairs[pairs_num][0] = val;
			in_pairs[pairs_num++][1] = len;
			totle += len;
		}

		cout << width <<endl;

		int pos = 0;
		int out_index = 0;

		for(int k=0;k<pairs_num;k++){
			int row = pos/width;
			int col = pos%width;

			for(int i=row-1;i<row+2;i++){
				for(int j=col-1;j<col+2;j++){

					int tmp_pos = i*width + j;
					//if(j<0 || j>=width || i<0 || tmp_pos>=totle)
					if(j<0 || i<0 || tmp_pos>=totle)
						continue;

					out_pairs[out_index].pos = tmp_pos;
					out_pairs[out_index++].value = cal_value(tmp_pos);
				}
			}
			pos += in_pairs[k][1];
		}

		//head point in last line
		out_pairs[out_index].pos = totle - width;
		out_pairs[out_index++].value = cal_value(totle - width);

		qsort(out_pairs, out_index, sizeof(Pix), cmp);

		int res_val=-1, start_pos = -1;
		for(int i=0;i<out_index;i++){
			if(out_pairs[i].value == res_val)
				continue;
			else{
				if(res_val < 0){
					res_val = out_pairs[i].value;
					start_pos = 0;
					continue;
				}
				else{
					cout<<res_val<<" "<<out_pairs[i].pos-start_pos<<endl;
					res_val = out_pairs[i].value;
					start_pos = out_pairs[i].pos;
				}
			}
		}
		cout<<res_val<<" "<<totle-start_pos<<endl;
		cout<<"0 0"<<endl;
	}
	cout<<"0";
}
```
