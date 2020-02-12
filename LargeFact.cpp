#include <bits/stdc++.h>
#include <sstream>
#include <string> 
using namespace std;
string multiply(int factNo, string s);
int main()
{

	string s("1024");
	int x=10000;
	s=multiply(x,s);

	string add("1");
	for(int i=2;i<=x;i++)
	{
		add=multiply(i,add);
	}

	int i=0;
	while(add[i]=='0')
	{
		i++;
	}
	while(i<add.length())
	{
		cout<<add[i++];
	}

	//cout<<"factorial:"<<add;

}


string multiply(int factNo, string s)
{

	vector<char> v;
	string carry("00");
	string res;
	stringstream no(s);
	int car;

	for(int i=0;i<s.length();i++)
	{
		stringstream no(carry);

		
		no>>car;
		int x=(s[s.length()-(i+1)])-'0';
		int c=(car-(car%10))/10;
		
		int result=factNo*x+c;
		//cout<<"result:"<<factNo<<"*"<<x<<"+"<<c<<endl;
		res=to_string(result);

		// cout<<"|result:"<<res;
		// cout<<"pushed:"<<res[(res.length()-1)];
		v.push_back(res[(res.length()-1)]);

		res.replace (res.length()-1,1,"0");
		//cout<<"carry"<<res<<endl;
		if(res.length()>1)
		carry=res;
		else
		carry="00";
	}

	stringstream n(carry);
	n>>car;

	//cout<<"FINAL:"<<car/10;
	carry=to_string(car/10);
	
	for(int i=v.size()-1;i>=0;i--)
	{
		//cout<<v[i];
		carry.push_back(v[i]);
	}

	return carry;
}