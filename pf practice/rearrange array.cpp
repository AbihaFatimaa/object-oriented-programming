/*Write a program to rearrange the array so that all negative numbers appear before positive numbers, while
maintaining the original order as much as possible.*/
# include <iostream>
# include<string>
using namespace std;
int main(){
	int arr[9] = {8,12,-7,5,-1,-2,8,-3,6};
	int j=0;
	for(int i=0; i<9; i++){
		if(arr[i]<0){
			swap(arr[j], arr[i]);
			j++;
		}		
			}		
	
		cout<<"array is: ";
		for(int y=0; y<9; y++){
			cout<<arr[y]<<"  ";
		}
		return 0;
	}
