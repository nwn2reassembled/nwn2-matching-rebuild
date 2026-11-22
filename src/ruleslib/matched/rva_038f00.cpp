struct Param { char pad[0x138]; void* ptr138; };
struct Inner { char pad[0x24]; int field24; };
struct C { int foo(Param* p); };
int C::foo(Param* p) { return reinterpret_cast<Inner*>(p->ptr138)->field24; }
