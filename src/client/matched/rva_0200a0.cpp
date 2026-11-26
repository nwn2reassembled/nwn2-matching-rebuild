struct Entity {
    unsigned char pad[0x338];
    unsigned int field_338;
    unsigned int field_33C;
};

void __cdecl Entity_SetFields(Entity *self, unsigned int a, unsigned int b) {
    self->field_338 = a;
    self->field_33C = b;
}
