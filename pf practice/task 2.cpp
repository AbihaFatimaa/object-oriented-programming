/*1- Declare and initialize an integer array arr[5] and display the address of its first index.
2- Declare a pointer to integer p and assign the contents of arr to p. Take input from user for all of the
elements of the array by using pointer p and dereference operator.
3- Display the address and contents of all the elements of the array by using pointer p and dereference
operator.
4- Repeat the above three steps for char and double data types.*/
# include <iostream>
# include <string>
using namespace std;
int main(){
	int arr[5] = {2,3,4,5,6};
	cout<<&arr<<endl;
	int* p = &arr[0];
	for(int i=0; i<5; i++){
		cin>>*(p+i);
	}
	for(int i=0; i<5; i++){
		cout<<"address of "<<i+1<<": "<<(p+i)<<endl;
		cout<<"contents of "<<i+1<<": "<<*(p+i)<<endl;
	}
	double darr[5] = {};
	cout<<&darr<<endl;
	double* dp = &darr[0];
	for(int i=0; i<5; i++){
		cin>>*(dp+i);
	}
	for(int i=0; i<5; i++){
		cout<<"address of "<<i+1<<": "<<(dp+i)<<endl;
		cout<<"contents of "<<i+1<<": "<<*(dp+i)<<endl;
	}
	char carr[5] = {};
	cout<<&carr<<endl;
	char* cp = &carr[0];
	for(int i=0; i<5; i++){
		cin>>*(cp+i);
	}
	for(int i=0; i<5; i++){
		cout<<"address of "<<i+1<<": "<<(cp+i)<<endl;
		cout<<"contents of "<<i+1<<": "<<*(cp+i)<<endl;
	}
	return 0;
}