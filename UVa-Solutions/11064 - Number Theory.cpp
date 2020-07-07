#include "bits/stdc++.h"
 
using namespace std;
  
int main(){	
	auto phi = [] (long long n) -> long long{ long long ret = n;
				for (long long i = 2; i * i <= n; i++) 
    				if (n % i == 0) {
     					while (n % i == 0)  n /= i;	 ret -= ret / i; 
				    }  				
				return (n > 1)? ret-(ret/n) : ret; }; 	
	
	auto NoOfFactor = [] (long long n) -> int{ int cnt(0); for(long long i=1; i*i<=n; ++i) if(n%i==0) cnt += 1 + (i*i!=n);    return cnt;};
 	long long n;
 	while(cin>>n and cout<<n-NoOfFactor(n)-phi(n)+1<<endl);
	
    return 0;
}
