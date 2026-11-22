struct B{char pad[0x68];int value;};

class A{public:int dummy;B* ptr;int getValue();};

int A::getValue(){return ptr->value;}
