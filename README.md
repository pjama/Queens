#Queens

##The Riddle

Have you ever wondered if it's possible to arrange 8 Queens on a standard chess board with all the positions being mutually non-threatening?

Probably not -- But if so, then look no further!

For example:

    0 0 0 0 0 1 0 0 
    0 0 0 1 0 0 0 0 
    1 0 0 0 0 0 0 0 
    0 0 0 0 1 0 0 0 
    0 0 0 0 0 0 0 1 
    0 1 0 0 0 0 0 0 
    0 0 0 0 0 0 1 0 
    0 0 1 0 0 0 0 0

(0's are empty cells, 1's are positions of queen pieces)

This code is written for square board sizes up to 8x8 cells. The positions are bit-packed into an unsigned long (i.e. 64 bits) structure.

Implementing larger sizes of boards would require a more generalized data structure.

##Conclusions

It is an interesting foray into algorithms and data structures in C.

Some interesting results:

* On an 8x8 board, there are 92 unique solutions (counting rotations as unique)
* A 4x4 board is the smallest board size with solutions (4 queens) -- 2 solutions
* 5x5: 10 Solutions
* 6x6:  4 Solutions
* 7x7: 40 Solutions

