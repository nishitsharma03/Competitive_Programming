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
vector<int> printDivisors(int n) 
{ 
    // Note that this loop runs till square root
    vector<int> v;

    for (int i=1; i<=sqrt(n); i++) 
    { 
        if (n%i == 0) 
        { 
            // If divisors are equal, print only one 
            
                
  
            // Otherwise print both 
                v.pb(i);
                v.pb(n/i);
        } 
    }
    return v; 
}

int main()
{ quick;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	int n,m,k;
	cin>>n>>m>>k;
	int a[n],b[m];
	int cnta=0,cntb=0;
	fab(0,n,i)
	{
		cin>>a[i];
		if(a[i]==1)
			cnta++;
	}
	fab(0,m,j)
	{
		cin>>b[j];
		if(b[j]==1)
			cntb++;
	}

ll int cnt=0,ans=0;
/*	if(k<=n)
	{	
		fab(0,n,i)
		{if(a[i]==1)
			cnt++;
			else
				cnt=0;
		}
		if(cnt>=k)
		ans++;
	}
	ans*=cntb;
	
	cnt=0;
	if(k<=m)
	{	
		fab(0,m,i)
		{if(b[i]==1)
			cnt++;
		else
			cnt=0;
		if(cnt>=k)
		ans++;}
	}
	if(cnt>=m)
		ans*=cnta;
	*/
cnt=0;
	//cout<<"dsfs";
	vector<int> dp(m,0);
	
	for(int i=m-1;i>=0;i--)
	{
		if(b[i]==1)
			cnt++;
		else
			cnt=0;
		//cout<<"dfg";
		dp[i]=cnt;
	}
	sort(dp.begin(),dp.end());

//cout<<"sg";
	//vector<int> v=printDivisors(k);

cnt=0;
	fab(0,n,i)
	{
		if(a[i]==1)
		{
			cnt++;
		}
		else
			cnt=0;
		//cout<<"xnt="<<cnt;
		if(cnt>0&&k%cnt==0)
		{	
			int abx=1;int j=i+1;
			while(a[j]==1)
			{
				abx++;
				j++;
			}
			int ex=k/cnt;
			int ind=lower_bound(dp.begin(),dp.end(),ex)-dp.begin();
			//cout<<"ind="<<ind;
			ans+=(m-ind)*abx;	
		}
	}






	cout<<ans<<endl;
	return 0;
}