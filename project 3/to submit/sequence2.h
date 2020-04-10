#ifndef MAIN_SAVITCH_SEQUENCE2_H
#define MAIN_SAVITCH_SEQUENCE2_H
#include <cstdlib> 

namespace main_savitch_4 {
    class sequence {
      public:
          // typedefs and member constants
          typedef double value_type;
          typedef size_t size_type; 
          static const size_type DEFAULT_CAPACITY = 30; 
          // constructor
          sequence(size_type initial_capacity = DEFAULT_CAPACITY);
          sequence(const sequence& source);
          ~sequence( );
          // member functions
          void start( );
          void advance( );
          void insert(const value_type& entry);
          void attach(const value_type& entry);
          void remove_current( );
          void resize(size_type new_capacity);
          void operator=(const sequence& source);
          void operator+(const sequence& source);
          void operator+=(const sequence& source);
          // const member functions
          size_type size( ) const;
          size_type currentIndex( ) const;
          size_type currentCapacity( ) const;
          bool is_item( ) const;
          value_type current( ) const;
          value_type operator[](size_type idx) const;
      private:
          value_type *seq_array_ptr;
          size_type seq_currentIndex, seq_used, seq_capacity;
      };
}

#endif