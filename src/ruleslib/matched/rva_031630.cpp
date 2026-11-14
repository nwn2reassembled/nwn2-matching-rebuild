class Legacy {
public:
    int dummy;
    static int __stdcall getField(Legacy* ptr);
};

int Legacy::getField(Legacy* ptr) { return *reinterpret_cast<int*>(reinterpret_cast<char*>(ptr)+0x604); }
