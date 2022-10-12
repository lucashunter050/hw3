#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>

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
  std::vector<T> items;
  int ary;
  PComparator c1;

  // trickle functions
  void trickleUp(int idx);
  void trickleDown(int idx);

};

// Add implementation of member functions here

template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c) : ary(m), c1(c) {
  
}

template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() {
  // I indexed the vector starting at 1, so if it's only the empty spot
  // (size 1) our vector has no real elements
  if (!(items.size() - 1)) {
    return false;
  }
  return true;
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item) {

}

template <typename T, typename PComparator>
void Heap<T, PComparator>::trickleUp(int idx) {

}

template <typename T, typename PComparator>
void Heap<T, PComparator>::trickleDown(int idx) {
  
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

  // items.at(0) will be a dummy value, real values start at 1
  return items[1];


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



}



#endif

