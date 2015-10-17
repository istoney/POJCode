#include<iiostream>

using namespace std;

typedef struct {
	bool good_bad;
	bool live;
	guy * next;
} guy;

guy *head=NULL;

bool testM(int k, int m){
	int count = 0;
	while(true){
		
	}
}

void fresh()

int main(){
	int k;
	guy *cur=NULL, *last=NULL;
	while(cin>>k && k){
		for(int i=0;i<2*k;i++){
			cur = new guy;
			
			if(i<k) cur.good_bad = true;
			else cur.good_bad = false;
			cur.live = true;
			cur.next = NULL;
			
			if(head==NULL) head = cur;
			else last.next = cur;
			last = cur;
			if(i==(2*k-1)) cur.next = head;
		}
		
		
	}
}
