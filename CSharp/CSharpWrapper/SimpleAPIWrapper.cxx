/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 3.0.7
 *
 * This file is not intended to be easily readable and contains a number of
 * coding conventions designed to improve portability and efficiency. Do not make
 * changes to this file unless you know what you are doing--modify the SWIG
 * interface file instead.
 * ----------------------------------------------------------------------------- */

#define SWIGCSHARP
#define SWIG_DIRECTORS


#ifdef __cplusplus
/* SwigValueWrapper is described in swig.swg */
template<typename T> class SwigValueWrapper {
  struct SwigMovePointer {
    T *ptr;
    SwigMovePointer(T *p) : ptr(p) { }
    ~SwigMovePointer() { delete ptr; }
    SwigMovePointer& operator=(SwigMovePointer& rhs) { T* oldptr = ptr; ptr = 0; delete oldptr; ptr = rhs.ptr; rhs.ptr = 0; return *this; }
  } pointer;
  SwigValueWrapper& operator=(const SwigValueWrapper<T>& rhs);
  SwigValueWrapper(const SwigValueWrapper<T>& rhs);
public:
  SwigValueWrapper() : pointer(0) { }
  SwigValueWrapper& operator=(const T& t) { SwigMovePointer tmp(new T(t)); pointer = tmp; return *this; }
  operator T&() const { return *pointer.ptr; }
  T *operator&() { return pointer.ptr; }
};

template <typename T> T SwigValueInit() {
  return T();
}
#endif

/* -----------------------------------------------------------------------------
 *  This section contains generic SWIG labels for method/variable
 *  declarations/attributes, and other compiler dependent labels.
 * ----------------------------------------------------------------------------- */

/* template workaround for compilers that cannot correctly implement the C++ standard */
#ifndef SWIGTEMPLATEDISAMBIGUATOR
# if defined(__SUNPRO_CC) && (__SUNPRO_CC <= 0x560)
#  define SWIGTEMPLATEDISAMBIGUATOR template
# elif defined(__HP_aCC)
/* Needed even with `aCC -AA' when `aCC -V' reports HP ANSI C++ B3910B A.03.55 */
/* If we find a maximum version that requires this, the test would be __HP_aCC <= 35500 for A.03.55 */
#  define SWIGTEMPLATEDISAMBIGUATOR template
# else
#  define SWIGTEMPLATEDISAMBIGUATOR
# endif
#endif

/* inline attribute */
#ifndef SWIGINLINE
# if defined(__cplusplus) || (defined(__GNUC__) && !defined(__STRICT_ANSI__))
#   define SWIGINLINE inline
# else
#   define SWIGINLINE
# endif
#endif

/* attribute recognised by some compilers to avoid 'unused' warnings */
#ifndef SWIGUNUSED
# if defined(__GNUC__)
#   if !(defined(__cplusplus)) || (__GNUC__ > 3 || (__GNUC__ == 3 && __GNUC_MINOR__ >= 4))
#     define SWIGUNUSED __attribute__ ((__unused__))
#   else
#     define SWIGUNUSED
#   endif
# elif defined(__ICC)
#   define SWIGUNUSED __attribute__ ((__unused__))
# else
#   define SWIGUNUSED
# endif
#endif

#ifndef SWIG_MSC_UNSUPPRESS_4505
# if defined(_MSC_VER)
#   pragma warning(disable : 4505) /* unreferenced local function has been removed */
# endif
#endif

#ifndef SWIGUNUSEDPARM
# ifdef __cplusplus
#   define SWIGUNUSEDPARM(p)
# else
#   define SWIGUNUSEDPARM(p) p SWIGUNUSED
# endif
#endif

/* internal SWIG method */
#ifndef SWIGINTERN
# define SWIGINTERN static SWIGUNUSED
#endif

/* internal inline SWIG method */
#ifndef SWIGINTERNINLINE
# define SWIGINTERNINLINE SWIGINTERN SWIGINLINE
#endif

/* exporting methods */
#if (__GNUC__ >= 4) || (__GNUC__ == 3 && __GNUC_MINOR__ >= 4)
#  ifndef GCC_HASCLASSVISIBILITY
#    define GCC_HASCLASSVISIBILITY
#  endif
#endif

#ifndef SWIGEXPORT
# if defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__)
#   if defined(STATIC_LINKED)
#     define SWIGEXPORT
#   else
#     define SWIGEXPORT __declspec(dllexport)
#   endif
# else
#   if defined(__GNUC__) && defined(GCC_HASCLASSVISIBILITY)
#     define SWIGEXPORT __attribute__ ((visibility("default")))
#   else
#     define SWIGEXPORT
#   endif
# endif
#endif

/* calling conventions for Windows */
#ifndef SWIGSTDCALL
# if defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__)
#   define SWIGSTDCALL __stdcall
# else
#   define SWIGSTDCALL
# endif
#endif

/* Deal with Microsoft's attempt at deprecating C standard runtime functions */
#if !defined(SWIG_NO_CRT_SECURE_NO_DEPRECATE) && defined(_MSC_VER) && !defined(_CRT_SECURE_NO_DEPRECATE)
# define _CRT_SECURE_NO_DEPRECATE
#endif

/* Deal with Microsoft's attempt at deprecating methods in the standard C++ library */
#if !defined(SWIG_NO_SCL_SECURE_NO_DEPRECATE) && defined(_MSC_VER) && !defined(_SCL_SECURE_NO_DEPRECATE)
# define _SCL_SECURE_NO_DEPRECATE
#endif

/* Deal with Apple's deprecated 'AssertMacros.h' from Carbon-framework */
#if defined(__APPLE__) && !defined(__ASSERT_MACROS_DEFINE_VERSIONS_WITHOUT_UNDERSCORES)
# define __ASSERT_MACROS_DEFINE_VERSIONS_WITHOUT_UNDERSCORES 0
#endif

/* Intel's compiler complains if a variable which was never initialised is
 * cast to void, which is a common idiom which we use to indicate that we
 * are aware a variable isn't used.  So we just silence that warning.
 * See: https://github.com/swig/swig/issues/192 for more discussion.
 */
#ifdef __INTEL_COMPILER
# pragma warning disable 592
#endif


#include <stdlib.h>
#include <string.h>
#include <stdio.h>


/* Support for throwing C# exceptions from C/C++. There are two types: 
 * Exceptions that take a message and ArgumentExceptions that take a message and a parameter name. */
typedef enum {
  SWIG_CSharpApplicationException,
  SWIG_CSharpArithmeticException,
  SWIG_CSharpDivideByZeroException,
  SWIG_CSharpIndexOutOfRangeException,
  SWIG_CSharpInvalidCastException,
  SWIG_CSharpInvalidOperationException,
  SWIG_CSharpIOException,
  SWIG_CSharpNullReferenceException,
  SWIG_CSharpOutOfMemoryException,
  SWIG_CSharpOverflowException,
  SWIG_CSharpSystemException
} SWIG_CSharpExceptionCodes;

typedef enum {
  SWIG_CSharpArgumentException,
  SWIG_CSharpArgumentNullException,
  SWIG_CSharpArgumentOutOfRangeException
} SWIG_CSharpExceptionArgumentCodes;

typedef void (SWIGSTDCALL* SWIG_CSharpExceptionCallback_t)(const char *);
typedef void (SWIGSTDCALL* SWIG_CSharpExceptionArgumentCallback_t)(const char *, const char *);

typedef struct {
  SWIG_CSharpExceptionCodes code;
  SWIG_CSharpExceptionCallback_t callback;
} SWIG_CSharpException_t;

typedef struct {
  SWIG_CSharpExceptionArgumentCodes code;
  SWIG_CSharpExceptionArgumentCallback_t callback;
} SWIG_CSharpExceptionArgument_t;

static SWIG_CSharpException_t SWIG_csharp_exceptions[] = {
  { SWIG_CSharpApplicationException, NULL },
  { SWIG_CSharpArithmeticException, NULL },
  { SWIG_CSharpDivideByZeroException, NULL },
  { SWIG_CSharpIndexOutOfRangeException, NULL },
  { SWIG_CSharpInvalidCastException, NULL },
  { SWIG_CSharpInvalidOperationException, NULL },
  { SWIG_CSharpIOException, NULL },
  { SWIG_CSharpNullReferenceException, NULL },
  { SWIG_CSharpOutOfMemoryException, NULL },
  { SWIG_CSharpOverflowException, NULL },
  { SWIG_CSharpSystemException, NULL }
};

static SWIG_CSharpExceptionArgument_t SWIG_csharp_exceptions_argument[] = {
  { SWIG_CSharpArgumentException, NULL },
  { SWIG_CSharpArgumentNullException, NULL },
  { SWIG_CSharpArgumentOutOfRangeException, NULL }
};

static void SWIGUNUSED SWIG_CSharpSetPendingException(SWIG_CSharpExceptionCodes code, const char *msg) {
  SWIG_CSharpExceptionCallback_t callback = SWIG_csharp_exceptions[SWIG_CSharpApplicationException].callback;
  if ((size_t)code < sizeof(SWIG_csharp_exceptions)/sizeof(SWIG_CSharpException_t)) {
    callback = SWIG_csharp_exceptions[code].callback;
  }
  callback(msg);
}

static void SWIGUNUSED SWIG_CSharpSetPendingExceptionArgument(SWIG_CSharpExceptionArgumentCodes code, const char *msg, const char *param_name) {
  SWIG_CSharpExceptionArgumentCallback_t callback = SWIG_csharp_exceptions_argument[SWIG_CSharpArgumentException].callback;
  if ((size_t)code < sizeof(SWIG_csharp_exceptions_argument)/sizeof(SWIG_CSharpExceptionArgument_t)) {
    callback = SWIG_csharp_exceptions_argument[code].callback;
  }
  callback(msg, param_name);
}


#ifdef __cplusplus
extern "C" 
#endif
SWIGEXPORT void SWIGSTDCALL SWIGRegisterExceptionCallbacks_CSharpWrapper(
                                                SWIG_CSharpExceptionCallback_t applicationCallback,
                                                SWIG_CSharpExceptionCallback_t arithmeticCallback,
                                                SWIG_CSharpExceptionCallback_t divideByZeroCallback, 
                                                SWIG_CSharpExceptionCallback_t indexOutOfRangeCallback, 
                                                SWIG_CSharpExceptionCallback_t invalidCastCallback,
                                                SWIG_CSharpExceptionCallback_t invalidOperationCallback,
                                                SWIG_CSharpExceptionCallback_t ioCallback,
                                                SWIG_CSharpExceptionCallback_t nullReferenceCallback,
                                                SWIG_CSharpExceptionCallback_t outOfMemoryCallback, 
                                                SWIG_CSharpExceptionCallback_t overflowCallback, 
                                                SWIG_CSharpExceptionCallback_t systemCallback) {
  SWIG_csharp_exceptions[SWIG_CSharpApplicationException].callback = applicationCallback;
  SWIG_csharp_exceptions[SWIG_CSharpArithmeticException].callback = arithmeticCallback;
  SWIG_csharp_exceptions[SWIG_CSharpDivideByZeroException].callback = divideByZeroCallback;
  SWIG_csharp_exceptions[SWIG_CSharpIndexOutOfRangeException].callback = indexOutOfRangeCallback;
  SWIG_csharp_exceptions[SWIG_CSharpInvalidCastException].callback = invalidCastCallback;
  SWIG_csharp_exceptions[SWIG_CSharpInvalidOperationException].callback = invalidOperationCallback;
  SWIG_csharp_exceptions[SWIG_CSharpIOException].callback = ioCallback;
  SWIG_csharp_exceptions[SWIG_CSharpNullReferenceException].callback = nullReferenceCallback;
  SWIG_csharp_exceptions[SWIG_CSharpOutOfMemoryException].callback = outOfMemoryCallback;
  SWIG_csharp_exceptions[SWIG_CSharpOverflowException].callback = overflowCallback;
  SWIG_csharp_exceptions[SWIG_CSharpSystemException].callback = systemCallback;
}

#ifdef __cplusplus
extern "C" 
#endif
SWIGEXPORT void SWIGSTDCALL SWIGRegisterExceptionArgumentCallbacks_CSharpWrapper(
                                                SWIG_CSharpExceptionArgumentCallback_t argumentCallback,
                                                SWIG_CSharpExceptionArgumentCallback_t argumentNullCallback,
                                                SWIG_CSharpExceptionArgumentCallback_t argumentOutOfRangeCallback) {
  SWIG_csharp_exceptions_argument[SWIG_CSharpArgumentException].callback = argumentCallback;
  SWIG_csharp_exceptions_argument[SWIG_CSharpArgumentNullException].callback = argumentNullCallback;
  SWIG_csharp_exceptions_argument[SWIG_CSharpArgumentOutOfRangeException].callback = argumentOutOfRangeCallback;
}


/* Callback for returning strings to C# without leaking memory */
typedef char * (SWIGSTDCALL* SWIG_CSharpStringHelperCallback)(const char *);
static SWIG_CSharpStringHelperCallback SWIG_csharp_string_callback = NULL;


#ifdef __cplusplus
extern "C" 
#endif
SWIGEXPORT void SWIGSTDCALL SWIGRegisterStringCallback_CSharpWrapper(SWIG_CSharpStringHelperCallback callback) {
  SWIG_csharp_string_callback = callback;
}


/* Contract support */

#define SWIG_contract_assert(nullreturn, expr, msg) if (!(expr)) {SWIG_CSharpSetPendingExceptionArgument(SWIG_CSharpArgumentOutOfRangeException, msg, ""); return nullreturn; } else

/* -----------------------------------------------------------------------------
 * director_common.swg
 *
 * This file contains support for director classes which is common between
 * languages.
 * ----------------------------------------------------------------------------- */

/*
  Use -DSWIG_DIRECTOR_STATIC if you prefer to avoid the use of the
  'Swig' namespace. This could be useful for multi-modules projects.
*/
#ifdef SWIG_DIRECTOR_STATIC
/* Force anonymous (static) namespace */
#define Swig
#endif
/* -----------------------------------------------------------------------------
 * director.swg
 *
 * This file contains support for director classes so that C# proxy
 * methods can be called from C++.
 * ----------------------------------------------------------------------------- */

#if defined(DEBUG_DIRECTOR_OWNED)
#include <iostream>
#endif
#include <string>
#include <exception>

namespace Swig {
  /* Director base class - not currently used in C# directors */
  class Director {
  };

  /* Base class for director exceptions */
  class DirectorException : public std::exception {
  protected:
    std::string swig_msg;

  public:
    DirectorException(const char *msg) : swig_msg(msg) {
    }

    DirectorException(const std::string &msg) : swig_msg(msg) {
    }

    virtual ~DirectorException() throw() {
    }

    const char *what() const throw() {
      return swig_msg.c_str();
    }
  };

  /* Pure virtual method exception */
  class DirectorPureVirtualException : public DirectorException {
  public:
    DirectorPureVirtualException(const char *msg) : DirectorException(std::string("Attempt to invoke pure virtual method ") + msg) {
    }
  };
}


#include <string>


	#include <SimplifiedAPI.h>


struct SWIG_null_deleter {
  void operator() (void const *) const {
  }
};
#define SWIG_NO_NULL_DELETER_0 , SWIG_null_deleter()
#define SWIG_NO_NULL_DELETER_1
#define SWIG_NO_NULL_DELETER_SWIG_POINTER_NEW
#define SWIG_NO_NULL_DELETER_SWIG_POINTER_OWN



/* ---------------------------------------------------
 * C++ director class methods
 * --------------------------------------------------- */

#include "SimpleAPIWrapper.h"

SwigDirector_A::SwigDirector_A() : A(), Swig::Director() {
  swig_init_callbacks();
}

void SwigDirector_A::SetName(std::string const &n) {
  char * jn = 0 ;
  
  if (!swig_callbackSetName) {
    A::SetName(n);
    return;
  } else {
    jn = SWIG_csharp_string_callback((&n)->c_str()); 
    swig_callbackSetName(jn);
  }
}

std::string SwigDirector_A::SayHello() {
  std::string c_result ;
  char * jresult = 0 ;
  
  if (!swig_callbackSayHello) {
    return A::SayHello();
  } else {
    jresult = (char *) swig_callbackSayHello();
    if (!jresult) {
      SWIG_CSharpSetPendingExceptionArgument(SWIG_CSharpArgumentNullException, "null string", 0);
      return c_result;
    }
    c_result.assign(jresult); 
  }
  return c_result;
}

SwigDirector_A::~SwigDirector_A() {
  
}


void SwigDirector_A::swig_connect_director(SWIG_Callback0_t callbackSetName, SWIG_Callback1_t callbackSayHello) {
  swig_callbackSetName = callbackSetName;
  swig_callbackSayHello = callbackSayHello;
}

void SwigDirector_A::swig_init_callbacks() {
  swig_callbackSetName = 0;
  swig_callbackSayHello = 0;
}


#ifdef __cplusplus
extern "C" {
#endif

SWIGEXPORT void SWIGSTDCALL CSharp_A_SetName(void * jarg1, char * jarg2) {
  A *arg1 = (A *) 0 ;
  std::string *arg2 = 0 ;
  std::shared_ptr< A > *smartarg1 = 0 ;
  
  
  smartarg1 = (std::shared_ptr<  A > *)jarg1;
  arg1 = (A *)(smartarg1 ? smartarg1->get() : 0); 
  if (!jarg2) {
    SWIG_CSharpSetPendingExceptionArgument(SWIG_CSharpArgumentNullException, "null string", 0);
    return ;
  }
  std::string arg2_str(jarg2);
  arg2 = &arg2_str; 
  (arg1)->SetName((std::string const &)*arg2);
}


SWIGEXPORT void SWIGSTDCALL CSharp_A_SetNameSwigExplicitA(void * jarg1, char * jarg2) {
  A *arg1 = (A *) 0 ;
  std::string *arg2 = 0 ;
  std::shared_ptr< A > *smartarg1 = 0 ;
  
  
  smartarg1 = (std::shared_ptr<  A > *)jarg1;
  arg1 = (A *)(smartarg1 ? smartarg1->get() : 0); 
  if (!jarg2) {
    SWIG_CSharpSetPendingExceptionArgument(SWIG_CSharpArgumentNullException, "null string", 0);
    return ;
  }
  std::string arg2_str(jarg2);
  arg2 = &arg2_str; 
  (arg1)->A::SetName((std::string const &)*arg2);
}


SWIGEXPORT char * SWIGSTDCALL CSharp_A_SayHello(void * jarg1) {
  char * jresult ;
  A *arg1 = (A *) 0 ;
  std::shared_ptr< A > *smartarg1 = 0 ;
  std::string result;
  
  
  smartarg1 = (std::shared_ptr<  A > *)jarg1;
  arg1 = (A *)(smartarg1 ? smartarg1->get() : 0); 
  result = (arg1)->SayHello();
  jresult = SWIG_csharp_string_callback((&result)->c_str()); 
  return jresult;
}


SWIGEXPORT char * SWIGSTDCALL CSharp_A_SayHelloSwigExplicitA(void * jarg1) {
  char * jresult ;
  A *arg1 = (A *) 0 ;
  std::shared_ptr< A > *smartarg1 = 0 ;
  std::string result;
  
  
  smartarg1 = (std::shared_ptr<  A > *)jarg1;
  arg1 = (A *)(smartarg1 ? smartarg1->get() : 0); 
  result = (arg1)->A::SayHello();
  jresult = SWIG_csharp_string_callback((&result)->c_str()); 
  return jresult;
}


SWIGEXPORT void SWIGSTDCALL CSharp_delete_A(void * jarg1) {
  A *arg1 = (A *) 0 ;
  std::shared_ptr< A > *smartarg1 = 0 ;
  
  
  smartarg1 = (std::shared_ptr<  A > *)jarg1;
  arg1 = (A *)(smartarg1 ? smartarg1->get() : 0); 
  (void)arg1; delete smartarg1;
}


SWIGEXPORT void * SWIGSTDCALL CSharp_new_A() {
  void * jresult ;
  A *result = 0 ;
  
  result = (A *)new SwigDirector_A();
  
  jresult = result ? new std::shared_ptr<  A >(result SWIG_NO_NULL_DELETER_1) : 0;
  
  return jresult;
}


SWIGEXPORT void SWIGSTDCALL CSharp_A_director_connect(void *objarg, SwigDirector_A::SWIG_Callback0_t callback0, SwigDirector_A::SWIG_Callback1_t callback1) {
  std::shared_ptr< A > *obj = (std::shared_ptr< A > *)objarg;
  // Keep a local instance of the smart pointer around while we are using the raw pointer
  // Avoids using smart pointer specific API.
  SwigDirector_A *director = dynamic_cast<SwigDirector_A *>(obj->operator->());
  if (director) {
    director->swig_connect_director(callback0, callback1);
  }
}


SWIGEXPORT void SWIGSTDCALL CSharp_B_SetA(void * jarg1, void * jarg2) {
  B *arg1 = (B *) 0 ;
  std::shared_ptr< A > arg2 ;
  std::shared_ptr< B > *smartarg1 = 0 ;
  
  
  smartarg1 = (std::shared_ptr<  B > *)jarg1;
  arg1 = (B *)(smartarg1 ? smartarg1->get() : 0); 
  if (jarg2) arg2 = *(std::shared_ptr< A > *)jarg2; 
  (arg1)->SetA(arg2);
}


SWIGEXPORT char * SWIGSTDCALL CSharp_B_CallA(void * jarg1) {
  char * jresult ;
  B *arg1 = (B *) 0 ;
  std::shared_ptr< B > *smartarg1 = 0 ;
  std::string result;
  
  
  smartarg1 = (std::shared_ptr<  B > *)jarg1;
  arg1 = (B *)(smartarg1 ? smartarg1->get() : 0); 
  result = (arg1)->CallA();
  jresult = SWIG_csharp_string_callback((&result)->c_str()); 
  return jresult;
}


SWIGEXPORT void SWIGSTDCALL CSharp_delete_B(void * jarg1) {
  B *arg1 = (B *) 0 ;
  std::shared_ptr< B > *smartarg1 = 0 ;
  
  
  smartarg1 = (std::shared_ptr<  B > *)jarg1;
  arg1 = (B *)(smartarg1 ? smartarg1->get() : 0); 
  (void)arg1; delete smartarg1;
}


SWIGEXPORT void * SWIGSTDCALL CSharp_new_B() {
  void * jresult ;
  B *result = 0 ;
  
  result = (B *)new B();
  
  jresult = result ? new std::shared_ptr<  B >(result SWIG_NO_NULL_DELETER_1) : 0;
  
  return jresult;
}


#ifdef __cplusplus
}
#endif

