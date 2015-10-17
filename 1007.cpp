//Problem: 1007		User: vcc
//Memory: 252K		Time: 0MS
//Language: C++		Result: Accepted

#include<iostream>
#include<string>
using namespace std;

typedef struct DNA{
	char* str;
	unsigned inver_num;
} DNA;

void cal_unsortedness(DNA & dna, unsigned n);
int dna_compare(const void * dna1, const void *dna2)
{     
	return ((DNA*)dna1)->inver_num - ((DNA*)dna2)->inver_num; 
}

int main()
{
	unsigned n,m;
	cin>>n>>m;
	DNA *dna_vec = (DNA *)malloc(sizeof(DNA)*m);
	char *tmp_str = (char *)malloc(sizeof(char)*(n+1));
	for(int i=0;i<m;i++)
	{
		cin>>tmp_str;
		dna_vec[i].str = (char *)malloc(sizeof(char)*(n+1));
		strcpy(dna_vec[i].str, tmp_str);
		cal_unsortedness(dna_vec[i], n);
	}
	qsort(dna_vec,m,sizeof(DNA),dna_compare);
	//cout<<"  \n";
	for(int i=0;i<m;i++)
		cout<<dna_vec[i].str<<endl;

	delete tmp_str;
	for(int i=0;i<m;i++)
		delete dna_vec[i].str;
	delete dna_vec;
	return 0;
}
void cal_unsortedness(DNA & dna, unsigned n)
{
	dna.inver_num = 0;
	for(int i=0;i<n;i++)
	{
		char tmp = dna.str[i];
		for(int j=i+1;j<n;j++)
			if(dna.str[j] < tmp) dna.inver_num++;
	}
}
