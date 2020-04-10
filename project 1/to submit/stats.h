#ifndef STATS_H     // Prevent duplicate definition
#define STATS_H
#include <iostream>

namespace main_savitch_2C
{
    class statistician 
    {
      public:
          // constructors
          statistician();
          statistician(int count, double total, double smallest, double largest);

          // member functions
          void next(double r);
          void reset( );
          void checkMax(double possibleMax);
          void checkMin(double possibleMin);
          void changeCount(int newCount);
          void changeTotal(double newTotal);
          void changeMin(double newMin);
          void changeMax(double newMax);

          // const member functions
          int length( ) const;
          double sum( ) const;
          double mean( ) const;
          double minimum( ) const;
          double maximum( ) const;

          // friend functions
          friend statistician operator +
              (const statistician& s1, const statistician& s2);
          friend statistician operator *
              (double scale, const statistician& s);
      private:
          int seq_count;       
          double seq_total;   
          double seq_smallest; 
          double seq_largest; 
    };

    // non-member functions for the statistician class
    bool operator ==(const statistician& s1, const statistician& s2);
}

#endif