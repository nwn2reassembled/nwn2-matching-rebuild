class EntryList;

struct Node {
  char pad00[0x10];
  EntryList* owner;
  char pad14[0x18];
  Node* field2c;
  Node* field30;
};

class EntryList {
public:
  void AppendEntry(Node* entry);
private:
  char pad00[0x18];
  Node* head;
  Node* tail;
};

void EntryList::AppendEntry(Node* entry) {
  entry->owner = this;
  entry->field2c = this->tail;
  entry->field30 = 0;
  if (this->tail != 0) {
    this->tail->field30 = entry;
    this->tail = entry;
  } else {
    this->head = entry;
    this->tail = entry;
  }
}
