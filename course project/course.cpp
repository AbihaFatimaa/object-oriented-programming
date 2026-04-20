#include "course.h"
# include <iostream>
# include <string>
course::course(string a , string b , string c):coursename(a), instructor(b), textbook(c){
}
void course::print(){
	cout<<"Course Name:	"<<coursename<<endl;
	cout<<"Instructor:	"<<instructor<<endl;
	cout<<"Text Book:	"<<textbook<<endl;
}