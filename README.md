## Longest_compounded_word
Impledge Technologies Interview Coding Test 


The problem statement can be found in the [Exercise_Fresher_Word_Problem.pdf](https://github.com/jahnavitiwari789/Longest_compounded_word/blob/main/Exercise_Fresher_Word_Problem.pdf) flie.


## Code Execution Procedure
**Requires VS Code editor with MinGW compiler or newer to be Installed**

 1. Download / Clone the repo into the machine.
 2. Open the `main.cpp` file and scroll to the code segment with the comment 
 3. Execute the file `main.cpp`.

## A brief study of the problem

 - Compounded words are the words formed using one or more of the valid words only in the selected file. 
 - Since the files are already sorted alphabetically and only contain one word per line some of the the valid words that compose the compounded words are bound to come before the compounded word itself.
 - Thus the compounded word can be thought of as the combination of some of the the words that have been already read i.e. -> prefix, and a suffix.
 - If there is a situation where some character which is not the part of any valid word in the file but occours within any position of the word currently being read. Then the word can not be considered as a compounded word.

   ## Approach and Algorithm

TRIE BASED APPROACH--

The algorithm for the solution :
> Step 1. Build the trie by reading every word one by one from the selected file.
> 
>  Step 2. While building the trie also build a dequeue which contains `<word,suffix>` pairs if any w.r.t the previously existing valid words in the trie.
>  
> Step 3. Initialize the `longest`, `second_longest` variables.
>
> Step 4. Repeat untill the queue is empty, POP the `<word,suffix>` pairs from the dequeue.
> 
> > i) Check if the suffix of the word contains any valid word i.e. `prefix` from the trie and if `length (word) > max_length` , set 
> `second_longest = longest` , 
> `longest = word`.
> 
> >ii) Else get all the prefixes of the current suffix of the word , and find the new suffixes w.r.t each and every prefix length. Append the new `<word,suffix>` pairs into the deque. 
> 
> Step 5. Return the longest and second_longest words



## Results:

**Machine Specifications**
>
> OS: Windows 10 
>
> CPU: Intel i5 10 GEN
>
> RAM: 8 GB
>

1) Output  for File: Input_01.txt


![Output  for File: Input_01.txt](/Output_01.jpg)

2) Output  for File: Input_02.txt


![Output  for File: Input_02.txt](/Output_02.jpg)
