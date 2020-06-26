#include<bits/stdc++.h>
using namespace std;


const string keyboard = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";

int main(int argc, char const *argv[])
{
	string s;
	while(getline(cin,s)){
	int idx;
	for (int i = 0; i < s.length(); ++i)
	{
		if(s[i]==' ') cout<<" ";
		else{
			for(int j=0;j<keyboard.length();j++){
			if(tolower(s[i])==keyboard[j]){
				cout<<keyboard[j-2];
				break;
			}
		}
		}
		
	}
	cout<<endl;
}
	return 0;
}