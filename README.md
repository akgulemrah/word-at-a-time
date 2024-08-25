# word_at_a_time

`word_at_a_time` is a C utility designed to extract words from a string, one at a time. This header file defines a function to parse words from a source string and store them into a buffer. The function is particularly useful for processing text in a memory-efficient way, where the source string can be progressively parsed word by word.

## Features

- **Extract Words**: Retrieve one word at a time from the source string.
- **Static Pointer Management**: Maintain the current position in the source string across multiple calls.
- **Flexible Input**: Initialize with a new source string or continue parsing from the previous position.

## Function

### `int word_at_a_time(char *src, char *buf)`

#### Description

This function extracts the next word from the `src` string and copies it to `buf`. 

- **Parameters**:
  - `src`: A pointer to the source string. If `src` is `NULL`, the function will continue from the last position set by a previous call.
  - `buf`: A pointer to the buffer where the extracted word will be stored.

- **Returns**:
  - `0` if a word was successfully extracted and copied to `buf`.
  - `-1` if there are no more words to extract or if `src` is `NULL` and no previous source was set.

#### Behavior

- If `src` is not `NULL`, it updates the internal pointer to start extracting from this new source.
- Skips any leading spaces in the source string.
- Copies characters from the source to the buffer until it encounters a space or the end of the string.
- Null-terminates the buffer after the word.

## Example Usage

```c
#include <stdio.h>
#include <string.h>
#include "word_at_a_time.h"

int main() {
    char src[] = "Hello world from ChatGPT";
    char buf[50];

    // Initialize the source
    word_at_a_time(src, buf);
    printf("First word: %s\n", buf); // Output: Hello

    // Continue to extract the next word
    word_at_a_time(NULL, buf);
    printf("Second word: %s\n", buf); // Output: world

    // Continue to extract the next word
    word_at_a_time(NULL, buf);
    printf("Third word: %s\n", buf); // Output: from

    // Continue to extract the next word
    word_at_a_time(NULL, buf);
    printf("Fourth word: %s\n", buf); // Output: ChatGPT

    // Attempt to extract further will return -1
    if (word_at_a_time(NULL, buf) == -1) {
        printf("No more words\n"); // Output: No more words
    }

    return 0;
}
