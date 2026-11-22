struct Target{ char pad[0x58]; unsigned short field; };

class MyClass{ public: static void __stdcall setField(Target* p, unsigned short val); };

void MyClass::setField(Target* p, unsigned short val){ p->field = val; }
