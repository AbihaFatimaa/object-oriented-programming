# include <iostream>
# include <string>
using namespace std;
struct book{
	char name[50];
	char publisher[50];
	int ISBNNumber;
};
struct Library
{
	book * data;
	int noOfBooks;
	int capacity;
};
 Library ly;
void initializeLibrary( Library & ly, const int capacity){
	ly.capacity = capacity;
	ly.noOfBooks = 0;
	ly.data =new book[capacity];
}
bool addBook( Library & ly, const book & bo){
	ly.data[ly.noOfBooks] = bo;
    ly.noOfBooks++;
    return true;
}
bool removeBook (Library& ly, char * BookName, int count = 1 ){
	int rem =0;
	for(int i=0; i<ly.noOfBooks && rem<count; i++){
		if(strcmp(BookName,ly.data[i].name)==0){
			for(int j=0; j<ly.noOfBooks; j++){
				ly.data[j] = ly.data[j+1];
			}
			ly.noOfBooks--;
			rem++;
			i--;
		}
	}
	if(rem>0){
		return true;
	}
	return false;
}
void DisplayAllBooksInformation( Library & ly){
	for(int i=0; i<ly.noOfBooks; i++){
		cout<<"BOOK NO.: "<<i+1<<endl;
		cout<<"Name: "<<ly.data[i].name<<endl;
		cout<<"Publisher: "<<ly.data[i].publisher<<endl;
		cout<<"isbn no. : "<<ly.data[i].ISBNNumber<<endl;
	}
}
void resize(Library& ly , int s=5){
	int newCap = ly.capacity+s;
	book* newdata = new book [newCap];
	for(int i=0; i<newCap; i++){
		newdata[i] = ly.data[i];
	}
	delete ly.data;
	ly.data = newdata;
	ly.capacity = newCap;
}
int main(){

    Library ly;
    initializeLibrary(ly, 2);

    book b1 = {"C++ Programming", "ABC Publishers", 12345};
    book b2 = {"Data Structures", "XYZ Publishers", 67890};

    addBook(ly, b1);
    addBook(ly, b2); 

    DisplayAllBooksInformation(ly);

    removeBook(ly, (char*)"Data Structures");

    cout << "After Removing: "<<endl;
    DisplayAllBooksInformation(ly);

    delete[] ly.data; 
    return 0;
}
