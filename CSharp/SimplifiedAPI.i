// External ZeroMQ interface. Client Use via CreateContext
// Details on SWIG http://www.swig.org/Doc3.0/SWIGDocumentation.html#Library_std_shared_ptr
// swig.exe -c++ -csharp -namespace LibraryNamespace -I../CPP/Library/ -outdir ./CSharpLibrary/ -o ./CSharpWrapper/SimpleAPIWrapper.cxx SimplifiedAPI.i

%module(directors="1") CSharpWrapper
//%feature("director"); // Manual shared_ptr into needed type conversion is required! Stuff like SWIGTYPE_p_std__shared_ptrT_%TYPE_NAME%_t into TYPE_NAME replacement

%include "std_string.i"
%include "std_shared_ptr.i"
%shared_ptr(A)
%shared_ptr(B)
%feature("director") A;

%{
	#include <SimplifiedAPI.h>
%}

%include <SimplifiedAPI.h>


