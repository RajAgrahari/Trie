//https://practice.geeksforgeeks.org/problems/longest-common-prefix-in-an-array5129/1
string longestCommonPrefix (string a[], int N)
    {
        sort(a,a+N);
        for(int i=0;i<N;i++)
        string smallest = a[0];
        string largest = a[N-1];
        int i=0;
        int n = a[0].size();
        
        while(i<=n-1 && smallest[i]==largest[i])
        i++;
        
        string ans;
        for(int j=0;j<i;j++)
        ans += smallest[j];
        
        if(ans=="")
        return "-1";
        
        return ans;
        
    }
