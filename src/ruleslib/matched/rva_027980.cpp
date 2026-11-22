struct MyStruct{char padding[0x60];short field_at_0x60;};
class MyClass{public: short getField(MyStruct* p);};
short MyClass::getField(MyStruct* p){return p->field_at_0x60;}
