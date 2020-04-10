#ifndef MAIN_SAVITCH_SEQUENCE3_H
#define MAIN_SAVITCH_SEQUENCE3_H
#include <cstdlib> 
#include "node1.h"

namespace main_savitch_5
{
    class sequence
    {
    public:
        // typedef
        typedef size_t size_type; 
        typedef node::value_type value_type;
        // constructors and destructors
        sequence( );
        sequence(const sequence& source);
        ~sequence( );
        // member functions
        void start( );
        void advance( );
        void insert(const value_type& entry);
        void attach(const value_type& entry);
        void remove_current( );
        void operator =(const sequence& source);
        // const member functions
        size_t size( ) const;
        bool is_item( ) const;
        value_type current( ) const;
        node* getHead( ) const;
        node* getTail( ) const;
        node* getCurrent( ) const;
        node* getPrevious( ) const;
    private:
      size_type seq_nodeCount;
      node* head_ptr, *tail_ptr, *currentItem_ptr, *prevItem_ptr;
    };
}

#endif