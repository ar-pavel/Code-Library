#include <bits/stdc++.h>

using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	    freopen("in.txt","r",stdin);
	    freopen("out.txt","w",stdout);
	#endif


	int tc,t(1);
	for(scanf("%d",&tc); tc; ++t,--tc){
		long long sday,syear,eday,eyear;
		char c[10];

		scanf("%s %lld,%lld", &c,&sday,&syear);
		if(!((c[0]=='J' and c[1]=='a') or (c[0]=='F' and c[1]=='e')))
			syear++;

		scanf("%s %lld,%lld", &c,&eday,&eyear);
		if(((c[0]=='J' and c[1]=='a') or (c[0]=='F' and eday<29)))
			eyear--;
		
		long long lyear =0;
		lyear =  int(eyear/4)  + int((syear-1)/100) + int(eyear/400) - int((syear-1)/4) -  int((syear-1)/400) -  int((eyear)/100);

		printf("Case %d: %lld\n",t,lyear);
	}

	return 0;
}
