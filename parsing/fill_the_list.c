#include "parsing.h"

void    add_to_list(char ch, int flag)
{
	static char *str;
	t_cmd *node;
	// t_cmd *list;

	if(flag == 0)
		str = NULL;
	else if(flag == 1)
		str = join_str_char(str, ch);
	else if(flag == 2)
	{
		node = new_node(str);
		lstadd_back(v_cmd(), node);
	}
}

// int main()
// {
// 	add_to_list('a',1);
// 	add_to_list('b',1);
// 	add_to_list('c',1);
// 	add_to_list('d',1);
// 	add_to_list(0,2);
// 	add_to_list(0,0);
// 	add_to_list('1',1);
// 	add_to_list('2',1);
// 	add_to_list('3',1);
// 	add_to_list('4',1);
// 	add_to_list(0,2);

// 	t_cmd *ptr = (*v_cmd());
// 	while(ptr)
// 	{
// 		printf("%s\n", ptr->content);
// 		ptr = ptr->next;
// 	}
// 	return 0;
// }
