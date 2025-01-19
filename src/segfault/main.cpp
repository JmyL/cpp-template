int cause_segfault() {
  int *seg_ptr = nullptr;
  *seg_ptr = 42;
  return 0;
}

int main() { return cause_segfault(); }
