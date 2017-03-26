//lab2
//Thida Aung, Songjie Cai

#include <cstdlib>
#include <iostream>

using namespace std;


class Complex
{
    public:
    Complex();
    Complex(double x,double y);
    double getreal()const;
    double getim()const;
    void setreal(double);
    void setim(double);
    

    private:
    double real;
    double im;
    
}; //end of class declaration

//constructor
Complex::Complex()
{
    real=0;
    im=0;
}

Complex::Complex(double x, double y)
{
    real=x;
    im=y;
}
//getter since it's privately delcared in member function
double Complex::getreal()const
{
    return real;
}

double Complex::getim()const
{
    return im;
}
//setter since it's privately delcared in member function
void Complex::setreal(double num)
{
    real=num;
}

void Complex::setim(double num)
{
    im=num;
}

//overloading Operators +,-,*, <<, >>
Complex operator+(const Complex& a,const Complex& b)
{
    Complex c;
    c.setreal(a.getreal()+b.getreal());
    c.setim(a.getim()+b.getim());
    return c;
}
Complex operator-(const Complex& a,const Complex& b)
{
    Complex c;
    c.setreal( a.getreal()-b.getreal());
    c.setim(a.getim()-b.getim());
    return c;
}

Complex operator*(const Complex& a, const Complex& b)
{
    Complex c;
    c.setreal(a.getreal() * b.getreal() - a.getim() * b.getim());
    c.setim( a.getreal() * b.getim() +b.getreal()*a.getim());
    return c;
}

ostream& operator <<(ostream& out, const Complex& c)
{
	out <<"complex number: "<<c.getreal()<<"+("<<c.getim()<<"i)";
	return out;
}

istream& operator >>(istream& inputs, Complex& c)
{
    double a,b;
    inputs>> a>> b;
    c = Complex(a,b);

    return inputs;
}
//main function to test the value and output
int main()
{

        Complex c1;
        c1.setreal(2);
        c1.setim(2);
        cout<< c1 <<endl;
        
        Complex c2;
        c2.setreal(1);
        c2.setim(-4);
        cout << c2 << endl;
        
        cout << c1 + c2 << endl;
        
        cout << c1 - c2 << endl;
        
        cout << c1 * c2 << endl;
        
        Complex c3;
        cout<<"Enter a complex number:"<<endl;
        cin >> c3;
        cout << c3 << endl;
        cout << c3 + c2 << endl;
        
        cout << c3 - c2 << endl;
        
        cout << c3 * c2 << endl;
        
        return 0;

}