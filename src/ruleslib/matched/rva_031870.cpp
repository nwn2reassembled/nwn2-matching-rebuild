struct Legacy {
    static void __stdcall write_at_offset(unsigned* p, unsigned value);
};

void Legacy::write_at_offset(unsigned* p, unsigned value) {
    *reinterpret_cast<unsigned*>(reinterpret_cast<char*>(p)+0x624) = value;
}

