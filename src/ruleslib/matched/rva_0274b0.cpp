struct Data { int a; int b; float f; };
class Legacy { public: float getValue(Data* p); };
float Legacy::getValue(Data* p) { return p->f; }

