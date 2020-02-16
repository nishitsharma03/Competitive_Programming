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
		int n;
		cin>>n;
		int sum=0;
		while(n>=10)
		{
			sum+=(n-n%10);
			int cb=n/10;

			n=n%10;
			n=n+cb;
		}
		cout<<sum+n<<endl;
	}

	return 0;
}