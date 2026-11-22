struct X { static int __stdcall f(int); };

int __stdcall X::f(int a) { return a + 0x194; }
