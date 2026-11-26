struct Blob { int v[16]; };

struct Y {
    int a;
    int b;
    int c;
    int d;
    Blob blob;
    int e;
    unsigned char f;
    unsigned char g;
};

struct X {
    char pad[0x30];
    int a;
    int b;
    int c;
    int d;
    Blob blob;
    int e;
    unsigned char f;
    unsigned char g;
    X& operator=(const Y& rhs);
};

X& X::operator=(const Y& rhs) {
    a = rhs.a;
    b = rhs.b;
    c = rhs.c;
    d = rhs.d;
    blob = rhs.blob;
    e = rhs.e;
    f = rhs.f;
    g = rhs.g;
    return *this;
}
