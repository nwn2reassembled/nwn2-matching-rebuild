struct Arg{int dummy;float value;};

class MyClass{
public:
    float getValue(Arg* arg);
};

float MyClass::getValue(Arg* arg){return arg->value;}
