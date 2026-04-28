# include <iostream>
# include <string>
using namespace std;
class book{
	private:
		string author;
		string bookName;
	public:
		book(string author ="", string bookName=""){
			this->author = author;
			this->bookName = bookName;
			cout<<"coons book"<<endl;
		}
		void print (){
			cout<<"title: "<<bookName<<"	"<<"author: "<<author<<endl;
		}
		~book(){
			cout<<"destructor book"<<endl;
		}
};
class library{
	private:
		book **b;
		int curr;
	public:
		library(){
			b=nullptr;
			curr = 0;
			cout<<"cons lib"<<endl;
		}
		void addBook( book* n){
			book** t = new book* [curr+1];
			for(int i=0; i<curr; i++){
				t[i] = b[i];
			}
			t[curr++] = n;
			delete b;
			b=t;
		}
		~library(){
			delete[]b;
			cout<<"des lib";
		}
		void printlib (){
			for(int i=0; i<curr; i++){
				b[i]->print();
			}
		
		}
};
int main() {
	book b1("authur", "name");
	library b;
	b.addBook(&b1);
	book b2("bjarne", "c++");
	b.addBook(&b2);
	b.printlib();
	return 0;
	   }
