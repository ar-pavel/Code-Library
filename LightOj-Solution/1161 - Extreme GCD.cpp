#include "bits/stdc++.h"
 
using namespace std;

/* 
template<typename... T>
void read(T&... args) {
    ((cin >> args), ...);
}
 
template<typename... T>
void write(T&&... args) {  
    ((cout << args << " "), ...);
}
 */

#define deb(x,y) cerr << #x << " " << x << " " << #y << " " << y <<endl;
#define deb1(x) cerr << #x << " " << x <<endl;
#define isSet(x,i) (bool)(x & (1<<i)) 
 
const int mx = 100000;
 
int lcm(int a, int b){
    return a/__gcd(a,b) * b;
}

void init(vector<int>& factors, int n){
	 for(long long i=2; i*i<=n; ++i)  {
        if(n%i==0){
            factors[i]++;
           	if(n/i!=i) 
           		factors[n/i]++;
        }
    }
    if(n>1)factors[n]++;
}

long long nc4 (long long n){
	return n*(n-1)*(n-2)*(n-3)/24ll;
}
 
int main(){
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int t(1),tc;
    for(cin>>tc;t<=tc; ++t){
    	int n;
    	cin>>n;
    	vector<int>factors(mx+1,0);

    	for(int i=0,val; i<n; ++i){
    		cin>>val;
    		init(factors, val);
    	}
    	factors[1]=n;

    	vector<long long> combinations(mx+1,0ll);

    	for(int i=mx; i>=1; --i){
    		combinations[i]=nc4(factors[i]);
    	}
    	/*
    	for(int i=1; i<10; ++i)
    		if(factors[i])
    			cout<<i<<"\t"<<factors[i]<<"\t"<<combinations[i]<<endl;
    	cout<<combinations[1]<<endl;
    	cout<<endl;
		*/
    	cout<<"Case "<<t<<": ";
		
		for(int i=mx; i>1; --i){
			if(combinations[i])
			for(int j=2; j*j<=i; ++j)
				if(i%j==0){
					combinations[j]-=combinations[i];
					if(i/j!=j)
						combinations[i/j]-=combinations[i];
				}

			combinations[1] -= combinations[i];
		}		
		cout<<combinations[1]<<endl;
    }
    return 0;
}
