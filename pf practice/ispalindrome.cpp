/*Write a function that will take an array of Characters as parameters and returns true if it is a Palindrome and
return false if it is not Palindrome.*/
# include <iostream>
# include <string>
using namespace std;
bool isPalindrome(char arr[]){
	int len = 0;
	for(int i=0; arr[i]!='\0'; i++){
		len++;
	}
	
	bool flag = true;
	for(int i=0; i<len/2; i++){
		if(arr[i] != arr[len-i-1]){
			return false;
		}
	}
	return true;
}
int main(){
	char arr[] = "abba";
	char arr1[] = "123";
	bool flag = isPalindrome(arr1);
	if(flag){
		cout<<"it is a Palindrome!"<<endl;
	}
	else{
		cout<<"it is NOT a palindrome!"<<endl;
	}
	return 0;
}