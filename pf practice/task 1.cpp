# include <iostream>
# include <string>
using namespace std;
int main(){
	int j = 5;
	cout<<"address of j: "<<&j<<endl;
	cout<<"data of j: "<<j<<endl;
	int* p = &j;
	cout<<p<<endl;
	cout<<*p<<endl;
	j=(*p)+1;
	cout<<j;
	double k = 6.7;
	cout<<"address of k: "<<&k<<endl;
	cout<<"data of k: "<<k<<endl;
	double* dp = &k;
	cout<<dp<<endl;
	cout<<*dp<<endl;
	k = (*dp)+1;
	cout<<k<<endl;
	char l = '*';
	cout<<"address of l: "<<&l<<endl;
	cout<<"data of l: "<<l<<endl;
	char* cp = &l;
	cout<<cp<<endl;
	cout<<*cp<<endl;
	l = (*p)+1;
	cout<<l;
	return 0;
}