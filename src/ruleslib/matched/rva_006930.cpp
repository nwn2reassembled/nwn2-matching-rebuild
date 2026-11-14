struct Body {
    unsigned int words[12];
};

struct Tail {
    unsigned int e, f, g;
};

struct MyStruct {
    unsigned char a;
    Body body;
    Tail tail;
    MyStruct(const MyStruct& other);
};

MyStruct::MyStruct(const MyStruct& other) {
    a = other.a;
    body = other.body;
    tail = other.tail;
}
