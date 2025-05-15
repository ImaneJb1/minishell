#include "../../parsing.h"

void	identify_all_types(void)
{
	if(!v_cmd() ||!(*v_cmd()))
		return;
	identify_symbols();
	identify_delimiter();
	identify_cmd();
	identify_file();
	identify_path();
	identify_double_q();
	identify_single_q();    
	hanlde_case();
	identify_cmd_arg();
	identify_var();
}
