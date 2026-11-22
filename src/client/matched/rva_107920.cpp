struct Legacy {
    int* data;
    int get(int idx) const;
};

int Legacy::get(int idx) const {
    return *reinterpret_cast<int*>( reinterpret_cast<char*>(data) + idx*4 + 0x7abb0 );
}

