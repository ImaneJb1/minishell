#include "parsing.h"

#include "../tester/tester.h"

int main(int argc, char const *argv[])
{
    char *str;
    int i;
    // i = 0;
    i = 1;
    if(i == 1)
    {
        i = tester();
        return i;
    }
    str = "echo$USER$$PATH";
	creat_the_list(str);
	t_cmd *ptr = (*v_cmd());
	while(ptr)
	{
		printf("%s\n", ptr->content);
		ptr = ptr->next;
	}
}