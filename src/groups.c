#include "utils.h"
#include "groups.h"
group_t set_group(double data[], int count, char* name)
{
    group_t group = (group_t)malloc(sizeof(Group));
    group -> data = data;
    group -> count = count;
    group -> name = string_alloc(name);

    return group;
}
