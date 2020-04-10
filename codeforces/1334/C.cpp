#include<iostream>
#define quick ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;
long long int mv(long long int a,long long int b)
{
    if (a>b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int main()
{
    quick;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
long long int T;
cin>>T;
while(T--)
{
    long long int n,fb,fa;
    cin>>n;
    long long int A[n][2];
    for (long long int i=0;i<n;i++)
    {
        long long int a,b;
        cin>>a>>b;
        A[i][0]=a;
        A[i][1]=b;
        if (i==0)
        {
            fb=A[0][0];
        }
        else
        {
            fb=fb+mv(A[i][0]-A[i-1][1],0);
        }
    }
    fa=fb;
    for (long long int i=1;i<n;i++)
    {
        if (i==1)
        {
        fb=fb-A[i-1][0]-mv(A[i][0]-A[i-1][1],0)+mv(A[i-1][0]-A[n-1][1],0)+A[i][0];
        if (fb<fa)
            fa=fb;
        }
        else
        {
            fb=fb-A[i-1][0]-mv(A[i][0]-A[i-1][1],0)+mv(A[i-1][0]-A[i-2][1],0)+A[i][0];
        if (fb<fa)
            fa=fb;
        }
    }
    cout<<fa<<endl;

}
return 0;
}