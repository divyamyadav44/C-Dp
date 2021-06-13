#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void find_LCS(char *x ,char *y,int n,int m)
{
    int  L[n+1][m+1];
    for(int i=0;i<=n;i++)
    for(int j=0;j<=m;j++)
    {
        if(i==0 || j==0)
        L[i][j]=0;
        else if(x[i-1]==y[j-1])
        L[i][j]=1+L[i-1][j-1];
        else
        L[i][j]=max(L[i-1][j],L[i][j-1]);  
    }
    int index= L[n][m];
    char LCS[index+1];
    LCS[index]='\0';
    index--;
    int i=n,j=m;
    while(i>0 && j>0)
    {
        if(x[i]==y[j])
        {
            LCS[index]=x[i-1];
            index--,i--,j--;
        }
        else if(L[i-1][j]>L[i][j-1])
        i--;
        else
        j--;
    }
    cout<<LCS;
    
}
int main()
{
    int n,m;
    cin>>n>>m;
    char str1[n],str2[m];
    cin>>str1;
    cin>>str2;
    /*int res=*/find_LCS(str1,str2,n,m);
  /*  cout<<res;*/
    return 0;
}

