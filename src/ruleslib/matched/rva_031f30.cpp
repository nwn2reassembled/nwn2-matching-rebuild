struct MyStruct;
class Legacy {
public:
    static void __stdcall func(MyStruct* p, unsigned int val);
};

void Legacy::func(MyStruct* p, unsigned int val) {
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(p)+0x30) = val;
}

