typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef unsigned int DWORD;

class Legacy {
public:
    int init();
};

int Legacy::init() {
    BYTE* p = reinterpret_cast<BYTE*>(this);
    *reinterpret_cast<DWORD*>(p + 0x14) = 0; // [ecx+0x14]
    *reinterpret_cast<DWORD*>(p + 0x18) = 0; // [ecx+0x18]
    *reinterpret_cast<WORD*>(p + 0xc)   = 0; // [ecx+0xc]
    *reinterpret_cast<DWORD*>(p + 0x10) = 0; // [ecx+0x10]
    *reinterpret_cast<DWORD*>(p + 0x1c) = 0; // [ecx+0x1c]
    *reinterpret_cast<DWORD*>(p + 0x20) = 0; // [ecx+0x20]
    *reinterpret_cast<DWORD*>(p + 0x24) = 0; // [ecx+0x24]
    *reinterpret_cast<DWORD*>(p + 0x28) = 0; // [ecx+0x28]
    *reinterpret_cast<DWORD*>(p + 0x40) = 0; // [ecx+0x40]
    *reinterpret_cast<DWORD*>(p + 0x44) = 0; // [ecx+0x44]
    p[0x48] = 0;                            // [ecx+0x48]
    return 1;
}
