# Number Sorter
This is a simple program that recieves input from the Command Line Arguments, then places all of these arguments inside both a linked list and inside and array.
After placing them into these different data structures, the program then sorts the numbers using a few sorting algorithms.


### Algorithms

The sorting algorithms used in this program were:
- Bogo Sort aka Dumb Sort.
- Bubble Sort.
- Insertion Sort.
- Quick Sort.
- Radix Sort - Base 10.
- Radix Sort - Base 2.
- Selection Sort.
- Tree Sort.

The first algorithm, Bogo Sort, is only used as a baseline, this algorithm will forcefully quit after attempting to sort the list around 80000 times.
The following ones are the ones that matter, some of them have no difference in the ammount of steps from Linked List to Arrays, some of them are equal for both data structutes, this is algorithm dependent and not data structure dependent.

# Using
1. Download the repository: `git clone https://github.com/Filz0r/number_sort.git`
2. Compile the program using Make: `make all` or `make re`
3. Run the compiled binary with a set of arguments: `./num_sort 10 3 230 12 41 232` or `./num_sort $(cat ./tests/5.txt)`
4. Check results.

## NOTES:
1. You can check if the data structures are actually sorted by editing the `includes/c_lists.h` and update the `PRINT_LISTS` and `PRINT_ARRAYS` macros from 0 to 1.
2. The output will not be sorted for easy readability, I might change this in the future if people ask for better readability of the data.
3. This program was created as a study method, it shouldn't be used for production environments or something like that.
4. You can use the some of the files in the tests folder to check how the program works for different sizes of inputs (I don't recommend printing the outputs when using more than 100 numbers)  
