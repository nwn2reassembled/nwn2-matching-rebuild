struct MyStruct {
    unsigned short* array;
    int count;
    int dummy;
    int (*compare)(int, const unsigned short*);
    int find(int target) const;
};

int MyStruct::find(int target) const {
    int high = count - 1;
    int low = 0;
    if (high > -1) {
        while (low <= high) {
            int mid = (low + high) / 2;
            int cmp = compare(target, array + mid);
            if (cmp > 0)
                low = mid + 1;
            else if (cmp < 0)
                high = mid - 1;
            else
                return 1;
        }
    }
    return 0;
}
