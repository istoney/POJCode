/*	POJ
Problem: 1018		User: vcc
Memory: 1576K		Time: 157MS
Language: C++		Result: Accepted
*/

#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;

#define MAX_DEVICES 100

class DEVICE{
	public:
		int B;
		int P;
		int id;
};

int cmp(const void * a, const void * b){
	DEVICE *x = (DEVICE *)a;
	DEVICE *y = (DEVICE *)b;
	
	if((x->B) == (y->B)){
		if((x->P) == (y->P)) return (x->id) - (y->id);	
		
		return (x->P) - (y->P);
	}
	return (x->B) - (y->B);
}

double max(double x, double y){
	return x>y?x:y;
}

int main(){
	int test;
	cin>>test;
	for(int t=0;t<test;t++){
		int n, m = 0;
		cin>>n;
		
		int *MaxB = new int[n];
		DEVICE *dev = new DEVICE[MAX_DEVICES*MAX_DEVICES];
		
		int dev_ptr = 0;
		
		//get input
		for(int i=0;i<n;i++){
			int mi;
			cin>>mi;
			m += mi;
			
			MaxB[i] = 0;
			
			int b,p;
			for(int j=0;j<mi;j++){
				cin>>b>>p;
				dev[dev_ptr].B = b;
				dev[dev_ptr].P = p;
				dev[dev_ptr].id = i;
				
				if(dev[dev_ptr].B > MaxB[i]) MaxB[i] = dev[dev_ptr].B;
				dev_ptr++;
			}
		}
		
		qsort(dev, m, sizeof(DEVICE), cmp);
		
		//start
		bool flag = false;
		double ans = 0;
		
		for(int i=0;i<=(m-n);i++){
			bool *visit = new bool[n];
			memset(visit, false, sizeof(bool) * n);
			
			visit[dev[i].id] = true;
			int B = dev[i].B;
			double price = dev[i].P;
			int count = 1;
			
			for(int j=i+1;j<m;j++){
				if(visit[dev[j].id]) continue;
				
				if(B > MaxB[dev[j].id]){
					flag = true;
					break;
				}
				
				visit[dev[j].id] = true;
				price += dev[j].P;
				count++;
			}
			
			//当有一个设备的最大带宽小于B时停止
			//当 
			if(flag || count<n)
				break;
			
			ans = max(ans, B/price);
		}
		
		cout<<fixed<<setprecision(3)<<ans<<endl;
	
		delete [] MaxB;
		delete [] dev;
	}
	
	return 0;
}
