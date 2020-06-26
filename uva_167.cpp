#include<bits/stdc++.h>
using namespace std;
int arr[10][10];
char new_arr[10][10];
int mx = 0;
int ans=0;

bool isPossible(int x,int y){
	for (int i = 0; i < 8; ++i)
	{
		if(new_arr[x][i]=='q' || new_arr[i][y]=='q') return false;
	}
	int i,j;
	for (i=x, j=y; i>=0 && j>=0; i--, j--) 
        if (new_arr[i][j]=='q') 
            return false; 
	for (i=x, j=y; j<8 && i>=0; i--, j++) 
        if (new_arr[i][j]=='q') 
            return false; 
	return true;
}

void placeQueen(int i,int j){
	if(i==8){
		ans=0;
		for (int i = 0; i < 8; ++i)
		{
			for (int j = 0; j < 8; ++j)
			{
				if(new_arr[i][j]=='q') ans+=arr[i][j];
			}
		}
		/*for (int i = 0; i < 8; ++i)
		{
			for (int j = 0; j < 8; ++j)
			{
				cout<<new_arr[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		//cout<<ans<<endl;*/
		mx = max(mx,ans);
		return;
	}
	for (int k = 0; k < 8; ++k)
	{
		if(isPossible(i,k)){
			new_arr[i][k] = 'q';
			placeQueen(i+1,k);
			new_arr[i][k] = '-';
		}
	}

	return ;
}

int main(int argc, char const *argv[])
{
	int k;
	cin>>k;
	while(k--){
		memset(new_arr,'-',sizeof(new_arr));
		mx = 0;
		ans = 0;
		for (int i = 0; i < 8; ++i)
		{
			for (int j = 0; j < 8; ++j)
			{
				cin>>arr[i][j];
			}
		}
		placeQueen(0,0);
		cout<<setw(5)<<setfill(' ')<<mx<<endl;
	}
	return 0;
}