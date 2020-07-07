#include "bits/stdc++.h"
 
using namespace std;

#define deb(x) cout << #x << " " << x << endl;

template<typename... T>
void read(T&... args) {
    ((cin >> args), ...);
}

template<typename... T>
void write(T&&... args) {  
    ((cout << args << " "), ...);
}

// #define mod 1000000007
#define mx  10000256

#define set(N,pos) ( N = N | (1<<pos))
#define check(N,pos) (bool)(N & (1<<pos))
#define reset(N,pos) (N = N & ~(1<<pos))

vector<int>isprime(mx + 1, true);
vector<int>primes;

map<long long,long long>factors;
map<long long,long long>prime;


void sieve(){
    isprime[0] =isprime[1] = 0;
    for(int i=2; i*i <= mx; i++) 
    if (isprime[i]){
        primes.push_back(i);
        for (int j = i * i; j <= mx; j += i) 
            isprime[j] = false;        
    } 
}

long long power(int a, int n, int mod){
    if(n == 0)
        return 1;

    if(n & 1)
        return 1LL * power(a, n - 1, mod) * a % mod;

    long long half = power(a, n >> 1, mod);

    return 1LL * half * half % mod;

}

long long mulMod(long long a, long long b, long long c){
    long long x = 0, y = a%c;
    while (b > 0){
        if (b&1)
            x = (x+y)%c;

        y = (y*2)%c;
        b /= 2;
    }
    return x%c;
}

long long pollard_rho(long long n){  

    if(!(n&1))
        return 2;

    long long x = rand()%n+1;
    long long c = rand()%n+1;

    long long y = x;
    long long g = 1;

    while(g==1){

        x = (mulMod(x, x, n) + c)%n;
        y = (mulMod(y, y, n) + c)%n;
        y = (mulMod(y, y, n) + c)%n;
        g = __gcd(abs(x-y),n);
    }

    return g;
}

long long pollards_p_minus_1(long long n) {
    int B = 10;
    long long g = 1;

    while (B <= 1000000 && g < n) {
        long long a = 2 + rand() %  (n - 3);
        g = __gcd(a, n);

        if (g > 1)
            return g;

        // compute a^M
        for (int p : primes) {

            if (p >= B)
                continue;

            long long p_power = 1;

            while (p_power * p <= B)
                p_power *= p;

            a = power(a, p_power, n);

            g = __gcd(a - 1, n);

            if (g > 1 && g < n)
                return g;

        }

        B *= 2;
    }

    return 1;

}

long long Mod(long long a, long long b, long long p){
    long long res = 1;
    long long x = a%p;

    while (b){

        if (b&1)        
            res = mulMod(res, x, p);

        x = mulMod(x, x, p);
        b /= 2;
    }

    return res%p;
}



bool millerTest(long long d, long long s, long long n){
    long long a = rand() % (n-4) + 2;
    long long x = Mod(a, s, n);

    if (x==1 or x==n-1)
        return true;

    for (int r = 1; r < d; r++)
    {
        x = mulMod(x, x, n);

        if (x==1)
            return false;
        if (x==n-1)
            return true;
    }
    return false;
}

bool isPrime(long long n, int k = 20){
    if(prime[n])
        return true;

    if (n <= 1 || n==4)
        return false;

    if (n<=3)
        return true;

    if (n%2==0)
        return false;

    long long s = n-1, d = 0;

    while (s%2==0){
        s/=2;
        d++;
    }

    for (int i = 0; i < k; i++){
        if (millerTest(d, s, n)==false)
            return false;
    }

    return true;
}

void factorize(long long n){
    if(n==1)
        return;

    if(isPrime(n)){
        prime[n]++;
        factors[n]++;
        return;
    }

    long long div = pollard_rho(n);

    factorize(div);
    factorize(n/div);
}

int main(){ 
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif

    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    // sieve();

    int tc,t(1);
    for(cin>>tc; tc; ++t,--tc){
    
        long long n;
        cin>>n;
        // cout<<n<<endl;


        if(n<=3){
            cout<<n<<" = "<<n<<endl;
            continue;
        }

        factorize(n);

        cout<<n<<" = ";
        int sz =factors.size();
        for(auto it=factors.begin(); it != factors.end(); ++it){
            cout<<it->first;
            if(it->second>1)
                cout<<"^"<<it->second;
            if(--sz)
                cout<<" * ";

        }
        cout<<endl;
        factors.clear();

        // for(auto x: factors)
        //     cout<<x.first<<"\t"<<x.second<<endl;
        // cout<<endl;
         
    }

    return 0;
}

