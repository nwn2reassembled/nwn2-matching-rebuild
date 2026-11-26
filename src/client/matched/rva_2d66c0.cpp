struct ListView {
    unsigned long field_0;
    ListView* next;
    unsigned char pad_0x08[0xe4];
    unsigned long value_0xec;
};

unsigned long __stdcall ListView_GetLastValue(ListView* list) {
    if (list == 0) {
        return 0;
    }
    while (list->next != 0) {
        list = list->next;
    }
    return list->value_0xec;
}
