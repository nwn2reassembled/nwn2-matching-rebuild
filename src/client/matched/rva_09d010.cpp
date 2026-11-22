struct LegacyStruct {
    int get_value();
};

int LegacyStruct::get_value() {
    return *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0xc8);
}

