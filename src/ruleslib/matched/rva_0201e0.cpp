struct Record {
    char pad[0x32c];
    int active;
    char tail[8];
};

struct Legacy {
    int count;
    Record* records;
    int check(int arg);
};

int Legacy::check(int arg) {
    if (records && arg >= 0 && arg < count && records[arg].active == 1)
        return 1;
    return 0;
}
