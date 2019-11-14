# Project 2: Passed

## Part 1
#### a)
OK. Capacity should start at 1.
#### b)
OK.
#### c)
OK.
#### d)
OK.
#### e)
OK. You should also print the ArrayList.
#### f)
OK.
#### g)
OK. You should also remember to call `resize()` if necessary.
#### h)
OK.
#### i)
Making a new instance of the ArrayList object within the method isn't optimal. Instead you should simply copy the data into a new array the same way you do in the `resize()` method.
#### j)
Not implemented.

## Part 2
#### a)
Good. Nice to see you implemented the doubly linked list!
#### b)
Good.
#### c)
Good. A few errors:
- You need to set `head` and `tail` equal to `nullptr` before the loop in the vector initialization constructor.
- In insert, you should be able to use `index = size`, it should then work like `append()`.
#### d)
Good.

## Part 3
Your notation is slightly confusing, it would be better if you just had a list of the operations the assignment asks for. It seems mostly correct, however you do not need to include the factors (O(n/2) can be simplified to O(n)).

It would also be good if you had a few more sentences explaining why the various things have the cost they do.

For ArrayList, `append()` uses O(1), unless you need to resize, in which case it's O(n).  
The same for removing the final element, no loops are required for this.

## Part 4
In general good, but your code is a little overcomplicated. And you are missing the destructor.
#### a)
Good.
#### b)
Good.
#### c)
Good.
#### d)
Good.
#### e)
Good.
#### f)
Good.
#### g)
Good. Correct.

## Miscellaneous

If you have any questions about the exercises or the feedback you are welcome to send me an email: j.o.f.akerholm@fys.uio.no
