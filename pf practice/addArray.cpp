/*Write a program that contains following functions:
1- bool addArrays(int arr1[], int s1, int arr2[], int s2) it takes two arrays and their sizes and if the sizes of
both arrays are same then adds arr2 into arr1 and returns true otherwise it does not perform addition and
returns false.
2- bool addArrays(int arr1[][..], int r1, int c1, int arr2[][..], int r2, int c2) it takes two matrices and their
dimensions(i.e. number of rows and columns) and if the dimensions of both 2D arrays are same then adds
arr2 into arr1 and returns true otherwise it does not perform addition and returns false.

3- int main() it contains required variables and calls the above two functions and displays proper massages.*/
# include <iostream>
# include <string>
using namespace std;
const int c1 = 2, c2 = 2;
bool addArrays(int arr1[], int s1, int arr2[], int s2){
	bool flag = false;
	if(s1 == s2){
		for(int i=0; i<s1; i++){
			arr1[i] = arr1[i]+arr2[i];
			flag = true; 
		}
	}
	else{
		flag = false;
	}
	return flag;
}
bool addArrays( int r1,int arr1[][c1],  int r2, int arr2[][c2]){
	bool flag = false;
	if(r1 == r2&& c1==c2){
		for(int i=0; i<r1; i++){
			for(int j=0; j<c1; j++){
				arr1[i][j] = arr1[i][j]+arr2[i][j];
				flag = true;
			}
		}
	}
	return flag;
}
int main(){
	int s1 = 4, s2 = 4;
	int arr1[s1] = {2,3,4,5};
	int arr2[s2] = {1,4,6,7};
	int r1 = 2,  r2=2;
	int matrix1[r1][c1] = {{1,2}, {3,4}};
	int matrix2[r2][c2]= {{5,6},{7,8}};
	bool flag = addArrays(arr1, s1, arr2, s2);
	if(flag){
		cout<<"array were added."<<endl;
	}
	else{
		cout<<"arrays were not added"<<endl;
	}
	bool matrixFlag = addArrays( r1,matrix1,  r2,matrix2);
	if(matrixFlag){
		cout<<"matrices were added"<<endl;
	}
	else{
		cout<<"matrices were not added"<<endl;
	}
	return 0;
}