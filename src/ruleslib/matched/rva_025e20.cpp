struct LegacyStruct;
class MyClass{public: unsigned int getValue(LegacyStruct* obj);};
struct LegacyStruct{char padding[0xb8];unsigned int value;};
unsigned int MyClass::getValue(LegacyStruct* obj){return obj->value;}

