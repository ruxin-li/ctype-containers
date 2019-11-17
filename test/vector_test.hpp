#ifndef VECTOR_TEST_HPP
#define VECTOR_TEST_HPP

#include <gtest/gtest.h>
#include <vector_template_declare.h>
#include <vector_template_define.h>

VECTOR_DECLARATION(int);
VECTOR_DEFINATION(int);

TEST(VectorTest, TestCreate)
{
    Vector(int) vec = VectorCreate(int, 10);
    EXPECT_TRUE(VectorIsCreated(vec));
    EXPECT_EQ(VectorGetSize(int, vec), 0);
    EXPECT_EQ(VectorGetCapacity(int, vec), 10);

    VectorDestroy(int, vec);
}

#endif // VECTOR_TEST_HPP
