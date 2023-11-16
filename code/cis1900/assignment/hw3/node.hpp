#ifndef NODE_HPP
#define NODE_HPP

class node {
private:
  int val;
  node *left = nullptr;
  node *right = nullptr;

public:
  node(int);
  ~node();
  bool search(int) const;
  void insert(int);
};

#endif
