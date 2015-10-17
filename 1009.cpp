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
