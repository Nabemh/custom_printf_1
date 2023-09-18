#include <unistd.h>
#include <errno.h>

ssize_t _write(int file_des, const void *buff, size_t count)
{
	ssize_t written_bytes = write(file_des, buff, count);

	if (written_bytes == -1)
		errno = EIO;

	return written_bytes;
}


