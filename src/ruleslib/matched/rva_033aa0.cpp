struct Param{int a,b,c;float value;};class MyClass{public:float func(const Param* p);};float MyClass::func(const Param* p){return p->value;}
