#include <iostream>

using namespace std;

int main(){
	int key = 2;
	int n=6;
	int r[n];
	int ar[n] = {1,2,3,4,5,6};
	for(int i=0; i<n; i++){
		r[i] = ar[(i+key)%n];
	}
	for(int i=0; i<n; i++){
		cout<<r[i]<<" ";
	}
	return 0;
}