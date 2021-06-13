#include<bits/stdc++.h>
using namespace std;
bool is_subset(vector<int> vect,int n,int sum)
{ bool dp[n+1][sum+1] ;
    for(int i=0;i<=n;i++)
    for(int j=0;j<=sum;j++)
    {   if(i==0)
        dp[i][j]=false;
        if(j==0)
        dp[i][j]=true;
 if(vect[i-1]<=j)
 dp[i][j] = dp[][]||is_subset(vect,n-1,target_sum));
 else
 return is_subset(vect,n-1,target_sum);
 
 
}    
int main()
{
    int n,m,item,target_sum;
    vector<int> vect;
    cin>>n;
    m=n;
    while(m--)
    {
        cin>>item;
        vect.push_back(item);
    }
    cin>>target_sum;
    if(is_subset(vect,n,target_sum))
    cout<<"Subset found \n";
    else
    cout<<"No subset found\n";
    return 0;
    
    
}
