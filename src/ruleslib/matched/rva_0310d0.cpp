struct Data;

struct Wrapper {
    int GetField(Data* data);
};

int Wrapper::GetField(Data* data) {
    return *(int*)((char*)data + 0x5dc);
}

