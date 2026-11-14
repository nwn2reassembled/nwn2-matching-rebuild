struct Target {
    char pad[0xA4];          // Pad to reach field at offset 0xa4
    unsigned int value;      // Field written by the legacy function
};

class Utils {
public:
    static void __stdcall setField(Target* ptr, unsigned int val);
};

void Utils::setField(Target* ptr, unsigned int val) {
    ptr->value = val;
}

