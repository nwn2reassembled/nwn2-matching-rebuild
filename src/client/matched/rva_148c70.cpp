struct Off{char pad[0x1008c];int value;};

struct MyClass{void* placeholder;Off* data;int getValue() const;};

int MyClass::getValue() const{return data->value;}
