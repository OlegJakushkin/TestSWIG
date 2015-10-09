#include "SimplifiedAPI.h"
#include <iostream>
#include <sstream>

void A::SetName(const std::string & n) {
	name = n;
}

std::string A::SayHello() {
	std::cout << "C++ Hello! from C++ to " << name << std::endl;
	return "C++ " + name;
}

A::~A() {
	std::cout << "C++ Del A with " << name << std::endl;
}

void B::SetA(std::shared_ptr<A> p) {
	std::cout << "C++ Set A" << std::endl;
	p_ptr = p;
}

// void B::SetSF(std::function<void(int)> f) {}

std::string B::CallA() {
	std::stringstream ss;
	ss << "C++ Call A:" << p_ptr->SayHello();
	return ss.str();
}

B::~B() {
	std::string s = p_ptr->SayHello();
	std::cout << "C++ Del B owner of " << s << std::endl;
}
