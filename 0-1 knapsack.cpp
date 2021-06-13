#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int knapsack(int dp[1001][1001],vector<int> values,vector<int> weight,int capacity,int n)
{
    if(n==0 || capacity==0)
    return 0;
    if(dp[n][capacity]!=-1)
    return dp[n][capacity];
    if(weight[n-1]<=capacity)
    return dp[n][capacity]= max(values[n-1] + knapsack(dp,values,weight,capacity-weight[n-1],n-1),knapsack(dp,values,weight,capacity,n-1));
    else 
    return dp[n][capacity]=knapsack(dp,values,weight,capacity,n-1);
    
}
int main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T--)
    {  
        int n,val,w,m,capacity;
        vector<int> values;
        vector<int> weight;
        cin>>n;
        cin>>capacity;
        int dp[1001][1001];
        memset(dp,-1,sizeof(dp));
        m=n;
        while(m--)
        {
            cin>>val;
            values.push_back(val);
        }
        m=n;
        while(m--)
        {
            cin>>w;
            weight.push_back(w);
        }
        
        int max_value=knapsack(dp,values,weight,capacity,n);
        cout<<max_value<<"\n";
    }    
    return 0;
    
}

