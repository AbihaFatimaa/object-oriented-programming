#include<iostream>
#include<map>
using namespace std;
class User{
    private:
        string location = "unset";
        map<string, int>skills;
    public:
        string username;
        string email;
        User(string u="", string e = ""){
            this->username=u; this->email = e;
        }
        string getLocation(){return location;}
        void setLocation(string j){location = j;}
        void info(){
            cout<<"Username: "<<username<<endl;
            cout<<"Email: "<<email<<endl;
            cout<<"Location: "<<location;
        }
        void learn(string s){
            skills[s]++;
        }
        void showSkills(){
            for(auto it:skills){
                cout<<it.first<<": "<<it.second<<endl;
            }
        }
        void clearSkill(string s){
                    skills.erase(s);
        }
        int calculateSalary(){
            int sum=0;
            for(auto it:skills){
                sum +=it.second;
            }
            return sum*100;
        }
};
int main(){
	User b("bob", "bob@gmail.com");
	b.setLocation("canada");
	b.learn("python");
	b.learn("C++");
	b.learn("python");
	b.learn("C++");
	b.learn("java");
	cout<<"Salary: "<<b.calculateSalary()<<endl;
	b.info();
}