#include<bits/stdc++.h>
using namespace std;

#define pb push_back

string f(int x){
	ostringstream s1;
	s1<<x;
	string t = s1.str();
	return t;
}

int main(int argc, char const *argv[])
{
	string s;
	std::vector<string> v_1,v_2,v_3,v_4,v_5;
	std::vector<char> v1;
	for (int i = 0; i <26; ++i)
	{
		v1.pb(i+97);
		string x="";
		for (int i1 = 0; i1 < v1.size(); ++i1)
		{
			x+=v1[i1];
		}
		v_1.pb(x);
		for (int j = i+1; j <26 ; ++j)
		{
			v1.pb(j+97);
			string y="";
			for (int j1 = 0; j1 < v1.size(); ++j1)
			{
				y+=v1[j1];
			}
			v_2.pb(y);
			for (int k = j+1; k <26 ; ++k)
			{
				v1.pb(k+97);
				string w="";
				for (int k1 = 0; k1 < v1.size(); ++k1)
				{
					w+=v1[k1];
				}
				v_3.pb(w);
				for (int l = k+1; l < 26; ++l)
				{
					v1.pb(l+97);
					string u="";
					for (int l1 = 0; l1 < v1.size(); ++l1)
					{
						u+=v1[l1];
					}
					v_4.pb(u);
					for (int m = l+1; m <26 ; ++m)
					{
						v1.pb(m+97);
						string z="";
						for (int m1 = 0; m1 < v1.size(); ++m1)
						{
							z+=v1[m1];
						}
						v_5.pb(z);
						v1.pop_back();
					}
					v1.pop_back();
				}
				v1.pop_back();
			}
			v1.pop_back();
		}
		v1.pop_back();
	}
	//cout<<v_1.size()+v_2.size()+v_3.size()+v_4.size()+v_5.size();
	std::map<string, int> m;
	int cnt=1;
	for (int i = 0; i < v_1.size(); ++i)
	{
		m[v_1[i]] = cnt;
		cnt++;
	}
	for (int i = 0; i < v_2.size(); ++i)
	{
		m[v_2[i]] = cnt;
		cnt++;
	}
	for (int i = 0; i < v_3.size(); ++i)
	{
		m[v_3[i]] = cnt;
		cnt++;
	}
	for (int i = 0; i < v_4.size(); ++i)
	{
		m[v_4[i]] = cnt;
		cnt++;
	}
	for (int i = 0; i < v_5.size(); ++i)
	{
		m[v_5[i]] = cnt;
		cnt++;
	}

	while(cin>>s){
		cout<<m[s]<<endl;
	}
	return 0;
}