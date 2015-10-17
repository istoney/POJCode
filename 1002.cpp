//Memory:624K	Time:1250MS
//2013-08-08 00:05:00

#include<iostream>
#include<string>
using namespace std;

unsigned tele_check(string);
void tele_print(unsigned);
int tele_compare(const void *a, const void *b)
{
	return *(unsigned *)a - *(unsigned *)b;
}
int main()
{
	unsigned num =0,un_tmp;
	string str_tmp;
	
	cin>>num;
	unsigned *teles = (unsigned *)malloc(sizeof(unsigned)*num);

	for(int i=0;i<num;i++)
	{
		cin>>str_tmp;
		un_tmp = tele_check(str_tmp);
		teles[i] = un_tmp;
	}
	qsort(teles, num, sizeof(unsigned), tele_compare);

	int flag=0;
	for(int i=0;i<num;)
	{
		int j;
		for(j=i+1;teles[j]==teles[i];j++) {}
		if(j>i+1) {
			flag=1;
			tele_print(teles[i]);
			cout<<" "<<j-i<<endl;
		}
		i=j;
	}
	if(!flag) cout<<"No duplicates."<<endl;
	delete teles;
	return 0;
}
unsigned tele_check(string tele_str)
{
	unsigned tele_int = 0;
	for(int i=0;i<tele_str.size();i++)
	{
		if('0'<=tele_str[i] && tele_str[i]<='9'){
			tele_int = tele_int*10;
			tele_int += tele_str[i]-'0';
		}
		else if('A'<=tele_str[i] && tele_str[i]<='P'){
			tele_int = tele_int*10;
			tele_int += (tele_str[i] - 'A')/3 +2;
		}
		else if('R'<=tele_str[i] && tele_str[i]<='Y'){
			tele_int = tele_int*10;
			tele_int += (tele_str[i]-'Q')/3 + 7;
		}
	}
	return tele_int;
}
void tele_print(unsigned tele)
{
	cout<< tele/1000000;
	tele = tele%1000000;
	cout<< tele/100000  ;
	tele = tele%100000;
	cout<< tele/10000  <<'-';
	tele = tele%10000;
	cout<< tele/1000  ;
	tele = tele%1000;
	cout<< tele/100  ;
	tele = tele%100;
	cout<< tele/10  ;
	tele = tele%10;
	cout<< tele  ;
}
