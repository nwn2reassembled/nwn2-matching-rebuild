int GetSomething(void* obj) {
    return *(int*)((char*)obj + 0x8B4);
}
