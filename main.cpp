#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
bool isprime(int x){
	for(int i=2;i*i<=x;i++)
		if(x%i==0)
			return false;
	return true;
}



inline LL fastmod(LL x,int &k,int &b,int &p){
	const LL mask=(1LL<<k)-1;
	
		x=(x>>k)*b+(x&mask);
		x=(x>>k)*b+(x&mask);
		x=(x>>k)*b+(x&mask);
		x=(x>>k)*b+(x&mask);
		x=(x>>k)*b+(x&mask);
		x=(x>>k)*b+(x&mask);
		x=(x>>k)*b+(x&mask);
		x=(x>>k)*b+(x&mask);
		x=(x>>k)*b+(x&mask);

	return x;
}

LL rnd(){
	return 1LL*rand()<<30 | rand();
}

const int TIMES=100;
void check(int p){
	int T=TIMES;
	int k,b;	
	for(int i=0;i<34;i++){
		if((1LL<<i)>p){
			k=i;
			b=(1<<k)-p;
			break;
		}
	}

	cout<<"check "<<p<<"=2^"<<k<<"-"<<b<<endl;
	static LL tmp[TIMES];
	for(int i=0;i<T;i++)
		tmp[i]=rnd();
	
	LL output1=0,output2=0;
	double st=clock();
	for(int i=0;i<T;i++){
		output1^=tmp[i]%p;
	}
	cout<<"t1:"<<(clock()-st)/CLOCKS_PER_SEC<<endl;
	st=clock();
	for(int i=0;i<T;i++){
		output2^=fastmod(tmp[i],k,b,p);
	}
	cout<<"t2:"<<(clock()-st)/CLOCKS_PER_SEC<<endl;
	cout<<"xor: "<<output1<<" "<<output2<<endl;

}

int main(){


	check(INT_MAX);

return 0;
	for(int i=13;;i++){
		if(isprime(i)){
			check(i);	
		}
	}

}
