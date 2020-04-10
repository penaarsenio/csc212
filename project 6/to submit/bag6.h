#ifndef BAG6_H
#define BAG6_H
#include <cstdlib>
#include "bintree.h" 

namespace main_savitch_10
{
    template <class Item>
    class bag
    {
    public:
        // typedefs
	typedef std::size_t size_type;
        typedef Item value_type;
        // constructor and destructor
        bag( ) { root_ptr = NULL; }
        bag(const bag& source);
        ~bag( );
        // member functions
        size_type erase(const Item& target);
        bool erase_one(const Item& target);
        void insert(const Item& entry);
        void operator +=(const bag& addend);
        void operator =(const bag& source);
        // const member functions
        size_type size( ) const;
        size_type count(const Item& target) const;
	void debug( ) const { print(root_ptr, 0); }
    private:
        binary_tree_node<Item> *root_ptr;
        void insert_all(binary_tree_node<Item>* addroot_ptr);
    };

    // non-member functions for the bag<Item> template class
    template <class Item>
    bag<Item> operator +(const bag<Item>& b1, const bag<Item>& b2);
}

#include "bag6.template"
#endif