#ifndef MAIN_SAVITCH_SEQUENCE_H
#define MAIN_SAVITCH_SEQUENCE_H
#include <cstdlib>

namespace main_savitch_3
{

    class sequence
    {
    public:
        // typedefs and member constants
        typedef double value_type;
        typedef size_t size_type; 
        static const size_type CAPACITY = 30; 
        // constructor
        sequence( );
        // member functions
        void start( );
        void advance( );
        void insert(const value_type& entry);
        void attach(const value_type& entry);
        void remove_current( );
        // const member functions
        size_type currentIndex ( ) const;
        size_type size( ) const;
        bool is_item( ) const;
        value_type current( ) const;
    private:
      value_type seq_data[CAPACITY];
      size_type seq_used;
      size_type seq_currentIndex; 
    };
}

#endif