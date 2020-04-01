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
string dectobin(ll int a)
{
    string s="";
    while(a>0)
    {
        if(a%2)
            s='1'+s;
        else
            s='0'+s;
        a/=2;
    }
    return s;
}
int binaryToDecimal(string n) 
{ 
    string num = n; 
    int dec_value = 0; 
  
    // Initializing base value to 1, i.e 2^0 
    int base = 1; 
  
    int len = num.length(); 
    for (int i = len - 1; i >= 0; i--) { 
        if (num[i] == '1') 
            dec_value += base; 
        base = base * 2; 
    } 
  
    return dec_value; 
} 

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    
  ll n;
  cin>>n;
  string s=dectobin(n);
  while(s.size()<6)
    s='0'+s;
    
    swap(s[1],s[5]);
    swap(s[2],s[3]);
    cout<<binaryToDecimal(s);

    

    return 0;
}