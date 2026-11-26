struct Thing {
    char pad0[6];
    unsigned short value;
};

void __stdcall SetThingValue(Thing* thing, unsigned short value)
{
    thing->value = value;
}
