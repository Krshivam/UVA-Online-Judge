#include<bits/stdc++.h>
using namespace std;

string two[3] = { "00", "01", "81" };

string four[5] = { "0000", "0001", "2025", "3025", "9801" };

string six[5] = { "000000", "000001", "088209", "494209", "998001" };

string eight[9] = { "00000000", "00000001", "04941729", "07441984", "24502500", "25502500", "52881984", "60481729", "99980001" };


int main(int argc, char const *argv[])
{
	
	int n;
	while(cin>>n){
		if(n==2){
			for(int i=0;i<3;i++){
				cout<<two[i]<<endl;
			}
		}
		if(n==4){
			for(int i=0;i<5;i++){
				cout<<four[i]<<endl;
			}
		}
		if(n==6){
			for(int i=0;i<5;i++){
				cout<<six[i]<<endl;
			}
		}
		if(n==8){
			for(int i=0;i<9;i++){
				cout<<eight[i]<<endl;
			}
		}
	}
	return 0;
}