struct B{char pad[12];int value;};struct A{char pad[0x138];B* sub;};class Legacy{public:static int __stdcall getValue(A*p);};int Legacy::getValue(A*p){return p->sub->value;}
