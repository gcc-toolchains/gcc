
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __gnu_CORBA_IOR$Internet_profile__
#define __gnu_CORBA_IOR$Internet_profile__

#pragma interface

#include <java/lang/Object.h>
extern "Java"
{
  namespace gnu
  {
    namespace CORBA
    {
      namespace CDR
      {
          class AbstractCdrOutput;
      }
        class IOR;
        class IOR$CodeSets_profile;
        class IOR$Internet_profile;
        class Version;
    }
  }
}

class gnu::CORBA::IOR$Internet_profile : public ::java::lang::Object
{

public:
  IOR$Internet_profile(::gnu::CORBA::IOR *);
  virtual ::java::lang::String * toString();
  virtual void write(::gnu::CORBA::CDR::AbstractCdrOutput *);
  static const jint TAG_INTERNET_IOP = 0;
  ::java::lang::String * __attribute__((aligned(__alignof__( ::java::lang::Object)))) host;
  ::gnu::CORBA::Version * version;
  jint port;
  ::gnu::CORBA::IOR$CodeSets_profile * CodeSets;
public: // actually package-private
  ::java::util::ArrayList * components;
  ::gnu::CORBA::IOR * this$0;
public:
  static ::java::lang::Class class$;
};

#endif // __gnu_CORBA_IOR$Internet_profile__
