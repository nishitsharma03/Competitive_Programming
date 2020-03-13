#pragma GCC optimize "trapv"
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
		int n;
		cin>>n;
		int k;
		int even=0,odd=0;
		fab(0,n,i)
		{
			cin>>k;
			if(k%2)
				even++;
			else
				odd++;
			
		}
		//cout<<"r"<<even<<"R"<<odd<<endl;
		if(even&&odd)
			cout<<"NO\n";
		else
			cout<<"YES\n";
	}
	

	return 0;
}