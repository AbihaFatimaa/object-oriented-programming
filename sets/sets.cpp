# include "sets.h"
#include<iostream>
using namespace std;
void set::setA(int a){
	this->a = a;
}
void set::setB(int b){
	this->b = b;
}
int set::getAB(){
	cout<<a<<" "<<b<<endl;
}