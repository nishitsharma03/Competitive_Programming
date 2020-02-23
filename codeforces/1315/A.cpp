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
	int t;
	cin>>t;
	while(t--)
	
	{
		int a,b,x,y;
		cin>>a>>b>>x>>y;
		int ar[4];
		ar[0]=(x)*b;
		ar[1]=(y)*a;
		ar[2]=(a-x-1)*b;
		ar[3]=(b-y-1)*a;
		cout<<*max_element(ar,ar+4)<<endl;
	}

	return 0;
}