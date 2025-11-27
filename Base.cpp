#include "Base.h"
int Base::nextId = 1;

Base::Base() { id = nextId++; }
Base::Base(const Base&) { id = nextId++; }
int Base::getId() const { return id; }
