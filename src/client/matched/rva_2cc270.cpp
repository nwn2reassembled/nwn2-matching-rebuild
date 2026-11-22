class MyClass {
public:
    int method();
};

int MyClass::method() {
    // Retrieve pointer stored at offset 4 from this object
    int* inner = *reinterpret_cast<int**>(reinterpret_cast<char*>(this) + 4);
    // Return dword located at offset 0x8C within the pointed‑to structure
    return *reinterpret_cast<int*>(reinterpret_cast<char*>(inner) + 0x8C);
}

