struct Inner {
    int pad[186];
    int result;
};

struct Outer {
    int dummy;          // offset 0x0, serves as padding to shift 'inner' to 0x4
    Inner* inner;       // offset 0x4, the pointer accessed by the legacy function
    int getResult();    // member that matches the assembly
};

int Outer::getResult() {
    return inner->result;
}

