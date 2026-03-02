#include <iostream>

using namespace std;

class SuperHero {
private:
    string hero_name;
    string ability;
    int power;
public:
    SuperHero(string hero_name = "", string ability = "", int power = 0) {
        this->hero_name = hero_name;
        this->ability = ability;
        this->power = power;
    }
    bool operator==(const SuperHero& s)const{
        if(ability==s.ability && power==s.power && hero_name==s.hero_name){
            return true;
        }
        return false;
    }
     SuperHero& operator=(const SuperHero& newHero){
        if(this != &newHero){
            hero_name = newHero.hero_name;
            ability=newHero.ability;
            power=newHero.power;
        }
        return *this;
    }
};
int main(){
	SuperHero car1("maximus", "laservision", 4200);
    SuperHero car2("invictus", "laservision", 4200);
    SuperHero car3("invictus", "laservision", 4200);

    if(car1 == car2)
        cout << "Car1 and Car2 are the same" << endl;
    if(car2 == car3)
        cout << "Car2 and Car3 are the same" << endl;
    SuperHero s=car1;
    if(s == car1){
    	cout<<"s and car1 are equal";
	}
    return 0;
}