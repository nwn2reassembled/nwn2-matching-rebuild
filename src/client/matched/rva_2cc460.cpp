struct Inner { char padding[0x328]; int field; }; struct MyClass { int dummy; Inner* inner; void setInnerField(); }; void MyClass::setInnerField() { inner->field = 1; }
