struct X { unsigned char padding[0xc8]; unsigned char value; };
unsigned char __stdcall f(const X* p) { return p->value; }
