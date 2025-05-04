#pragma once
class Time
{
private:
	int hours = 0;
	int minutes = 0;
public:
	Time(int h = 0, int m = 0);
	friend Time operator+ (const Time& t1, const Time& t2);
	friend Time operator- (const Time& t1, const Time& t2);
	friend std::ostream& operator<< (std::ostream& os, const Time& t);
};

Time::Time(int h, int m)
{
	hours = h;
	minutes = m;
}

Time operator+ (const Time& t1, const Time& t2)
{
	Time sum;
	sum.minutes = t1.minutes + t2.minutes;
	sum.hours = t1.hours + t2.hours + sum.minutes / 60;
	sum.minutes %= 60;
	return sum;
}

Time operator- (const Time& t1, const Time& t2)
{
	Time diff;
	int tol1 = 0, tol2 = 0;
	tol1 = t1.minutes + 60 * t1.hours;
	tol2 = t2.minutes + 60 * t2.hours;
	diff.minutes = (tol1 - tol2) % 60;
	diff.hours = (tol1 - tol2) / 60;
	return diff;
}

std::ostream& operator<< (std::ostream& os, const Time& t)
{
	os << t.hours << " hours, " << t.minutes << " minutes\n";
	return os;
}