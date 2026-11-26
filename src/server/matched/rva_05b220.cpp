struct Element {
    int values[22];
};

struct Container {
    int reserved[17];
    Element* items;
    int spare;
    int count;
    Element* Get(int index);
};

Element* Container::Get(int index) {
    if (index > count || index < 0)
        return items;
    return &items[index];
}
