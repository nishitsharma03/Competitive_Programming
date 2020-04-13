//#pragma GCC optimize "trapv"
#include<bits/stdc++.h>
#define ll long long 
#define fab(a,b,i) for(int i=a;i<b;i++)
#define pb push_back
#define db double
#define mp make_pair
#define endl "\n"
#define f first
#define se second
#define all(x) x.begin(),x.end()
#define MOD 1000000007
#define quick ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

int main()
{ quick;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	int t;
	cin>>t;
	while(t--)
	{
		string s[9];
		fab(0,9,i)
		cin>>s[i];
		if(s[0][0]=='1')
			s[0][0]='2';
		else
			s[0][0]='1';
		if(s[3][1]=='1')
			s[3][1]='2';
		else
			s[3][1]='1';
		if(s[6][2]=='1')
			s[6][2]='2';
		else
			s[6][2]='1';
		if(s[1][3]=='1')
			s[1][3]='2';
		else
			s[1][3]='1';
		if(s[2][6]=='1')
			s[2][6]='2';
		else
			s[2][6]='1';
		if(s[4][4]=='1')
			s[4][4]='2';
		else
			s[4][4]='1';
		if(s[7][5]=='1')
			s[7][5]='2';
		else
			s[7][5]='1';
		if(s[5][7]=='1')
			s[5][7]='2';
		else
			s[5][7]='1';
		if(s[8][8]=='1')
			s[8][8]='2';
		else
			s[8][8]='1';
	
	fab(0,9,i)
	cout<<s[i]<<endl;
	}

	return 0;
}