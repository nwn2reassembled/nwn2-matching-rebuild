class MyClass {
public:
    int data;                 // ordinary member
    void func(int a, int b, int c, int d, int e);  // non‑static member
};

// Out‑of‑line definition – empty body so the compiler emits only
// "ret 0x14" (callee cleans 5×4 byte arguments).  ECX holds *this.
void MyClass::func(int a, int b, int c, int d, int e) {}

