string print_lcs(int x, int y, string s1, string s2){
    
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
                output[i][j]=max(a,max(b,c));
            }
        }
    }
  
  ini i=n;
  int j=m;
  string s="";
  while(i>0 && j>0)
  {
    if(s1[i-1]==s2[j-1])
    {
      s.push_back(s1);
      i--;
      j--;
    }
    else
    {
      if(output[i][j-1]>output[i-1][j];
         {
           j--;
         }
         else
         {
           i--;
         }
         
    }
    
    
  }
         reverse(s.begin(),s.end());
         return s;       
}
