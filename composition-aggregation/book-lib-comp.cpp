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
		book *b;
		int curr;
	public:
		library(){
			b=nullptr;
			curr = 0;
			cout<<"cons lib"<<endl;
		}
		void addBook(const book& n){
			book* t = new book [curr+1];
			for(int i=0; i<curr; i++){
				t[i] = b[i];
			}
			t[curr++] = n;
			delete b;
			b=t;
		}
		~library(){
			cout<<"des lib";
		}
		void printlib (){
			b->print();
		}
};
int main() {
	library b;
	b.addBook(book("bjarne", "c++"));
	b.printlib();
	return 0;
	   }
