class SmallestInfiniteSet {
 public:
  int popSmallest() {
    if (added.empty())
      return curr++;
    const int min = *added.begin();
    added.erase(added.begin());
    return min;
  }

  void addBack(int num) {
    if (num < curr)
      added.insert(num);
  }

 private:
  int curr = 1;
  set<int> added;
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */