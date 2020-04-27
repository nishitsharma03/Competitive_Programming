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

 ll int lcm(int a, int b)  
 {  
    return (a*b)/__gcd(a, b);  
 }
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
		ll int a,b,q;
		cin>>a>>b>>q;
		if(a>b)
			swap(a,b);
		ll int cnt=1;
		int mid=lcm(a,b);

	/*	fab(1,221,i)
		{
			if((i%a)%b==(i%b)%a)
				cout<<i<<" ";

		}*/
		fab(0,q,i)
		{
			ll int l,r;
			cin>>l>>r;
			if(r<b or b%a==0)
			{
				cout<<0<<" ";
				continue;
			}
			
			ll int p=max(l,b);
			
			ll int mult=abs((((p/mid)*mid)-(r/mid)*mid)/mid)*b;

			//cout<<"mult:"<<mult<<endl;
			if((r/mid)*mid+b-1>r)
				mult-=(b-(r-(r/mid)*mid)-1);
			if(p%mid<b)
			{
				mult+=b-p%mid;
			}
			//cout<<"mult"<<mult<<endl;
			cout<<r-p+1-mult<<" ";


		}
		cout<<endl;
	}
	

	return 0;
}