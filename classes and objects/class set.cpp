# include <iostream>
# include <string>
using namespace std;
class Set{
	private:
		int* data;
		int capacity;
		int noOfElements;
	public:
		Set(int cap){        
			capacity = cap;
			noOfElements = 0;
			data = new int[capacity];
		}
		Set (const Set& s){
			capacity = s.capacity;
			noOfElements = s.noOfElements;
			data = new int[capacity];
			for(int i=0; i<noOfElements; i++){
				data[i] = s.data[i];
			}
		}	
		bool contains(int n){
			for(int i=0; i<noOfElements; i++){
				if(data[i] == n){
					return true;
				}
			}
			return false;
		}
		
		void addData(int n){
			if(noOfElements>=capacity){
				cout<<"not enough space";
				return;
			}
			if(!contains(n)){
			data[noOfElements] = n;
			noOfElements++;
			}
		}
		void displayData(){
			cout<<"{";
			for(int i=0; i<noOfElements; i++){
				cout<<data[i];
				if(i != noOfElements-1)
            cout<<",";
			}
			cout<<"}"<<endl;
		}
		Set setUnion(Set& s2){
			Set result(capacity+s2.capacity);
			int k=0; 
			for(int i=0; i<noOfElements; i++){
				result.data[k++] = data[i];
			}
			for(int i=0; i<s2.noOfElements; i++){
				if(!s2.contains(data[i])){
				result.data[k++] = s2.data[i];
			}
			}
			result.noOfElements = k;
			return result;
		}
		Set Intersection(Set& s2){
			Set result(capacity);
			int k=0;
			for(int i=0; i<noOfElements; i++){
				if(s2.contains(data[i])){
					result.data[k++] = data[i];
				}
			}
			result.noOfElements = k;
			return result;
		}
		Set Difference(Set& s2){
			Set result(noOfElements);
			int k=0;
			for(int i=0; i<noOfElements; i++){
				if(!s2.contains(data[i])){
					result.data[k++]=data[i];
				}
			}
			result.noOfElements = k;
			return result;
		}
		bool subset(Set& s2){
			for(int i=0; i<noOfElements; i++){
				if(!s2.contains(data[i])){
					return false;
				}
			}
			return true;
		}
		void removeElement(int n){
			for(int i=0;i<noOfElements; i++){
				if(data[i] == n){
					for(int k=i; k<noOfElements-1; k++){
						data[k] = data[k+1];
					}
						noOfElements--;
						return;
				}
			}
		
		}
		bool equal(Set& s1){
			if(noOfElements != s1.noOfElements){
				return false;
			}
			for(int i=0; i<noOfElements; i++){
				if(!s1.contains(data[i])){
					return false;
				}
			}
			return true;
		}
		bool properSubset (Set& s){
			if(noOfElements>s.noOfElements){
				return false;
			}
			for(int i=0; i<noOfElements; i++){
				if(!s.contains(data[i])){
					return false;
				}
			}
			return true;
		}
		int cardinality(){
			return noOfElements;
		}
		void clear(){
			noOfElements = 0;
		}
		bool isempty (){
			return noOfElements == 0;
		}
		Set symmetricDifference(Set& s){
			Set result(capacity+s.capacity);
			int k=0; 
			for(int i=0; i<noOfElements; i++){
				if(!s.contains(data[i])){
					result.data[k++] = data[i];
				}
			}
			for(int j=0; j<s.noOfElements; j++){
				if(!contains(s.data[j])){
					result.data[k++] = s.data[j];
				}
			}
			result.noOfElements=k;
			return result;
		}
		~Set(){
			delete[]data;
			data = nullptr;
		}
};
int main(){
	Set s1(6);
	s1.addData(1);
	s1.addData(3);
	s1.addData(5);
	s1.displayData();
	Set s2(4);
	s2.addData(1);
	s2.addData(2);
	s2.addData(5);
	s2.addData(3);
	Set s3 = s1.Intersection(s2);
	s3.displayData();
	Set s4 = s1.setUnion(s2);
	s4.displayData();
	Set s5 = s1.Difference(s2);
	s5.displayData();
	bool a = s1.subset(s2);
	cout<<"subset "<<a<<endl;
	cout<<"isempty "<<s1.isempty()<<endl;
	Set s6 = s1.symmetricDifference(s2);
	s6.displayData();
	cout<<"cardinality "<<s3.cardinality();
	return 0;
}