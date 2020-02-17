#include<bits/stdc++.h>
#define ll long long 
#define fab(a,b,i) for(int i=a;i<b;i++)
#define pb push_back
#define db double
#define quick ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

int main()
{ quick;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	string s;
	int n;
	cin>>n;
	cin>>s;
	int k=count(s.begin(),s.end(),'n');
	n-=k*3;
	n/=4;
	fab(0,k,i)
	cout<<"1 ";
	fab(0,n,i)
	cout<<"0 ";
	cout<<endl;

	return 0;
}