class Solution {
public:
    int countPrimes(int n) {
        if(n < 2) return 0;
        vector<bool> primes(n, true);
        primes[0] = false;
        primes[1] = false;
        
        for(int i = 0; i < sqrt(n); i++)
            if(primes[i])
                for(int j = i*i; j < n; j += i)
                    primes[j] = false;
        
        return count(primes.begin(), primes.end(), true);
    }
};