﻿#include <iostream>
using namespace std;



class Fraction;
Fraction operator *(Fraction left, Fraction right);
Fraction operator /(const Fraction left, const Fraction right);
Fraction operator +(Fraction left, Fraction right);
Fraction operator -(Fraction left, Fraction right);
bool operator ==(Fraction left, Fraction right);
bool operator !=(Fraction left, Fraction right);
bool operator >(Fraction left, Fraction right);
bool operator <(Fraction left, Fraction right);
bool operator >=(Fraction left, Fraction right);
bool operator <=(Fraction left, Fraction right);
std::ostream& operator<<(std::ostream& os, const Fraction obj);
std::istream& operator>>(std::istream& is,Fraction &obj);

class Fraction
{
public:

	Fraction();
	Fraction(int integ);
	Fraction(int numer, int den);
	Fraction(int integ, int numer, int den);
	Fraction(const Fraction& other);
	int Get_integ()const;
	int Get_den()const;
	int Get_numer()const;
	void Set_integ (int integ);
	void Set_numer (int numer);
	void Set_den(int den);
	void Print()const;
	Fraction& to_improper();   
	Fraction& to_proper();     
	Fraction& reduce();        
	Fraction  inverted()const; 
	
	Fraction& operator =(const Fraction& other);
	Fraction& operator *= (const Fraction& other);
	Fraction& operator /= (const Fraction& other);
	Fraction& operator +=(const Fraction& other);
	Fraction& operator -=(const Fraction& other);

	Fraction& operator ++();
	Fraction  operator ++(int);
	Fraction& operator --();
	Fraction  operator --(int);

private:
	int integ;
	int numer;
	int den;
};

int main()
{
	setlocale(LC_ALL, "Rus");
	cout << "Арифметические операторы:" << endl;
	Fraction A{ 5, 1, 5 };
	Fraction B{ 3, 2, 7 };
	Fraction C{ 2, 2, 3 };
	Fraction D{ 5, 3, 5 };
	Fraction R{ 5, 3, 5 };
	Fraction U;
	Fraction E = A + B;
	cout << "Операция +" << endl;
	E.Print();
	Fraction F = D - C;
	cout << "Операция -" << endl;
	F.Print();
	Fraction H = A * B;
	cout << "Операция *" << endl;
	H.Print();
	Fraction L = D / C;
	cout << "Операция /" << endl;
	L.Print();
	cout << "Операторы присваивания: " << endl;
	cout << "Операция =" << endl;
	Fraction M = D;
	M.Print();
	cout << "Операция *=" << endl;
	M *= D;
	M.Print();
	cout << "Операция /=" << endl;
	M /= D;
	M.Print();
	cout << "Операция +=" << endl;
	M += D;
	M.Print();
	cout << "Операция -=" << endl;
	M -= D;
	M.Print();
	cout << "Increment / Decrement(++ / --)" << endl;
	for (Fraction i{ 1,2,5}; i < 10; i++) cout << i << "\t";
	cout << endl;
	for (Fraction i{ 1,2,5}; i < 10; ++i) cout << i << "\t";
	cout << endl;
	for (Fraction i{ 10,2,5 }; i > 0; i--) cout << i << "\t";
	cout << endl;
	for (Fraction i{ 10,2,5 }; i > 0; --i) cout << i << "\t";
	cout << endl;
	cout << "Операторы сравнения: " << endl;
	cout << "Оператор ==" << endl;
	bool check1 = D == R;
	cout << check1;
	cout << endl;
	bool check2 = A == B;
	cout << check2;
	cout << endl;
	cout << "Оператор !=" << endl;
	bool check3 = D != R;
	cout << check3;
	cout << endl;
	bool check4 = A != B;
	cout << check4;
	cout << endl;
	cout << "Оператор >" << endl;
	bool check5 = A > B;
	cout << check5;
	cout << endl;
	bool check6 = B > A;
	cout << check6;
	cout << endl;
	cout << "Оператор <" << endl;
	bool check7 = B < A;
	cout << check7;
	cout << endl;
	bool check8 = A < B;
	cout << check8;
	cout << endl;
	cout << "Оператор >=" << endl;
	bool check9 = D >= R;
	cout << check9;
	cout << endl;
	bool check10 = A >= B;
	cout << check10;
	cout << endl;
	bool check11 = B >= A;
	cout << check11;
	cout << endl;
	cout << "Оператор <=" << endl;
	bool check12 = D <= R;
	cout << check12;
	cout << endl;
	bool check13 = A <= B;
	cout << check13;
	cout << endl;
	bool check14 = B <= A;
	cout << check14;
	cout << endl;
	cout << "Оператор >> <<" << endl;
	cout << "Введите дробь: " << endl;
	cin >> U;
	cout << U;
}

Fraction::Fraction()
{
	this->integ = 0;
	this->den = 1;
	this->numer = 0;
}
Fraction::Fraction(int integ)
{
	this->integ = integ;
	this->numer = 0;
	this->den = 1;
}
Fraction::Fraction(int numer, int den)
{
	this->integ = 0;
	this->numer = numer;	
	Set_den(den);
}
Fraction::Fraction(int integ, int numer, int den)
{
	this->integ = integ;
	this->numer = numer;
	Set_den(den);
}
Fraction::Fraction(const Fraction& other)
{
	this->integ = other.integ;
	this->den = other.den;
	this->numer = other.numer;
}

Fraction& Fraction::operator = (const Fraction& other)
{
	this->integ = other.integ;
	this->numer = other.numer;
	this->den = other.den;
	return *this;
}
Fraction& Fraction::operator *= (const Fraction& other)
{
	return *this = *this * other;
}
Fraction& Fraction::operator /= (const Fraction & other)
{
	return *this = *this / other;
}
Fraction& Fraction::operator += (const Fraction& other)
{
	return *this = *this + other;
}
Fraction& Fraction::operator -= (const Fraction& other)
{
	return *this = *this - other;
}

Fraction& Fraction::operator ++()
{
	to_proper();
	integ++;
	return *this;
}
Fraction  Fraction::operator ++(int)
{
	to_proper();
	Fraction old = *this;
	integ++;
	return old;
}
Fraction& Fraction::operator --()
{
	to_proper();
	integ--;
	return *this;
}
Fraction  Fraction::operator --(int)
{
	to_proper();
	Fraction old = *this;
	integ--;
	return old;
}

int  Fraction::Get_integ() const
{
	return integ;
}
int  Fraction::Get_numer() const
{
	return numer;
}
int  Fraction::Get_den() const
{
	return den;
}
void Fraction::Set_integ(int integ)
{
	this->integ = integ;
}
void Fraction::Set_numer(int numer)
{
	this->numer = numer;
}
void Fraction::Set_den(int den)
{
	if (den == 0)den = 1;
	this->den = den;
}
void Fraction::Print() const
{
	if (integ) cout << integ;
	if (numer)
	{
		if (integ) cout << "(";
		cout << numer << "/" << den;
		if (integ) cout << ")";
	}
	else if (integ == 0)cout << 0;
	cout << endl;
}

Fraction& Fraction::to_improper()  //убираем целую часть
{
	numer += integ *den;
	integ = 0;
	return *this;
}
Fraction& Fraction::to_proper()
{
	integ += numer / den;
	numer %=den;
	return *this;
}
Fraction& Fraction::reduce()
{
	int more, less, rest;
	if (numer > den)more = numer, less = den;
	else less = numer, more = den;
	do
	{
		rest = more % less;
		more = less;
		less = rest;
	} while (rest);

	int GCD = more;
	numer /= GCD;
	den /= GCD;
	return *this;
}
Fraction  Fraction::inverted()const
{
	Fraction inverted = *this;
	inverted.to_improper();
	inverted.numer ^= inverted.den;
	inverted.den ^= inverted.numer;
	inverted.numer ^= inverted.den;
	return inverted;
}

Fraction operator *( Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.Get_numer() * right.Get_numer(),
		left.Get_den() * right.Get_den()
	).to_proper().reduce();
}
Fraction operator /(const Fraction left, const Fraction right)
{
	return left * right.inverted();
}
Fraction operator +(const Fraction left,const Fraction right)
{
	return Fraction
	(
		left.Get_integ() + right.Get_integ(),
		left.Get_numer() * right.Get_den() + left.Get_den() * right.Get_numer(),
		left.Get_den() * right.Get_den()
	).to_proper().reduce();
}
Fraction operator -(const Fraction left, const Fraction right)
{
	    int more, less, rest, num1, num2;
		if (left.Get_den() > right.Get_den()) more =left.Get_den(), less = right.Get_den();
		else less = left.Get_den(), more = right.Get_den();
		do
		{
			rest = more % less;
			more = less;
			less = rest;
		} while (rest);
        more;
		num1 = left.Get_den() / more;
		num2 = right.Get_den() / more;
		
		if (num2 * left.Get_numer() < num1 * right.Get_numer());
		{
			return Fraction
			(
				(left.Get_integ() - right.Get_integ()) - 1,
				(left.Get_numer() * num2 + (left.Get_den() * num2)) - (right.Get_numer() * num1),
				left.Get_den() * num2
			).reduce();
		}

		if (num2 * left.Get_numer() >= num1 * right.Get_numer());
		{
			return Fraction
			(
				left.Get_integ() - right.Get_integ(),
				(left.Get_numer() * num2) - (right.Get_numer() * num1),
				left.Get_den() * num2
			).reduce();
		}
		
		
}
bool operator ==(Fraction left, Fraction right)
{
	return left.Get_integ() == right.Get_integ() && left.Get_numer() == right.Get_numer() && left.Get_den() == right.Get_den();
}
bool operator !=(Fraction left, Fraction right)
{
	return !(left.Get_integ() == right.Get_integ() && left.Get_numer() == right.Get_numer() && left.Get_den() == right.Get_den());
}
bool operator >(Fraction left, Fraction right)
{ 
	if (left.Get_integ() > right.Get_integ())  return true;
	if (left.Get_integ() == right.Get_integ()) return left.Get_den() > right.Get_den();
	if (left.Get_integ() == right.Get_integ() && left.Get_den() == right.Get_den()) return left.Get_numer() > right.Get_numer();
	else return false;
}
bool operator <(Fraction left, Fraction right)
{
	if (left.Get_integ() < right.Get_integ())  return true;
	if (left.Get_integ() == right.Get_integ()) return left.Get_den() < right.Get_den();
	if (left.Get_integ() == right.Get_integ() && left.Get_den() == right.Get_den()) return left.Get_numer() < right.Get_numer();
	else return false;
}
bool operator >=(Fraction left, Fraction right)
{
	if (left.Get_integ() > right.Get_integ())  return true;
	if (left.Get_integ() == right.Get_integ() && left.Get_den() > right.Get_den()) return true;
	if (left.Get_integ() == right.Get_integ() && left.Get_den() == right.Get_den() && left.Get_numer() > right.Get_numer()) return true;
	if (left.Get_integ() == right.Get_integ() && left.Get_den() == right.Get_den() && left.Get_numer() == right.Get_numer()) return true;
	else return false;
}
bool operator <=(Fraction left, Fraction right)
{
	if (left.Get_integ() < right.Get_integ())  return true;
	if (left.Get_integ() == right.Get_integ() && left.Get_den() < right.Get_den()) return true;
	if (left.Get_integ() == right.Get_integ() && left.Get_den() == right.Get_den() && left.Get_numer() < right.Get_numer()) return true;
	if (left.Get_integ() == right.Get_integ() && left.Get_den() == right.Get_den() && left.Get_numer() == right.Get_numer()) return true;
	else return false;
}

std::ostream& operator<<(std::ostream& os, const Fraction obj)
{
	if (obj.Get_integ())os << obj.Get_integ();
	if (obj.Get_numer())
	{
		if (obj.Get_integ())os << "(";
		os << obj.Get_numer() << "/" << obj.Get_den();
		if (obj.Get_integ()) os << ")";
	}
	else if (obj.Get_integ() == 0) os << 0;
	return os;
}
std::istream& operator>>(std::istream& is,Fraction &obj)
{
	int integ;
	int den;
	int numer;
	if (is >> integ >> numer >> den)
	{
	    obj.Set_integ(integ);
		obj.Set_numer(numer);
		obj.Set_den(den);
	}
	return is;
}





