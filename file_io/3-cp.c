#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void close_fd(int fd);
void copy_loop(int fd_from, int fd_to, char *file_from, char *file_to);

/**
 * main - Copies the content of a file to another file.
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success, or exits with specific error codes
 */
int main(int argc, char **argv)
{
	int fd_from, fd_to;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		close_fd(fd_from);
		exit(99);
	}

	copy_loop(fd_from, fd_to, argv[1], argv[2]);
	close_fd(fd_from);
	close_fd(fd_to);

	return (0);
}

/**
 * copy_loop - Copies data from one file descriptor to another.
 * @fd_from: file descriptor to read from.
 * @fd_to: file descriptor to write to.
 * @file_from: name of the source file (for error messages).
 * @file_to: name of the destination file (for error messages).
 *
 * Description: Reads up to 1024 bytes at a time from @fd_from and writes
 * them to @fd_to until EOF or an error occurs. On read/write error,
 * prints an error message to stderr and exits with the proper code.
 */
void copy_loop(int fd_from, int fd_to, char *file_from, char *file_to)
{
	ssize_t rd, wr;
	char buffer[1024];

	while ((rd = read(fd_from, buffer, 1024)) > 0)
	{
		wr = write(fd_to, buffer, rd);
		if (wr == -1 || wr != rd)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
			close_fd(fd_from);
			close_fd(fd_to);
			exit(99);
		}
	}

	if (rd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
		close_fd(fd_from);
		close_fd(fd_to);
		exit(98);
	}
}

/**
 * close_fd - Closes a file descriptor and handles errors.
 * @fd: file descriptor to close.
 *
 * Description: If closing @fd fails, prints an error message to stderr
 * and exits with status code 100.
 */
void close_fd(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}
