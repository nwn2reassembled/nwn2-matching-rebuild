struct Grid {
    unsigned int field0;
    unsigned int field4;
    unsigned char cells[2];
};

void __stdcall Grid_SetCell(Grid* self, unsigned char index, unsigned char value) {
    if (index < 2)
        self->cells[index] = value;
}
