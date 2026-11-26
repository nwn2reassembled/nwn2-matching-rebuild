struct Legacy { void setValue(float); };

void Legacy::setValue(float val) {
    *reinterpret_cast<float*>(reinterpret_cast<char*>(this)+0xf4) = val;
}

