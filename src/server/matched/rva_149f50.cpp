class Legacy{
public:
    int func();
};

int Legacy::func()
{
    int *ptr = *(int **)(reinterpret_cast<char *>(this) + 4);
    return *reinterpret_cast<int *>(reinterpret_cast<char *>(ptr) + 0x100c4);
}

