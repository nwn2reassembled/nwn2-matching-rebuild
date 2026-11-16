class Legacy { public: static void __stdcall func(unsigned int edx, unsigned int ecx, unsigned char value); };

void Legacy::func(unsigned int edx, unsigned int ecx, unsigned char value) {
    *(unsigned char*)(edx + ecx + 16) = value;
}
