#pragma once
#include <string>
#include <sstream>
#include <ostream>

using namespace std;
class TestCase
{
	int _suc;
	int _fail;
	string _str;
	void to_os(string text);
protected:
	ostream & _os;
public:

	TestCase(string str, ostream& os) :_str(str), _os(os) {
		_os << str << endl;
		_suc = 0;
		_fail = 0;

	};
	template<typename T>
	TestCase& check_equal(T a, T b);

	template<typename T>
	TestCase& check_different(T a, T b);

	template<typename T1, typename T2, typename T3>
	TestCase& check_function(T1 func, T2 x, T3 y);

	template <typename T>
	TestCase& check_output(T x, string str);

	void print();
	~TestCase();


};

template<typename T>
inline TestCase & TestCase::check_equal(T a, T b)
{
	{

		if (a != b)
		{
			_fail++;
			ostringstream s1, s2;
			s1 << a;
			s2 << b;
			string s = "error  " + s2.str() + "is not the same as " + s1.str();
			to_os(s);
		}
		else _suc++;

		return*this;
	}
}

template<typename T>
inline TestCase & TestCase::check_different(T a, T b)
{
	if (a == b) {
		_fail++;
		ostringstream s1, s2;
		s1 << a;
		s2 << b;
		string s = "error  " + s2.str() + "== " + s1.str() + " ";
		to_os(s);
	}
	else _suc++;

	return *this;
}

template<typename T1, typename T2, typename T3>
inline TestCase & TestCase::check_function(T1 fu, T2 x, T3 y)
{
	T2 temp = fu(x);
	if (temp == y)  _suc++;
	else {
		_fail++;
		ostringstream s1, s2;
		s1 << temp;
		s2 << y;
		string s = "Function should return  " + s2.str() + "instead of  " + s1.str() + "!";
		to_os(s);
	}

	return *this;
}

template<typename T>
inline TestCase & TestCase::check_output(T x, string str)
{
	ostringstream out;
	out << x;
	if (out.str() == str)
	{
		_suc++;
	}
	else {
		_fail++;
		string s = "string value should be " + str + " but is " + out.str();
		to_os(s);

	}

	return (*this);
}

