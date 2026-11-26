struct Thing {
    char pad[0xd4];
    char value;
};

char __stdcall ReadValue(const Thing* thing)
{
    return thing->value;
}
