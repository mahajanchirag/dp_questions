class Solution{
    public:
# define mod 1000000007
    long long countWays(int n, int k){
        // code here
        if(n == 0) return 0;

if(n == 1) return k;

long long same = (k * 1) % mod;
long long diff = (k * (k - 1)) % mod;
long long total = (same + diff) % mod;

for(int i = 3; i <= n; i++) {
same = (diff * 1) % mod;
diff = (total * (k - 1)) % mod;
total = (same + diff) % mod;
}

return (total % mod);
        
    }
};
