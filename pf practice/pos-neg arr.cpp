# include <iostream>
# include <string>
using namespace std;
const int n_ar = 6;
const int ar[] = {1,2,3,-5,-7,4};
void getPosNeg(const int ar[], const int n_ar, int* &pos, int& n_pos, int* &neg, int& n_neg){
	n_pos = 0;
	n_neg = 0;
	pos = nullptr;
	neg = nullptr;
	for(int i=0; i<n_ar; i++){
		if(ar[i] >0){
			n_pos++;
		}
		else{
			n_neg++;
		}
	}
	if(n_pos >0){
		pos = new int[n_pos];
	}
	if(n_neg >0){
		neg = new int[n_neg];
	}
	int p =0, n=0;
	for(int i=0; i<n_ar; i++){
		if(ar[i]>0){
			pos[p] = ar[i];
			p++;
		}
		if(ar[i]<0){
			neg[n] = ar[i];
			n++;
		}
	}
}
int main(){
	const int n_ar = 10;
   const int arr[n_ar] = {-5,3,4,-9,1,3,2,-8,4,-1};

    int* pos = nullptr;
    int* neg = nullptr;
    int n_pos = 0;
    int n_neg = 0;
    getPosNeg(arr, n_ar, pos, n_pos, neg, n_neg);
    
    if(n_pos>0){
    	cout<<"POSITIVE NUMBERS: ";
    	for(int i=0; i<n_pos; i++){
    		cout<< pos[i]<<" ";
		}
		cout<<endl;
	}
	else{
		cout<<"No positive numbers";
	}
	
	if(n_neg>0){
		cout<<"NEGATIVE NUMBERS: ";
		for(int k=0; k<n_neg; k++){
			cout<< neg[k]<<" ";
		}
	}
	else{
		cout<<"No negative numbers";
	}
	delete[] pos;
	delete[]neg;
	return 0;
}