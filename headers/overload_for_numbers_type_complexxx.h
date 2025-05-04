#pragma once

class complexx
{
private:
	double first = 0.0;
	double second = 0.0;
public:
	complexx();
	complexx(double a, double b);
	friend std::ostream& operator<< (std::ostream& os, const complexx& t);
	complexx operator+ (const complexx& a);
	complexx operator- (const complexx& a);
};

complexx::complexx()
{
	this->first = 0.0;
	this->second = 0.0;
}

complexx::complexx(double a, double b)
{
	this->first = a;
	this->second = b;
}

std::ostream& operator<< (std::ostream& os, const complexx& a)
{
	os << "(" << a.first << ", " << a.second << "i)\n";
	return os;
}

complexx complexx::operator+ (const complexx& a)
{
	complexx sum((first + a.first), (second + a.second));
	return sum;
}

complexx complexx::operator- (const complexx& a)
{
	complexx sum((first - a.first), (second - a.second));
	return sum;
}