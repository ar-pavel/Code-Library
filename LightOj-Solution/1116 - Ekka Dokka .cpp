#include <bits/stdc++.h>

using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	    freopen("in.txt","r",stdin);
	    freopen("out.txt","w",stdout);
	#endif


	int tc,t(1);
	for(scanf("%d",&tc); tc; ++t,--tc){
		long long w,n,m;
		scanf("%lld", &w);

		if(w&1){
			printf("Case %d: Impossible\n",t);
			continue;
		}

		m=2;
		n=w/2;
		while(n%2==0)
			n/=2,m*=2;		
			
		printf("Case %d: %lld %lld\n",t,n,m);
	}


	return 0;
}
