#include "header.h"

char	*get_current_directory_path()
{
	char	*buf;
	char	*ptr;

	if ((buf = (char *)malloc((size_t)MAX_PATH_LENGTH)) != NULL)
		ptr = getcwd(buf, (size_t)MAX_PATH_LENGTH);
	else
		return NULL;
	return ptr;
}
