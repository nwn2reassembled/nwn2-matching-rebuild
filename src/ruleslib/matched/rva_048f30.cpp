struct Legacy {
    const char* data;
    int func(char target, int start);
};

int Legacy::func(char target, int start) {
    const char* p = data;
    int result = start;
    if (p && start >= 0) {
        int i = 0;
        while (i < start) {
            if (*p == 0)
                return -1;
            ++i;
            ++p;
        }
        while (*p != 0) {
            if (*p != target)
                return result;
            ++p;
            ++result;
        }
    }
    return -1;
}
