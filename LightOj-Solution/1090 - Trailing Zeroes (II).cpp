#include <bits/stdc++.h>

using namespace std;

long long numOfFive[1000006];
long long numOfTwo[1000006];


long long factors(int val, long long p) {
	long long ans = 0;
	long long b = p;
	while (b <= val) {
	   ans += val / b;
	   b *= p;
	}
	return ans;
}

int pf(int n, int p){
	int cnt(0);
	while(n%p==0)
		n/=p, ++cnt;
	return cnt;
}


int main(){
	#ifndef ONLINE_JUDGE
	    freopen("in.txt","r",stdin);
	    freopen("out.txt","w",stdout);
	#endif

	for(int i=1; i<=1000000; ++i)
		numOfFive[i]=factors(i,5);	

	for(int i=1; i<=1000000; ++i)
		numOfTwo[i]=factors(i,2);	


	int tc,t(1);
	for(scanf("%d",&tc); tc; ++t,--tc){
		int n,r,p,q;
		// cin>>n>>b;
		scanf("%d%d%d%d",&n,&r,&p,&q);

		long long digit = numOfFive[n]-numOfFive[r]-numOfFive[n-r]+(pf(p,5)*q);
		long long digit1 = numOfTwo[n]-numOfTwo[r]-numOfTwo[n-r]+(pf(p,2)*q);

		printf("Case %d: %lld\n",t, min(digit,digit1) );
		// cout<<"Case "<<t<<": "<<digit<<endl;
	}

	return 0;
}
