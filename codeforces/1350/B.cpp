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

const int MAX = 1e5; 
ll int n; 
ll int a[100005];
ll int dp[100005];
    
// Initialize global divisor vector  
// array of sequence container  
vector<int> divisor[MAX + 1];  
  
// Calculate all  
// divisors of number  
void sieve()  
{  
    for (int i = 1; i <= MAX; ++i) {  
        for (int j = i; j <= MAX; j += i)  
            divisor[j].push_back(i);  
    }  
} 
void recurse(int start)
{
	
	
		ll int j=2,cnt=1;
		while(start*j<=n)
		{
			if(a[start*j]>a[start])
					{cnt=max(cnt,dp[start*j]+1);
						}
						j++;
			}
					dp[start]=cnt;
	
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
		
		cin>>n;
		
		fab(1,n+1,i)
		cin>>a[i];
		ll int ans=1;
	/*	fab(1,n+1,i)
		{
			ll int j=i;
			ll int start=a[i]-1;
			ll int cnt=0;
			if(a[1]<a[i])
				cnt++;
			while(j<=n)
			{
				if(a[j]>start)
					{cnt++;
						start=a[j];}
				j*=2;
			}
			dp[i]=cnt;
			ll int add=0;
			for(auto j: divisor[i])
			{
				if(a[j]<a[i])
					tot++;
				else
			}
			ans=max(ans,cnt+add);
		}*/
		for(int i=n;i>0;i--)
		{
			recurse(i);
		}
		//fab(1,n+1,i)
		//cout<<dp[i]<<" ";
		//cout<<endl;
		cout<<*max_element(dp+1,dp+n+1)<<endl;

	}
	

	return 0;
}