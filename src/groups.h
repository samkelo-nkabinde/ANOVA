#ifndef GROUPS_H
#define GROUPS_H

typedef struct {

    double* data;
    int count;
    char* name;

} Group;
typedef Group* group_t;
group_t set_group(double* data, int count, char* name);

#endif
