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
