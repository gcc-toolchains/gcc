
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __gnu_java_awt_color_SrgbConverter__
#define __gnu_java_awt_color_SrgbConverter__

#pragma interface

#include <java/lang/Object.h>
#include <gcj/array.h>

extern "Java"
{
  namespace gnu
  {
    namespace java
    {
      namespace awt
      {
        namespace color
        {
            class SrgbConverter;
        }
      }
    }
  }
}

class gnu::java::awt::color::SrgbConverter : public ::java::lang::Object
{

public:
  SrgbConverter();
  virtual JArray< jfloat > * fromCIEXYZ(JArray< jfloat > *);
  virtual JArray< jfloat > * toCIEXYZ(JArray< jfloat > *);
  virtual JArray< jfloat > * toRGB(JArray< jfloat > *);
  virtual JArray< jfloat > * fromRGB(JArray< jfloat > *);
  static JArray< jfloat > * XYZtoRGB(JArray< jfloat > *);
  static JArray< jfloat > * RGBtoXYZ(JArray< jfloat > *);
  static ::java::lang::Class class$;
};

#endif // __gnu_java_awt_color_SrgbConverter__