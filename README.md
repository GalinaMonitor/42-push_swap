
# Push_swap
## Sort an array of numbers using two stacks and deque rules
The Push_swap project is a very simple and highly effective algorithm project. You have at your disposal a set of int values, 2 stacks and a set of instructions to manipulate both stacks.

[push_swap_subject.pdf](https://github.com/GalinaMonitor/42-push_swap/files/7177846/push_swap_subject.pdf)

Program sorts stacks `a` and `b` with the following operations:

> `sa` : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).
>
> `sb` : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).
>
> `ss` : sa and sb at the same time.
>
> `pa` : push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
>
> `pb` : push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
>
> `ra` : rotate a - shift up all elements of stack a by 1. The first element becomes the last one.
>
> `rb` : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
>
> `rr` : ra and rb at the same time.
>
> `rra` : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
>
> `rrb` : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.
>
> `rrr` : rra and rrb at the same time.
Example:
#
	----------------------------
	Init a and b:
	2
	1
	3
	6
	5
	8
	_ _
	a b
	----------------------------
	Exec sa:
	1
	2
	3
	6
	5
	8
	_ _
	a b
	----------------------------
	Exec pb pb pb:
	6 3
	5 2
	8 1
	_ _
	a b
	----------------------------
	Exec ra rb (equiv. to rr):
	5 2
	8 1
	6 3
	_ _
	a b
	----------------------------
	Exec rra rrb (equiv. to rrr):
	6 3
	5 2
	8 1
	_ _
	a b
	----------------------------
	Exec sa:
	5 3
	6 2
	8 1
	_ _
	a b
	----------------------------
	Exec pa pa pa:
	1
	2
	3
	5
	6
	8
	_ _
	a b
Program prints operations for sorting an array.
#
## Algorythm
The main difficulty of task is to create your own effective algorythm.
For array size 5 and less i used manual search.

For bigger arrays i used [`radix sort`](https://www.interviewcake.com/concept/java/radix-sort):

_                 | Complexity |
------------------|:----------:|
Worst case time   | O(n)       |
Best case time    | O(n)       |
Average case time | O(n)       |
Space             | O(n)       |

#
## Usage:
How to make push_swap and use it

	make
	./push_swap "your combination of numbers without parentheses"
#
## Testing
You can test program, using `./test.sh`. Working on Mac/Linux.
#
There are additional commands for make

* `make clean` // clean all .o files
* `make fclean` // clean push_swap, libft.a, all .o and .d files
