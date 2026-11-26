class ServerObject {
public:
    void* GetBasePointer();
};

void* ServerObject::GetBasePointer() {
    return reinterpret_cast<char*>(this) - 0xAD0;
}
