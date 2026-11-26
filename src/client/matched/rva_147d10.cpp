struct Entity {
    unsigned char pad_0x00[0x28];
    unsigned long field_0x28;
};

void __cdecl Entity_SetField28(Entity* entity, unsigned long value) {
    entity->field_0x28 = value;
}
