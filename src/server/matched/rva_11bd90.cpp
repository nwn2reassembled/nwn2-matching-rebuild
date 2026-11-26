struct Element { unsigned int first; unsigned int second; };

struct Foo {
    unsigned int padding[17];
    Element* array;
    unsigned int bar(unsigned int);
};

unsigned int Foo::bar(unsigned int idx) {
    return array[idx].second;
}

