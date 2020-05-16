I made the following changes to the hri files:  
1. Removed the const void const * to peripheral struct space. void pointers should be used sparingly and this certainly wasn't the case here. C types are not that great in the first place, so why break it further.  In most cases, the pointer is unnecessary to pass. 
2. Significant pruning of the procedures. ie toggle of non-bitfields is fairly useless, yet it was used everywhere as though some dumb script created the functions. Quite a few of the bit specifics could be done with get, set and write passed with the same bitfield and I have more flexibility than the single bit manipulation. 
3. Removed hri_ and _bit, _bf from the function names. This isn't a HAL layered driver, so that is unneeded. When you remove some of the unnecessary function calls, you don't need _bit, _bf and so on.
4. Removed the critical code. It really doesn't buy you anything. I would use whatever RTOS version of critical code macros and it would be used sparingly. 
5. Assign typedefs to return values is reverted back to basic types. Here it actually is useful information to have the basic size of the return value than a made up name which conveys no more information than you already have. 
6. Added doxygen comments with included bit patterns from the component and instance files for the functions referencing those. It makes it easier to construct a cut-n-paste function call. 
7. Optimized the code removing unnecessary variables and lines of code. 
8. They were not consistent in the convention indicating types or variable names (with _t or _Type for types) Changed several to at least have _t rather than funky case differences between variable and type.

