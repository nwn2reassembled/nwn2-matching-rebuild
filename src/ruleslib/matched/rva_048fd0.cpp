struct Legacy {
    void* field;
    int check() const;
};

int Legacy::check() const
{
    if (!field || *static_cast<const unsigned char*>(field) == 0)
        return 1;
    else
        return 0;
}

