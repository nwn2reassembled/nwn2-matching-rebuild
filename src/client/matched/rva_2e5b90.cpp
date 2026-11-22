struct MyClass { char pad[0x304]; unsigned int value_; void setValue(unsigned int); }; void MyClass::setValue(unsigned int v) { this->value_ = v; }
