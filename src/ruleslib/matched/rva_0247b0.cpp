class Legacy {
public:
    static bool __stdcall check(const char* s);
};

bool Legacy::check(const char* s) { return *s != 0; }
