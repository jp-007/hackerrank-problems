#include<bits/stdc++.h>
using namespace std;

string superReducedString(string s) {
	string res;
	int i = 1;
	
	for(i = 0; i < s.size(); i++) {
		while(s[i] == s[i+1]) {
			i+=2;
		}
		res.push_back(s[i]);
	}
	return res;
}
int main() {
	string s;
	cin>>s;
	cout<<superReducedString(s);
}
