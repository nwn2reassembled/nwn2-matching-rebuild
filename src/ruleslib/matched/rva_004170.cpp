struct Legacy {
    int count;
    int dummy;   // unused field to align the pointer at offset 8
    short* array;

    short getValue(int index);
};

short Legacy::getValue(int index) {
    if (index < count)
        return array[index];
    else
        return -1;   // matches "or ax,0xffff"
}
