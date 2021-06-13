#include<iostream>
#include<bits/stdc++.h>
using namespace std;/*
bool sum_subset(vector<int> vect,int sum,int n)
{
    if(sum==0)
    return true;
    if(n==0 && sum!=0)
    return false;
    if(vect[n-1]<=sum)
    return sum_subset(vect,sum-vect[n-1],n-1)||sum_subset(vect,sum,n-1);
    else
    return sum_subset(vect,sum,n-1);
}*/
bool sum_subset(vector<int> vect,int sum,int n)
{   bool dp[n+1][sum+1];
    for (int i = 0; i <= n; i++) 
        dp[i][0] = true; 
  
    // If sum is not 0 and set is empty, 
    // then answer is false 
    for (int i = 1; i <= sum; i++) 
        dp[0][i] = false;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=sum;j++)
    {
        if(vect[i-1]<=j)
        dp[i][j]=dp[i-1][j-vect[i-1]] ||dp[i-1][j];
        else
        dp[i][j]=dp[i-1][j];
        }
        return dp[n][sum];
}
bool isequal_subset(vector<int> vect,int n)
{
    int sum=0;
    for(int i=0;i<vect.size();i++)
    {
        sum+=vect[i];
    }
    if(sum%2!=0)
    return false;
    return sum_subset(vect,sum/2,n);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,item;
    int T;
    cin>>T;
    while(T--)
    {
        vector<int> vect;
        cin>>n;
        m=n;
        while(m--)
        {
            cin>>item;
            vect.push_back(item);
        }
        if(isequal_subset(vect,n))
        cout<<"YES\n";
        else
        cout<<"NO\n";
    }    
    return 0;
    
}

