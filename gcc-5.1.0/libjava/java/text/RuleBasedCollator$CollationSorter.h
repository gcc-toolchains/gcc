
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __java_text_RuleBasedCollator$CollationSorter__
#define __java_text_RuleBasedCollator$CollationSorter__

#pragma interface

#include <java/lang/Object.h>
extern "Java"
{
  namespace java
  {
    namespace text
    {
        class RuleBasedCollator$CollationSorter;
    }
  }
}

class java::text::RuleBasedCollator$CollationSorter : public ::java::lang::Object
{

  RuleBasedCollator$CollationSorter(jint, ::java::lang::String *, jint, jboolean);
public: // actually package-private
  RuleBasedCollator$CollationSorter(jint, ::java::lang::String *, jint, jboolean, ::java::text::RuleBasedCollator$CollationSorter *);
  static const jint GREATERP = 0;
  static const jint GREATERS = 1;
  static const jint GREATERT = 2;
  static const jint EQUAL = 3;
  static const jint RESET = 4;
  static const jint INVERSE_SECONDARY = 5;
  jint __attribute__((aligned(__alignof__( ::java::lang::Object)))) comparisonType;
  ::java::lang::String * textElement;
  jint hashText;
  jint offset;
  jboolean ignore;
  ::java::lang::String * expansionOrdering;
public:
  static ::java::lang::Class class$;
};

#endif // __java_text_RuleBasedCollator$CollationSorter__
