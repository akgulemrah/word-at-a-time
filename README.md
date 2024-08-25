# word_at_a_time

`word_at_a_time is a simple C utility that helps you pull words from a string, one at a time. This header file includes a straightforward function that lets you extract words from a source string and put them into a buffer. It’s perfect for when you need to handle text efficiently, processing it word by word as you go.


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
#include "word_at_a_time.h"
#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	char *str = "Lorem ipsum dolor sit amet, consectetur adipisicing elit, "
		"sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. "
		"Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris "
		"nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in "
		"reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla "
		"pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa "
		"qui officia deserunt mollit anim id est laborum.";
	char buf[50];

	// 
	if (!word_at_a_time(str, buf))
		printf("%s | ", buf);
	else
		return EXIT_FAILURE;
	
	while (!word_at_a_time(0, buf))
		printf("%s | ", buf);
	return EXIT_SUCCESS;
}
```
##License
Unlicense

This header file is provided "as is" and is intended for personal use only. There is no warranty for this code, and it is not licensed for commercial purposes. Use this utility at your own risk. The author accepts no responsibility for any issues or damages that may arise from using this code.
