#include <bits/stdc++.h>
 
using namespace std;

#define le 1000007
#define ck(ve) (n[ve >> 6] & (1 << ((ve >> 1) & 31)))
#define st(ve) (n[ve >> 6] |= (1 << ((ve >> 1) & 31)))

int n[le >> 6];
int mx = 20;
vector<int>primes; 

void se(){
    int rt = sqrt(le) + 1, k;
    for(int i = 3; i < rt; i += 2) 
    	if(!ck(i)) 
    		for(int j = i*i, k = i << 1; j < le; j += k) 
    			st(j);

    primes.push_back(2);
    for(int i=3; i<le; i+=2)
    	if(!ck(i))primes.push_back(i);
          
}
 
long long findIt(long long n){
    long long sum=1;
   	
   	for(int i=0; i<primes.size() and primes[i]*primes[i]<=n; ++i){
   		int k=0;
   		
   		while(n%primes[i]==0){
                k++;
                n=n/primes[i];
        }
   		
   		sum *= (k+1);
   	}


   	return (n==1?sum:sum*2)-1;
}
 
int main(){
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
   	se();
   
    int tc,t(1);
    for(scanf("%d",&tc); tc; ++t,--tc){
 
        long long num;
        scanf("%lld",&num);       
       
       printf("Case %d: %lld\n",t,findIt(num));
    }
 
    return 0;
}    
