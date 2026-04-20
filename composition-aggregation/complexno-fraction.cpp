# include <iostream>
# include <string>
using namespace std;
int abs(int x) {
    return x < 0 ? -x : x;
}

int gcd(int a, int b) {
    a = abs(a);
    b = abs(b);
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
class Fraction
{
	private:
		int numerator;
		int denominator;
	public:
		void display();
		void reduce();
		~Fraction();
		Fraction(int = 1, int = 1);
		Fraction operator+(const Fraction &)const;
		Fraction operator*(const Fraction &)const;
		Fraction operator/(const Fraction &)const;
		Fraction operator-(const Fraction &)const;
		void operator+=(const Fraction &);
		void operator*=(const Fraction &);
		void operator/=(const Fraction &);
		void operator-=(const Fraction &);
		bool operator==(const Fraction &);
		bool operator!=(const Fraction &);
		bool operator<=(const Fraction &);
		bool operator>=(const Fraction &);
		bool operator<(const Fraction &);
		bool operator>(const Fraction &);
		Fraction operator++();
		Fraction operator++(int);
		Fraction operator--();
		Fraction operator--(int);
		Fraction operator-();
		 operator double();
		 friend ostream& operator<<(ostream&, const Fraction&);
};
ostream& operator<<(ostream& out, const Fraction& f) {
    out << f.numerator << "/" << f.denominator;
    return out;
}
Fraction::~Fraction(){
}
void Fraction::display(){
	cout<<numerator<<'/'<<denominator<<endl;
}
void Fraction::reduce(){
	if(denominator == 0){
		cout<<"denominator can't be zero.";
		return;
	}
	if(denominator<0){
		numerator = -numerator;
		denominator = -denominator;
	}
	int common = gcd(abs(numerator), denominator);
	numerator/=common;
	denominator/=common;
}
Fraction::Fraction(int a, int b){
	this->numerator = a;
	this->denominator = b;
}
Fraction Fraction::operator+(const Fraction &ref)const{
	Fraction result;
	result.numerator = (numerator*ref.denominator) + (ref.numerator*denominator);
	result.denominator = denominator*ref.denominator;
	result.reduce();
	return result;
}
Fraction Fraction::operator*(const Fraction& ref)const{
	Fraction result;
	result.numerator = numerator*ref.numerator;
	result.denominator = denominator*ref.denominator;
	result.reduce();
	return result;
}
Fraction Fraction::operator/(const Fraction& ref)const{
	Fraction result;
	result.numerator = numerator*ref.denominator;
	result.denominator = denominator*ref.numerator;
	result.reduce();
	return result;
}
Fraction Fraction::operator-(const Fraction& ref)const{
	Fraction result;
	result.numerator = (numerator*ref.denominator) - (ref.numerator*denominator);
	result.denominator = denominator*ref.denominator;
	result.reduce();
	return result;
}
void Fraction::operator+=(const Fraction& ref){
	this->numerator = (this->numerator*ref.denominator) + (ref.numerator*this->denominator);
	this->denominator = this->denominator*ref.denominator;
	reduce();
}
void Fraction::operator*=(const Fraction& ref){
	this->numerator = this->numerator*ref.numerator;
	this->denominator = this->denominator*ref.denominator;
	reduce();
}
void Fraction::operator/=(const Fraction& ref){
	this->numerator= this->numerator* ref.denominator;
	this->denominator = this->denominator*ref.numerator;
	reduce();
}
void Fraction::operator-=(const Fraction& ref){
	this->numerator = (this->numerator*ref.denominator) - (ref.numerator*this->denominator);
	this->denominator = this->denominator*ref.denominator;
	reduce();
}
bool Fraction::operator==(const Fraction& ref){
	if(this->numerator * ref.denominator == ref.numerator * this->denominator){
	return true;
	}
	return false;
}
bool Fraction::operator!=(const Fraction& ref){
	if(this->numerator!=ref.numerator && this->denominator!=ref.denominator){
		return true;
	}
	return false;
}
bool Fraction::operator<=(const Fraction& ref){
	if(this->numerator==ref.numerator && this->denominator==ref.denominator){
		return true;
	}
	if(this->numerator*ref.denominator<this->denominator*ref.numerator){
		return true;
	}
	return false;
}
bool Fraction::operator>=(const Fraction& ref){
		if(this->numerator==ref.numerator && this->denominator==ref.denominator){
		return true;
	}
	if(this->numerator*ref.denominator>this->denominator*ref.numerator){
		return true;
	}
	return false;
}
bool Fraction::operator<(const Fraction& ref){
		if(this->numerator*ref.denominator<this->denominator*ref.numerator){
		return true;
	}
	return false;
}
bool Fraction::operator>(const Fraction& ref){
		if(this->numerator*ref.denominator>this->denominator*ref.numerator){
		return true;
	}
	return false;
}
Fraction Fraction::operator++(){
	this->numerator = denominator+numerator;
	reduce();	
	return *this;
}
Fraction Fraction::operator++(int){
	Fraction temp = *this;
	this->numerator = denominator+numerator;
	reduce();	
	return temp;
}
Fraction Fraction::operator--(){
	this->numerator= numerator-denominator;
	reduce();
	return *this;
}
Fraction Fraction::operator--(int){
	Fraction temp = *this;
	this->numerator=numerator-denominator;
	reduce();
	return temp;
}
Fraction Fraction::operator-(){
	this->numerator = -numerator;
	reduce();
	return *this;
}
Fraction::operator double(){
	return ((double)numerator/denominator);
}
class ComplexNumber{
	private:
		Fraction real;
		Fraction imaginary;
	public:
		ComplexNumber(Fraction = Fraction(0,1), Fraction = Fraction(0,1));
		void display();
		ComplexNumber operator+(const ComplexNumber & ref);
		ComplexNumber operator-(const ComplexNumber & ref);
		ComplexNumber operator*(const ComplexNumber & ref);
		ComplexNumber operator/(const ComplexNumber & ref);
};
ComplexNumber::ComplexNumber(Fraction a, Fraction b){
	this->real = a;
	this->imaginary = b; 
}
void ComplexNumber::display(){
	char sign = '+';
	cout<<real;
    if ((double)imaginary < 0){
	cout<<imaginary<<'i'<<endl;
	}
	else{
	cout<<sign<<imaginary<<'i'<<endl;
}
}
ComplexNumber ComplexNumber::operator+(const ComplexNumber& ref){
	ComplexNumber c;
	c.real = real+ref.real;
	c.imaginary = imaginary+ ref.imaginary;
	return c;
}
ComplexNumber ComplexNumber::operator-(const ComplexNumber& ref){
	ComplexNumber c;
	c.real= real-ref.real;
	c.imaginary = imaginary-ref.imaginary;
	return c;
}
ComplexNumber ComplexNumber::operator*(const ComplexNumber& ref){
	ComplexNumber mul;      //(a + bi)(c + di) = ac + bci + adi + bd i 2 = (ac-bd) + (bc+ad)i
	mul.real = (real*ref.real)-(imaginary*ref.imaginary);
	mul.imaginary = (imaginary*ref.real)+(real*ref.imaginary);
	return mul;
}
ComplexNumber ComplexNumber::operator/(const ComplexNumber& ref){
	ComplexNumber div;
	div.real = ((real*ref.real)+(imaginary*ref.imaginary))/(ref.real*ref.real+ref.imaginary*ref.imaginary);
	div.imaginary = ((imaginary*ref.real)-(real*ref.imaginary))/(ref.real*ref.real+ref.imaginary*ref.imaginary);
	return div;
}
int main(){
	ComplexNumber a;
	ComplexNumber b(Fraction(1,2), Fraction(2,3));
	ComplexNumber c = a+b;
	c.display();
	
}