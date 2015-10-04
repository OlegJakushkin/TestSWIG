# TestSWIG
SWIG+CSharp samples
Structure:
----
	CPP	-> Main library
	CSharp -> C++ library proxy (wrapper)
			-> C# Library
			-> C# Tests

Loosely based on  [CSharpOdeLibrary](https://github.com/OlegJakushkin/CSharpOdeLibrary ) and my NEC'2015 talk.
Requires SWIG 3 installed in your path.


Steps to reproduce:
----
 - you create C++ library
 - you minimize its interface and build its dll+lib into Build folder
 - you create a SWIG .i wrapper
 - you ran SWIG code generator
 - create a C++ wrapper dll based on generated files, connect it to your library, and build its dll into Build folder
 - create a C# wrapper library based on generated files, and build its dll into Build folder
 - create a C# tests project to test C# library and build it into Build folder

So you shall get:

 - a pure C++ library with no exports (build for all platforms you need)
 - a C++ wrapper library with exports for each language you support, (build for all platforms you need)
 - a library in target language
 - a test case library
 - a bench mark library if required

General Notes:
----
 - Pure C APIs with C++ backend make development iterations longer.
 - It is important to keep architecture as simple and bare bone C++ as possible.
 - Any standard library object can cause pain in one language or another (like for example std::complex).
 - Minimize header file includes required for your API.
 - Templates require special treatment and are not there in generated wrappers code.
 - Create special target language helper objects that could help integration of your library into users codebase.

SWIG .i notes:
----
 - use ```%module(directors="1") ModuleName;``` and ```%feature("director");``` to get inheritance
 - use template specialization alike ```%template(StateType) std::vector<double>;``` inside .i file in conjunction with type defenitions alike ```typedef std::vector<T> StateType;``` in your C++ interface
 - use ```%shared_ptr(ClassName)``` for an object to be passable as shared_ptr, note that manual shared_ptr into needed type conversion is required on C# side! Stuff like SWIGTYPE_p_std__shared_ptrT_%TYPE_NAME%_t into TYPE_NAME replacement

C++ Notes:
----
 - Write events/delegates using virtual class functions (no C pointers, std::function's etc)
 - Write Interfaces as pure virtual classes
 - Use single inheritance trees
 - Wrap all non **std** library objects needed externaly
