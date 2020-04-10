#include "sequence2.h"
#include <algorithm>
#include <assert.h>

namespace main_savitch_4 {
  // constructor and destructor
  sequence::sequence(sequence::size_type initial_capacity) 
  {
    seq_array_ptr = new sequence::value_type[initial_capacity];
    seq_capacity = initial_capacity;
    seq_currentIndex = 0;
    seq_used = 0;
  }

  sequence::sequence(const sequence& source) 
  {
    if (this == &source) return;
    seq_array_ptr = new sequence::value_type[source.currentCapacity()];
    seq_capacity = source.currentCapacity();
    seq_currentIndex = source.currentIndex();
    seq_used = source.size();
    std::copy(source.seq_array_ptr, source.seq_array_ptr+size(), seq_array_ptr);
  }

  sequence::~sequence() 
  {
    delete [] seq_array_ptr;
  }

  // member functions
  void sequence::start() 
  {
      seq_currentIndex = 0;
  }

  void sequence::advance( ) 
  {
    if(is_item() && (currentIndex() < size())) seq_currentIndex++;
  }

  void sequence::insert(const sequence::value_type& entry) 
  {
    if (currentCapacity() <= size()) resize(size()+1);
    if(!is_item()) {
        if (seq_used == 0) 
        {
          seq_array_ptr[0] = entry;
          seq_used++;
        } 
        else 
        {
          seq_currentIndex = 0;
          for(sequence::size_type i = size(); i > currentIndex(); i--) seq_array_ptr[i] = seq_array_ptr[i-1];
          seq_currentIndex++;
          seq_array_ptr[0] = entry;
          seq_used++;
        }
      } 
      else 
      {
        for (sequence::size_type i = seq_used; i > currentIndex(); i--) seq_array_ptr[i] = seq_array_ptr[i-1];
        seq_array_ptr[currentIndex()] = entry;
        seq_used++;
      }
  }

  void sequence::attach(const sequence::value_type& entry) 
  {
    if (currentCapacity() <= size()) resize(size()+1);
    if (!is_item()) 
    {
        seq_array_ptr[currentIndex()] = entry;
        seq_used++;
      } 
      else 
      {
        for(sequence::size_type i = seq_used; i > currentIndex(); i--) seq_array_ptr[i] = seq_array_ptr[i-1];
        seq_currentIndex++;
        seq_array_ptr[currentIndex()] = entry;
        seq_used++;
      }
  }

  void sequence::remove_current( ) 
  {
    assert(is_item());
    for(sequence::size_type i = currentIndex(); i < size(); i++) seq_array_ptr[i] = seq_array_ptr[i+1];
    seq_used--;
  }

  void sequence::resize(size_type new_capacity) 
  {
    sequence::value_type *newArray_ptr;
    if(currentCapacity() == new_capacity) return ;  
    else if(currentCapacity() > new_capacity) 
    {
       if(size() < new_capacity) 
       {
         newArray_ptr = new sequence::value_type[new_capacity];
         std::copy(seq_array_ptr, seq_array_ptr+size(), newArray_ptr);
         delete [] seq_array_ptr;  
         seq_array_ptr = newArray_ptr;
         seq_capacity = new_capacity;
      }
    } 
    else if(currentCapacity() < new_capacity) 
    {
          newArray_ptr = new sequence::value_type[new_capacity];
          std::copy(seq_array_ptr, seq_array_ptr+size(), newArray_ptr);
          delete [] seq_array_ptr;  
          seq_array_ptr = newArray_ptr;
          seq_capacity = new_capacity;
    }
  }

  void sequence::operator=(const sequence& source) 
  {
    sequence::value_type *newSeq_ptr;
    if(this == &source) return;
    if(currentCapacity() != source.currentCapacity()) 
    {
        seq_capacity = source.currentCapacity();
        newSeq_ptr = new sequence::value_type[source.currentCapacity()];
        delete [] seq_array_ptr;
        seq_array_ptr = newSeq_ptr;
    }
    seq_used = source.size();
    seq_currentIndex = source.currentIndex();
    std::copy(source.seq_array_ptr, source.seq_array_ptr+size(), seq_array_ptr);
  }

  // EXTRA CREDIT
  sequence::value_type sequence::operator[](sequence::size_type index) const 
  {
    assert(index >= 0 && index < size());
    return seq_array_ptr[index];
  }

  void sequence::operator+(const sequence& source) 
  {
    sequence::value_type *newSeq_ptr = new sequence::value_type[currentCapacity()+source.currentCapacity()];
    std::copy(seq_array_ptr, seq_array_ptr+size(), newSeq_ptr);
    delete [] seq_array_ptr;
    seq_array_ptr = newSeq_ptr;
    for (int i = 0; i < source.size(); i++) this->attach(source[i]);
  }

  void sequence::operator+=(const sequence& source) {
    sequence::value_type *newSeq_ptr = new sequence::value_type[currentCapacity()+source.currentCapacity()];
    std::copy(seq_array_ptr, seq_array_ptr+size(), newSeq_ptr);
    delete [] seq_array_ptr;
    seq_array_ptr = newSeq_ptr;
    for (int i = 0; i < source.size(); i++) this->attach(source[i]);
  }

  // const member functions
  sequence::size_type sequence::size( ) const 
  {
    return seq_used;
  }

  sequence::size_type sequence::currentIndex( ) const 
  {
    return seq_currentIndex;
  }

  sequence::size_type sequence::currentCapacity( ) const 
  {
    return seq_capacity;
  }

  bool sequence::is_item( ) const 
  {
    return (currentIndex() < size());
  }

  sequence::value_type sequence::current( ) const 
  {
    assert(is_item());
    return seq_array_ptr[currentIndex()];
  }
}