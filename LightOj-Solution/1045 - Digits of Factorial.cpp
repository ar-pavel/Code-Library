#include <bits/stdc++.h>

using namespace std;

double preLog[1000006];

long long findDigit(int n, int b){
	double val = preLog[n]/log(b);
	return 1+floor(val);
}

int main(){
	#ifndef ONLINE_JUDGE
	    freopen("in.txt","r",stdin);
	    freopen("out.txt","w",stdout);
	#endif

	for(int i=1; i<=1000000; ++i)
		preLog[i]= preLog[i-1] + log(i);	

	// for(int i=1; i<20; ++i)
	// 	cout<<preLog[i]<<" ";
	// cout<<endl;

	int tc,t(1);
	for(scanf("%d",&tc); tc; ++t,--tc){
		int n,b;
		// cin>>n>>b;
		scanf("%d%d",&n,&b);
		// long long digit;
		printf("Case %d: %lld\n",t,findDigit(n,b) );
		// cout<<"Case "<<t<<": "<<digit<<endl;
	}

	return 0;
}
