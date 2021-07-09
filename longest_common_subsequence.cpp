#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

int lcs(int, int, string, string);

int main()
{
    int t,n,k,x,y;
    
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        
        cout << lcs(x, y, s1, s2) << endl;
    }
    return 0;
}
// } Driver Code Ends


// function to find longest common subsequence

int lcs(int x, int y, string s1, string s2){
    
    // your code here
    int **output=new int*[x+1];
    for(int i=0;i<x+1;i++)
    {
        output[i]=new int[y+1];
    }
    
    output[0][0]=0;
    
    for(int j=1;j<y+1;j++)
    {
        output[0][j]=0;
    }
    
    for(int i=1;i<x+1;i++)
    {
        output[i][0]=0;
    }
    
    
    for(int i=1;i<x+1;i++)
    {
        for(int j=1;j<y+1;j++)
        {
            if(s1[x-i]==s2[y-j])
            {
                output[i][j]=1+output[i-1][j-1];
            }
            else
            {
                int a=output[i-1][j];
                int b=output[i][j-1];
                int c=output[i-1][j-1];
                output[i][j]=max(a,max(b,c));
            }
        }
    }
    return output[x][y];
    
}
