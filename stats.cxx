#include "stats.h"
#include <iostream>
#include <assert.h>

using namespace std;

namespace main_savitch_2C {
  //default constructor
  statistician::statistician() 
  {
    reset();
  }

  //custom constructor
  statistician::statistician(int count, double total, double smallest, double largest) 
  {
    seq_count = count;
    seq_total = total;
    seq_smallest = smallest;
    seq_largest = largest;
  }

  void statistician::next(double r) 
  {
    seq_count += 1;
    seq_total += r;
    checkMin(r);
    checkMax(r);
  }

  void statistician::reset() 
  {
    seq_count = 0;
    seq_total = 0;
    seq_smallest = 0;
    seq_largest = 0;
  }

  // const member functions
  int statistician::length( ) const 
  {
    return seq_count;
  }

  double statistician::sum( ) const 
  {
    return seq_total;
  }

  double statistician::mean( ) const 
  {
    assert(length() > 0);
    return seq_total / seq_count;
  }

  double statistician::minimum( ) const 
  {
    assert(length() > 0);
    return seq_smallest;
  }

  double statistician::maximum( ) const 
  {
    assert(length() > 0);
    return seq_largest;
  }

  void statistician::checkMin(double possibleMin) 
  {
    if (length() == 1) changeMin(possibleMin); 
    (possibleMin < minimum()) ? changeMin(possibleMin) : changeMin(minimum());
  }

  void statistician::checkMax(double possibleMax) 
  {
    if (length() == 1) changeMax(possibleMax); 
    (possibleMax > maximum()) ? changeMax(possibleMax) : changeMax(maximum());
  }

  void statistician::changeCount(int newCount) 
  {
    seq_count = newCount;
  }

  void statistician::changeTotal(double newTotal) 
  {
    seq_total = newTotal;
  }

  void statistician::changeMin(double newMin) 
  {
    seq_smallest = newMin;
  }

  void statistician::changeMax(double newMax) 
  {
    seq_largest = newMax;
  }

  // friend functions
  statistician operator+ (const statistician& s1, const statistician& s2) 
  {
      
    statistician s3;
    
    if (s1.length() == 0 && s2.length() == 0)
    { 
        return s3;
    }
    else if (s1.length() == 0)
    {
        return s2;
    }
    else if (s2.length() == 0)
    {
        return s1;
    }
    else 
    {
      s3.changeCount(s1.length() + s2.length());
      s3.changeTotal(s1.sum() + s2.sum());
      double smallestMin = (s1.minimum() < s2.minimum()) ? s1.minimum() : s2.minimum(); 
      s3.changeMin(smallestMin);
      double largestMax = (s1.maximum() > s2.maximum()) ? s1.maximum() : s2.maximum(); 
      s3.changeMax(largestMax);
    } 
    return s3;
  }

  statistician operator* (double scale, const statistician& s) 
  {
      
    statistician scaled = s;
    scaled.changeTotal(s.sum() * scale);
    
    if (s.length() == 0)
    {
        return s;
    } 
    if (scale < 0) 
    { 
      scaled.changeMax(s.minimum() * scale);
      scaled.changeMin(s.maximum() * scale);
    } 
    else if (scale == 0) 
    {
      scaled.reset();
      scaled.changeCount(s.length());
    }
    else 
    {
      scaled.changeMin(s.minimum() * scale);
      scaled.changeMax(s.maximum() * scale);
    } 
    return scaled;
  }

  // non-member functions for the statistician class
  bool operator ==(const statistician& s1, const statistician& s2) 
  {
    if (s1.length() == 0 && s2.length() == 0)
    {
        return true;
    }
    else if (s1.length() == s2.length() && s1.sum() == s2.sum() && s1.minimum() == s2.minimum() && s1.maximum() == s2.maximum())
    {
        return true;
    }
    else 
    {
        return false;
    }
  }
};