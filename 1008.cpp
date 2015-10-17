//Problem: 1008		User: vcc
//Memory: 256K		Time: 0MS
//Language: C++		Result: Accepted

//POJ_1008_Maya Calendar
//Created By Stoney
//2013-8-14

#include<iostream>
#include<string>
using namespace std;
int main()
{
	char month_name[19][8] = {"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
	char day_name[20][10] = {"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};

	int case_num = 0;
	cin>>case_num;
	cout<<case_num<<endl;
	while(case_num--)
	{
		unsigned day,month,year,i = 0;
		char tmp[8];
		cin>>day;
		getchar();getchar();
		cin>>tmp>>year;
		for(i=0;i<19 && abs(strcmp(tmp,month_name[i]));i++) {}
		month = i;

		i = year*365 + month*20 + day;
		cout<<i%13+1<<" "<<day_name[i%20]<<" "<<i/260<<endl;
	}
	return 0;
}
