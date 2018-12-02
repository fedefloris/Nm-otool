#include "nm_otool.h"
#include "nm.h"

// static t_symbol	*get_middle_symbol(t_symbol *symbols)
// {
// 	t_symbol *fast;
// 	t_symbol *slow;
//
// 	if (!symbols)
// 		return ;
// 	slow = symbols;
// 	fast = symbols;
// 	while (fast->next && fast->next->next)
// 	{
// 		slow = slow->next;
// 		fast = fast->next->next;
// 	}
// 	return (slow);
// }
//
// static t_symbol	*subdivide(t_symbol *head)
// {
// 	t_symbol	*middle;
// 	t_symbol	*after_middle;
//
// 	middle = get_middle_symbol(head);
// 	after_middle = middle->next;
// 	middle->next = NULL;
// 	return (merge(subdivide(head), subdivide(after_middle)));
// }

void						sort_symbols(t_nm_otool *nm_otool, t_symbol **symbols)
{
	if (!*symbols || !(*symbols)->next || op(nm_otool, 'p'))
		return ;
	// *symbols = subdivide(*symbols);
}
