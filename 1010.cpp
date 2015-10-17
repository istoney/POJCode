#include<iostream>
#include<vector>
#include<string>
using namesapce std;

typedef struct {
	int typeN;
	int totalN;
	int max;
} comb;

int stamps[25];
vector<int> customers;
vector<comb> ;

int main(){
	int n;
	while(cin>>n){
		int index = 0;
		stamps[index++] = n;
		while(cin>>n && n){
			stamps[index++] = n;
		}
		
		string tmp;
		getline(cin, tmp);
		
		customers.clear();
		while(cin>>n && n){
			customers.push_back(n);
		}
		
		
	}
	return 0;
}
