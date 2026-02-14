# include <iostream>
# include <string>
# include <cstring>
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
const int NoOfEmployee = 2;
Employee emp[NoOfEmployee];
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
void searchEmployee(Employee emp[], int NoOfEmployee){
	char lastn[20];
	cin>>lastn;
	for(int i=0; i<NoOfEmployee; i++){
		if(strcmp(lastn, emp[i].lname) == 0)
{
	cout<<"first name:"<<emp[i].fname<<endl;
	cout<<"last name:"<<emp[i].lname<<endl;
	cout<<"birth year (1950 - 1990):"<<emp[i].dob.byear<<endl;
	cout<<"birth month: "<<emp[i].dob.bmonth<<endl;
	cout<<"birth day(1-31)"<<emp[i].dob.bday<<endl;
	cout<<"joining year: (1980-2013)"<<emp[i].jdate.jyear<<endl;
	cout<<"joining month: "<<emp[i].jdate.jmonth<<endl;
	cout<<"joining day (1-31)"<<emp[i].jdate.jday<<endl;
	cout<<"Salary: (10000-100000)"<<emp[i].salary<<endl;
		}
	}
}
int main(){
	for(int i=0; i<NoOfEmployee; i++){
	initEmployee(emp[i]);
   	addEmployee(emp[i]);
	}
	searchEmployee(emp,NoOfEmployee);
	return 0;
}