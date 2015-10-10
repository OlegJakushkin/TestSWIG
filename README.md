# TestSWIG
SWIG + CSharp samples

[![Build Status Linux](https://travis-ci.org/OlegJakushkin/TestSWIG.svg)](https://travis-ci.org/OlegJakushkin/TestSWIG)
[![Build status Windows ](https://ci.appveyor.com/api/projects/status/uhf5rnnrc8fbf36v?svg=true)](https://ci.appveyor.com/project/OlegJakushkin/testswig)

Structure:
----
	CPP	-> Main library
	CSharp -> C++ library proxy (wrapper)
			-> C# Library
			-> C# Tests

Loosely based on [CSharpOdeLibrary](https://github.com/OlegJakushkin/CSharpOdeLibrary ) and my NEC'2015 talk.
Requires SWIG 3 installed in your path.


Steps to reproduce:
----
 - You create C++ library
 - You minimize its interface and build its dll+lib into Build folder
 - You create a SWIG .i wrapper
 - You ran SWIG code generator
 - create a C++ wrapper dll based on generated files, connect it to your library, and build its dll into Build folder
 - create a C# wrapper library based on generated files, and build its dll into Build folder
 - create a C# tests project to test C# library and build it into Build folder

So you shall get:

 - A pure C++ library with no exports (build for all platforms you need)
 - A C++ wrapper library with exports for each language you support, (build for all platforms you need)
 - A library in target language
 - A test case library
 - A bench mark library if required

General Notes:
----
 - Pure C APIs with C++ backend make development iterations longer.
 - It is important to keep architecture as simple and bare bone C++ as possible.
 - Any standard library object can cause pain in one language or another (like for example std::complex).
 - Minimize header file includes required for your API.
 - Templates require special treatment and are not there in generated wrappers code.
 - Create special target language helper objects that could help integration of your library into users codebase.
 - Configure build order correctly

SWIG .i notes:
----
 - use ```%module(directors="1") ModuleName;``` and ```%feature("director");``` to get inheritance
 - use template specialization alike ```%template(StateType) std::vector<double>;``` inside .i file in conjunction with type defenitions alike ```typedef std::vector<T> StateType;``` in your C++ interface
 - use ```%shared_ptr(ClassName)``` for an object to be passable as shared_ptr, if done correctly Stuff like SWIGTYPE_p_std__shared_ptrT_%TYPE_NAME%_t should not appear - lock for the order
 - In case of ```shared_ptr``` use, note that GC collectable objects that inherit from C++ code will be bound to GC rules! Thus if you have a ```shared_ptr``` in object ```B``` C++ code you must create an object ```BTargetLanguage``` that would keep a reference in target language to that ```shared_ptr``` (see ```BSharp``` implementation and ```TestWithNew``` for reference).
- Write ```shared_ptr(A)``` before ```%feature("director") A;```

C++ Notes:
----
 - Write events/delegates using virtual class functions (no C pointers, std::function's etc)
 - Write Interfaces as pure virtual classes
 - Use single inheritance trees
 - Wrap all non **std** library objects needed externally

Travis CI Notes:
----
 - Build Order:
	- Compile Library (C++)
	- Call SWIG (run on .i file)
	- Compile Wrapper Library (C++)
	- Compile Wrapper Library (C#),
	- Compile tests
 - Install mixed enviroment C++ + target language