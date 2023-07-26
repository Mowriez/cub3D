#include <unistd.h>

int main(void)
{
	write(1, "test", 5);
	return (0);
}
