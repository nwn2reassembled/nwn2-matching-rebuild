class Legacy {
public:
    static int __stdcall foo(int);
};

int __stdcall Legacy::foo(int) { return 0; }

