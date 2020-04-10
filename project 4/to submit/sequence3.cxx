#include <assert.h>
#include "node1.h"
#include "sequence3.h"

namespace main_savitch_5 {

    sequence::sequence( ) 
    {

        head_ptr = NULL;
        tail_ptr = NULL;
        currentItem_ptr = NULL;
        prevItem_ptr = NULL;
        seq_nodeCount = 0;
    }

    sequence::sequence(const sequence& source) 
    {
        list_copy(source.getHead(), head_ptr, tail_ptr);
        list_copy(source.getCurrent(), currentItem_ptr, prevItem_ptr);
        seq_nodeCount = source.size();
	  }

    sequence::~sequence( ) 
    {
        list_clear(head_ptr);
    }

    void sequence::start( ) 
    {
        currentItem_ptr = getHead();
        prevItem_ptr = NULL;
    }

    void sequence::advance( ) 
    {
        assert(is_item());
        prevItem_ptr = getCurrent();
        currentItem_ptr = currentItem_ptr->link();
    }

    void sequence::insert(const value_type& entry) 
    {
        if(is_item()) 
        {
            if((prevItem_ptr == NULL)) 
            {
                list_head_insert(head_ptr, entry);
                currentItem_ptr = getHead();
                prevItem_ptr = NULL;
            } 
            else 
            {
                list_insert(prevItem_ptr, entry);
                currentItem_ptr = prevItem_ptr->link();
            }
        } if(!is_item()) 
        {
            list_head_insert(head_ptr, entry);
            currentItem_ptr = getHead();
            prevItem_ptr = NULL;
        } 
        seq_nodeCount++;
    }

    void sequence::attach(const value_type& entry) 
    {
        if(is_item()) 
        {
            prevItem_ptr = getCurrent();
            list_insert(currentItem_ptr, entry);
            currentItem_ptr = currentItem_ptr->link();
        } 
        if(!is_item()) 
        {
            if((prevItem_ptr == NULL)) 
            {
                list_head_insert(head_ptr, entry);
                currentItem_ptr = getHead();
                prevItem_ptr = NULL;
            } 
            else 
            {
                currentItem_ptr = list_locate(head_ptr, list_length(head_ptr));
                list_insert(currentItem_ptr, entry);
                currentItem_ptr = prevItem_ptr->link();
            }
        } seq_nodeCount++;
    }

    void sequence::remove_current( ) 
    {
        assert(is_item());
        if(currentItem_ptr == getHead()) 
        {
            list_head_remove(head_ptr);
            currentItem_ptr = getHead();
            prevItem_ptr = NULL;
        } 
        else 
        {
            currentItem_ptr = currentItem_ptr->link();
            list_remove(getPrevious());
        } 
        seq_nodeCount--;
    }

    void sequence::operator =(const sequence& source) 
    {
        if(this == &source)
        {
            return;
        }
        else 
        {
            list_clear(head_ptr);
            list_copy(source.getHead(), head_ptr, tail_ptr);
            if(source.getPrevious() == NULL) 
            {
                if(source.getCurrent() == NULL) 
                {
                    currentItem_ptr = NULL;
                    prevItem_ptr = NULL;
                } 
                else 
                {
                    currentItem_ptr = getHead();
                    prevItem_ptr = NULL;
                }
            } 
            else 
            {
                node *tmp_ptr = getHead();
                node *source_ptr = source.getHead();
                while(source_ptr != source.getPrevious()) 
                {
                    source_ptr = source_ptr->link();
                    tmp_ptr = tmp_ptr->link();
                }
                currentItem_ptr = tmp_ptr->link();
                prevItem_ptr = tmp_ptr;
            } 
            seq_nodeCount = source.size();
        }
    }

    sequence::size_type sequence::size( ) const 
    {
        return seq_nodeCount;
    }

    bool sequence::is_item( ) const 
    {
        return ((getCurrent() != NULL) && (size() > 0));
    }

    sequence::value_type sequence::current( ) const 
    {
        assert(is_item());
        return currentItem_ptr->data();
    }

    node* sequence::getHead( ) const 
    {
      return head_ptr;
    }

    node* sequence::getTail( ) const 
    {
      return tail_ptr;
    }

    node* sequence::getCurrent( ) const 
    {
      return currentItem_ptr;
    }

    node* sequence::getPrevious( ) const 
    {
      return prevItem_ptr;
    }
}