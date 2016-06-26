 ///
 /// @file    teststring.cc
 /// @author  boluo(169180920@qq.com)
 /// @date    2016-06-15 19:49:43
 ///
#include "stringclass.h" 
#include <stdio.h>

int main()
{
#if 0
	MyString ms1("hello");
	MyString ms2 = "world";
	char str[] = "hellowolrd";
	cout << ms1 << endl;
	MyString ms2(ms);
	cout << ms2 << endl;
	ms += ms1;
	cout << ms << endl;
	ms = ms1 + "world";
	ms = "hello" + ms2;
	cout << ms << endl;
	cout << ms1.substr(2,5) << endl;
	MyString ms3;
	cin >> ms3;
	cout << ms3 << endl;
	MyString ms("hello");
	MyString ms5(ms);
	cout << ms5 << endl;
	MyString s1 = "helloworld";
	MyString s2 = s1;
	MyString s3 = s1;
	
	printf("%p\n",s1.c_str());
	printf("%p\n",s2.c_str());
	printf("%p\n",s3.c_str());
#endif
	MyString s1("hello");
	MyString s2;
	s2 = std::move(s1);
	cout << s2 << endl;
	return 0;
}
