#ifndef course_h
#define course_h
# include <iostream>
# include <string>
using namespace std;
class course{
	private:
		string coursename;
		string instructor;
		string  textbook;
	public:
		course(string a ="", string b ="", string c="");
		void print();
		
};
#endif