#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int main() {
int fd;
char buf1[100] = "just a test\n";
char buf2[100];
// Open the file &quot;tfile&quot; with read and write permissions. Create it if it doesn&#39;t exist.
fd = open("tfile", O_RDWR | O_CREAT, 0644);
if (fd < 0) {
perror("Failed to open file");
return 1;
}
// Write initial text to the file
write(fd, buf1, strlen(buf1));
// Get user input
printf("\nEnter your text now:" );
if (fgets(buf1, sizeof(buf1), stdin) == NULL) {
perror("Error reading input");
close(fd);
return 1;
}
// Remove trailing newline character from fgets
buf1[strcspn(buf1, "\n")] = '\0';
// Write user input to the file
write(fd, buf1, strlen(buf1));
// Reset the file descriptor offset to the beginning of the file
lseek(fd, 0, SEEK_SET);
// Read and display the file contents
ssize_t bytesRead = read(fd, buf2, sizeof(buf2) - 1);
if (bytesRead < 0) {
perror("Error reading file");
close(fd);
return 1;
}
buf2[bytesRead] = '\0'; // Null-terminate the buffer

printf("\nFile contents:\n%s\n ", buf2);
// Close the file
close(fd);
return 0;
}
