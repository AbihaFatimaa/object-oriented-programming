# include <iostream>
# include <string>
using namespace std;
struct DateOfBirth{
	int byear;
	char bmonth[4];
	int bday;
};
struct JoiningDate{
	int jyear;
	char jmonth[4];
	int jday;
};
struct Employee{
	char fname[20];
	char lname[20];
	DateOfBirth dob;
	JoiningDate jdate;
	long salary;
};
void initEmployee(Employee emp){
	emp = {};
}
void viewEmployee(Employee &emp){
	cout<<"first name:"<<emp.fname<<endl;
	cout<<"last name:"<<emp.lname<<endl;
	cout<<"birth year (1950 - 1990):"<<emp.dob.byear<<endl;
	cout<<"birth month: "<<emp.dob.bmonth<<endl;
	cout<<"birth day(1-31)"<<emp.dob.bday<<endl;
	cout<<"joining year: (1980-2013)"<<emp.jdate.jyear<<endl;
	cout<<"joining month: "<<emp.jdate.jmonth<<endl;
	cout<<"joining day (1-31)"<<emp.jdate.jday<<endl;
	cout<<"Salary: (10000-100000)"<<emp.salary<<endl;
}
void addEmployee(Employee &emp){
	cin>>emp.fname>>emp.lname>>emp.dob.byear>>emp.dob.bmonth>>emp.dob.bday>>emp.jdate.jyear>>emp.jdate.jmonth>>emp.jdate.jday>>emp.salary;
}
Employee emp;
int main(){
	initEmployee(emp);
	viewEmployee(emp);
	addEmployee(emp);
	viewEmployee(emp);
	return 0;
}