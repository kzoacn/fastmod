#include<iostream>
//#include"block.h"
using namespace std;
typedef unsigned __int128 int128;
//For p=2^127-1;

int128 p;

void _print(int128 x){
	if(x){
		_print(x/10);
		putchar(x%10+'0');
	}
}
void print(int128 x){
	if(x)
		_print(x);
	else 
		putchar('0');
	puts("");
}

#define out(x) cout<<#x"=";print(x)

int128 Mod(int128 x){
	while(x>=p)
		x-=p;
	return x;
}

int128 mask64(int128 x){
	int128 r=0;
	for(int i=0;i<8;i++){
		r|=(x&255)<<i*8;
		x>>=8;
	}
	return r;
}

int128 mul(int128 a,int128 b){
	int128 a1=a>>64;
	int128 a2=mask64(a);
	int128 b1=b>>64;
	int128 b2=mask64(b);
	int128 r=0;
	r=Mod(Mod(a1*b1)*2);
	r=Mod(r+Mod(a2*b2));
	int128 c=Mod(Mod(a1*b2)+Mod(a2*b1));
	int128 c1=c>>64;
	int128 c2=mask64(c);
	r=Mod(r+Mod(c1*2));
	r=Mod(r+Mod(c2<<64));
	return r;
}

int128 rand128(){
	int128 r=0;
	for(int i=0;i<127;i++)
		r=r*2+(rand()%2);
	return r;
}

int main(){
srand(time(0));
	p=1;
	for(int i=0;i<127;i++)
		p=p*2;
	p--;

	print(p);

	int128 a=rand128()%p;
	int128 b=rand128()%p;
	out(a);
	out(b);
	print(mul(a,b));
	return 0;
}
