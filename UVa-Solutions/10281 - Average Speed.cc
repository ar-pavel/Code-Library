#include <bits/stdc++.h>

using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	    freopen("in.txt","r",stdin);
	    freopen("out.txt","w",stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	int hour,min,sec,speed(0);
	double distanceSum(0.0),prevTime(0.0),curTime;
	char s;
	cout<<setprecision(2)<<fixed<<setfill('0');
	while(cin>>hour>>s>>min>>s>>sec){
		curTime = (hour*3600.0)+(min*60.0)+sec;
		
		double distance =((curTime-prevTime)*speed)/3600.0;

		if(cin.peek()==' '){
			cin>>speed;
			distanceSum += distance;
			prevTime = curTime;
		}else 
			cout<<setw(2)<<hour<<":"<<setw(2)<<min<<":"<<setw(2)<<sec<<" "<<distanceSum+distance<<" km"<<endl;
			
	}

	return 0;
}
