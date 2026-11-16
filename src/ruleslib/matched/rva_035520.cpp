class Arg { public: char pad[0x138]; int* p; };

class Foo {
public:
    int method(Arg*);
};

int Foo::method(Arg* arg) {
    return *arg->p;
}
