
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __javax_management_Query$ClassAttributeValueExp__
#define __javax_management_Query$ClassAttributeValueExp__

#pragma interface

#include <javax/management/AttributeValueExp.h>
extern "Java"
{
  namespace javax
  {
    namespace management
    {
        class ObjectName;
        class Query$ClassAttributeValueExp;
        class ValueExp;
    }
  }
}

class javax::management::Query$ClassAttributeValueExp : public ::javax::management::AttributeValueExp
{

  Query$ClassAttributeValueExp();
public:
  ::javax::management::ValueExp * apply(::javax::management::ObjectName *);
public: // actually package-private
  Query$ClassAttributeValueExp(::javax::management::Query$ClassAttributeValueExp *);
private:
  static const jlong serialVersionUID = -1081892073854801359LL;
public:
  static ::java::lang::Class class$;
};

#endif // __javax_management_Query$ClassAttributeValueExp__
