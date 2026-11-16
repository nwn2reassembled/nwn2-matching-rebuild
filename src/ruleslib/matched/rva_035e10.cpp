class Legacy {
public:
    static float __stdcall getValue(void* basePtr, int index);
};

float Legacy::getValue(void* basePtr, int index) {
    char* p = reinterpret_cast<char*>(basePtr);
    return *reinterpret_cast<float*>(p + 0x74 + index * sizeof(float));
}

