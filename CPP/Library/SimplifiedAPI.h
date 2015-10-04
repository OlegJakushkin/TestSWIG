#ifndef ZMQBackEndH
#define ZMQBackEndH
#include <string>
#include <memory>

class A {
	std::string name;
public:
	virtual void SetName(const std::string & n);

	virtual std::string SayHello();

	virtual ~A();
};


class B {
	std::shared_ptr<A> p_ptr;
public:
	virtual void SetA(std::shared_ptr<A> p);
	// virtual void SetSF(std::function<void(int)> f); // Ignored By SWIG yet crap is generated!(

	virtual std::string CallA();

	virtual ~B();

};
#endif // ZMQBackEndH

