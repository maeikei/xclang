#include <iostream>
#include <string>
static std::ios_base::Init __start_std_streams;

#include <stdio.h>
class A
{
public:
	A()
	{
		printf("%s\n",__func__);
	}
};

A a;
int i = 100;
int main(int argc,char * argv[])
{
	A *p = &a;
	A b;
	printf("%d\n",i);
	static std::ios_base::Init __start_std_streams;
	std::cout << 1000 << std::endl;
	std::cout << "hello" << std::endl;
	std::cout << __func__<< std::endl;
	
	return 0;
}
