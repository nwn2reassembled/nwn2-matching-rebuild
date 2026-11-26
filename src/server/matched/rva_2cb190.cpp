class Server { public: char pad[0x310]; unsigned int field_310; unsigned int& GetField310(); }; unsigned int& Server::GetField310() { return this->field_310; }
