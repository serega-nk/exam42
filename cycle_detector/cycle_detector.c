#include <unistd.h>
#include "list.h"

int		cycle_detector(const t_list *list)
{
	const t_list	*walk;

	walk = list;
	while (list && walk && walk->next)
	{
		list = list->next;
		walk = walk->next->next;		
		if (walk == list)
			return (1);
	}
	return (0);
}
