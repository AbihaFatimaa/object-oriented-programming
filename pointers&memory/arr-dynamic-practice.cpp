#include <iostream>
#include <string>
using namespace std;
int* createReverseArray(const int arr[], int size){
	int* arr1 = new int [size];
	for(int i=0; i<size; i++){
		arr1[i] = arr[size-i-1];
	}
	return arr1;
}
int main() {
	const int size = 5;
    const int arr[size] ={1,2,3,4,5};
    int* arr1 = createReverseArray(arr,size);
    for(int i=0; i<size; i++){
    	cout<<arr1[i]<<" ";
	}
	delete[] arr1;
    return 0;
}
