# include <iostream>
# include <string>
using namespace std;
class person{
	private:
		string name;
		int age;
	public:
		person(string n="", int a=0){
			name = n;
			age = a;
		}
		void setname(string n){
			name = n;
		}
		string gtname(){
			return name;
		}
		void setage(int a){
			age = a;
		}
		int getage(){
			return age;
		}
};
class employee{
	private:
		string empname;
		int wage;
	public:
		employee(string e="", int w=0){
			empname = e;
			wage = w;
		}
		void setname(string w){
			empname = w;
		}
		void setwage(int w){
			wage = w;
		}
		int getwage(){return wage;
		}
		string getname(){return empname;
		}
};
class teacher:public person, employee{
	private:
		int payscale;
	public:
		teacher(string n, int a, string e, int w, int p=0):person(n,a), employee(e,w){
			payscale = p;
		}
		int getpayscale(){return payscale;
		}
		void setpayscale(int p){payscale = p;
		}
		void display(){
			cout<<"Name: "<<person::gtname()<<endl;
			cout<<"Age: "<<person::getage()<<endl
			<<"EmployerName: "<<employee::getname()<<endl
			<<"Wage: "<<employee::getwage()<<endl
			<<"payscale: "<<payscale<<endl;
		}
};
int main() {
	teacher t("ali", 24, "ahmed", 500, 12);
	t.display();
	return 0;
	   }
