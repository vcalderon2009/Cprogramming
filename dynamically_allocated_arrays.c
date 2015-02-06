#include <stdio.h>
#include <stdlib.h> // for atoi and atof

int main(int argc, char **argv)
{

   // Sometimes you can't predict the size
   // of an array at compile time, or you need
   // to grow or shrink the size of an array.
   //
   // Dynamically allocated arrays are great
   // for either of these purposes
   if ( argc != 2 ) {
      printf("Usage: dynamically_allocated_arrays arraySize\n");
      exit(0);
   }

   int n = atoi(argv[1]);

   // initialize an allocatable array of size n
   // malloc reserves a block of memory for the array.
   //
   // malloc needs to know the number of bytes you'd
   // like to reserve, which you can get by muliplying
   // the desired size of the array times sizeof(type)
   int * myDynamicArray = malloc( n * sizeof(int) );

   // fill and access your dynamic array like any
   // other "normal" array
   int i;
   for ( i=0; i<n ; i++ ) { 
      myDynamicArray[i] = i * 9;
      printf("i: %d, myDynamicArray[i]: %d\n",i,myDynamicArray[i]);
   }

   // the memory for dynamically allocated arrays must 
   // be manually released before a program terminates.
   // Failure to do so can lead to memory leaks.
   free(myDynamicArray);

   return 0;
}