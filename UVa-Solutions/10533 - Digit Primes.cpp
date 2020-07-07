#include <bits/stdc++.h>

using namespace std;


#define le 1000007
#define ck(ve) (n[ve >> 6] & (1 << ((ve >> 1) & 31)))
#define st(ve) (n[ve >> 6] |= (1 << ((ve >> 1) & 31)))

int n[le >> 6];
int mx = 20;
vector<int>primes(le,0); 

int digitSum(int n){
	
	int sum=0;
	while(n>0)
		sum+=(n%10), n/=10;
	return sum;
}

void se(){
    int rt = sqrt(le) + 1, k;
    for(int i = 3; i < rt; i += 2) 
    	if(!ck(i)) 
    		for(int j = i*i, k = i << 1; j < le; j += k) 
    			st(j);

    
    primes[2]=1;
    for(int i=3; i<le; i++)
    	if(i&1 and !ck(i)){
    		int ds = digitSum(i);
    		if(ds ==2 or (ds&1 and !ck(ds)))
    			primes[i]=primes[i-1]+1;
    		else 
    			primes[i]=primes[i-1];

    	}
    	else
    		primes[i]=primes[i-1];

   
          
}		

int main(){
	#ifndef ONLINE_JUDGE
	    freopen("in.txt","r",stdin);
	    freopen("out.txt","w",stdout);
	#endif
	// ios::sync_with_stdio(false);
	// cin.tie(0);cout.tie(0);
	
	se();
	// for(auto x: primes)
	// 		cout<<x<<"\t";
	// cout<<endl;
	
	int n;
	// cin>>n;
	scanf("%d",&n);

	while(n--){

		int a,b;
		scanf("%d%d",&a,&b);
		// cin>>a>>b;
		printf("%d\n",primes[b]-primes[a-1]);
		// cout<<primes[b]-primes[a-1]<<endl;
	}
	
	return 0;
}
