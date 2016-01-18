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
