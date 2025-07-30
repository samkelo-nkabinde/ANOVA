#include "utils.h"
#include "groups.h"
group_t create_group(double data[], int count, char* name)
{
    group_t group = (group_t)malloc(sizeof(Group));
    group -> data = data;
    group -> count = count;
    group -> name = string_alloc(name);
    group -> sum = sum(data, count);
    group -> average = mean(data, count);
    group -> varience = varience(data, count);
    return group;
}
