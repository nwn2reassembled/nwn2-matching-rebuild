class Foo {
public:
  Foo();
  void Init();
};

void Foo::Init() {
  // reconstructs the vtable-store prologue emitted for a virtual
  // function table assignment on the implicit this pointer
  *(void**)this = (void*)0x806730;
}
