class Legacy {
public:
    int getField() const; // defined out-of-line
};

int Legacy::getField() const {
    return *reinterpret_cast<const int*>( reinterpret_cast<const char*>(this) + 0xD0 );
}
