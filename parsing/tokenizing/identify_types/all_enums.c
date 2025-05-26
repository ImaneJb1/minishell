#include "../../parsing.h"

void	identify_all_types(void)
{
	if(!v_cmd() ||!(*v_cmd()))
		return;
	identify_symbols();
	identify_delimiter();
	identify_file();
	identify_path();
	identify_cmd(); 
	hanlde_case();
	//commad case
	identify_cmd_arg();
	identify_double_q();
	identify_single_q();    
	identify_var();
}
