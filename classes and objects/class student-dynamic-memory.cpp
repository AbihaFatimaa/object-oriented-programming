# include <iostream>
# include <string>
# include <cstring>
using namespace std;
const int NAME_SIZE =40;
class student{
	private:
		int roll_number;
		char name[NAME_SIZE];
		int noOfQuiz;
		int* marks;
		int totalMarks;
		void inputMarks(){
			int n;
			for(int i=0; i<noOfQuiz; i++){
				cout<<"enter marks of quiz "<<i+1<<": ";
				cin>>n;
				if(n<0 || n>totalMarks){
					cout<<"invalid marks";
					return;
				}
				marks[i] = n;
			}
		}
	public:
		student(){
			roll_number =0;
			strcpy(name,"null");
			noOfQuiz = 0;
			marks = nullptr;
			totalMarks = 0;
		}
		student(int roll, char n[], int noquiz, int total){
			roll_number = roll;
			strcpy(name, n);
			noOfQuiz = noquiz;
			totalMarks = total;
			marks = new int[noOfQuiz];
			for(int i=0; i<noOfQuiz; i++){
				marks[i] = 0;
			}
		}
		~student(){
			delete[]marks;
		}
		void getInputFromUser(){
			cout<<"enter roll no: ";
			cin>>roll_number;
			cout<<"enter name: ";
			cin>>name;
			cout<<"enter no of quizzes: ";
			cin>>noOfQuiz;
			cout<<"enter total marks: ";
			cin>>totalMarks;
			if(marks!=nullptr){
				delete[]marks;
			}
			marks = new int[noOfQuiz];
			inputMarks();
		}
		void display(){
			cout<<"Name: "<<name<<endl;
			cout<<"Roll no: "<<roll_number<<endl;
			cout<<"Marks Obtained: "<<endl;
			int sum=0;
			for(int i=0; i<noOfQuiz; i++){
				cout<<"Quiz "<<i+1<<": "<<marks[i]<<endl;
				sum+=marks[i];
			}
			cout<<"Average Marks in all quizzes: "<<sum/noOfQuiz<<endl;
		}
		student(const student& s){
			roll_number = s.roll_number;
			strcpy(name, s.name);
			noOfQuiz=s.noOfQuiz;
			totalMarks=s.totalMarks;
			marks = new int[noOfQuiz];
			for(int i=0; i<noOfQuiz; i++){
				marks[i] = s.marks[i];
			}
		}
};
	void printStudent(student s){
		s.display();
	}
int main() {
	student b;
	student a(123, "abiha", 4, 10);
	b.getInputFromUser();
	printStudent(b);
	printStudent(a);
	
	return 0;
	   }
