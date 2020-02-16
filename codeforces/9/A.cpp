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
	
	
	{
		int w,h;
		cin>>w>>h;
		int am=6-max(w,h)+1;
		int den=6;
		int g=__gcd(am,den);
		am/=g;
		den/=g;
		cout<<am<<"/"<<den<<endl;
	}

	return 0;
}