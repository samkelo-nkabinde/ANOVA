#ifndef GROUPS_H
#define GROUPS_H

typedef struct {
    char* name;
    double* data;
    int count;
    double sum;
    double average;
    double varience;

} Group;
typedef Group* groupPtr;
groupPtr create_group(double* data, int count, char* name);
#endif
