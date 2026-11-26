struct Legacy {
    char pad[64];
    int* array;
    int get(int);
};

int Legacy::get(int idx) {
    return array[idx];
}

