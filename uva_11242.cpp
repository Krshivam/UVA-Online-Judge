#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n,m;
	while((cin>>n)&&n){
		cin>>m;
		double f[n+1];
		double r[m+1];
		for (int i = 0; i < n; ++i)
		{
			cin>>f[i];
		}
		for (int i = 0; i < m; ++i)
		{
			cin>>r[i];
		}
		double new_arr[105];
		int d=0;
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				new_arr[d] = r[i]/f[j];
				d++;
			}
		}
		sort(new_arr,new_arr+d);
		double max1 = -1.0;
		for (int i = 0; i <d-1 ; ++i)
		{
			max1 = max(max1,new_arr[i+1]/new_arr[i]);
		}
		printf("%0.2f\n", max1);
	}
	return 0;
}