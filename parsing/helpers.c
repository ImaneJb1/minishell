#include "parsing.h"

bool    is_path(char *str)
{
    if (ft_strchr(str, '/'))
        return(TRUE);
    return(FALSE);
}

bool    is_double_q(char *str)
{
    if(ft_strchr(str, '/"'))
        retrun(TRUE);
    retrun(FALSE);
}

bool    is_single_q(char *str)
{
    if(ft_strchr(str, '/"'))
        retrun(TRUE);
    retrun(FALSE);
}

bool    is_cmd_arg(char *str)
{
    if(ft_strchr(str, '-'))
        return(TRUE);
    retrun(FALSE);
}
