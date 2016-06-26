 ///
 /// @file    stringclass.h
 /// @author  boluo(169180920@qq.com)
 /// @date    2016-06-15 16:35:18
 ///
#ifndef __STRINGCLASS_H__ 
#define __STRINGCLASS_H__ 
#include <iostream>
 
using namespace std;

class MyString
{
	friend bool operator==(const MyString&,const MyString &);
	friend bool operator!=(const MyString&,const MyString &);
	friend bool operator<(const MyString&,const MyString &);
	friend bool operator>(const MyString&,const MyString &);
	friend bool operator<=(const MyString&,const MyString &);
	friend bool operator>=(const MyString&,const MyString &);
	//读写运算符
	friend ostream &operator<<(ostream &,const MyString &);
	friend istream &operator>>(istream &, MyString &);

public:
	//构造函数
	MyString();
	MyString(const MyString&);
	MyString(const char*);
	MyString(const char *,size_t);
	MyString(MyString &&);
	//析构函数
	~MyString();
	//属性
	size_t length() const;
	const char * c_str() const;//返回C风格的字符串
	//赋值操作符
	MyString &operator = (const MyString &);
	MyString &operator = (const char *);
	MyString &operator = (MyString &&);
	//+=操作符
	MyString &operator +=(const MyString &);
	MyString &operator +=(const char *);
	//下标运算符
	char & operator[](const size_t index);
	const char &operator[](const size_t index) const;
    //子串操作
	MyString substr(size_t, size_t);
private:
	size_t _strLength;
	char *_pstr;
};
	
//+操作符
MyString operator+(const MyString &, const MyString &);
MyString operator+(const MyString &, const char *);
MyString operator+(const char *, const MyString &);
	

#endif
