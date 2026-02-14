# include <iostream>
# include <string>
using namespace std;
struct Employee{
	char fname[20];
	char lname[20];
	int byear;
	char bmonth[4];
	int bday;
	int jyear;
	char jmonth[4];
	int jday;
	long salary;
};
void initEmployee(Employee emp){
	emp = {};
}
void viewEmployee(Employee &emp){
	cout<<"first name:"<<emp.fname<<endl;
	cout<<"last name:"<<emp.lname<<endl;
	cout<<"birth year (1950 - 1990):"<<emp.byear<<endl;
	cout<<"birth month: "<<emp.bmonth<<endl;
	cout<<"birth day(1-31)"<<emp.bday<<endl;
	cout<<"joining year: (1980-2013)"<<emp.jyear<<endl;
	cout<<"joining month: "<<emp.jmonth<<endl;
	cout<<"joining day (1-31)"<<emp.jday<<endl;
	cout<<"Salary: (10000-100000)"<<emp.salary<<endl;
}
void addEmployee(Employee &emp){
	cin>>emp.fname>>emp.lname>>emp.byear>>emp.bmonth>>emp.bday>>emp.jyear>>emp.jmonth>>emp.jday>>emp.salary;
}
Employee emp;
int main(){
	initEmployee(emp);
	viewEmployee(emp);
	addEmployee(emp);
	viewEmployee(emp);
	return 0;
}