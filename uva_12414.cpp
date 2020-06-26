#include<bits/stdc++.h>
using namespace std;

string f(int x){
	ostringstream s;
	s<<x;
	string s1 = s.str();
	return s1;
}

int f2(string s){
	stringstream f3(s);
	int x;
	f3>>x;
	return x;
}

string f1(string s1){
	string s2="";
	for (int i = 0; i < s1.length()-1; ++i)
	{
		s2+=f((s1[i]-'0'+s1[i+1]-'0')%10);
	}
	return s2;
}

int main(int argc, char const *argv[])
{
	string s;
	while(cin>>s){
		int st=1;
		int b=0;
		int n = s.length();
		while(st<=10000){
			string s1="";
			for (int i = 0; i < n ;++i)
			{
				int x = s[i]-'A'+st;
				s1+=f(x);
			}
			 b=0;
			 while(s1!="100" && s1.length()>2){
			 	b=0;
			 	s1 = f1(s1);
				if(s1=="100"){
					cout<<st<<endl;
					b=1;
					break;
				}
			 }
			if(b) break;
			st++;
		}
		if(!b) cout<<":("<<endl;
	}
	return 0;
}