#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below

  // keeps track of how many elements are in the heap
  size_t size_ = 0;

  // items_ vector stores the data
  std::vector<T> items_;

  // keeps track of what the order of the tree is
  unsigned ary_;

  // keeps track of the functor -- i.e. if we are a min or max heap
  PComparator c1;

  // gets the parent node of a given index
  unsigned getParent(unsigned idx);

  // checks if the node at the given index is a leaf
  bool isLeaf(unsigned idx);

  // trickle functions
  void trickleUp(unsigned idx);
  void trickleDown(unsigned idx);

};

// Add implementation of member functions here

template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c) : ary_(m), c1(c) {
  
}

template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap() {}

template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const {
  // I indexed the vector starting at 1, so if it's only the empty spot
  // (size 1) our vector has no real elements
  if (!(items_.empty())) {
    return false;
  }
  return true;
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item) {
  // add the value to the end of the vector and trickle it up
  items_.push_back(item);
  ++size_;
  trickleUp(items_.size()-1);
  
}

template <typename T, typename PComparator>
unsigned Heap<T, PComparator>::getParent(unsigned idx) {
  if (idx == 0) {
    return 0;
  }

  unsigned parent = (idx - 1) / ary_;
  return parent;
}

template <typename T, typename PComparator>
bool Heap<T, PComparator>::isLeaf(unsigned idx) {
  // checks if the left-most child node exists for a given index
  // if it isn't contained in the vector, it returns that the node is a leaf

  if (((ary_ * idx) + 1) >= items_.size()) {
    return true;
  } else {
    return false;
  }
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::trickleUp(unsigned idx) {
  unsigned parent = getParent(idx);

  // min heap case

  // replace with functor here
  // probably: while (parent >= 0 && c1(items_[parent], items_[idx]))
  // replacing: items_[idx] < items_[parent]
  while (parent >= 0 && c1(items_[idx], items_[parent]))
  {
    std::swap(items_[parent], items_[idx]);
    idx = parent;
    parent = getParent(idx);
  }  
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::trickleDown(unsigned idx) {
  // base case: the index is a leaf node
  if (isLeaf(idx)) {
    return;
  }

  unsigned smallestChild = ary_ * idx + 1;
  unsigned rChild = smallestChild;

  // min heap implementation

  // while right child exists, keep testing if it's smaller than the smallest
  // previously known child
  while (rChild < items_.size() - 1 && (rChild < ary_ * idx + ary_)) {
    ++rChild;
    // replace comp with the functor
    // replacement is probably: c1(items_[smallestChild], items_[rChild])
    if (c1(items_[rChild], items_[smallestChild])) {
      smallestChild = rChild;
    }
  }

  // replace comp with the functor
  
  // checks if the smallestChild has higher priority than the parent
  if (c1(items_[smallestChild], items_[idx])) {
    std::swap(items_[idx], items_[smallestChild]);
    trickleDown(smallestChild);
  }
}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::invalid_argument("top called on empty heap");

  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element

  return items_[0];
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::invalid_argument("pop called on empty heap");

  }

  // swap with value in the back and popback
  std::swap(items_[0], items_[items_.size()-1]);
  items_.pop_back();

  // then get this element into its right place (if we haven't made the heap empty), 
  // restoring the heap property

  if (!empty()) {
    trickleDown(0);
  }

  --size_;
}



#endif

