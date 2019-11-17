//
// Created by 李汝新 on 2019-11-17.
//

#ifndef VECTOR_TEMPLATE_DEFINE_H
#define VECTOR_TEMPLATE_DEFINE_H

#include <stdlib.h>
#include "vector_template_declare.h"

#define VECTOR_CREATE_DEFINE(DataType) \
Vector(DataType) Create##DataType##Vector(int capacity, VectorAssignFn##DataType assignFn) \
{ \
    if (capacity < 1) { \
        return NULL; \
    } \
    Vector(DataType) vec = (Vector(DataType))malloc(sizeof(Vector##DataType##Struct)); \
    if (vec == NULL) { \
        return NULL; \
    } \
    vec->base = (DataType*)malloc(sizeof(DataType) * capacity); \
    if (vec->base == NULL) { \
        VectorDestroy(DataType, vec); \
        return NULL; \
    } \
    vec->capacity = capacity; \
    vec->curSize = 0; \
    vec->assignFn = assignFn; \
    return vec; \
}

#define VECTOR_DESTROY_DEFINE(DataType) \
void Destroy##DataType##Vector(Vector(DataType)* vec) \
{ \
    if ((vec == NULL) || ((*vec) == NULL)) { \
        return; \
    } \
    if ((*vec)->base != NULL) { \
        free((*vec)->base); \
        (*vec)->base = NULL; \
    } \
    free(*vec); \
    (*vec) = NULL; \
}

#define VECTOR_GETAT_DEFINE(DataType) \
DataType* VectorGet##DataType##At(Vector(DataType) vec, int pos) \
{\
    return VectorIsCreated(vec) ? &(vec->base[pos]) : NULL; \
}

#define VECTOR_GETSIZE_DEFINE(DataType) \
int Vector##DataType##GetSize(Vector(DataType) vec) \
{ \
    return VectorIsCreated(vec) ? vec->curSize : 0; \
}

#define VECTOR_GETCAPACITY_DEFINE(DataType) \
int Vector##DataType##GetCapacity(Vector(DataType) vec) \
{ \
    return VectorIsCreated(vec) ? vec->capacity : 0; \
}

#define VECTOR_PUSHBACK_DEFINE(DataType) \
int VectorPushBack##DataType(Vector(DataType) vec, const DataType* elem, int pushCnt) \
{\
    return 0; \
}

#define VECTOR_POPBACK_DEFINE(DataType) \
void VectorPopBack##DataType(Vector(DataType) vec, int popCnt) \
{\
}

#define VECTOR_DEFINATION(DataType) \
VECTOR_CREATE_DEFINE(DataType); \
VECTOR_DESTROY_DEFINE(DataType); \
VECTOR_GETSIZE_DEFINE(DataType); \
VECTOR_GETCAPACITY_DEFINE(DataType); \
VECTOR_GETAT_DEFINE(DataType); \
VECTOR_PUSHBACK_DEFINE(DataType); \
VECTOR_POPBACK_DEFINE(DataType);

#endif //VECTOR_TEMPLATE_DEFINE_H
