struct MyLegacy {
    unsigned int foo();
};

unsigned int MyLegacy::foo() {
    return *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x9a0) + 0x1f8;
}

