#include "sequence1.h"
#include <assert.h>

// Invariant for the sequence class
// 1. For an empty sequence we ignore if it is empty.
//    otherwise we hold values in its member data
// 2. The number of items in the sequence is used.
// 3. index_value holds current item in the sequence.

namespace main_savitch_3 {

    const sequence::size_type sequence::CAPACITY; 

    // default constructor
    sequence::sequence() 
    {
      seq_used = 0;
      seq_currentIndex = 0;
    }

    // member functions
    void sequence::start() 
    {
      seq_currentIndex = 0;
    }

    void sequence::advance() 
    {
      if(is_item() && (currentIndex() < seq_used))
      {
          seq_currentIndex++;
      }
    }

    void sequence::insert(const value_type& entry) 
    {
      assert(size() < CAPACITY);
      
      if(!is_item()) 
      {
        if (seq_used == 0) 
        {
          seq_data[0] = entry;
          seq_used++;
        } 
        else 
        {
          seq_currentIndex = 0;
          for(sequence::size_type i = seq_used; i > currentIndex(); i--) seq_data[i] = seq_data[i-1];
          seq_currentIndex++;
          seq_data[0] = entry;
          seq_used++;
        }
      } 
      else 
      {
        for (sequence::size_type i = seq_used; i > currentIndex(); i--) seq_data[i] = seq_data[i-1];
        seq_data[currentIndex()] = entry;
        seq_used++;
      }
    }

    void sequence::attach(const value_type& entry) {
      assert(size() < CAPACITY);
      if (!is_item()) 
      {
        seq_data[currentIndex()] = entry;
        seq_used++;
      } 
      else 
      {
        for(sequence::size_type i = seq_used; i > currentIndex(); i--) seq_data[i] = seq_data[i-1];
        seq_currentIndex++;
        seq_data[currentIndex()] = entry;
        seq_used++;
      }
    }

    void sequence::remove_current( ) 
    {
      assert(is_item());
      
      if(is_item()) 
      {
        for(sequence::size_type i = currentIndex(); i < seq_used; i++) seq_data[i] = seq_data[i+1];
      } 
      seq_used--;
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

    bool sequence::is_item( ) const 
    {
      return (seq_currentIndex < seq_used);
    }

    sequence::value_type sequence::current( ) const 
    {
      assert(is_item());
      return seq_data[currentIndex()];
    }
}