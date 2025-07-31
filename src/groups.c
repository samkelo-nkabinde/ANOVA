#include "utils.h"
#include "groups.h"
groupPtr create_group(double data[], int count, char* name)
{
    groupPtr group = (groupPtr)malloc(sizeof(Group));
    group -> data = data;
    group -> count = count;
    group -> name = string_alloc(name);
    group -> sum = sum(data, count);
    group -> average = mean(data, count);
    group -> varience = varience(data, count);
    return group;
}
