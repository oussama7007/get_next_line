Functions in Detail
1. ft_free
Purpose: Combines the existing buffer (buffer) with newly read data (buf) and frees the old buffer to avoid memory leaks.

Key Steps:
Combines buffer and buf using ft_strjoin.
Frees the memory of the old buffer.
Returns the newly created string.


3. ft_next
Purpose: Updates the buffer to keep only the unprocessed part of the data (the part after the newline).

Key Steps:
Locates the newline (\n) in the buffer.
If no newline is found, the function frees the buffer and returns NULL (indicating no more lines).
Allocates memory for the remaining data in the buffer (after the newline).
Copies the remaining data into the newly allocated buffer and frees the old buffer.
Returns the updated buffer.


5. ft_line
Purpose: Extracts a single line (up to and including the newline) from the buffer.

Key Steps:
Locates the end of the first line (up to \n or the end of the string).
Allocates memory for the line, including space for the newline and null terminator.
Copies characters from the buffer up to the newline.
Adds the newline (if it exists) and null terminator to the line.
Returns the extracted line.


7. read_file
Purpose: Reads data from the file descriptor (fd) and appends it to the existing buffer (res).

Key Steps:
Allocates a temporary buffer (buffer) for reading.
Reads up to BUFFER_SIZE bytes from the file descriptor into the buffer.
If the read operation fails, it frees the buffer and returns NULL.
Appends the newly read data to the res using ft_free.
Stops reading further if a newline is found.
Frees the temporary buffer and returns the updated res.


9. get_next_line
Purpose: The main function that combines all the helper functions to return a single line from a file descriptor.

Key Steps:
Validates the file descriptor (fd) and BUFFER_SIZE.
Calls read_file to read data into the static buffer.
If the buffer is NULL, it means there's no more data to read, and the function returns NULL.
Extracts a single line from the buffer using ft_line.
Updates the buffer to hold only the remaining data after the newline using ft_next.
Returns the extracted line.


#Static Variable
The buffer is declared as a static char*. This means its value persists between calls to get_next_line. This is essential because:
It allows the function to keep track of leftover data that was not processed in the previous call.

#How It All Comes Together
On the first call to get_next_line, the file is read into the buffer.
The first line is extracted and returned. The buffer is updated to hold the leftover data.
On subsequent calls, the process repeats using the leftover data from the buffer and reading more from the file if necessary.
When no more data is left, the function returns NULL.


#Memory Management
Memory is dynamically allocated for the buffer, the lines, and temporary storage.
Every allocated memory is freed once it is no longer needed to prevent memory leaks.
The leaks tool checks for unfreed memory, ensuring the implementation is clean.

