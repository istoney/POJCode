//Memeory:220K	Time:16MS
//2013-08-06 01:50:51

#include<iostream>
#include<string>
using namespace std;
unsigned string_reverse(string &);
void string_multiply(string &res,string &ori);
void string_add(string &,unsigned,int);
void string_print(string, unsigned);
int main()
{
	string result = "",origin = "";
	unsigned n =0, poi_pos = 0;
	while(cin >> origin >>n)
	{
		poi_pos = string_reverse(origin);
		result = origin;
		for(int i=1;i<n;i++)
			string_multiply(result, origin);
		string_reverse(result);
		string_print(result,poi_pos*n);
		result = "";
		origin = "";
	}
	return 0;
}
unsigned string_reverse(string &ori)
{
	string tmp = "";
	unsigned poi_pos =0, poi_flag=0, j=0;
	for(int i=ori.size()-1; i>=0; i--){
		if(ori[i]!='.'){
			if(j>=tmp.size()) tmp.resize(j+1);
			tmp[j] = ori[i];
			j++;
			if(!poi_flag) poi_pos++;
		}
		else poi_flag = 1;
	}
	ori = tmp;
	return poi_pos;
}
void string_multiply(string &res,string &ori)
{
	string tmp = "";
	unsigned tmp_itor, a, c;//c=a*b
	for(unsigned i=0;i<ori.size();i++)
	{
		a=ori[i]-'0';
		tmp_itor = i;
		for(unsigned j=0;j<res.size();j++)
		{
			c=a*(res[j]-'0');
			string_add(tmp,tmp_itor,c%10);
			if(c>=10) 
				string_add(tmp,tmp_itor+1,c/10);
			tmp_itor++;
		}
	}
	res = tmp;
}
void string_add(string &ori,unsigned itor,int addend)//假设itor位置不是“.”
{
	if(itor>=ori.size()){
		ori.resize(itor+1);
		ori[itor]=addend+'0';
		return;
	}
	unsigned tmp = ori[itor] -'0' + addend;
	ori[itor] = tmp%10 + '0';
	if(tmp<=9)
		return;
	string_add(ori,itor+1,tmp/10);
}

void string_print(string res, unsigned poi_pos)
{
	for(int i=res.size()-1;i>=(res.size()-poi_pos);i--)
		if(res[i]=='0'){
			//res.pop_back();
			//res[i]='\0';
			res.erase(res.end()-1);
			poi_pos--;
		}else break;

	int zero_flag = 0;
	for(int i=0;i<res.size();i++)
	{
		if((!zero_flag) && res[i]=='0' && i<=(res.size()-poi_pos-1))
			continue;
		else zero_flag=1;
		if(i==(res.size()-poi_pos))
			cout<<".";
		cout<<res[i];
	}
	cout<<"\n";
}
