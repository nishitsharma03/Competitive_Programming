#pragma GCC optimize "trapv"
#include<bits/stdc++.h>
#define ll long long 
#define fab(a,b,i) for(ll int i=a;i<b;i++)
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
ll int n,m;
cin>>n>>m;
 ll int min,max;
 if(m>=ceil(float(n)/2.0))
 	min=0;
 else
 	{min=((n)/2-m)*2;
 		min+=(n%2?1:0);

 	}
 if(m>((n-2)*(n-1))/2)
 	max=0;
 else
 {
	//ll int sum=0; 	
 	fab(1,n,i)
 	{	
 		ll int sum=((i)*(i-1))/2;
 		//cout<<sum<<" ";
 		if(sum>=m)
 		{
 			max=n-i;
 			break;
 		}
 	}
 	if(m==0)
 		max=n;
 }
	cout<<min<<" "<<max<<endl;

	return 0;
}