# K&R Exercise 1-11

Solution to Exercise 1-11 from Kernighan and Ritchie (1988).

## Instruction

How can we test the program listed below? What kinds of input are most likely to uncover bugs if there are any?

## Solution

The program counts words, lines, and characters. Three whitespace characters act as word delimiters: space, newline, and tab. These whitespace characters still contribute to the character count because `nc` is incremented for every character read.

<https://github.com/HenrikSamuelsson/kernighan-and-ritchie-1988/blob/dfd10dd5919acca2728b1fcf667e8bf8db80c597/exercises/chapter_01/exercise_11/main.c#L1-L35>

Since the complete source code is available, white-box testing can be
performed. Black-box testing is typically used when only requirements are
available.

One initial white-box approach is to set breakpoints and feed the program input character by character, verifying that the intended paths execute. We can also verify that the `IN` and `OUT` state transitions occur as expected.

Next, prepare systematic test inputs to exercise all relevant paths in the
program. For each test, compute the expected (nl, nw, nc) and compare against the program output. When designing test cases, it is important to think about boundary conditions and extreme or unusual inputs.

In the examples below, `<TAB>` denotes a literal tab character.

Examples of test data.

Empty input:

```text

```

Single character:

```text
a
```

Two characters separated by space:

```text
a b
```

Two characters separated by tab:

```text
a<TAB>b
```

Two characters separated by newline:

```text
a
b
```

Multi-character words separated by different types of whitespace:

```text
abc abc
abc<TAB>abc
abc

```

Leading and trailing whitespace:

```text
 abc 
<TAB>abc<TAB>
```

Multiple consecutive delimiters between words:

```text
a     b
a<TAB><TAB>b
a

b
```

Word followed immediately by EOF:

```text
abc
```

When we ensured that basic test cases work as expected we should also stress test the program with extreme cases such as very long words or big files.

``` text
canTheProgramHandleVeryLongWordsLongerThanTheLongestWordsInEnglish
```

## Answer

Testing is a large topic, but for a small program like this, we can reach a high degree of confidence with a systematic set of inputs. Start with normal cases, then add boundary and corner cases such as empty input, multiple consecutive delimiters, and inputs that end immediately after a word. Having the source code (or detailed requirements) helps ensure the tests cover all relevant paths and state transitions.

## References

Kernighan, B. W., & Ritchie, D. M. (1988). *The C programming language* (2nd ed.). Prentice Hall.
