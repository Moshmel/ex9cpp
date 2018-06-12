

void TestCase::to_os(string text)
{
	_os << _str << ": Failure in test #" << _suc + _fail << " : " << text <<"!"<<endl;
}

void TestCase::print()
{
	_os << _str << ": " << std::to_string(_fail) << " failed, ";
	_os << to_string(_suc) << " passed, ";
	_os << to_string(_suc+_fail) << " total." << endl << "---" << endl;
}

TestCase::~TestCase()
{
}
