# Certified Associate of Python Programming
## Contents

\#    | Links
:---  | :---
0     | 
0.1   | 
1     | 
2     | 
3     | 
4     | 
5     | 



## 0 Introduction
### 0.1.1 How does a computer program work?
This course aims to show you what the Python language is and what it is used for. Let’s start from the absolute basics.\
A program makes a computer usable. Without a program, a computer, even the most powerful one, is nothing more than an object. Similarly, without a player, a piano is nothing more than a wooden box.\ 
Computers are able to perform very complex tasks, but this ability is not innate. A computer’s nature is quite different.\
It can execute only extremely simple operations, e.g., a computer cannot evaluate the value of a complicated mathematical function by itself, although this isn’t beyond the realms of possibility in the near future.\
Contemporary computers can only evaluate the results of very fundamental operations, like adding or dividing, but they can do it very fast, and can repeat these actions virtually any number of times.\
Imagine that you want to know the average speed you’ve reached during a long journey. You know the distance, you know the time, you need the speed.\
Naturally, the computer will be able to compute this, but the computer is not aware of such things as distance, speed or time.\
Therefore, it is necessary to instruct the computer to:
- **accept a number** representing the distance;
- **accept a number** representing the travel time;
- **divide the former value by the latter and store** the result in the memory;
- **display the result** (representing the average speed) in a readable format.

These four simple actions form a program. Of course, these examples are not formalized, and they are very far from what the computer can understand, but they are good enough to be translated into a language the computer can accept.\ 
Language is the keyword. 

### 0.1.2 Natural languages vs. programming languages
A **language** is a means (and a tool) for expressing and recording thoughts. There are many languages all around us. Some of them require neither speaking nor writing, such as body language; it’s possible to express your deepest feelings very precisely without saying a word.\ 
Another language you use each day is your mother tongue, which you use to manifest your will and to think about reality. Computers have their own language, too, called machine language, which is very rudimentary.\
A computer, even the most technically sophisticated, is devoid of even a trace of intelligence. You could say that it is like a well-trained dog – it responds only to a predetermined set of known commands.\ 
The commands it recognizes are very simple. We can imagine that the computer responds to orders like “take that number, divide by another and save the result”.\
A complete set of known commands is called an instruction list, sometimes abbreviated to IL. Different types of computers may vary depending on the size of their ILs, and the instructions could be completely different in different models.\ 
Note: machine languages are developed by humans.\ 
No computer is currently capable of creating a new language. However, that may change soon.\
On the other hand, people use a number of very different languages, too, but these languages created themselves. Moreover, they are still evolving.\
New words are created every day and old words disappear. These languages are called natural languages.\
What makes a language?\
We can say that each language (machine or natural, it doesn’t matter) consists of the following elements:
- **an alphabet**: a set of symbols used to build words of a certain language (e.g., the Latin alphabet for English, the Cyrillic alphabet for Russian, Kanji for Japanese, and so on) 
- **a lexis** aka a **dictionary**: a set of words the language offers its users (e.g., the word “computer” comes from the English language dictionary, while “cmoptrue” doesn’t; the word “chat” is present both in English and French dictionaries, but their meanings are different)
- **a syntax**: a set of rules (formal or informal, written or felt intuitively) used to determine if a certain string of words forms a valid sentence (e.g., “I am a python” is a syntactically correct phrase, while “I a python am” isn’t)
- **semantics**: a set of rules determining if a certain phrase makes sense (e.g., “I ate a doughnut” makes sense, but “A doughnut ate me” doesn’t)

The IL is, in fact, the alphabet of a machine language. This is the simplest and most primary set of symbols we can use to give commands to a computer. It’s the computer’s mother tongue.\ 
Unfortunately, this tongue is a far cry from a human mother tongue. We all (both computers and humans) need something else, a **common language** for computers and humans, or a **bridge between the two different worlds**.\ 
We need a language in which humans can write their programs and a language that computers may use to execute the programs, one that is far more complex than machine language and yet far simpler than natural language.\ 
Such languages are often called **high-level programming languages**. They are at least somewhat similar to natural ones in that they use symbols, words and conventions readable to humans. These languages enable humans to express commands to computers that are much more complex than those offered by ILs.\
A program written in a high-level programming language is called a source code (in contrast to the machine code executed by computers).\
Similarly, the file containing the source code is called the source file.

### 0.1.3 Compilation vs. interpretation
Computer programming is the act of composing the selected programming language’s elements in the order that will cause the desired effect. The effect could be different in every specific case – it’s up to the programmer’s imagination, knowledge and experience.\
Of course, such a composition has to be correct in many senses:
- alphabetically – a program needs to be written in a recognizable script, such as Roman, Cyrillic, etc.  
- lexically – each programming language has its dictionary and you need to master it; thankfully, it’s much simpler and smaller than the dictionary of any natural language; 
- syntactically – each language has its rules and they must be obeyed; 
- semantically – the program has to make sense.

Unfortunately, a programmer can also make mistakes with each of the above four senses. Each of them can cause the program to become completely useless.\ 
Let’s assume that you’ve successfully written a program. How do we persuade the computer to execute it? You have to render your program into machine language.\
Luckily, the translation can be done by a computer itself, making the whole process fast and efficient.\
There are two different ways of transforming a program from a high-level programming language into machine language:
- **compilation** – the source program is translated once (however, this act must be repeated each time you modify the source code) by getting a file (e.g., an .exe file if the code is intended to be run under MS Windows) containing the machine code; now you can distribute the file worldwide; the program that performs this translation is called a compiler or translator;
- **interpretation** – you (or any user of the code) can translate the source program each time it has to be run; the program performing this kind of transformation is called an interpreter, as it interprets the code every time it is intended to be executed; it also means that you cannot just distribute the source code as-is, because the end-user also needs the interpreter to execute it.

Due to some very fundamental reasons, a particular high-level programming language is designed to fall into one of these two categories.\
There are very few languages that can be both compiled and interpreted. Usually, a programming language is projected with this factor in its constructors’ minds – will it be compiled or interpreted?

### 0.1.4 Compilation vs. interpretation
What does the interpreter actually do?\
Let’s assume once more that you have written a program. Now, it exists as a computer file: a computer program is actually a piece of text, so the source code is usually placed in text files. Note: it has to be pure text, without any decorations like different fonts, colors, embedded images or other media.\
Now you have to invoke the interpreter and let it read your source file.\
The interpreter reads the source code in a way that is common in Western culture: from top to bottom and from left to right. There are some exceptions – they’ll be covered later in the course.
First of all, the interpreter checks if all subsequent lines are correct (using the four aspects covered earlier). If the compiler finds an error, it finishes its work immediately. The only result in this case is an error message. The interpreter will inform you where the error is located and what caused it. However, these messages may be misleading, as the interpreter isn’t able to follow your exact intentions, and may detect errors at some distance from their real causes.\
For example, if you try to use an entity of an unknown name, it will cause an error, but the error will be discovered in the place where it tries to use the entity, not where the new entity’s name was introduced. In other words, the actual reason is usually located a little earlier in the code, e.g., in the place where you had to inform the interpreter that you were going to use the entity of the name.\
If the line looks good, the interpreter tries to execute it (note: each line is usually executed separately, so the trio “read-check-execute” can be repeated many times – more times than the actual number of lines in the source file, as some parts of the code may be executed more than once).\
It is also possible that a significant part of the code may be executed successfully before the interpreter finds an error. This is normal behavior in this execution model.\

### 0.1.5 Compilation vs. interpretation
You may ask now: which is better? The “compiling” model or the “interpreting” model?
There is no obvious answer. If there had been, one of these models would have ceased to exist a long time ago. Both of them have their advantages and their disadvantages.
Here is a list of the main ones →
\- | Compilation  | Interpretation
:--- | :--- | :---
Advantages | <ul><li>execution of the translated code is usually faster</li><li>only the user has to have the compiler - the end-user may use the code without it</li><li>translated code is stored using machine language - as it is hard to understand it, your own inventions and programming tricks are likely to remain your secret</li></ul> | <ul><li>you can run the code as soon as you complete it - there are no additional phases of translation</li><li>the code is stored using programming language, not the machine one - this means that it can be run on computers using different machine language: you don't compile your code separately for each different architecture</li></ul>
Disadvantages | <ul><li>the compilation itself may be a very time-consuming process - you may not be able to run your code immediately after any amendment</li><li>you have to have as many compilers as hardware platforms you want your code to be run on</li></ul> | <ul><li>don't expect that interpretation will ramp your code to high speed - your code will share the computer's power with the interpreter, so it can't be really fast</li><li>both you and the end user have to have the interpreter to run your code</li></ul>

What does this all mean for you?
1. Python is an interpreted language. This means that it inherits all the described advantages and disadvantages. Of course, it adds some of its unique features to both sets.
2. If you want to program in Python, you’ll need the Python interpreter. You won’t be able to run your code without it. Fortunately, Python is free. This is one of its most important advantages.

Due to historical reasons, languages designed to be utilized in the interpretation manner are often called scripting languages, while the source programs encoded using them are called scripts.

## 1 Basics: Part 1
### 1.1.1 Your very first program
It’s time to start writing some real, working Python code. It’ll be very simple for the time being.\
As we’re going to show you some fundamental concepts and terms, these snippets of code won’t be serious or complex.\
Launch IDLE, create a new Python source file, fill it with this code, name the file and save it.\
```py
print("Pussy cat, pussy cat where have you been?")
```
Now run it. If everything goes okay, you’ll see the rhyme’s line in the IDLE console window.\
Alternatively, launch Edube Sandbox, enter the code in the editor window, and run it.\
If everything goes okay here, you'll see the line of text in the Edube console window.\
The code you have run should look familiar. You saw something very similar when we led you through the setting up of the IDLE environment.\ 
Now we’ll spend some time showing you what you’re actually seeing, and why it looks like this.  
As you can see, the first program consists of the following parts:
- the word print;
- an opening parenthesis;
- a quotation mark;
- a line taken from a classic nursery rhyme;
- another quotation mark;
- a closing parenthesis.

Each of the above plays a very important role in the code.

### 1.1.2 The `print()` function
The word print that you can see here is a function name. That doesn’t mean that wherever the word appears it is always a function name. The meaning of the word comes from the context in which the word has been used.\ 
You’ve probably encountered the term function many times before, during math classes. You can probably also list several names of mathematical functions, like sine or log.\
Python’s functions, however, are more flexible, and can contain more content than their mathematical siblings.\
A function (in this context) is a separate part of the computer code,able to:
- **cause some effect** (e.g., send text to the terminal, create a file, draw an image, play a sound, etc.); this is something completely unheard of in the world of mathematics;
- **evaluate a value or some values** (e.g., the square root of a value or the length of a given text); this is what makes Python’s functions the relatives of mathematical concepts.

Moreover, many of Python’s functions can do the above two things together.\
Where do the functions come from?
- They may come from Python itself; the print function is one of this kind; such a function is an added value received together with Python and its environment (it is built-in); you don’t have to do anything special (e.g., ask anyone for anything) if you want to make use of it;
- they may come from one or more of Python’s add-ons named modules; some of the modules come with Python, others may require separate installation – whatever the case, they all need to be explicitly connected with your code (we’ll show you how to do that soon);
- you can write them yourself, placing as many functions as you want and need inside your program to make it simpler, clearer and more elegant.

The name of the function should be significant (the name of the print function is self-evident).\
Of course, if you’re going to make use of any already existing function, you have no influence on its name, but when you start writing your own functions, you should consider carefully your choice of names.

### 1.1.3 The `print()` function
As we said before, a function may have:
- an effect;
- a result.

There’s also a third, very important, function component – the arguments.\
Mathematical functions usually take one argument, e.g., sin(x) takes an x, which is the measure of an angle.\
Python functions, on the other hand, are more versatile. Depending on the individual needs, they may accept any number of arguments – as many as necessary to perform their tasks. Note: any number includes zero – some Python functions don’t need any argument.\
In spite of the number of needed/provided arguments, Python functions strongly demand the presence of a pair of parentheses – opening and closing ones, respectively.\
If you want to deliver one or more arguments to a function, you place them inside the parentheses. If you’re going to use a function which doesn’t take any argument, you still have to have the parentheses.\
Note: to distinguish ordinary words from function names, place a pair of empty parentheses after their names, even if the corresponding function wants one or more arguments. This is a standard convention.\
The function we’re talking about here is `print()`.\
Does the `print()` function in this example have any arguments? Of course it does, but what are they?

### 1.1.4 The `print()` function
The only argument delivered to the `print()` function in this example is a string.\
As you can see, the string is delimited with quotes – in fact, the quotes make the string – they cut out a part of the code and assign a different meaning to it.\
You can imagine that the quotes say something like: the text between us is not code. It isn’t intended to be executed, and you should take it as is.\
Almost anything you put inside the quotes will be taken literally, not as code, but as data. Try to play with this particular string – modify it, enter some new content, delete some of the existing content.\
There’s more than one way to specify a string inside Python’s code, but for now, though, this one is enough.\
So far, you have learned about two important parts of the code: the function and the string. We’ve talked about them in terms of syntax, but now it’s time to discuss them in terms of semantics.\

### 1.1.5 The `print()` function
The function name (print in this case) along with the parentheses and argument(s), forms the function invocation. We’ll discuss this in more depth soon, but we should just shed a little light on it right now.\
What happens when Python encounters an invocation like this one?
- First, Python checks if the name specified is legal (it browses its internal data in order to find an existing function of the name; if this search fails, Python aborts the code);
- second, Python checks if the function’s requirements for the number of arguments allows you to invoke the function in this way (e.g., if a specific function demands exactly two arguments, any invocation delivering only one argument will be considered erroneous, and will abort the code’s execution);
- third, Python leaves your code for a moment and jumps into the function you want to invoke; of course, it takes your argument(s) too and passes it/them to the function;
- fourth, the function executes its code, causes the desired effect (if any), evaluates the desired result(s) (if any) and finishes its task;
- finally, Python returns to your code (to the place just after the invocation) and resumes its execution.

### 1.1.6 The `print()` function
Three important questions have to be answered as soon as possible:
1. What is the effect the `print()` function causes?
The effect is very useful and very spectacular. The function takes its arguments (it may accept more than one argument and may also accept less than one argument) converts them into human-readable form if needed (as you may suspect, strings don’t require this action, as the string is already readable) and send the resulting data to the output device (usually the console); in other words, anything you put into the `print()` function will appear on your screen. No wonder then, that from now on, you’ll utilize `print()` very intensively to see the results of your operations and evaluations.
2. What arguments does `print()` expect? 
Any. We’ll show you soon that `print()` is able to operate with virtually all types of data offered by Python. Strings, numbers, characters, logical values, objects – any of these may be successfully passed to `print()`.
3. What value does the `print()` function evaluate?

None. Its effect is enough. `print()` does not evaluate anything.

### 1.1.7 The `print()` function
You already know that this program contains one function invocation. In turn, the function invocation is one of the possible kinds of Python instruction. Ergo, this program consists of just one instruction.\ 
Of course, any complex program usually contains many more instructions than one. The question is: how do you couple more than one instruction into the Python code?\
Python’s syntax is quite specific in this area. Unlike most programming languages, Python requires that there cannot be more than one instruction in a line.\
A line can be empty (i.e., it may contain no instruction at all) but it must not contain two, three or more instructions. This is strictly prohibited.\
Note: Python makes one exception to this rule – it allows one instruction to spread across more than one line (which may be helpful when your code contains complex constructions).\
Let’s expand the code a bit. This is how it looks now →
```py
print("Pussy cat, pussy cat where have you been?")
print("I've been to London to look at the queen.")
```
Run it and note what you see in the console. 

### 1.1.8 The `print()` function
Your Python console should now look like this →
```
Pussy cat, pussy cat where have you been?
I've been to London to look at the queen. 
```
This is a good opportunity to make some observations:
- the program invokes the `print()` function twice, and you can see two separate lines in the console – this means that `print()` begins its output from a new line each time it starts its execution; you can change this behavior, but you can also use it to your advantage;
- each `print()` invocation contains a different string, as its argument and the console content reflects it – this means that the instructions in the code are executed in the same order in which they have been placed in the source file; no next instruction is executed until the previous one is completed (there are some exceptions to this rule, but you can ignore them for now)

### 1.1.9 The `print()` function
We’ve changed the example a bit – we’ve added one empty `print()` function invocation. We call it empty because we haven’t delivered any arguments to the function →
```py
print("Pussy cat, pussy cat where have you been?")
print()
print("I've been to London to look at the queen.")
```
Follow the example and make the same amendment in your editor window (don’t forget about the parentheses).\ 
Run it.\ 
What happens?

### 1.1.10 The `print()` function
If everything goes right, you should see something like this →
```
Pussy cat, pussy cat where have you been?

I've been to London to look at the queen. 
```
As you can see, the empty `print()` invocation is not as empty as you may have expected – it does output an empty line, or (this interpretation is also correct) its output is just a newline.\ 
This is not the only way to produce a newline in the output console. We’re now going to show you another way.

### 1.1.11 The `print()` function
We’ve modified the code again. Look at it carefully →
```py
print("Pussy cat, pussy cat where have you been?")
print()
print("I've been to London to look at the queen.")
```
There are two very subtle changes – we’ve inserted a strange pair of characters inside the rhyme. They look like this:
```
\n
```
Interestingly, while you can see two characters, Python sees one.\ 
The backslash (\) has a very special meaning when used inside strings – this is called the escape character.\
The word escape should be understood specifically – it means that the series of characters in the string escapes for the moment (a very short moment) to introduce a special inclusion.\
In other words, the backslash doesn’t mean anything in itself, but is only a kind of announcement, that the next character after the backslash has a different meaning too.\The letter n placed after the backslash comes from the word newline.\
Both the backslash and the n form a special symbol named a newline character, which urges the console to start a new output line.\
This convention has two important consequences:
1. if you want to put just one backslash inside a string, don’t forget its escaping nature – you have to double it, e.g., such an invocation will cause an error:
```py
print("\")
```
while this one won’t:
```py
print("\\")
```
2. not all escape pairs (the backslash coupled with another character) mean something.

Run the code. 

### 1.1.13 The print() function
This is what we’re going to test now →
```py
print("Pussy cat,"," pussy cat, ","where have you been?")
```
There is one print() function invocation, but it contains three arguments. All of them are strings.\
The arguments are separated by commas. We’ve surrounded them with spaces to make them more visible, but it’s not really necessary, and we won’t be doing it anymore.\
In this case, the commas separating the arguments play a completely different role than the comma inside the string. The former is a part of Python’s syntax, the latter is intended to be shown in the console.\
If you look at the code again, you’ll see that there are no spaces inside the strings.\ 
Run the code and see what happens.
 
### 1.1.14 The print() function 
Your console should now be showing the following text →
```
Pussy cat, pussy cat where have you been?
```
The spaces, removed from the strings, have appeared again.\
Can you explain why?\
Two conclusions emerge from this example:
- a print() function invoked with more than one argument outputs them all on one line;
- the print() function puts a space between the outputted arguments on its own initiative.

### 1.1.14 The print() function 
Your console should now be showing the following text →
```
Pussy cat, pussy cat where have you been?
```
The spaces, removed from the strings, have appeared again.\
Can you explain why?\
Two conclusions emerge from this example:
- a print() function invoked with more than one argument outputs them all on one line;
- the print() function puts a space between the outputted arguments on its own initiative.

### 1.1.15 The print() function
Now that you know a bit about print() function customs, we’re going to show you how to change them.\
You should be able to predict this output without running the code.\
The way in which we are passing the arguments into the print() function is the most common in Python, and is called the positional way (this name comes from the fact that the meaning of the argument is dictated by its position, e.g., the second argument will be outputted after the first, not the other way round).\
Python offers another mechanism for the passing of arguments, which can be helpful when you want to convince the print() function to change its behavior a bit.\
We aren’t going to explain it in depth right now. We plan to do this when we talk about functions. For now, we simply want to show you how it works. Feel free to use it in your own programs.\
The mechanism is called keyword arguments. The name stems from the fact that the meaning of these arguments is taken not from its location (position) but from the special word (keyword) used to identify them.\
The print() function has two keyword arguments that you can use for your purposes. The first of them is named end.\

### 1.1.16 The print() function
To the side, you can see a very simple example of using a keyword argument →
```py
print("My name is","Python",end=" ")
print("Monty Python")
```
In order to use it, it is necessary to know some rules:
- a keyword argument consists of three elements: a keyword identifying the argument (end here); an equal sign (=); and a value assigned to that argument;
- any keyword arguments have to be put after the last positional argument (this is very important)

In our example, we have made use of the end keyword argument, and set it to a string containing one space.\
Run the code to see how it works.

### 1.1.17 The print() function
The output looks as follows now →
```
My name is Python Monty Python
```
As you can see, the end keyword argument determines the characters the print() function sends to the output once it reaches the end of its positional arguments.\ 
The default behavior reflects the situation where the end keyword argument is implicitly used in the following way:
```
end="\n"
```
And now it’s time to try something more difficult.

### 1.1.18 The print() function
If you look carefully, you’ll see that we’ve used the end argument, but the string assigned to is empty (it contains no characters at all) →
```py
print("My name is ",end="")
print("Monty Python")
```
What will happen now?\
Run the program to find out.

### 1.1.19 The print() function
As the end argument has been set to nothing, the print() function outputs nothing too, once its positional arguments have been exhausted.\
The output looks like this →
```
My name is Monty Python
```
Note: no newlines have been sent to the output.\
The string assigned to the end keyword argument can be of any length. Experiment with it if you want.

### 1.1.20 The print() function
We’ve said previously that the print() function separates its outputted arguments with spaces. This behavior can be changed, too.  \
The keyword argument that can do this is named sep (like separator).  \
Look at the example →
```py
print("My","name","is","Monty","Python",sep="-")
```
 
### 1.1.21 The print() function
The sep argument delivers the following results →
```
My-name-is-Monty-Python
```
The print() function uses a dash, instead of a space, to separate the outputted arguments.\
Note: the sep argument’s value may be an empty string, too. Try it for yourself.

### 1.1.22 The print() function
Both keyword arguments may be mixed in one invocation, just like here →
```py
print("My","name","is",sep="_",end="*")
print("Monty","Python",sep="*",end="*\n")
```
The example doesn’t make much sense, but it visibly presents the interactions between `end` and `sep`.\
Can you predict the output?
 
### 1.1.23 The print() function
This is how it looks now →
```
My_name_is*Monty*Python*
```
Now that you understand the print() function, you’re ready to consider how to store and process data in Python.

Without print(), you wouldn’t be able to see any results.

### 1.2.1 Literals – the data in itself
Now that you have a little knowledge of some of the powerful features offered by the print() function, it’s time to learn about some new issues, and one important new term – the literal.\
A literal is data whose values are determined by the literal itself.\
As this is a difficult concept to understand, a good example may be helpful.\
Take a look at the following set of digits:\
```
123
```
Can you guess what value it represents? Of course you can – it’s one hundred twenty three.\
But what about this:
```
c
```
Does it represent any value? Maybe. It can be the symbol of the speed of light, for example. It also can be the constant of integration. Or even the length of a hypotenuse in the sense of a Pythagorean theorem. There are many possibilities.\
You cannot choose the right one without some additional knowledge.\
And this is the clue – 123 is a literal, and c is not.\
You use literals to encode data and to put them into your code. We’re now going to show you some conventions you have to obey when using Python.\
Let’s start with a simple experiment – take a look at the snippet →\
```py
print("2")
print(2) 
```
The first line looks familiar. The second seems to be erroneous due to the visible lack of quotes.\
Try to run it.

### 1.2.2 Literals – the data in itself
If everything went okay, you should now see two identical lines.
```
2
2
```
What happened? What does it mean?
Through this example, you encounter two different types of literals – a string, which you already know, and an integer number, something completely new.\
The print() function presents them in exactly the same way – this example is obvious, as their human-readable representation is also the same. Internally, in the computer’s memory, these two values are stored in completely different ways – the string exists as just a string – a series of letters.\
The number is converted into machine representation (a set of bits). The print() function is able to show them both in a form readable to humans.\
We’re now going to be spending some time discussing numeric literals and their internal life.\

### 1.2.3. Literals – integers
You may already know a little about how computers perform calculations on numbers. Perhaps you’ve heard of the binary system, and know that it’s the system computers use for storing numbers, and that they can perform any operation upon them.\
We won’t explore the intricacies of positional numeral systems here, but we’ll say that the numbers handled by modern computers are of two types:\
- integers, that is, those which are devoid of the fractional part;
- and floating-point numbers (or simply floats), that contain (or are able to contain) the fractional part.
This definition is not entirely accurate, but quite sufficient for now. The distinction is very important, and the boundary between these two types of numbers is very strict. Both of these kinds of numbers differ significantly in how they’re stored in a computer memory and in the range of acceptable values.\
The characteristic of the numeric value which determines its kind, range, and application, is called the type.\
If you encode a literal and place it inside Python code, the form of the literal determines the representation (type) Python will use to store it in the memory.\
For now, let’s leave the floating-point numbers aside (we’ll come back to them soon) and consider the question of how Python recognizes integers.\
The process is almost like how you would write them with a pencil on paper – it’s simply a string of digits that make up the number. But there’s a reservation – you must not interject any characters that are not digits inside the number.\
Take, for example, the number eleven million one hundred and eleven thousand one hundred and eleven. If you took a pencil in your hand right now, you would write the number like this:\
```
11,111,111
```
or like this:
```
11.111.111
```
or even like this:
```
11 111 111
```
It’s clear that this provision makes it easier to read, especially when the number consists of many digits. However, Python doesn’t accept things like these. It’s prohibited. What Python does allow, though, is the use of underscores in numeric literals.\
Therefore, you can write this number as follows →
```
11111111
11_111_111
```

### 1.2.4 Literals – integers
How do we code negative numbers in Python? As usual – by adding a minus. You can write →
```
-11111111
```

### 1.2.5 Literals – integers
Positive numbers do not need to be preceded by the plus sign, but it’s permissible, if you wish to do it.\
The following lines describe the same number →
```
+11111111
11111111
```
 
### 1.2.6 Literals – integers
There are two additional conventions in Python that are unknown to the world of mathematics. The first allows us to use numbers in an octal representation.\
If an integer number is preceded by an 0O or 0o prefix (zero-o), it will be treated as an octal value. This means that the number must contain digits taken from the [0..7] range only.\
`0o123` is an octal number with a (decimal) value equal to 83.\
The print() function does the conversion automatically – try this →
```
print(0o123)
```

### 1.2.7 Literals – integers
The second allows us to use hexadecimal numbers. Such numbers should be preceded by the prefix 0x or 0X (zero-x).\
0x123 is a hexadecimal number with a (decimal) value equal to 291. The print() function can manage these values too →\
```py
print(0x123)
```

### 1.2.8 Literals – floats
Now it’s time to talk about another type, which is designed to represent and to store the numbers that (as a mathematician would say) have a non-empty decimal fraction.\
They are the numbers that have (or may have) a fractional part after the decimal point, and although such a definition is very poor, it’s certainly sufficient for what we wish to discuss.\
Whenever we use a term like two and a half or minus zero point four, we think of numbers which the computer considers floating numbers →\
```
2.5
0.4
```

### 1.2.9 Literals – floats
Note: two and a half looks normal when you write it in a program, although if your native language prefers to use a comma instead of a point in the number, you should ensure that your number doesn’t contain any commas at all.\
Python will not accept that, or (in very rare but possible cases) may misunderstand your intentions, as the comma itself has its own reserved meaning in Python.\
If you want to use just a value of two and a half, you should write it as shown to the side. Note once again – there is a point between 2 and 5 – not a comma.\
```
2.5
```

### 1.2.10 Literals – floats
As you can probably imagine, the value of zero point four could be written in Python as 0.4\
But don’t forget this simple rule – you can omit zero when it is the only digit in front of or after the decimal point.\
In essence, you can write the value 0.4 as →\
```
.4
```
 
### 1.2.11 Literals – floats
For example: the value of 4.0 could be written as →
```
4.
```
This will change neither its type nor its value.\
Note: the decimal point is essentially important in recognizing floating-point numbers in Python.\
Look at these two numbers:\
```
4
4.0
```
You may think that they are exactly the same, but Python sees them in a completely different way.
- 4 is an integer number
- 4.0 is a floating-point number

The point is what makes a float.

### 1.2.12 Literals – floats
But it’s not only points that make a float. You can also use the letter e.\
When you want to use any numbers that are very large or very small, you can use scientific notation.\
Take, for example, the speed of light, expressed in meters per second. Written directly it would look like this:\
```
300000000
```
To avoid writing out so many zeros, physics textbooks use an abbreviated form, which you have probably already seen:
```
3 × 108
```
It reads: three times ten to the power of eight\
In Python, the same effect is achieved in a slightly different way – take a look:
```
3E8
```
The letter E (you can also use the lower-case letter e – it comes from the word exponent) is a concise record of the phrase times ten to the power of.\
Note:
- the exponent (the value after the E) has to be an integer;
- the base (the value in front of the E) may be an integer.

### 1.2.13 Literals – floats
Let’s see how this convention is used to record numbers that are very small (in the sense of their absolute value, which is close to zero).\
A physical constant called Planck’s constant (and denoted as h), according to the textbooks, has the value of\
```
6.62607 × 10−34
```
If you would like to use it in a program, you should write it this way →
```py
6.62607E-34
```
 
### 1.2.14 Literals – floats
Note: the fact that you’ve chosen one of the possible forms of coding float values doesn’t mean that Python will present it the same way.\
Python may sometimes choose different notation than you.\
For example, let’s say you’ve decided to use the following float literal:
```
0.0000000000000000000001
```
When you run this literal through Python:
```py
print(0.0000000000000000000001)
```
this is the result →
```
1e-22
```
Python always chooses the more economical form of the number’s presentation, and you should take this into consideration when creating literals.

### 1.2.15 Literals – strings
Strings are used when you need to process text (like names of all kinds, addresses, novels, etc.), not numbers.\
You already know a bit about them, e.g., that strings need quotes the way floats need points.\
This is a very typical string →\
```
"I am a string"
```

### 1.2.16 Literals – strings
However, there is a catch.\
The catch is how to encode a quote inside a string which is already delimited by quotes.\
Let’s assume that we want to print a very simple message saying →\
```
I like "Monty Python"
```
How do we do it without generating an error?

### 1.2.17 Literals – strings
There are two possible solutions.\
The first is based on the concept we already know of the escape character, which you should remember is played by the backslash.\
The backslash can escape quotes too. A quote preceded by a backslash changes its meaning – it’s not a delimiter, but just a quote.\
This will work as intended →
```py
print("I like \"Monty Python\"")
```
Note: there are two escaped quotes inside the string – can you see them both?

### 1.2.18 Literals – strings
The second solution may be a bit surprising.\
Python can use an apostrophe instead of a quote. Either of these characters may delimit strings, but you must be consistent.\
If you open a string with a quote, you have to close it with a quote.\
If you start a string with an apostrophe, you have to end it with an apostrophe.\
This example will work too →
```py
print('I like "Monty Python"')
```
Note: you don’t need to do any escaping here.

### 1.2.19 Literals – strings
Now, the next question is how do you embed an apostrophe into a string placed between apostrophes?\
You should already know the answer, or to be precise, two possible answers.\
Try to write a string containing the following message:\
```
I'm Monty Python
```

### 1.2.20 Literals – strings
Here are the answers →
```py
print('I\'m Monty Python')
print("I'm Monty Python")
```
As you can see, the backslash is a very powerful tool – it can escape not only quotes, but also apostrophes.

### 1.2.21 Literals – strings
We’ve shown it already, but we want to emphasize this phenomenon once more – a string can be empty – it may contain no characters at all.\
An empty string still remains a string.
```py
''
""
```
 
### 1.2.22 Literals – Boolean values
To conclude with Python’s literals, there are two additional ones.\
They’re not as obvious as any of the previous ones, as they’re used to represent a very abstract value – truthfulness.\
Each time you ask Python if one number is greater than another, the question results in the creation of some specific data – a Boolean value.\
The name comes from George Boole (1815–1864), the author of the fundamental work, The Laws of Thought, which contains the definition of Boolean algebra – a part of algebra which makes use of only two distinct values: true and false, denoted as 1 and 0.\
A programmer writes a program, and the program asks questions. Python executes the program, and provides the answers. The program must be able to react according to the received answers.\
Fortunately, computers know only two kinds of answers: yes, this is true or no, this is false. You’ll never get a response like I don’t know or probably yes, but I don’t know for sure.\
Python, then, is a binary reptile.\
These two Boolean values have strict denotations in Python →
```py
True
False
```
You cannot change anything – you have to take these symbols as they are, including case-sensitivity.
 
### 1.3.1 Operators – data manipulation tools
Now, we’re going to show you a completely new side of the print() function. You already know that the function is able to show you the values of the literals passed to it by arguments.\
In fact, it can do something more. Take a look at the snippet →
```py
print(2+2)
```
Start IDLE, create a new source file, copy our example and press the F5 key.\
You should see the number four.\
Without taking this too seriously, you’ve just discovered that Python can be used as a calculator.\
Not a very handy one, and definitely not a pocket one, but a calculator nonetheless.\
Taking it more seriously, we are now entering the province of operators and expressions.

### 1.3.2 Operators – data manipulation tools
An operator is a symbol of the programming language, which is able to operate on the values.\
For example, just as in arithmetic, the + (plus) sign is the operator which is able to add two numbers, giving the result of the addition.\
Not all Python operators are as obvious as the plus sign, though, so let’s go through some of the operators available in Python, and we’ll explain which rules govern their use, and how to interpret the operations they perform.\
We’ll begin with the operators which are associated with the most widely recognizable arithmetic operations.\
The order of their appearance is not accidental. We’ll talk more about it once we’ve gone through them all.\
Data and operators when connected together form expressions. The simplest expression is a literal itself.

### 1.3.3 Arithmetic operators – exponentiation
A `**` (double asterisk) sign is an exponentiation (power) operator.\
Its left argument is the base, its right, the exponent.\
Classical mathematics prefers notation with superscripts, just like this:\
2<sup>3</sup>
Pure text editors don’t accept that, so Python uses ** instead:\
```py
2**3
```
Take a look at our example →
```py
print(2 ** 3)
print(2 ** 3.)
print(2. ** 3)
print(2. ** 3.)
```
Note: we’ve surrounded the double asterisks with spaces in our example.\
It’s not compulsory, but it improves the readability of the code.\
The example shows a very important feature of virtually all Python numerical operators.\
Run the code and look carefully at the results it produces.\
Can you see any regularity here?

### 1.3.4 Arithmetic operators – exponentiation
The results look like this →
```
8
8.0
8.0
8.0
```
It’s possible to formulate the following rules based on this result:
- when both ** arguments are integers, the result is an integer, too;
- when at least one ** argument is a float, the result is a float, too.

This is an important distinction to remember.

### 1.3.5 Arithmetic operators – multiplication
An `*` (asterisk) sign is a multiplication operator.\ 
Run the code and check if our integer vs float rule is still working.
```py
print(2 * 3)
print(2 * 3.)
print(2. * 3)
print(2. * 3.)
```

### 1.3.6 Arithmetic operators – multiplication
```
6
6.0
6.0
6.0
```
Yes, it works.


## 2 Basics: Part 2

## 3 Basics: Part 3

## 4

## 5

### 5.5.1 Inheritance – why and how?
Before we start talking about inheritance, we want to present a new, handy mechanism utilized by Python’s classes and objects – it’s the way in which the object is able to introduce itself.\ 
Let’s start with the following example →
```py
class Star:
  def __init__(self, name, galaxy):
    self.name = name
    self.galaxy = galaxy
sun = Star("Sun","Milky Way")
print(sun)
```
The program prints out just one line of text, which in our case is this:
```
<__main__.Star object at 0x7f1074cc7c50>
```
If you run the same code on your computer, you’ll see something very similar, although the hexadecimal number (the substring starting with 0x) will be different, as it’s just an internal object identifier used by Python, and it’s unlikely that it would appear the same when the same code is run in a different environment. As you can see, the printout here isn’t really useful, and something more specific, or just prettier, may be more preferable.\ 
Fortunately, Python offers just such a function.

### 5.5.2 Inheritance – why and how?
When Python needs any class/object to be presented as a string (putting an object as an argument in the print() function invocation fits this condition) it tries to invoke a method named `__str__()` from the object and to use the string it returns. The default `__str__()` method returns the previous string – ugly and not very informative. You can change it just by defining your own method of the name.\ 
We’ve just done it here →
```py
class Star:
  def __init__(self,name,galaxy):
    self.name = name
    self.galaxy = galaxy
  def __str__(self):
    return self.name + ' in ' + self.galaxy
sun = Star("Sun","Milky Way")
print(sun)
```
This new `__str__()` method makes a string consisting of the star’s and galaxy’s names – nothing special, but the print results look better now:\ 
```
Sun in Milky Way
```

### 5.5.3 Inheritance – why and how?
The term inheritance is older than computer programming, and it describes the common practice of passing different goods from one person to another upon that person’s death. The term, when related to computer programming, has an entirely different meaning.\ 
Let’s define the term for our purposes:\
Inheritance is a common practice (in object programming) of passing attributes and methods from the superclass (defined and existing) to a newly created class, called the subclass.\
In other words, inheritance is a way of building a new class, not from scratch, but by using an already defined repertoire of traits. The new class inherits (and this is the key) all the already existing equipment, but is able to add some new ones if needed. Thanks to that, it’s possible to build more specialized (more concrete) classes using some sets of predefined general rules and behaviors.\ 
The most important factor of the process is the relation between the superclass and all of its subclasses (note: if B is a subclass of A and C is a subclass of B, this also means than C is a subclass of A, as the relationship is fully transitive).

### 5.5.4 Inheritance – why and how?
A very simple example of two-level inheritance is presented here →\
```py
class Vehicle:
  pass
class LandVehicle(Vehicle):
  pass
class TrackedVehicle(LandVehicle):
  pass
```

All the presented classes are empty for now, as we’re going to show you how the mutual relations between the super- and subclasses work. We’ll fill them with contents soon.

We can say that:
- The Vehicle class is the superclass for both the LandVehicle and TrackedVehicle classes;
- The LandVehicle class is a subclass of Vehicle and a superclass of TrackedVehicle at the same time;
- The TrackedVehicle class is a subclass of both the Vehicle and LandVehicle classes.

The above knowledge comes from reading the code (in other words, we know it because we can see it). Does Python know the same? Is it possible to ask it about it? Yes, it is.
### 5.5.5 Inheritance – why and how?

Python offers a function which is able to identify a relationship between two classes, and although its diagnosis isn’t complex, it can check if a particular class is a subclass of any other class.

This is how it looks →
`issubclass(class1,class2)`

The function returns True if class1 is a subclass of class2, and False otherwise.

Let’s see it in action – it may surprise you.
### 5.5.6 Inheritance – why and how?

Read the code carefully →

```py
class Vehicle:
  pass

class LandVehicle(Vehicle):
  pass

class TrackedVehicle(LandVehicle):
  pass

for cl1 in [Vehicle, LandVehicle, TrackedVehicle]:
  for cl2 in [Vehicle, LandVehicle, TrackedVehicle]:
    print(issubclass(cl1,cl2),end='\t')
  print()

```

There are two nested loops. Their purpose is to check all possible ordered pairs of classes, and to print the results of the check to determine whether the pair matches the subclass-superclass relationship.

The program produces the following output:

True  False False True  True  False True  True  True

There is one important observation to make: each class is considered to be a subclass of itself.
### 5.5.7 Inheritance – why and how?

As you already know, an object is an incarnation of a class. This means that the object is like a cake baked using a recipe which is included inside the class.

This can generate some important issues. Let’s assume that you’ve got a cake (e.g., as an argument passed to your function). You want to know what recipe has been used to make it. Why? Because you want to know what to expect from it, e.g., whether it contains nuts or not, which is crucial information to some people.

Similarly, it can be crucial if the object does have (or doesn’t have) certain characteristics. In other words, whether it is an object of a certain class or not.

Such a fact could be detected by the function named isinstance()→
`isinstance(object,class)`

The functions returns True if the object is an instance of the class, or False otherwise.

Being an instance of a class means that the object (the cake) has been prepared using a recipe contained in either the class or one of its superclasses.

Don’t forget: if a subclass contains at least the same equipment as any of its superclasses, it means that objects of the subclass can do the same as objects derived from the superclass, ergo, it’s an instance of its home class and any of its superclasses.

Let’s test it.
### 5.5.8 Inheritance – why and how?

This is the code which tests the function →

```py
class Vehicle:
  pass

class LandVehicle(Vehicle):
  pass

class TrackedVehicle(LandVehicle):
  pass

vehicle = Vehicle()
landvehicle = LandVehicle()
trackedvehicle = TrackedVehicle()

for ob in [vehicle, landvehicle, trackedvehicle]:
  for cl in [Vehicle, LandVehicle, TrackedVehicle]:
    print(isinstance(ob,cl),end='\t')
  print()

```

We’ve created three objects, one for each of the classes. Next, using two nested loops, we check all possible object-class pairs to find out if the objects are instances of the classes.

This is what we get:

True  False False True  True  False True  True  True 
### 5.5.9 Inheritance – why and how?

There is also a Python operator worth mentioning, as it refers directly to objects – here it is →
`object1 is object2`

The operator checks whether two variables (object1 and object2 here) refer to the same object.

Don’t forget that variables don’t store the objects themselves, but only the handles pointing to the internal Python memory. Assigning a value of an object variable to another variable doesn’t copy the object, but only its handle. This is why an operator like is may be very useful in particular circumstances.

### 5.5.10 Inheritance – why and how?

Take a look at the code →

```py
class ThisIsClass:
  def __init__(self,val):
    self.val = val

ob1 = ThisIsClass(0)
ob2 = ThisIsClass(2)
ob3 = ob1
ob3.val += 1
print(ob1 is ob2)
print(ob2 is ob3)
print(ob3 is ob1)
print(ob1.val, ob2.val, ob3.val)

str1 = "Mary had a little "
str2 = "Mary had a little lamb"
str1 += "lamb"
print(str1 == str2, str1 is str2)
```

There is a very simple class equipped with a simple constructor, creating just one property. The class is used to instantiate two objects. The former is then assigned to another variable, and its val property is incremented by one.

Afterward, the is operator is applied three times to check all possible pairs of objects, and all val property values are also printed.

The last part of the code carries out another experiment. After three assignments, both strings contain the same texts, but these texts are stored in different objects.

The code prints:
  False
  False
  True
  1 2 1
  True False

The results prove that ob1 and ob3 are actually the same objects, while str1 and str2 aren’t, despite their contents being the same.
### 5.5.11 How Python finds properties and methods?

Now we’re going to look at how Python deals with inheriting methods.

Take a look at the example →

```py
class Super:
  def __init__(self,name):
    self.name = name
  def __str__(self):
    return "My name is " + self.name + "."

class Sub(Super):
  def __init__(self,name):
    Super.__init__(self,name)

object = Sub("Andy")
print(object)
```

There is a class named Super, which defines its own constructor used to assign the object’s property, named name. The class defines the `__str__()` method, too, which makes the class able to present its identity in clear text form.

The class is next used as a base to create a subclass named Sub. The Sub class defines its own constructor, which invokes the one from the superclass. Note how we’ve done it:

`Super.__init__(self,name)`

We’ve explicitly named the superclass, and pointed to the method to invoke `__init__(),` providing all needed arguments.

We’ve instantiated one object of class Sub and printed it.

The code outputs:

My name is Andy.

Note: As there is no `__str__()` method within the Sub class, the printed string is to be produced within the Super class. This means that the `__str__()` method has been inherited by the Sub class.
### 5.5.12 How Python finds properties and methods?

We’ve modified the code to show you another method of accessing any entity defined inside the superclass. In the last example, we explicitly named the superclass. In this example, we make use of the `super()` function, which accesses the superclass without needing to know its name →

```py
class Super:
  def __init__(self,name):
    self.name = name
  def __str__(self):
    return "My name is " + self.name + "."

class Sub(Super):
  def __init__(self,name):
    super().__init__(name)

object = Sub("Andy")
print(object)
```

The `super()` function creates a context in which you don’t have (moreover, you mustn’t) pass the self argument to the method being invoked – this is why it’s possible to activate the superclass constructor using only one argument.

Note: you can use this mechanism not only to invoke the superclass constructor, but also to get access to any of the resources available inside the superclass.
### 5.5.13 How Python finds properties and methods?

Let’s try to do something similar, but with properties (more precisely: with class variables).

Take a look at the example →

```py
class Super:
  SupVar = 1
class Sub(Super):
  SubVar = 2

object = Sub()
print(object.SubVar)
print(object.SupVar)
```

As you can see, the Super class defines one class variable named SupVar, and the Sub class defines a variable named SubVar. Both these variables are visible inside the object of class Sub – this is why the code outputs:
  2
  1
### 5.5.14 How Python finds properties and methods?

The same effect can be observed with instance variables – take a look →

```py
class Super:
  def __init__(self):
    self.supvar = 11

class Sub(Super):
  def __init__(self):
    super().__init__()
    self.subvar = 12

object = Sub()
print(object.subvar)
print(object.supvar)
```

The Sub class constructor creates an instance variable named subvar, while the Super constructor does the same with a variable named supvar. As previously, both variables are accessible from within the object of class Sub. The program’s output is:
  12
  11

Note: the existence of the supvar variable is obviously conditioned by the Super class constructor invocation. Omitting it would result in the absence of the variable in the created object (try it yourself).
### 5.5.15 How Python finds properties and methods?

It’s now possible to formulate a general statement describing Python’s behavior:

When you try to access any object’s entity, Python will try (in this order)
- to find it inside the object itself;
- to find it in all classes involved in the object’s inheritance line from bottom to top;
- if both of the above fail, an exception (AttributeError) is raised.

The first condition may need some additional attention. As you know, all objects deriving from a particular class may have different sets of attributes, and some of the attributes may be added to the object a long time after the object’s creation.

The example summarizes this in a three-level inheritance line →

```py
class Level0:
  Var0 = 100
  def __init__(self):
    self.var0 = 101
  def fun0(self):
    return 102

class Level1(Level0):
  Var1 = 200
  def __init__(self):
    super().__init__()
    self.var1 = 201
  def fun1(self):
    return 202

class Level2(Level1):
  Var2 = 300
  def __init__(self):
    super().__init__()
    self.var2 = 301
  def fun2(self):
    return 302


object = Level2()
print(object.Var0, object.var0, object.fun0())
print(object.Var1, object.var1, object.fun1())
print(object.Var2, object.var2, object.fun2())

```

All the previous comments referred to single inheritance, when a subclass has exactly one superclass. This is the most common situation (and the recommended one, too) but Python offers more here. Let’s have a look at this.
### 5.5.16 How Python finds properties and methods?

Multiple inheritance occurs when a class has more than one superclass.

Syntactically, such inheritance is presented as a comma-separated list of superclasses put inside parentheses after the new class name – just like here →

```py
class SuperA:
  VarA = 10
  def funa(self):
    return 11

class SuperB:
  VarB = 20
  def funb(self):
    return 21

class Sub(SuperA,SuperB):
  pass

object = Sub()

print(object.VarA, object.funa())
print(object.VarB, object.funb())
```

The Subclass has two superclasses, SuperA and SuperB. This means that the Sub class inherits all the goods offered by both SuperA and SuperB.

The code prints:
  10 11 
  20 21

Now it’s time to introduce a brand new term – overriding.

What do you think will happen if more than one of the superclasses defines an entity of a particular name?
### 5.5.17 How Python finds properties and methods?

This is what the example shows →

```py
class Level0:
  Var = 100
  def fun(self):
    return 101

class Level1(Level0):
  Var = 200
  def fun(self):
    return 201

class Level2(Level1):
  pass

object = Level2()
print(object.Var, object.fun())

```

Both, Level0 and Level1 classes define a method named fun() and a property named Var. Does this mean that the Level2 class object will be able to access two copies of each entity?

Not at all.

The entity defined later (in the inheritance sense) overrides the same entity defined earlier. This is why the code produces the following output:
  200 201

As you can see, the Var class variable and fun() method from Level1 class override the entities of the same names derived from the Level0 class.

This feature can be intentionally used to modify default (or previously defined) class behaviors when any of its classes needs to act in a different way to its ancestor.

We can also say that Python looks for an entity from bottom to top, and is fully satisfied with the first entity of the desired name.

How does it work when a class has two ancestors offering the same entity, and they lie on the same level? In other words, what should you expect when a class emerges using multiple inheritance?

Let’s look at this.
### 5.5.18 How Python finds properties and methods?
The Sub class inherits goods from two superclasses, Left and Right (these names are intended to be meaningful) →
```py
class Left:
  Var = 'L'
  VarL = 'LL'
  def fun(self):
    return 'left'

class Right:
  Var = 'R'
  VarR = 'RR'
  def fun(self):
    return 'right'

class Sub(Left,Right):
  pass

object = Sub()

print(object.Var, object.VarL, object.VarR, object.fun())
```
There is no doubt that the class variable VarR comes from the Right class, and VarL comes from Left respectively. This is clear. But where does Var come from? Is it possible to guess it? The same problem is encountered with the fun() method – will it be invoked from Left or from Right? Let’s run the program – its output is: L LL RR left\
This proves that both unclear cases have a solution inside the Left class. Is this a sufficient premise to formulate a general rule? Yes, it is.\
We can say that Python looks for object components in the following order:
- inside the object itself;
- in its superclasses, from bottom to top;
- if there is more than one class on a particular inheritance path, Python scans them from left to right.
Do you need anything more? Just make a small amendment in the code – replace:
```py
class Sub(Left,Right):
```
with:
```py
class Sub(Right,Left):
```
What do you see now? We see:
```
R LL RR right
```
Do you see the same, or something different?

### 5.5.19 How to build a hierarchy of classes

Building a hierarchy of classes isn’t just art for art’s sake. If you divide a problem among classes and decide which of them should be located at the top and which should be placed at the bottom of the hierarchy, you have to carefully analyze the issue, but before we show you how to do it (and how not to do it), we want to highlight an interesting effect. It’s nothing extraordinary (it’s just a consequence of the general rules presented earlier), but remembering it may be key to understanding how some codes work, and how the effect may be used to build a flexible set of classes.

Take a look →

```py
class One:
  def doit(self):
    print("doit from One")
  def doanything(self):
    self.doit()

class Two(One):
  def doit(self):
    print("doit from Two")

one = One()
two = Two()

one.doanything()
two.doanything()
```

There are two classes, named One and Two, while Two is derived from One. Nothing special. However, one thing looks remarkable – the doit() method.

It’s defined twice: originally inside One and subsequently inside Two. The essence of the example lies in the fact that it is invoked just once – inside One.

The question is – which of the two methods will be invoked by the last two lines of the code?

The first invocation seems to be simple, and it is simple, actually – invoking doanything() from the  object named one will obviously activate the first of the methods.

The second invocation needs some attention. It’s simple, too if you keep in mind how Python finds class components.

The second invocation will launch doit() in the form existing inside the Two class, regardless of the fact that the invocation takes place within the One class.

In effect, the code produces the following output:
  doit from One
  doit from Two

Note: the situation in which the subclass is able to modify its superclass behavior (just like in the example) is called polymorphism. The word comes from Greek (polys: “many, much” and morphē, “form, shape”), which means that one and the same class can take various forms depending on the redefinitions done by any of its subclasses. The method, redefined in any of the superclasses, thus changing the behavior of the superclass, is called virtual.

In other words, no class is given once and for all. Each class’s behavior may be modified at any time by any of its subclasses.

We’re going to show you how to use polymorphism to extend class flexibility.
### 5.5.20 How to build a hierarchy of classes?

Take a look at the example →

```py
import time 
class TrackedVehicle:
  def controltrack(left,stop):
    pass

  def turn(left):
    controltrack(left,True)
    time.sleep(0.25)
    controltrack(left,False)

class WheeledVehicle:
  def turnfrontwheels(left,on):
    pass

  def turn(left):
    turnfrontwheels(left,True)
    time.sleep(0.25)
    turnfrontwheel(left,False)


```

Does it resemble anything? Yes, of course it does. It refers to the example shown in the beginning of the chapter when we talked about the general concepts of objective programming.

It may look weird, but we didn’t use inheritance in any way – just to show you that it doesn’t limit us, and we managed to get ours.

We defined two separate classes able to produce two different kinds of land vehicles. The main difference between them is in how they turn. A wheeled vehicle just turns the front wheels (generally). A tracked vehicle has to stop one of the tracks.

Can you follow the code?
- a tracked vehicle perform a turn by stopping and moving on one of its tracks (this is done by the controltrack() method, which will be implemented later)
- a wheeled vehicle turns when its front wheels turn (this is done by the turnfrontwheels() method)
- the turn() method uses the method suitable for each particular vehicle.

Can you see what’s wrong with the code?

The turn() methods look too similar to leave them in this form.

Let’s rebuild the code – we’re going to introduce a superclass to gather all the similar aspects of the driving vehicles, moving all the specifics to the subclasses.
### 5.5.21 How to build a hierarchy of classes?

This is what we’ve done →

```py
import time 

class Vehicle:
  def changedirection(left,on):
    pass
  def turn(left):
    changedirection(left,True)
    time.sleep(0.25)
    changedirection(left,False)

class TrackedVehicle(Vehicle):
  def controltrack(left,stop):
    pass
  def changedirection(left,on):
    controltrack(left,on)

class WheeledVehicle(Vehicle):
  def turnfrontwheels(left,on):
    pass
  def changedirection(left,on):
    turnfrontwheels(left,on)
```

- we defined a superclass named Vehicle, which uses the turn() method to implement a general scheme of turning, while the turning itself is done by a method named changedirection(); note: the former method is empty, as we are going to put all the details into the subclass (such a method is often called an abstract method, as it only demonstrates some possibility which will be instantiated later)
- we defined a subclass named TrackedVehicle (note: it’s derived from the Vehicle class) which instantiated the changedirection() method by using the specific (concrete) method named controltrack()
- respectively, the subclass named WheeledVehicle does the same trick, but uses the turnfrontwheel() method to force the vehicle to turn.

The most important advantage (omitting readability issues) is that this form of code enables you to implement a brand new turning algorithm just by modifying the turn() method, which can be done in just one place, as all the vehicles will obey it.

This is how polymorphism helps the developer to keep the code clean and consistent.
### 5.5.22 Inheritance vs. composition

Inheritance is not the only way of constructing adaptable classes. You can achieve the same goals (not always, but very often) by using a technique named composition.

Composition is the process of composing an object using other different objects. The objects used in the composition deliver a set of desired traits (properties and/or methods) so we can say that they act like blocks used to build a more complicated structure.

It can be said that:
- inheritance extends a class’s capabilities by adding new components and modifying existing ones; in other words, the complete recipe is contained inside the class itself and all its ancestors; the object takes all the class’s belongings and makes use of them;
- composition projects a class as a container able to store and use other objects (derived from other classes) where each of the objects implements a part of a desired class’s behavior.

Let us illustrate the difference by using the previously defined vehicles. The previous approach led us to a hierarchy of classes in which the top-most class was aware of the general rules used in turning the vehicle, but didn’t know how to control the appropriate components (wheels or tracks). The subclasses implemented this ability by introducing specialized mechanisms. Let’s do (almost) the same thing, but using composition. The class – like in the previous example – is aware of how to turn the vehicle, but the actual turn is done by a specialized object stored in a property named controller. The controller is able to control the vehicle by manipulating the relevant vehicle’s parts.

This is how it could look →

```py
import time 

class Tracks:
  def changedirection(self,left,on):
    print("tracks: ", left, on)

class Wheels:
  def changedirection(self,left,on):
    print("wheels: ", left, on)

class Vehicle:
  def __init__(self, controller):
    self.controller = controller
  def turn(self,left):
    self.controller.changedirection(left, True)
    time.sleep(0.25)
    self.controller.changedirection(left, False)

wheeled = Vehicle(Wheels())
tracked = Vehicle(Tracks())

wheeled.turn(True)
tracked.turn(False)
```

There are two classes named Tracks and Wheels – they know how to control the vehicle’s direction. There is also a class named Vehicle which can use any of the available controllers (the two already defined, or any other defined in the future) – the controller itself is passed to the class during initialization. In this way, the vehicle’s ability to turn is composed using an external object, not implemented inside the Vehicle’s class.

In other words, we have a universal vehicle and can install either tracks or wheels onto it.

The code produces the following output:
  wheels:  True True
  wheels:  True False
  tracks:  False True
  tracks:  False False
### 5.5.23 Single inheritance vs. multiple inheritance

As you already know, there are no obstacles to using multiple inheritance in Python. You can derive any new class from more than one previously defined classes.

There is only one but. The fact that you can do it does not mean you have to.

Don’t forget that:
- a single inheritance class is always simpler, safer, and easier to understand and maintain;
- multiple inheritance is always risky, as you have many more opportunities to make a mistake in identifying these parts of the superclasses which will effectively influence the new class;
- multiple inheritance may make overriding extremely tricky; moreover, using the super() function becomes  ambiguous;
- multiple inheritance violates the single responsibility principle (more details here: https://en.wikipedia.org/wiki/Single_responsibility_principle) as it makes a new class of two (or more) classes that know nothing about each other;
- we strongly suggest multiple inheritance as the last of all possible solutions – if you really need the many different functionalities offered by different classes, composition may be a better alternative.

### 5.5.24 Diamonds and why you don’t want them?

The spectrum of issues possibly coming from multiple inheritance is illustrated by a classical problem named the diamond problem. The name reflects the shape of the inheritance diagram – take a look →

- there is the top-most superclass named A;
- there are two subclasses derived from A – B and C;
- and there is also the bottom-most subclass named D, derived from B and C (or C and B, as these two variants mean different things in Python)

Can you see the diamond there?

Python, however, doesn’t like diamonds, and won’t let you implement anything like this. If you try to build a hierarchy like this one:

```py

class A:
  pass
class B(A):
  pass
class C(A):
  pass
class D(A,B):
  pass
d = D()
```

you will get a TypeError exception, along with the following message:
  Cannot create a consistent method resolution order (MRO) for bases B, A

where MRO stands for Method Resolution Order – this is the algorithm Python uses to look up the inheritance tree in order to find the needed methods.\
Diamonds are precious and valuable . . . but not in programming. Avoid them for your own good.
### 5.6.1 Exceptions once again
Discussing object programming offers a very good opportunity to return to exceptions. The objective nature of Python’s exceptions makes them a very flexible tool, able to fit to specific needs, even those you don’t yet know about.

Before we dive into the objective face of exceptions, we want to show you some syntactical and semantic aspects of the way in which Python treats the try-except block, as it offers a little more than what we have presented so far.

The first feature we want discuss here is an additional, possible branch that can be placed inside (or rather, directly behind) the try-except block – it’s the part of the code starting with else – just like here →

```py
def reciprocal(n):
  try:
    n = 1 / n
  except ZeroDivisionError:
    print("Division failed")
    return None
  else:
    print("Everything went fine")
    return n

print(reciprocal(2))
print(reciprocal(0))
```

A code labelled in this way is executed when (and only when) no exception has been raised inside the try part. We can say that exactly one branch can be executed after try: either the one beginning with except (don’t forget that there can be more than one branch of this kind) or the one starting with else.

Note: the else branch has to be located after the last `except` branch.

The example code produces the following output:
```
Everything went fine
0.5
Division failed
None
```
### 5.6.2 Exceptions once again

The `try-except` block can be extended in one more way – by adding a part headed by the `finally` keyword (it must be the last branch of the code designed to handle exceptions).

Note: these two variants (`else` and `finally)` aren’t dependent in any way, and they can coexist or occur independently.

The `finally` block is always executed (it finalizes the `try-except` block execution, hence its name), no matter what happened earlier, even when raising an exception, no matter whether this has been handled or not.

Look at the code →

```py
def reciprocal(n):
  try:
    n = 1 / n
  except ZeroDivisionError:
    print("Division failed")
    n = None
  else:
    print("Everything went fine")
  finally:
    print("It's time to say good bye")
    return n

print(reciprocal(2))
print(reciprocal(0))
```

It outputs:
```
Everything went fine
It's time to say good bye 
0.5
Division failed 
It's time to say good bye
None
```
### 5.6.3 Exceptions are classes, too

All the previous examples were content with detecting a specific kind of exception and responding to it in an appropriate way. Now we’re going to delve deeper, and look inside the exception itself.

You probably won’t be surprised to learn that exceptions are classes. Furthermore, when an exception is raised, an object of the class is instantiated, and goes through all levels of program execution, looking for the `except` branch that is prepared to deal with it.

Such an object carries some useful information which can help you to precisely identify all aspects of the pending situation. To achieve that goal, Python offers a special variant of the exception clause – you can find it here →

```py
try:
  i = int("hello!")
except Exception as e:
  print(e)
  print(e.__str__())
``` 

As you can see, the `except` statement is extended, and contains an additional phrase starting with the as keyword, followed by an identifier. The identifier is designed to catch the exception object so you can analyze its nature and draw proper conclusions. Note: the identifier’s scope covers its `except` branch, and doesn’t go any further.

The example presents a very simple way of utilizing the received object –just print it out (as you can see, the output is produced by the object’s `__str__()` method) and it contains a brief message describing the reason.

The same message will be printed if there is no fitting `except` block in the code, and Python is forced to handle it alone.  
### 5.6.4 Exceptions are classes, too

All the built-in Python exceptions form a hierarchy of classes. There is no obstacle to extending it if you find it reasonable.

This program dumps all predefined exception classes in the form of a tree-like printout.

Take a look at it →

```py
def PrintExcTree(thisclass, nest = 0):
  if nest > 1:
    print("   |" * (nest - 1), end = '')
  if nest > 0:
    print("   +---", end = '')
  print(thisclass.__name__)
  for subclass in thisclass.__subclasses__():
    PrintExcTree(subclass, nest + 1)

PrintExcTree(BaseException)
```

As a tree is a perfect example of a recursive data structure, a recursion seems to be the best tool to traverse through it. The `PrintExcTree()` function takes two arguments:
- a point inside the tree from which we start traversing the tree;
- a nesting level (we’ll use it to build a simplified drawing of the tree’s branches)

Let’s start from the tree’s root – the root of Python’s exception classes is the BaseException class (it’s a superclass of all other exceptions).

For each of the encountered classes, perform the same set of operations:
- print its name, taken from the `__name__` property;
- iterate through the list of subclasses delivered by the `__subclasses__()` method, and recursively invoke the `PrintExcTree(),` incrementing the nesting level respectively.

Note how we’ve drawn the branches and forks. The printout isn’t sorted in any way – you can try to sort it yourself, if you want a challenge. Moreover, there are some subtle inaccuracies in the way in which some branches are presented. That can be fixed, too, if you wish.

This is how it looks:

``` 
BaseException 
+---Exception 
|   +---TypeError 
|   +---StopIteration 
|   +---MemoryError 
|   +---NameError 
|   |   +---UnboundLocalError 
|   +---ValueError 
|   |   +---UnicodeError 
|   |   |   +---UnicodeEncodeError 
|   |   |   +---UnicodeDecodeError 
|   |   |   +---UnicodeTranslateError 
|   |   +---UnsupportedOperation 
|   +---Warning 
|   |   +---UserWarning 
|   |   +---DeprecationWarning 
|   |   +---UnicodeWarning 
|   |   +---BytesWarning 
|   |   +---SyntaxWarning 
|   |   +---ResourceWarning 
|   |   +---RuntimeWarning 
|   |   +---FutureWarning 
|   |   +---ImportWarning 
|   |   +---PendingDeprecationWarning 
|   +---AttributeError 
|   +---EOFError 
|   +---LookupError 
|   |   +---IndexError 
|   |   +---KeyError 
|   |   +---CodecRegistryError 
|   +---ReferenceError 
|   +---ArithmeticError 
|   |   +---FloatingPointError 
|   |   +---OverflowError 
|   |   +---ZeroDivisionError 
|   +---Error 
|   +---ImportError 
|   |   +---ZipImportError 
|   +---BufferError 
|   +---SyntaxError 
|   |   +---IndentationError 
|   |   |   +---TabError 
|   +---OSError 
|   |   +---ConnectionError 
|   |   |   +---BrokenPipeError 
|   |   |   +---ConnectionAbortedError 
|   |   |   +---ConnectionRefusedError 
|   |   |   +---ConnectionResetError 
|   |   +---BlockingIOError 
|   |   +---ProcessLookupError 
|   |   +---FileNotFoundError 
|   |   +---ItimerError 
|   |   +---NotADirectoryError 
|   |   +---UnsupportedOperation 
|   |   +---PermissionError 
|   |   +---FileExistsError 
|   |   +---ChildProcessError 
|   |   +---TimeoutError 
|   |   +---IsADirectoryError 
|   |   +---InterruptedError 
|   +---SystemError 
|   |   +---CodecRegistryError 
|   +---AssertionError 
|   +---RuntimeError 
|   |   +---NotImplementedError 
|   |   +---_DeadlockError 
+---GeneratorExit 
+---SystemExit 
+---KeyboardInterrupt
```

### 5.6.5 Detailed anatomy of exception

Let’s take a closer look at the exception’s object, as there are some really interesting elements here (we’ll return to the issue soon when we consider Python’s input/output base techniques, as their exception subsystem extends these objects a bit).

The `BaseException` class introduces a property named args. It’s a tuple designed to gather all arguments passed to the class constructor. It is empty if the construct has been invoked without any arguments, or contains just one element when the constructor gets one argument (we don’t count the self argument here), and so on.

We’ve prepared a simple function to print the args property in an elegant way. You can see the function here →

```py
def printargs(args):
  lng = len(args)
  if lng == 0:
    print("")
  elif lng == 1:
    print(args[0])
  else:
    print(str(args))

try:
  raise Exception
except Exception as e:
  print(e,e.__str__(),sep=' : ',end=' : ')
  printargs(e.args)

try:
  raise Exception("my exception")
except Exception as e:
  print(e,e.__str__(),sep=' : ',end=' : ')
  printargs(e.args)

try:
  raise Exception("my", "exception")
except Exception as e:
  print(e,e.__str__(),sep=' : ',end=' : ')
  printargs(e.args)
```

We’ve used the function to print the contents of the args property in three different cases, where the exception of the `Exception` class is raised in three different ways. To make it more spectacular, we’ve also printed the object itself, along with the result of the `__str__()` invocation.

The first case looks routine – there is just the name `Exception` after the raise keyword. This means that the object of this class has been created in a most routine way.

The second and third cases may look a bit weird at first glance, but there’s nothing odd here – these are just the constructor invocations. In the second raise statement, the constructor is invoked with one argument, and in the third, with two.

As you can see, the program output reflects this, showing the appropriate contents of the args property.

```
:  : 
my exception : my exception : my exception 
('my', 'exception') : ('my', 'exception') : ('my', 'exception')
```

### 5.6.6 How to create your own exception?

 The exceptions hierarchy is neither closed nor finished, and you can always extend it if you want or need to create your own world populated with your own exceptions. It may be useful when you create a complex module which detects errors and raises exceptions, and you want the exceptions to be easily distinguishable from any others brought by Python.

This is done by defining your own, new exceptions as subclasses derived from predefined ones.

Note: if you want to create an exception which will be utilized as a specialized case of any built-in exception, derive it from just this one. If you want to build your own hierarchy, and don’t want it to be closely connected to Python’s exception tree, derive it from any of the top exception classes, like Exception.

Imagine that you’ve created a brand new arithmetic, ruled by your own laws and theorems. It’s clear that division has been redefined, too, and has to behave in a different way than routine dividing. It’s also clear that this new division should raise its own exception, different from the built-in `ZeroDivisionError,` but it’s reasonable to assume that in some circumstances, you (or your arithmetic’s user) may want to treat all zero divisions in the same way.

Demands like these may be fulfilled in the way presented here →

```py
class MyZeroDivisionError(ZeroDivisionError):
	pass

def doTheDivision(mine):
	if mine:
		raise MyZeroDivisionError("worse news")
	else:		
		raise ZeroDivisionError("bad news")

for mode in [False, True]:
	try:
		doTheDivision(mode)
	except ZeroDivisionError:
		print('Division by zero')


for mode in [False, True]:
	try:
		doTheDivision(mode)
	except MyZeroDivisionError:
		print('My division by zero')
	except ZeroDivisionError:
		print('Original division by zero')		
```

We’ve defined our own exception, named `MyZeroDivisionError,` derived from the built-in `ZeroDivisionError.` As you can see, we’ve decided not to add any new components to the class.

In effect, an exception of this class can be – depending of the desired point of view – treated like a plain `ZeroDivisionError,` or considered separately.

The doTheDivision() function raises either a  `MyZeroDivisionError` or `ZeroDivisionError` exception, depending on the argument’s value. The function is invoked four times in total, while the first two invocations are handled using only one `except` branch (the more general one) and the last two ones with two different branches, able to distinguish the exceptions (don’t forget: the order of the branches makes a fundamental difference!)

### 5.6.7 How to create your own exception?

When you’re going to build a completely new universe filled with completely new creatures that have nothing in common with all the familiar things, you may want to build your own exception structure. For example, if you work on a large simulation system which is intended to model the activities of a pizza restaurant, it can be desirable to form a separate hierarchy of exceptions.

```py
class PizzaError(Exception):
  def __init__(self, pizza, message):
    Exception.__init__(message)
    self.pizza = pizza
```

You can start to build it by defining a general exception as a new base class for any other specialized exception. We’ve done in in the following way →

Note: we’re going to collect more specific information here than a regular Exception does, so our constructor will take two arguments: one specifying a pizza as a subject of the process, and one containing a more or less precise description of the problem. As you can see, we pass the second parameter to the superclass constructor, and save the first inside our own property. 
### 5.6.8 How to create your own exception?

A more specific problem (like an excess of cheese) can require a more specific exception. It’s possible to derive the new class from the already defined `PizzaError` class, like we’ve done here →

```py
class TooMucCheeseError(PizzaError):
  def __init__(self, pizza, cheese, message):
    PizzaError.__init__(self, pizza, message)
    self.cheese = cheese
```

The TooMuchCheese exception needs more information than a regular `PizzaError` exception, so we add it to the constructor –the name `cheese` is then stored for further processing.

### 5.6.9 How to use your own exception?

We’ve coupled together the two previously defined exceptions and harnessed them to work in a small example snippet →

```py
class PizzaError(Exception):
    def __init__(self, pizza, message):
        Exception.__init__(self,message)
        self.pizza = pizza

class TooMuchCheeseError(PizzaError):
    def __init__(self, pizza, cheese, message):
        PizzaError.__init__(self,pizza,message)
        self.cheese = cheese

def makePizza(pizza,cheese):
	if pizza not in ['margherita', 'capricciosa', 'calzone']:
		raise PizzaError(pizza,"no such pizza in menu")
	if cheese > 100:
		raise TooMuchCheeseError(pizza, cheese, "too much cheese")
	print("Pizza ready!")

for (pz,ch) in [('calzone',0),('margherita',110),('mafia',20)]:
	try:
		makePizza(pz,ch)
	except TooMuchCheeseError as tmce:
		print(tmce, ':', tmce.cheese)
	except PizzaError as pe:
		print(pe, ':', pe.pizza)
```

One of these is raised inside the `makePizza()` function when any of these two erroneous situations is discovered: a wrong pizza request, or a request for too much cheese.

Note:
- removing the branch starting with except `TooMuchCheeseError` will cause all appearing exceptions to be classified as `PizzaError;`
- removing the branch starting with except `PizzaError` will cause the `TooMuchCheeseError` exceptions to remain unhandled, and will cause the program to terminate.
### 5.6.10 How to use your own exception?

The previous solution, although elegant and efficient, has one important weakness. Due to the somewhat easygoing way of declaring the constructors, the new exceptions cannot be used as-is, without a full list of required arguments.

We’ll remove this weakness by setting the default values for all constructor parameters. Take a look →

```py
class PizzaError(Exception):
    def __init__(self, pizza='uknown', message=''):
        Exception.__init__(self,message)
        self.pizza = pizza

class TooMuchCheeseError(PizzaError):
    def __init__(self, pizza='uknown', cheese='>100', message=''):
        PizzaError.__init__(self,pizza,message)
        self.cheese = cheese

def makePizza(pizza,cheese):
	if pizza not in ['margherita', 'capricciosa', 'calzone']:
		raise PizzaError
	if cheese > 100:
		raise TooMuchCheeseError
	print("Pizza ready!")

for (pz,ch) in [('calzone',0),('margherita',110),('mafia',20)]:
	try:
		makePizza(pz,ch)
	except TooMuchCheeseError as tmce:
		print(tmce, ':', tmce.cheese)
	except PizzaError as pe:
		print(pe, ':', pe.pizza)
```

Now, if the circumstances permit, it is possible to use the class names alone.
### 5.7.1 Generators – where to find them

Generator – what do you associate this word with? Perhaps it refers to some electronic device. Or perhaps it refers to a heavy and serious machine designed to produce power, electrical or other.

A Python generator is a piece of specialized code able to produce a series of values, and to control the iteration process. This is why generators are very often called iterators, and although some may find a very subtle distinction between these two, we’ll treat them as one.

You may not realize it, but you’ve encountered generators many, many times before. Take a look at the very simple snippet →

```py
for i in range(5):
  print(i)
```

The `range()` function is, in fact, a generator, which is (in fact, again) an iterator.

What is the difference?

A function returns one, well-defined value – it may be the result of a more or less complex evaluation of, e.g., a polynomial, and is invoked once – only once.

A generator returns a series of values, and in general, is (implicitly) invoked more than once.

 In the example, the `range()` generator is invoked six times, providing five subsequent values from zero to four, and finally signaling that the series is complete.

The above process is completely transparent. Let’s shed some light on it. Let’s show you the iterator protocol. 
### 5.7.2 Generators – where to find them

The iterator protocol is a way in which an object should behave to conform to the rules imposed by the context of the for and in statements.

An object conforming to the iterator protocol is called an iterator.

An iterator must provide two methods:
- `__iter__()` which should return the object itself and which is invoked once (it’s needed for Python to successfully start the iteration)
- `__next__()` which is intended to return the next value (first, second, and so on) of the desired series – it will be invoked by the for/in statements in order to pass through the next iteration; if there are no more values to provide, the method should raise the StopIteration exception.

Does it look strange?
Not at all.
Look at the example → 

```py
class Fib:
	def __init__(self, nn):
		self.__n = nn
		self.__i = 0
		self.__p1 = self.__p2 = 1

	def __iter__(self):
		return self

	def __next__(self):
		self.__i += 1
		if self.__i > self.__n:
			raise StopIteration
		if self.__i in [1,2]:
			return 1
		ret = self.__p1 + self.__p2
		self.__p1, self.__p2 = self.__p2, ret
		return ret

class Class:
	def __init__(self,n):
		self.__iter = Fib(n)

	def __iter__():
		return self.__iter;

object = Class(8)

for i in object:
	print(i)

``` 

We’ve built a class able to iterate through the first n values (where n is a constructor parameter) of the Fibonacci numbers.

Let us remind you – the Fibonacci numbers (Fibi) are defined as follows:
- Fib1 = 1
- Fib2 = 1
- Fibi = Fibi-1 + Fibi-2

In other words:
- the first two Fibonacci numbers are equal to 1;
- any other Fibonacci number is the sum of the two previous ones (e.g. Fib3 = 2, Fib4 = 3, Fib5 = 5, and so on)

Let’s dive into the code:
- lines 02 through 06: the class constructor prints a message (we’ll use this to trace the class’s behavior), prepares some variables (`__n` to store the series limit, `__i` to track the current Fibonacci number to provide, and `__p1` along with `__p2` to save the two previous numbers);
- lines 08 through 10: the `__iter__` method is obliged to return the iterator object itself; its purpose may be a bit ambiguous here, but there’s no mystery; try to imagine an object which is not an iterator (e.g., it’s a collection of some entities), but one of its components is an iterator able to scan the collection; the `__iter__` method should extract the iterator and entrust it with the execution of the iteration protocol; as you can see, the method starts its action by printing a message;
- lines 12 through 21: the `__next__` method is responsible for creating the sequence; it’s somewhat wordy, but this should make it more readable; first, it prints a message, then it updates the number of desired values, and if it reaches the end of the sequence, the method breaks the iteration by raising the StopIteration exception; the rest of the code is simple, and it precisely reflects the definition we showed you earlier;
- lines 23 and 24 make use of the iterator.

The code produces the following output:

``` 
__init__
__iter__
__next__
1
__next__
1
__next__
2
__next__
3
__next__
5
__next__
8
__next__
13
__next__
21
__next__
34
__next__
55
__next__
```
 
Look:
- the iterator object is instantiated first;
- next, Python invokes the `__iter__` method to get access to the actual iterator;
- the `__next__` method is invoked 11 times – the first ten times produce useful values, while the 11th terminates the iteration.

### 5.7.3 Generators – where to find them

The previous example shows you a solution where the iterator object is a part of a more complex class.

The code isn’t really sophisticated, but it presents the concept in a clear way.

Take a look →

```py
class Fib:
  def __init__(self, nn):
    self.__n = nn
    self.__i = 0
    self.__p1 = self.__p2 = 1

  def __iter__(self):
    print("Fib iter")
    return self

  def __next__(self):
    self.__i += 1
    if self.__i > self.__n:
      raise StopIteration
    if self.__i in [1,2]:
      return 1
    ret = self.__p1 + self.__p2
    self.__p1, self.__p2 = self.__p2, ret
    return ret

class Class:
  def __init__(self,n):
    self.__iter = Fib(n)

  def __iter__(self):
    print("Class iter")
    return self.__iter;

object = Class(8)

for i in object:
  print(i)
``` 

We’ve built the Fib iterator into another class (we can say that we’ve composed it into the `Class` class). It’s instantiated along with Class’s object.

The object of the class may be used as an iterator when (and only when) it positively answers to the `__iter__` invocation – this class can do it, and if it’s invoked in this way, it provides an object able to obey the iteration protocol.

This is why the output of the code is the same as previously, although the object of the Fib class isn’t used explicitly inside the `for` loop’s context.
### 5.7.4 The yield statement

The iterator protocol isn’t particularly difficult to understand and use, but it is also indisputable that the protocol is rather inconvenient.

The main discomfort it brings is the need to save the state of the iteration between subsequent `__iter__` invocations.

For example, the Fib iterator is forced to precisely store the place in which the last invocation has been stopped (i.e., the evaluated number and the values of the two previous elements). This makes the code larger and less comprehensible.

This is why Python offers a much more effective, convenient, and elegant way of writing iterators.

The concept is fundamentally based on a very specific and powerful mechanism provided by the keyword `yield`

You may think of the `yield` keyword as a smarter sibling of the `return` statement, with one essential difference.
### 5.7.5 The yield statement

Take a look at this function →

```py
def fun(n):
  for i in range(n):
    return i
``` 

It looks strange, doesn’t it? It’s clear that the for loop has no chance to finish its first execution, as the return will break it irrevocably.

Moreover, invoking the function won’t change anything – the for loop will start from scratch and will be broken immediately.

We can say that such a function is not able to save and restore its state between subsequent invocations.

This also means that a function like this cannot be used as a generator.
### 5.7.6 The yield statement

We’ve replaced exactly one word in the code – can you see it?  →

```py
def fun(n):
  for i in range(n):
    yield i
```

We’ve added `yield` instead of `return.`

This little amendment turns the function into a generator, and executing the `yield` statement has some very interesting effects.

First of all, it provides the value of the expression specified after the `yield` keyword, just like `return,` but doesn’t lose the state of the function.

All the variables’ values are frozen, and wait for the next invocation, when the execution is resumed (not taken from scratch, like after `return).`

There is one important limitation: such a function should not be invoked explicitly as – in fact – it isn’t a function anymore; it’s a generator object.

The invocation will return the object’s identifier, not the series we expect from the generator.

Due to the same reasons, the previous function (the one with the `return` statement) may only be invoked explicitly, and must not be used as a generator.

Let us show you the new generator in action.
### 5.7.7 How to build your own generator

This is how we’ve used it →

```py
def fun(n):
  for i in range(n):
    yield i

for v in fun(5):
  print(v)
``` 

The code produces the following output:

```
0
1
2
3
4
```

### 5.7.8 How to build your own generator

What if you need a generator to produce the first n powers of 2?

Nothing easier.

Just look →
```py
def PowersOf2(n):
  pow = 1
  for i in range(n):
    yield pow
    pow *= 2

for v in PowersOf2(8):
  print(v)
``` 

The code prints:

```
1
2
4
8
16
32
64
128
```
### 5.7.9 How to build your own generator

Generators may also be used within list comprehensions, just like here →

```py
def PowersOf2(n):
  pow = 1
  for i in range(n):
    yield pow
    pow *= 2

t = [ x for x in PowersOf2(5) ]
print(t)
```
 
This is the output you’ll see:
```
[1, 2, 4, 8, 16]
```
### 5.7.10 How to build your own generator

The list() function can transform a series of subsequent generator invocations into a real list →

```py
def PowersOf2(n):
  pow = 1
  for i in range(n):
    yield pow
    pow *= 2

t = [ x for x in PowersOf2(5) ]
print(t)
``` 

The output looks as follows:

[1, 2, 4, 8, 16]
### 5.7.11 How to build your own generator

Moreover, the context created by the in operator allows you to use a generator, too.

The example shows how to do it →

```py
def PowersOf2(n):
	pow = 1
	for i in range(n):
		yield pow
		pow *= 2

for i in range(20):
	if i in PowersOf2(4):
		print(i)
``` 

The code’s output is:
```
1
2
4
8
```
### 5.7.12 How to build your own generator

Now let’s see a Fibonacci number generator, and ensure that it looks much better than the objective version based on the direct iterator protocol implementation.

Here it is →

```py
def Fib(n):
  p = pp = 1
  for i in range(n):
    if i in [0,1]:
      yield 1
    else:
      n = p + pp
      pp, p = p, n
      yield n

fibs = list(Fib(10))
print(fibs)
``` 

And this is the list produced by the generator:
```
[1, 1, 2, 3, 5, 8, 13, 21, 34, 55]
```
### 5.7.13 More about list comprehensions

You should be able to remember the rules governing the creation and use of a very special Python phenomenon named list comprehension – a simple and very impressive way of creating lists and their contents.

In case you need it, here is a quick reminder →

```py
list1 = []
for ex in range(6):
  list1.append(10 ** ex)
list2 = [10 ** ex for ex in range(6)]
print(list1)
print(list2)
``` 

There are two parts inside the code, both creating a list containing a few of the first natural powers of ten.

The former uses a routine way of utilizing the for loop, while the latter makes use of the list comprehension and builds the list in situ, without needing a loop, or any other extended code.

It looks like the list is created inside itself – it’s not true, of course, as Python has to perform nearly the same operations as in the first snippet, but it is indisputable that the second formalism is simply more elegant, and lets the reader to avoid any unnecessary details.

The example outputs two identical lines containing the following text:
```
[1, 10, 100, 1000, 10000, 100000]
```
### 5.7.14 More about list comprehensions

There is a very interesting syntax we want to show you now. Its usability is not limited to list comprehensions, but we have to admit that comprehensions are the ideal environment for it.

It’s a conditional expression – a way of selecting one of two different values based on the result of a Boolean expression.

Look →
`expression1 if condition else expression2`
 
It may look a bit surprising at first glance, but you have to keep in mind that it is not a conditional instruction. Moreover, it’s not an instruction at all. It’s an operator.

The value it provides is equal to `expression1` when the condition is true, and `expression2` otherwise.

A good example will tell you more. 
### 5.7.15 More about list comprehensions

And here is the example →

``py
list = []

for x in range(10):
  list.append( 1 if x % 2 == 0 else 0 )

print(list)
``` 

The code fills a list with 1’s and 0’s – if the index of a particular element is odd, the element is set to 0, and to 1 otherwise.

Simple? Maybe not at first glance.

Elegant? Indisputably. Can you use the same trick within a list comprehension? Yes, you can.
### 5.7.16 More about list comprehensions

This is how it can be done →

```py
list = [ 1 if x % 2 == 0 else 0 for x in range(10) ]
``` 

Compactness and elegance – these two words come to mind when looking at the code.

What do they have in common, generators and list comprehensions?  Is there any connection between them? Yes. A rather loose connection, but an unequivocal one. Just one change can turn any comprehension into a generator. 
### 5.7.17 More about list comprehensions

Look at the code and see if you can find the detail that turns a list comprehension into a generator →

```py
list = [ 1 if x % 2 == 0 else 0 for x in range(10) ]
genr = ( 1 if x % 2 == 0 else 0 for x in range(10) )

for v in list:
  print(v, end=" ")
print()

for v in genr:
  print(v, end=" ")
print()
``` 

It’s the parentheses.

The brackets make a comprehension – the parentheses make a generator.

The code, however, when run, produces two identical lines:

```
1 0 1 0 1 0 1 0 1 0
1 0 1 0 1 0 1 0 1 0
```
 
How can you know that the second assignment creates a generator, not a list?

There is some proof we can show you. Apply the len() function to both these entities.

`len(list)` will evaluate to 10. Clear and predictable.

`len(genr)` will raise an exception, and you will see the following message:

`TypeError: object of type 'generator' has no len()`
### 5.7.18 More about list comprehensions

Of course, saving either the list or the generator is not necessary – you can create them exactly in the place where you need them – just like here →

```py
for v in [ 1 if x % 2 == 0 else 0 for x in range(10) ]:
  print(v, end=" ")
print()

for v in ( 1 if x % 2 == 0 else 0 for x in range(10) ):
  print(v, end=" ")
print()
```

Note: the same appearance of the output doesn’t mean that both loops work in the same way. In the first loop, the list is created (and iterated through) as a whole – it actually exists when the loop is being executed. In the second loop, there is no list at all – there are only subsequent values produced by the generator, one by one.
### 5.7.19 The lambda function

The lambda function is a concept borrowed from mathematics, more specifically, from a part called the Lambda calculus, but these two phenomena are not the same. Mathematicians use the Lambda calculus in many formal systems connected with logic, recursion, or theorem provability. Programmers use the lambda function to simplify the code, to make it clearer and easier to understand.

A lambda function is a function without a name (you can also call it an anonymous function). Of course, such a statement immediately raises the question: how do you use anything that cannot be identified?

Fortunately, it’s not a problem, as you can name such a function if you really need, but, in fact, in many cases the lambda function can exist and work while remaining fully incognito.

The declaration of the lambda function doesn’t resemble a normal function declaration in any way – see for yourself →

  `lambda {parameters}: {expression}`

Such a clause returns the value of the expression when taking into account the current value of the current lambda argument.

As usual, an example will be helpful.
### 5.7.20 The lambda function

The first example uses three lambda functions, but gives them names. Look at it carefully →

```py
two = lambda : 2
sqr = lambda x : x * x
pwr = lambda x,y : x ** y

for a in range(-2,3):
	print(sqr(a), end = ' ')
	print(pwr(a,two()))
```

The first lambda is an anonymous parameterless function that always returns 2. As we’ve assigned it to a variable named two, we can say that the function is not anonymous anymore, and we can use the name to invoke it.

The second one is a one-parameter anonymous function that returns the value of its squared argument. We’ve named it as such, too.

The third lambda takes two parameters and returns the value of the first one raised to the power of the second one. The name of the variable which carries the lambda speaks for itself. We don’t use pow to avoid confusion with the built-in function of the same name and the same purpose.

The program produces the following output

  4 4
  1 1 
  0 0 
  1 1 
  4 4

This example is clear enough to show how lambdas are declared and how they behave, but it says nothing about why they’re necessary, and what they’re used for, since they can all be replaced with routine Python functions.

Where is the benefit?
### 5.7.21 How to use lambdas and what for?

The most interesting part of using lambdas appears when you can use them in their pure form – as anonymous parts of code intended to evaluate a result.

Imagine that we need a function (we’ll name it `printfunction`) which prints the values of a given (other) function for a set of selected arguments. We want `printfunction` to be universal – it should accept a set of arguments put in a list and a function to be evaluated, both as arguments – we don’t want to hardcode anything.

This is how we’ve implemented the idea →

```py
def printfunction(args, fun):
  for x in args:
    print('f(',x,')=',fun(x),sep='')

def poly(x):
  return 2 * x**2 - 4 * x + 2

printfunction([x for x in range(-2,3)], poly)
```


The `printfunction()` function takes two parameters:
- the first, a list of arguments for which we want to print the results;
- the second, a function which should be invoked as many times as the number of values that are collected inside the first parameter.

Note: we’ve also defined a function named poly() – this is the function whose values we’re going to print. The calculation the function performs isn’t very sophisticated – it’s the polynomial (hence its name) of a form:

  f(x) = 2x2 - 4x + 2

The name of the function is then passed to the `printfunction()` along with a set of five different arguments – the set is built with a list comprehension clause.

The code prints the following lines:

  f(-2)=18 
  f(-1)=8 
  f(0)=2 
  f(1)=0 
  f(2)=2

Can we avoid defining the poly() function, as we’re not going to use it more than once? Yes, we can – this is the benefit a lambda can bring.
### 5.7.22 How to use lambdas and what for?

Can you see the difference? →

```py
def printfunction(args, fun):
  for x in args:
    print('f(',x,')=',fun(x),sep='')

printfunction([x for x in range(-2,3)], lambda x: 2 * x**2 - 4 * x + 2)
```

The `printfunction()` has remained exactly the same, but there is no `poly()` function. We don’t need it anymore, as the polynomial is now directly inside the `printfunction()` invocation in the form of a lambda defined in the following way:

  `lambda x: 2 * x**2 - 4 * x + 2`

The code has become shorter, clearer, and more legible.

Let us show you another place where lambdas can be useful. We’ll start with a description of `map(),` a built-in Python function. Its name isn’t too descriptive, its idea is simple, and the function itself is really usable.
### 5.7.23 How to use lambdas and what for?

In the simplest of all possible cases, the `map()` function takes two arguments →
- a function;
- a list.

  `map(function, list)`

The above description is extremely simplified, as:
- the second `map()` argument may be any entity that can be iterated (e.g., a tuple, or just a generator)
- `map()` can accept more than two arguments.

The `map()` function applies the function passed by its first argument to all its second argument’s elements, and returns an iterator delivering all subsequent function results. You can use the resulting iterator in a loop, or convert it into a list using the list() function.

Can you see a role for any lambda here?
### 5.7.24 How to use lambdas and what for?

Here is some code for two lambdas →

```py
list1 = [ x for x in range(5) ]
list2 = list(map(lambda x: 2 ** x, list1))
print(list2)
for x in map(lambda x: x * x, list2):
  print(x, end=' ')
print()
```

This is the intrigue:
- build the list1 with values from 0 to 4;
- next, use map along with the first lambda to create a new list in which all elements have been evaluated as two raised to the power taken from the corresponding element from list1;
- list2 is printed then;
- in the next step, use the map() function again to make use of the generator it returns and to directly print all the values it delivers; as you can see, we’ve engaged the second lambda here – it just squares each element from list2.

Try to imagine the same code without lambdas. Would it be any better? It’s unlikely.
### 5.7.25 How to use lambdas and what for?

Another Python function which can be significantly beautified by the application of a lambda is `filter().` It expects the same kind of arguments as map(), but does something different – it filters its second argument while being guided by directions flowing from the function specified as the first argument (the function is invoked for each list element, just like in map()).

The elements which return True from the function pass the filter – the others are rejected.

The example shows the `filter()` function in action →

```py
from random import seed, randint

seed()
data = [ randint(-10,10) for x in range(5) ]
filtered = list(filter(lambda x: x > 0 and x % 2 == 0, data))
print(data)
print(filtered)
```

Note: we’ve made use of the random module to initialize the random number generator (not to be confused with the generators we’ve just talked about) with the `seed()` function, and to produce five random integer values from -10 to 10 using the `randint()` function. The list is then filtered, and only the numbers which are even and greater than zero are accepted.

Of course, it’s not likely that you’ll receive the same results, but this is what our results looked like:

  [6, 3, 3, 2, -7]
  [6, 2]
### 5.7.26 A brief look at closures

Let’s start with a definition: closure is a technique which allows the storing of values in spite of the fact that the context in which they have been created does not exist anymore. Intricate? A bit.

Let’s start with a simple example →

```py
def outer(par):
  loc = par
var = 1
outer(var)
print(var)
print(loc)
```

The example is obviously erroneous. The last two lines will cause a `NameError` exception – neither `par` nor `loc` is accessible outside the function. Both the variables exist when and only when the `outer()` function is being executed.
### 5.7.27 A brief look at closures

We’ve modified the code significantly →

```py
def outer(par):
  loc = par
  def inner():
    retrn loc
  return inner

var = 1
fun = outer(var)
print(fun())

```

There is a brand new element in it – a function (named inner) inside another function (named outer).

How does it work? Just like any other function except for the fact that `inner()` may be invoked only from within `outer().` We can say that `inner()` is `outer()’s` private tool – no other part of the code can access it.

Look carefully:
- the `inner()` function returns the value of the variable accessible inside its scope, as `inner()` can use any of the entities at the disposal of `outer()`
- the `outer()` function returns the `inner()` function itself; more precisely, it returns a copy of the `inner()` function, the one which was frozen at the moment of `outer()’s` invocation; the frozen function contains its full environment, including the state of all local variables, which also means that the value of loc is successfully retained, although `outer()` ceased to exist a long time ago.

In effect, the code is fully valid, and outputs:

  1

The function returned during the `outer()` invocation is a closure.
### 5.7.28 A brief look at closures

A closure has to be invoked in exactly the same way in which it has been declared.

In the previous example, the `inner()` function was parameterless, so we had to invoke it without arguments.

It is fully possible to declare a closure equipped with an arbitrary number of parameters, e.g., one, just like the `power()` function →

```py
def makeclosure(par):
  loc = par
  def power(p):
    return p ** loc
  return power

fsqr = makeclosure(2)
fcub = makeclosure(3)
for i in range(5):
  print(i,fsqr(i),fcub(i))
```

This means that the closure not only makes use of the frozen environment, but it can also modify its behavior by using values taken from the outside.

This example shows one more interesting circumstance – you can create as many closures as you want using one and the same piece of code. This is done with a function named `makeclosure().` Note:
- the first closure obtained from `makeclosure()` defines a tool squaring its argument;
- the second one is designed to cube the argument.

This is why the code produces the following output:

  0 0 0 
  1 1 1 
  2 4 8 
  3 9 27 
  4 16 64
### 5.8.1 Accessing files from Python code

One of the most common issues in the developer’s job is to process data stored in files while the files are usually physically stored using storage devices – hard, optical, network, or solid-state disks.

It’s easy to imagine a program that sorts 20 numbers, and it’s equally easy to imagine the user of this program entering these twenty numbers directly from the keyboard.

It’s much harder to imagine the same task when there are 20,000 numbers to be sorted, and there isn’t a single user who is able to enter these numbers without making a mistake.

It’s much easier to imagine that these numbers are stored in the disk file which is read by the program. The program sorts the numbers and doesn’t send them to the screen, but instead creates a new file and saves the sorted sequence of numbers there.

If we want to implement a simple database, the only way to store the information between program runs is to save it into a file (or files if your database is more complex).

In principle, any non-simple programming problem relies on the use of files, whether it processes images (stored in files), multiplies matrices (stored in files), or calculates wages and taxes (reading data stored in files).

You may ask why we have waited until now to show you these issues.

The answer is very simple – Python’s way of accessing and processing files is implemented using a consistent set of objects. There is no better moment to talk about it.
### 5.8.2 File names

Different operating systems can treat the files in different ways. For example, Windows uses a different naming convention than the one adopted in Unix/Linux systems.

If we use the notion of a canonical file name (a name which uniquely defines the location of the file regardless of its level in the directory tree) we can realize that these names look different in Windows and in Unix/Linux →

  Windows
  `C:\directory\file`

  Unix
  `/directory/file` 

As you can see, systems derived from Unix/Linux don’t use the disk drive letter (e.g., C:) and all the directories grow from one root directory called / ,while Windows systems recognize the root directory as \.
### 5.8.3 File names

In addition, Unix/Linux system file names are case-sensitive. Windows systems store the case of letters used in the file name, but don’t distinguish between their cases at all.

This means that these two strings → describe two different files in Unix/Linux systems, but are the same name for just one file in Windows systems.

The main and most striking difference is that you have to use two different separators for the directory names: \ in Windows, and / in Unix/Linux.

This difference is not very important to the normal user, but is very important when writing programs in Python.

To understand why, try to recall the very specific role played by the \ inside Python strings. 
### 5.8.4 File names

Suppose you’re interested in a particular file located in the directory dir, and named file.

Suppose also that you want to assign a string containing the name of the file.

In Unix/Linux systems, it may look as follows →
`name = '/dir/file'`
### 5.8.5 File names

But if you try to code it for the Windows system:

  name = "\dir\file"

you’ll get an unpleasant surprise: either Python will generate an error, or the execution of the program will behave strangely, as if the file name has been distorted in some way.

In fact, it’s not strange at all, but quite obvious and natural. Python uses the \ as an escape character (like \n).

This means that Windows file names must be written as follows →

Fortunately, there is also one more solution. Python is smart enough to be able to convert slashes into backslashes each time it discovers that it’s required by the OS.

This means that any the following assignments:

  name = "/dir/file"
  name = "c:/dir/file"

will work with Windows, too.
### 5.8.6 File names

Any program written in Python (and not only in Python, because that convention applies to virtually all programming languages) does not communicate with the files directly, but through some abstract entities that are named differently in different languages or environments – the most-used terms are handles or streams (we’ll use them as synonyms here).

The programmer, having a more- or less-rich set of functions/methods, is able to perform certain operations on the stream, which affect the real files using mechanisms contained in the operating system kernel.

In this way, you can implement the process of accessing any file, even when the name of the file is unknown at the time of writing the program.

The operations performed with the abstract stream reflect the activities related to the physical file.

To connect (bind) the stream with the file, it’s necessary to perform an explicit operation.

The operation of connecting the stream with a file is called opening the file, while disconnecting this link is named closing the file.

Hence, the conclusion is that the very first operation performed on the stream is always open and the last one is close. The program, in effect, is free to manipulate the stream between these two events and to handle the associated file.

This freedom is limited, of course, by the physical characteristics of the file and the way in which the file has been opened.

Let us say again that the opening of the stream can fail, and it may happen due to several reasons: the most common is the lack of a file with a specified name.

It can also happen that the physical file exists, but the program is not allowed to open it. There’s also the risk that the program has opened too many streams, and the specific operating system may not allow the simultaneous opening of more than n files (e.g., 200).

A well-written program should detect these failed openings, and react accordingly.
### 5.8.7 File streams

The opening of the stream is not only associated with the file, but should also declare the manner in which the stream will be processed. This declaration is called an open mode.

If the opening is successful, the program will be allowed to perform only the operations which are consistent with the declared open mode.

There are two basic operations performed on the stream:
- read from the stream: the portions of the data are retrieved from the file and placed in a memory area managed by the program (e.g., a variable);
- write to the stream: the portions of the data from the memory (e.g., a variable) are transferred to the file.

### 5.8.8 File streams

There are three basic modes used to open the stream:
1. read mode: a stream opened in this mode allows read operations only; trying to write to the stream will cause an exception (the exception is named UnsupportedOperation, which inherits OSError and ValueError, and comes from the io module);
2. write mode: a stream opened in this mode allows write operations only; attempting to read the stream will cause the exception mentioned above;
3. update mode: a stream opened in this mode allows both writes and reads.

Before we discuss how to manipulate the streams, we owe you some explanation. The stream behaves almost like a tape recorder.

When you read something from a stream, a virtual head moves over the stream according to the number of bytes transferred from the stream.

When you write something to the stream, the same head moves along the stream recording the data from the memory.

Whenever we talk about reading from and writing to the stream, try to imagine this analogy. The programming books refer to this mechanism as the current file position, and we’ll also use this term.

It’s necessary now to show you the object responsible for representing streams in programs.
### 5.8.9 File handles

Python assumes that every file is hidden behind an object of an adequate class.

Of course, it’s hard not to ask how to interpret the word adequate.

Files can be processed in many different ways – some of them depend on the file’s contents, some on the programmer’s intentions. In any case, different files may require different sets of operations, and behave in different ways.

An object of an adequate class is created when you open the file and annihilate it at the time of closing.

Between these two events, you can use the object to specify what operations should be performed on a particular stream. The operations you’re allowed to use are imposed by the way in which you’ve opened the file.

In general, the object comes from one of the classes shown here →

`IOBase`
  - `RawIOBase`
  - `BufferedIOBase`
  - `TextIOBase`

Note: you never use constructors to bring these objects to life. The only way you obtain them is to invoke the function named open().

The function analyses the arguments you’ve provided, and automatically creates the required object.

If you want to get rid of the object, you invoke the method named close().

The invocation will sever the connection to the object, and the file and will remove the object.

For our purposes, we’ll concern ourselves only with streams represented by BufferIOBase and TextIOBase objects. You’ll understand why soon.
### 5.8.10 File handles

Due to the type of the stream’s contents, all the streams are divided into text and binary streams.

The latter ones are structured in lines; that is, they contain typographical characters (letters, digits, punctuation, etc.) arranged in rows (lines), as seen with the naked eye when you look at the contents of the file in the editor.

This file is written (or read) mostly character by character, or line by line.

The former files don’t contain text but a sequence of bytes of any value. This sequence can be, for example, an executable program, an image, an audio or a video clip, a database file, etc.

Because these files don’t contain lines, the reads and writes relate to portions of data of any size. Hence the data is read/written byte by byte, or block by block, where the size of the block usually ranges from one to an arbitrarily chosen value.

Then comes a subtle problem. In Unix/Linux systems, the line ends are marked by a single character named LF (ASCII code 10) designated in Python programs as \n.

Other operating systems, especially these derived from the prehistoric CP/M system (which applies to Windows family systems, too) use a different convention: the end of line is marked by a pair of characters, CR and LF (ASCII codes 13 and 10) which can be encoded as \r\n.

This ambiguity can cause various unpleasant consequences. If you create a program responsible for processing a text file, and it is written for Windows, you can recognize the ends of the lines by finding the \r\n characters, but the same program running in a Unix/Linux environment will be completely useless, and vice versa: the program written for Unix/Linux systems might be useless in Windows.

Such undesirable features of the program, which prevent or hinder the use of the program in different environments, is called non-portability.

Similarly, the trait of the program allowing execution in different environments is called portability. A program endowed with such a trait is called a portable program.
### 5.8.11 File handles

Since portability issues were (and still are) very serious, a decision was made to definitely resolve the issue in a way that doesn’t engage the developer’s attention.

It was done at the level of classes, which are responsible for reading and writing characters to and from the stream. It works in the following way:
1. when the stream is open and it’s advised that the data in the associated file will be processed as text (or there is no such advisory at all), it is switched into text mode;
2. during reading/writing of lines from/to the associated file, nothing special occurs in the Unix environment, but when the same operations are performed in the Windows environment, a process called a translation of newline characters occurs: when you read a line from the file, every pair of \r\n characters is replaced with a single \n character, and vice versa; during write operations, every \n character is replaced with a pair of \r\n characters;
3. the mechanism is completely transparent to the program, which can be written as if it was intended for processing Unix/Linux text files only; the source code run in a Windows environment will work properly, too;
4. when the stream is open and it’s advised to do so, its contents are taken as-is, without any conversion – no bytes are added or omitted.

### 5.8.12 Opening the streams

The opening of the stream is performed by a function which can be invoked in the following way →

`stream = open(file,mode='r',encoding=None)` 

Note: the mode and encoding arguments may be omitted – their default values are assumed then:
- the name of the function speaks for itself;
- if the opening is successful, the function returns a stream object; otherwise, an exception is raised (e.g., FileNotFoundError if the file you’re going to read doesn’t exist);
- the first parameter of the function specifies the name of the file to be associated with the stream;
- the second parameter specifies the open mode used for the stream; it’s a string filled with a sequence of characters, and each of them has its own special meaning (more details soon);
- the opening must be the very first operation performed on the stream.

Let us now present you with the most important and useful open modes.
### 5.8.13 Opening the streams

“r” open mode: read
- the stream will be opened in “read” mode
- the file associated with the stream must exist and has to be readable, otherwise open() function raises exception 

### 5.8.14 Opening the streams

“w” open mode: write
- the stream will be opened in “write” mode
- the file associated with the stream doesn't need to exist; if it doesn't exist it will be created; if it exists it will truncated to the length of zero (erased);  if the creation isn't possible (e.g. due to system permissions) the open() function raises an exception

### 5.8.15 Opening the streams

“a” open mode: append
- the stream will be opened in “append” mode;
- the file associated with the stream doesn't need to exist; if it doesn't exist it will be created; if it exists the virtual recording head will be set at the end of the file (the previous content of the file remains untouched)

### 5.8.16 Opening the streams

“r+” open mode: read and update
- the stream will be opened in “read and update” mode;
- the file associated with the stream must exist and has to be writeable, otherwise the open() function raises an exception
- both read and write operations are allowed for the stream

### 5.8.17 Opening the streams

“w+” open mode: write and update
- the stream will be opened in “write and update” mode;
- the file associated with the stream doesn't need to exist; if it doesn't exist it will be created; the previous content of the file remains untouched
- both read and write operations are allowed for the stream 
### 5.8.18 Selecting text and binary modes

If there is a letter b at the end of the mode string it means that the stream is to be opened in the binary mode. If the mode string ends with a letter t the stream is opened in the text mode. This is the default behaviour assumed when no binary/text mode specifier was used.

Finally, the successful opening of the file will set the current file position (the virtual reading/writing head) before the first byte of the file if the mode is not a and after the last byte of file if the mode is set to a.
### 5.8.19 Opening the stream for the first time

Imagine that we want to develop a program that reads content of the text file named:

  C:\Users\User\Desktop\file.txt

How to open that file for reading? Here's the relevant snippet of the code →

```py
try: 
  stream = open("c:/users/user/Desktop/file.txt","r")
  # actual processing goes here
  stream.close()
except Exception as exc:
  print("open failed:", exc)
```

What's going on here?
- we've open the try-except block as we want to handle runtime errors softly
- we use the open() function to try to open the specified file (note the way we've specified the file name)
- the open mode is defined as text to read (as text is default setting, we can skip the t in mode string)
- in case of success we get an object from the open() function and we assign it to the stream variable;
- if open() fails, we handle the exception printing full error information (it's definitely good to know what exactly happened) 
### 5.8.20 Pre-opened streams

We said earlier that any stream operation must be preceded by the open() function invocation. There are three well-defined exceptions to the rule. When our program starts the three streams are already opened and don't require any extra preparations. What's more, your program can use these streams explicitly if you take care to import the sys module:

`import sys`

because that's where the declaration of the three streams is placed.

The names of these streams look as follows →
- `sys.stdin`
- `sys.stdout`
- `sys.stderr`

### 5.8.21 Pre-opened streams

stdin (as standard input)
- the stdin stream is normally associated with the keyboard, pre-open for reading and regarded as the primary data source for the running programs
- the well-known input() function reads data from stdin by default

### 5.8.22 Pre-opened streams

stdout (as standard output)
- the stdout stream is normally associated with the screen, pre-open for writing, regarded as the primary target for outputting data by the running program
- the well-known print()function outputs the data to stdout stream

### 5.8.23 Pre-opened streams

stderr (as standard error output)
- the stderr stream is normally associated with the screen, pre-open for writing, regarded as the primary place where the running program should send information on the errors encountered during its work
- we haven't presented any method to send the data to this stream (we will do it soon, we promise)
- The separation of stdout (useful results produced by the program) from the stderr (error messages, undeniably useful but does not provide results) gives the possibility of redirecting these two types of information to the different targets. More extensive discussion of this issue is beyond the scope of our course. The operation system handbook will provide more information on these issues.  
### 5.8.24 Closing streams

The last operation performed on a stream (this doesn't include the stdin, stdout, and stderr streams which don't require it) should be closing. That action is performed by a method invoked from within open stream object →

- the name of the function is definitely self-commenting
- the function expects exactly no arguments;  the stream doesn't need to be opened
- the function returns nothing but raises IOError exception in case of error
- most developers believe that the close() function always succeeds and thus there is no need to check if it's done its task properly. This belief is only partly justified. If the stream was opened for writing and then a series of write operations were performed it may happen that the data sent to the stream has not been transferred to the physical device yet (due to mechanism called caching or buffering). Since the closing of the stream forces the buffers to flush them, it may be that the flushes fail and therefore the close() fails too.

We have already mentioned failures caused by functions operating with streams but not mentioned a word how exactly we can identify the cause of the failure. The possibility of making a diagnosis exists and is provided by one of streams' exception component which we are going to tell you about just now.
### 5.8.25 Diagnosing stream problems

The IOError object is equipped with a property named errno (the name comes from the phrase error number) and you can access it as follows →

The value of the errno attribute can be compared with one of the predefined symbolic constants defined in the errno module.

```py
try:
  # some operations
except IOError as exc:
  print(exc.errno)
```

### 5.8.26 Diagnosing stream problems

We present a couple of constants useful for detecting stream errors →

- `errno.EACCES` (Permission denied) occurs when you try to open a file with the "read only" attribute for writing, for example
- `errno.EBADF` (Bad file number) occurs when you try to operate with the unopened stream, for example
- `errno.EEXIST` (File exists) occurs when you try to rename a file with its previous name, for example
- `errno.EFBIG` (File too big) occurs when you create a file that is larger than the maximum allowed by the OS
- `errno.EISDIR` (Is a directory) occurs when you try to treat the directory name as the name of the ordinary file
- `errno.EMFILE` (too many open files) occurs when you try to simultaneously open more streams than acceptable for your operating system
- `errno.ENOENT` (no such file or directory) occurs when you try to access non-existent file/directory
- `erno.ENOSPC` (no space left) occurs when there is no free space on the media
  
The complete list is much longer (it includes also some error codes not related to the stream processing)

### 5.8.27 Diagnosing stream problems

If you are a very careful programmer, you may feel the need to use the sequence of statements similar to those presented aside →

```py
import errno
try: 
  stream = open("c:/users/user/Desktop/file.txt","r")
  # actual processing goes here
  stream.close()
except Exception as exc:
  if exc.errno == errno.ENOENT:
    print("The file doesn't exist")
  elif exc.errno == errno.EMFILE:
    print("You've opened to many files")
  else:
    printf("The error number is",exc.errno)
```

### 5.8.28 Diagnosing stream problems

Fortunately, there is a function that can dramatically simplify the error handling code. It’s named strerror(), it comes from os module and expects just one argument – an error number.

Its role is simple: you give an error number and get a string describing the meaning of the error.

Note: if you pass a non-existent error code (a number which is not bound to any actual error), the function will raise ValueError exception.

Now we can simplify our code in the following way →

```py
from os import strerror
try: 
  stream = open("c:/users/user/Desktop/file.txt","r")
  # actual processing goes here
  stream.close()
except Exception as exc:
  print("File could not be opened:",strerror(exc.errno));
```
### 5.9.1 Dealing with text files

Prepare a simple text file with some short, simple content.

We’re going to show you some basic techniques you can utilize to read the file contents in order to process them.

The processing will be very simple – you’re going to copy the file’s contents to the console, and count all the characters the program has read in.

But remember – our understanding of a text file is very strict. In our sense, it’s a plain text file – it may contain only text, without any additional decorations (formatting, different fonts, etc.).

Don’t create the file using any advanced text processor like MS Word, LibreOffice Writer, or something like this. Use the very basics your OS offers: Notepad, vim, gedit, etc.

If your text files contain some national characters not covered by the standard ASCII charset, you may need an additional step. Your open() function invocation may require an argument denoting specific text encoding.

For example, if you’re using a Unix/Linux OS configured to use UTF-8 as a system-wide setting, the open() function may look as follows:

`str = open('file.txt', 'rt', encoding='utf-8')`

where the encoding argument has to be set to a value which is a string representing proper text encoding (UTF-8, here).

Consult your OS documentation to find an encoding name adequate to your environment.

We’ve assumed that your sample text is placed in a text file name text.txt. We’ll use this name in all our snippets.
### 5.9.2 Dealing with text files

Reading the text file’s contents can be performed using several different methods – none of them is any better or worse than any other. It’s up to you which of them you prefer and like. Some of them will sometimes be handier, and sometimes more troublesome. Be flexible. Don’t be afraid to change your preferences.

The most basic of these methods is the one offered by the read() function.

If applied to a text file, the function is able to:
- read a desired number of characters (including just one) from the file, and return them as a string;
- read all the file contents, and return them as a string;
- if there is nothing more to read (the virtual reading head reaches the end of the file), the function returns an empty string.

We’ll start with the simplest variant →

```py
from os import strerror
try:
  cnt = 0
  s = open('text.txt',"rt")
  ch = s.read(1)
  while ch != '':
    print(ch,end='')
    cnt += 1
    ch = s.read(1)
  s.close()
  print("Characters in file:", cnt)
except IOError as e:
  print("I/O error occurred: ", strerror(e.errno))
``` 

The routine is rather simple:

- use the try-except mechanism and open the file of the predetermined name;
- try to read the very first character from the file;
- if you succeed (this is proven by a positive result of the while condition check) output the character (note the end= argument – it’s important! You don’t want to skip to a new line after every character!);
- update the counter, too;
- try to read the next character, and the process repeats.  
### 5.9.3 Dealing with text files

If you’re absolutely sure that the file’s length is safe and you can read the whole file to the memory at once, you can do it – the read() function, invoked without any arguments or with an argument that evaluates to None, will do the job for you.

Remember – reading a terabyte-long file using this method may corrupt your OS.

Don’t expect miracles – computer memory isn’t stretchable.

What do you think of it? →

```py
from os import strerror
try:
	cnt = 0
	s = open('text.txt','rt')
	content = s.read()
	for ch in content:
		print(ch,end='')
		cnt += 1
	s.close()
	print("Characters in file:", cnt)
except IOError as e:
	print("I/O error occurred: ", strerr(e.errno))
``` 

1. open the file as previously;
2. read its contents by one read() function invocation;
3. next, process the text, iterating through it with a regular for loop, and updating the counter value at  each turn of the loop;

The result will be exactly the same as previously.
### 5.9.4 Dealing with text files

If you want to treat the file’s contents as a set of lines, not a bunch of characters, the readline() method will help you with that.

The method tries to read a complete line of text from the file, and returns it as a string in the case of success. Otherwise, it returns an empty string.

This opens up new opportunities – you can also count lines easily, not only characters.

Let’s make use of it. Just like here →

```py
from os import strerror
try:
  ccnt = lcnt = 0
  s = open('text.txt','rt')
  line = s.readline()
  while line != '':
    lcnt += 1
    for ch in line:
      print(ch,end='')
      ccnt += 1
    line = s.readline()
  s.close()
  print("Characters in file:", ccnt)
  print("Lines in file:     ", lcnt)
except IOError as e:
  print("I/O error occurred: ", strerr(e.errno))
```

As you can see, the general idea is exactly the same as in both previous examples.

### 5.9.5 Dealing with text files

Another method, which treats text file as a set of lines, not characters, is readlines().

The readlines() method, when invoked without arguments, tries to read all the file contents, and returns a list of strings, one element per file line.

If you’re not sure that the file size is small enough and don’t want to test the OS, you can convince the readlines() method to read not more than a specified number of bytes at once (the returning value remains the same – it’s a list of a string).

The maximum accepted input buffer size is passed to the method as its argument.

You may expect that readlines() can process a file’s contents more effectively than readline(), as it may need to be invoked fewer times.

Note: when there is nothing to read from the file, the method returns an empty list. Use it to detect the end of the file.

To the extent of the buffer’s size, you can expect that increasing it may improve input performance, but there is no golden rule for it – try to find the optimal values yourself.

We’ve modified the code to show you how to use readlines()→

```py
from os import strerror
try:
  ccnt = lcnt = 0
  s = open('text.txt','rt')
  lines = s.readlines(20)
  while len(lines) != 0:
    for line in lines:
      lcnt += 1
      for ch in line:
        print(ch,end='')
        ccnt += 1
    lines = s.readline(10)
  s.close()
  print("Characters in file:", ccnt)
  print("Lines in file:     ", lcnt)
except IOError as e:
  print("I/O error occurred: ", strerr(e.errno))
```

We’ve decided to use a 15-byte-long buffer. Don’t think it’s a recommendation.

We’ve used such a value to avoid the situation in which the first readlines() invocation consumes the whole file.

We want the method to be forced to work harder, and to demonstrate its capabilities.

There are two nested loops in the code – the outer one uses readlines()’s result to iterate through it, while the inner one prints the lines character by character.
### 5.9.6 Dealing with text files

The last example we want to present shows a very interesting trait of the object returned by the open() function in text mode.

We think it may surprise you – the object is an instance of the iterable class.

Strange? Not at all.

Usable? Yes, absolutely.

The iteration protocol defined for the file object is very simple – its `__next__` method just returns the next line read in from the file.

Moreover, you can expect that the object automatically invokes close() when any of the file reads reaches the end of the file.

Look how simple and clear the code has now become →

```py
from os import strerror
try:
	ccnt = lcnt = 0
	for line in open('text.txt','rt'):
		lcnt += 1
		for ch in line:
			print(ch,end='')
			ccnt += 1
	print("Characters in file:", ccnt)
	print("Lines in file:     ", lcnt)
except IOError as e:
	print("I/O error occurred: ", strerr(e.errno))
```
### 5.9.7 Dealing with text files
Writing text files seems to be simpler, as in fact there is one method that can be used to perform such a task.\
The method is named write() and it expects just one argument – a string that will be transferred to an open file (don’t forget – the open mode should reflect the way in which the data is transferred – writing a file opened in read mode won’t succeed).\
No newline character is added to the write()’s argument, so you have to add it yourself if you want the file to be filled with a number of lines.\
The example presented here → shows a very simple code that creates a file named newtext.txt (note: the open mode w ensures that the file will be created from scratch, even if it exists and contains data) and then puts ten lines into it.\
The string to be recorded consists of the word line, followed by the line number. We’ve decided to write the string’s contents character by character (this is done by the inner for loop) but you’re not obliged to do it in this way.\
We just wanted to show you that write() is able to operate on single characters.\
The code creates a file filled with the following text:
```
  line #1
  line #2
  line #3
  line #4
  line #5
  line #6
  line #7
  line #8
  line #9
  line #10
```

```py
from os import strerror
try:
  fo = open('newtext.txt','wt')
  for i in range(10):
    s = "line #" + str(i+1) + "\n"
    for ch in s:
      fo.write(ch)
  fo.close()
except IOError as e:
  print("I/O error occurred: ", strerr(e.errno))
```

### 5.9.8 Dealing with text files
We’ve modified the previous code to write whole lines to the text file – this is how it looks →
```py
from os import strerror
try:
	fo = open('newtext.txt','wt')
	for i in range(10):
		fo.write("line #" + str(i+1) + "\n")
	fo.close()
except IOError as e:
	print("I/O error occurred: ", strerr(e.errno))
```
The contents of the newly created file are the same.\
Note: you can use the same method to write to the stderr stream, but don’t try to open it, as it’s always open implicitly.\
For example, if you want to send a message string to stderr to distinguish it from normal program output, it may look like this:
```py
import sys
sys.stderr.write("Error message") 
```

### 5.9.9 What is bytearray?
Before we start talking about binary files, we have to tell you about one of the specialized classes Python uses to store amorphous data.\
Amorphous data is data which have no specific shape or form – they are just a series of bytes.\
This doesn’t mean that these bytes cannot have their own meaning, or cannot represent any useful object, e.g., bitmap graphics.\
The most important aspect of this is that in the place where we have contact with the data, we are not able to, or simply don’t want to, know anything about it.\
Amorphous data cannot be stored using any of the previously presented means – they are neither strings nor lists.\
There should be a special container able to handle such data.\
Python has more than one such container – one of them is a specialized class name bytearray – as the name suggests, it’s an array containing (amorphous) bytes.\
If you want to have such a container, e.g., in order to read in a bitmap image and process it in any way, you need to create it explicitly, using one of available constructors.\
Take a look →
```py
data = bytearray(100)
```
Such an invocation creates a bytearray object able to store ten bytes.\
Note: such a constructor fills the whole array with zeros.

### 5.9.10 What is bytearray?
Byte arrays resemble lists in many respects. For example, they are mutable, they’re a subject of the len() function, and you can access any of their elements using conventional indexing.\
There is one important limitation – you mustn’t set any byte array elements with a value which is not an integer (violating this rule will cause a TypeError exception) and you’re not allowed to assign a value that doesn’t come from the range 0 to 255 inclusive (unless you want to provoke a ValueError exception).\
You can treat any byte array elements as integer values – just like in this example →
```py
data = bytearray(10)
for i in range(len(data)):
  data[i] = 10 - i
for b in data:
  print(hex(b))
```
Note: we’ve used two methods to iterate the byte arrays, and made use of the hex() function to see the elements printed as hexadecimal values.\
Now we’re going to show you how to write a byte array to a binary file – binary, as we don’t want to save its readable representation – we want to write a one-to-one copy of the physical memory content, byte by byte.
