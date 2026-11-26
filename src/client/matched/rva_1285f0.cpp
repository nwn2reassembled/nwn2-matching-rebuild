struct Entry {
    int value;
    int pad;
};

class Foo {
    char pad0[0x20];
    Entry* entries;   // +0x20
    int count;        // +0x24
public:
    int __fastcall GetItem(int unusedEdx, int index);
};

int __fastcall Foo::GetItem(int unusedEdx, int index) {
    if (index < 0 || index >= count) {
        return 0;
    }
    return entries[index].value;
}
