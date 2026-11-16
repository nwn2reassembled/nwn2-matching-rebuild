struct SomeStruct{char dummy[0x11c];unsigned long field;};
class MyClass{public: unsigned long func(SomeStruct* p);};
unsigned long MyClass::func(SomeStruct* p){return p->field;}

