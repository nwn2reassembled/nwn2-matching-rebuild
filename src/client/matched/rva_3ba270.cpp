struct Result {
    void* field0;
};

struct Entry {
    Result* entries;   // +0x00
    int     count;     // +0x04
    int     pad08;     // +0x08
    int*    indices;   // +0x0C
};

class Obj {
public:
    char pad[0x48];
    int  field48;

    Result* GetAt(int index);
};

Result* Obj::GetAt(int index)
{
    Entry* e = (Entry*)((char*)this + (field48 << 5));

    if (index < 0 || index >= e->count)
        return 0;

    return &e->entries[e->indices[index] * 17];
}
