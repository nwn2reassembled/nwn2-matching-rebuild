struct Thing {
    char pad[0x5c0];
    int value;
};

void __stdcall SetThingValue(Thing* thing, int value) {
    thing->value = value;
}
