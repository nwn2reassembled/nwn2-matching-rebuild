struct MyClass{unsigned dummy; unsigned ptr; unsigned getValue() const;};

unsigned MyClass::getValue() const{return *reinterpret_cast<unsigned*>(ptr+0x1000c);}
