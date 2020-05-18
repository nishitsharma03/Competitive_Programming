//#pragma GCC optimize "trapv"
#include<bits/stdc++.h>
#define ll long long int
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
string s,t; 
ll dp[4000][4002];
ll recurse(ll sptr,ll tptr)
{
	if(sptr<0)
		return 0;
	if(tptr<0)
		return 0;
	if(dp[sptr][tptr]!=-1)
		return dp[sptr][tptr];
	if(s[sptr]==t[tptr])
		return dp[sptr][tptr]=recurse(sptr-1,tptr-1)+1;
	else 
		

		return dp[sptr][tptr]=max(recurse(sptr-1,tptr),recurse(sptr,tptr-1));
	
}
int main()
{ quick;

    cin>>s>>t;
    fab(0,s.size(),i)
    fab(0,t.size(),j)
    {
    	//cout<<dp[i][j];
    	dp[i][j]=-1;
    
    }

    ll sptr=s.size()-1,tptr=t.size()-1;
    ll siz=recurse(sptr,tptr);
    sptr=s.size()-1;tptr=t.size()-1;
    string ans="";
    while(sptr>=0 and tptr>=0)

    {
    	if(s[sptr]==t[tptr])
    		{ans=s[sptr]+ans;
    			sptr--;
    			tptr--;}
    	else if(sptr>0 and tptr>0 and dp[sptr-1][tptr]>dp[sptr][tptr-1])
    		sptr--;
    	else if(tptr==0)
    		sptr--;
    	else 
    		tptr--;


    }
    //assert(ans.size()==siz);
    cout<<ans<<endl;
    


	return 0;
}