int* Fill(int* first, int* last, const int* value) {
    while (first != last) {
        *first = *value;
        ++first;
    }
    return first;
}
