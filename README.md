![Pager](http://forhadahmed.net/github/pager-example.png)

###### pager.h

Simple pager for large output in CLI/text-based programs (C/C++).  Some programs which dump large amounts of text onto the console (such as `man ...` or `git log`) *automatically* page output (using `more` or `less`) without the user having to pipe the output

By including `pager.h`, programs can achieve the same behavior by placing the `BEGIN_PAGER` and `END_PAGER` macros around a piece of code that will print a large amount of text to `stdout`


###### 

Take an example program that prints 1000 lines of text.  

![No pager example](http://forhadahmed.net/github/no-pager-code.png)

Program output on a terminal.  Without paging, the user would easily miss most of the text lines since no terminal is ever 1000 lines high:

![No pager output](http://forhadahmed.net/github/no-pager-output.png)



###### Fork

The macros basically create a pipe between the running/parent program and a `fork()`-ed child program (`more` or `less`) and redirect the parent's `stdout` to the child.  
