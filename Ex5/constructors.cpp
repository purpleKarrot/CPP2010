#include <iostream>

#define BODY(X)                \
	 X() { std::cout << #X; }  \
	~X() { std::cout << #X; }  \

struct A
{
	BODY(A)
};

struct B
{
	BODY(B)
};

struct C: A, B
{
	BODY(C)
};

struct D: C
{
	BODY(D)
};

int main(int argc, char* argv[])
{
	D* d;
	std::cout << "construct: ";
	d = new D;
	std::cout << "\ndestruct: ";
	delete d;
	std::cout << std::endl;
}
