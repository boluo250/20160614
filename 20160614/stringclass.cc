 ///
 /// @file    stringclass.cc
 /// @author  boluo(169180920@qq.com)
 /// @date    2016-06-15 15:52:19
 ///
#include "stringclass.h" 
#include <string.h>

//构造函数
MyString::MyString()
:_strLength(0)
,_pstr(NULL)
{
	cout << "MyString()" << endl;
}
MyString::MyString(const char *str)
{
	_strLength = strlen(str);
	_pstr = new char[_strLength+1];
	strcpy(_pstr,str);
	cout << "MyString(const char *)" << endl;
}
//同一个类的不同对象，a对象的函数引用b对象，在a对象函数里，可以调用b私有成员
MyString::MyString(const MyString& rhs)
{
	_strLength = rhs.length();
	_pstr = new char[_strLength+1];
	strcpy(_pstr,rhs._pstr);
	cout << "MyString(const MyString &)" << endl;
}
MyString::MyString(const char *str,size_t n)
{
	_strLength = n;
	_pstr = new char[n+1];
	strncpy(_pstr,str,n);
}
MyString::MyString(MyString && rhs)
:_pstr(rhs._pstr)
,_strLength(rhs.length())
{
	cout << "MyString(MyString &&)" << endl;
	//如果忘记赋予nullptr，那么销毁源对象后，就会释放掉我们刚刚移动的内存
	rhs._pstr = nullptr;
}
//析构函数
MyString::~MyString()
{
	delete [] _pstr;
	cout << "~MyString()" << endl;
}
//属性
size_t MyString::length() const
{
	return _strLength;
}
const char * MyString::c_str() const
{
	return _pstr;
}
//赋值操作符
MyString & MyString::operator=(const MyString& rhs)
{
	if(this == &rhs)
		return *this;
	delete [] _pstr;
	_strLength = rhs.length();
	_pstr = new char[_strLength+1];
	strcpy(_pstr,rhs._pstr);
	cout << "MyString &operator=(const MyString&)" << endl;
	return *this;
}
MyString & MyString::operator=(const char * str)
{
	delete [] _pstr;
	_strLength = strlen(str);
	_pstr = new char[_strLength+1];
	strcpy(_pstr,str);
	cout << "MyString &operator=(const char *)" << endl;
	return *this;
}
MyString & MyString::operator=(MyString &&rhs)
{
	if(this != &rhs)
	{
		delete _pstr;
		_pstr = rhs._pstr;
		_strLength = rhs.length();
		rhs._pstr = nullptr;
		cout << "(MyString & operator=(MyString &&)" << endl;
		return *this;
	}
}
//+=操作符
MyString & MyString::operator+=(const MyString &rhs)
{
	_strLength += rhs.length();
	char *p_old = _pstr;
	_pstr = new char[_strLength+1];
	strcpy(_pstr,p_old);
	delete [] p_old;
	strcat(_pstr,rhs._pstr);
	cout << "MyString &operator+=(const MyString &)" << endl;
	return *this;
}
MyString & MyString::operator+=(const char *str)
{
	_strLength += strlen(str);
	char *p_old = _pstr;
	_pstr = new char[_strLength+1];
	strcpy(_pstr,p_old);
	delete [] p_old;
	strcat(_pstr,str);
	cout << "MyString &operator+=(const char *)" << endl;
	return *this;
}
char & MyString::operator[](const size_t idx)
{
	static char nullchar = '\0';
	if(idx >= 0 && idx <= _strLength)
	{
		return _pstr[idx];
	}
	else
	{
		cout << "index out of range" << endl;
		return nullchar;
	}
}
const char & MyString::operator[](const size_t idx) const
{
	static char nullchar = '\0';
	if(idx >= 0 && idx <= _strLength)
	{
		return _pstr[idx];
	}
	else
	{
		cout << "index out of range" << endl;
		return nullchar;
	}
}

//比较操作符
bool operator==(const MyString & lhs,const MyString &rhs)
{
	return strcmp(lhs._pstr,rhs._pstr) == 0;
}
bool operator!=(const MyString & lhs,const MyString &rhs)
{
	return strcmp(lhs._pstr,rhs._pstr) != 0;
}

bool operator<(const MyString & lhs,const MyString &rhs)
{
	return strcmp(lhs._pstr,rhs._pstr) < 0;
}
bool operator>(const MyString & lhs,const MyString &rhs)
{
	return strcmp(lhs._pstr,rhs._pstr) > 0;
}

bool operator<=(const MyString & lhs,const MyString &rhs)
{
	return strcmp(lhs._pstr,rhs._pstr) <= 0;
}
bool operator>=(const MyString & lhs,const MyString &rhs)
{
	return strcmp(lhs._pstr,rhs._pstr) >= 0;
}
//读写运算符
ostream & operator<<(ostream &os,const MyString & rhs)
{
	return os << rhs._pstr;
}
istream & operator>>(istream &is,MyString &rhs)
{
	char temp[1024];
	if(is >> temp)
	{
		delete [] rhs._pstr;
		rhs._strLength = strlen(temp);
		rhs._pstr = new char[rhs._strLength+1];
		strcpy(rhs._pstr,temp);
	}
	return is;
}
//+操作符
MyString operator+(const MyString &lhs,const MyString &rhs)
{
	MyString tmp(lhs);
	tmp += rhs;
	return tmp;
}
MyString operator+(const MyString &lhs, const char *str)
{
	MyString tmp(lhs);
	tmp += str;
	return tmp;
}
MyString operator+(const char *str, const MyString &rhs)
{
	MyString tmp = str;
	tmp += rhs;
	return tmp;
}
//子串操作(从pos位置的开始的n个字符)
MyString MyString::substr(size_t pos,size_t n)
{
	if(pos+n > _strLength)
		n = _strLength - pos;
	MyString ret;
	ret._strLength = n;
	ret._pstr = new char[ret._strLength+1];
	for(int i = 0; i != n; ++i)
		ret[i] = (*this)[pos+i];
	ret[n] = '\0';
	return ret;
}
