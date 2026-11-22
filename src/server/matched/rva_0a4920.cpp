struct Legacy {
    // Ordinary static member declared in the class.
    static void __stdcall legacy_func(int a,int b,int c,int d,int e,int f);
};

// Out‑of‑line definition of the static member function.
void Legacy::legacy_func(int a,int b,int c,int d,int e,int f) {
    // Empty body – compiler emits only 'ret 0x18' (3 bytes).
}

