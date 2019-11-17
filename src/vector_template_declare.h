#ifndef VECTOR_TEMPLATE_DECLARE_H
#define VECTOR_TEMPLATE_DECLARE_H

#include <stdint.h>

#define VECTOR_DECLARE_ASSIGN_FN(DataType) \
typedef void (*VectorAssignFn##DataType)(DataType*, const DataType*)

#define VECTOR_DECLARE_STRUCT(DataType) \
typedef struct { \
    DataType* base; \
    int capacity; \
    int curSize; \
    VectorAssignFn##DataType assignFn; \
} Vector##DataType##Struct, *Vector##DataType

#define Vector(DataType) Vector##DataType

#define VECTOR_DECLARATION(DataType) \
VECTOR_DECLARE_ASSIGN_FN(DataType); \
VECTOR_DECLARE_STRUCT(DataType); \
Vector(DataType) Create##DataType##Vector(int capacity, VectorAssignFn##DataType assignFn); \
void Destroy##DataType##Vector(Vector(DataType)*); \
int Vector##DataType##GetSize(Vector(DataType) vec); \
int Vector##DataType##GetCapacity(Vector(DataType) vec); \
int VectorPushBack##DataType(Vector(DataType) vec, const DataType* elem, int pushCnt); \
void VectorPopBack##DataType(Vector(DataType) vec, int popCnt); \
DataType* VectorGet##DataType##At(Vector(DataType) vec, int pos);

#define VectorCreate(DataType, capacity) \
Create##DataType##Vector(capacity, NULL)

#define VectorCreateEx(DataType, capacity, assignFn) \
Create##DataType##Vector(capacity, assignFn)

#define VectorIsCreated(vec) ((vec) != NULL)

#define VectorDestroy(DataType, vec) \
Destroy##DataType##Vector(&vec)

#define VectorGetAt(DataType, vec, pos) \
VectorGet##DataType##At(vec, pos)

#define VectorGetSize(DataType, vec) \
Vector##DataType##GetSize(vec)

#define VectorGetCapacity(DataType, vec) \
Vector##DataType##GetCapacity(vec)

#define VectorPushBack(DataType, vec, elem) \
VectorPushBack##DataType(vec, elem, 1)

#define VectorPushBackEx(DataType, vec, elem, pushCnt) \
VectorPushBack##DataType(vec, elem, cnt)

#define VectorPopBack(DataType, vec) \
VectorPopBack##DataType(vec, 1)

#define VectorPopBackEx(DataType, vec, popCnt) \
VectorPopBack##DataType(vec, popCnt)

#endif // VECTOR_TEMPLATE_DECLARE_H
