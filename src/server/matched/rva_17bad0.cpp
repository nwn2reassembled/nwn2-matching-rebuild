struct NodeListEntry;

struct Node {
    unsigned char pad0[4];
    unsigned short field4;
};

struct NodeListEntry {
    unsigned char pad0[4];
    NodeListEntry* next;
    Node* node;
};

class ServerObject {
public:
    NodeListEntry* GetListEntryByIndex(unsigned int index);

private:
    unsigned char pad0[0x184];
    NodeListEntry* entryList;
};

NodeListEntry* ServerObject::GetListEntryByIndex(unsigned int index)
{
    NodeListEntry* entry = entryList;
    if (entry == 0) {
        return 0;
    }

    Node* node = entry->node;
    unsigned short key = node->field4;

    if (index == 0) {
        return entry;
    }

    unsigned int i = 0;
    for (;;) {
        unsigned short value = node->field4;
        if (value != key) {
            key = value;
            i = i + 1;
        }
        if (i == index) {
            return entry;
        }
        entry = entry->next;
        if (entry == 0) {
            return 0;
        }
        node = entry->node;
        if (node == 0) {
            return 0;
        }
    }
}
