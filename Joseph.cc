#include <iostream>

using namespace std;
//f(n,m)= 0                ,n=1
//f(n,m)= [f(n-1,m)+m]%n   ,n>1
int Joseph(int n, int m) {
	if(n<=0 || m<0) {
		return -1;
	}
	int last=0;
	for(int i=2; i<=n; ++i) {
		last =(last + m) % i;
	}
	return last;
}

int main() {
	int n,m;
	while(1){
		cout<<"请输入n=";
		cin>>n;
		if(n<0){
			break;
		}
		cout<<"请输入m=";
		cin>>m;
		cout<<Joseph(n,m)<<endl;
	}

	return 0;
}
