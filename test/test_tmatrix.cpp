#include "utmatrix.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length) {
    ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, cant_create_too_large_matrix) {
    ASSERT_ANY_THROW(TMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length) {
    ASSERT_ANY_THROW(TMatrix<int> m(-5));
}

TEST(TMatrix, can_create_copied_matrix) {
    TMatrix<int> m(5);
    ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one) {
    TMatrix<int> m(7);
    EXPECT_EQ(TMatrix<int>(m), m);
}

TEST(TMatrix, copied_matrix_has_its_own_memory) {
    TMatrix<int> m1(10), m2(m1);
    m2[1][0] = 5;
    m2[1][1] = 7;
    EXPECT_NE(&m1[0], &m2[0]);
    EXPECT_NE(m1, m2);
}

TEST(TMatrix, can_get_size) {
    TMatrix<int> m(12);
    ASSERT_NO_THROW(m.GetSize());
}

TEST(TMatrix, can_set_and_get_element) {
    TMatrix<int> m(8);
    m[1][2] = 3;
    EXPECT_EQ(3, m[1][2]);
}

TEST(TMatrix, throws_when_set_element_with_negative_index) {
    TMatrix<int> m(15);
    ASSERT_ANY_THROW(m[-1][2]);
    ASSERT_ANY_THROW(m[1][-2]);
    ASSERT_ANY_THROW(m[-1][-2]);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index) {
    TMatrix<int> m(12);
    ASSERT_ANY_THROW(m[12][1]);
    ASSERT_ANY_THROW(m[4][14]);
}

TEST(TMatrix, can_assign_matrix_to_itself) {
    TMatrix<int> m(3);
    ASSERT_NO_THROW(m = m);
}

TEST(TMatrix, can_assign_matrices_of_equal_size) {
    TMatrix<int> m1(20), m2(20);
    m2[2][8] = 12;
    m2[15][18] = 123;
    m1 = m2;
    EXPECT_EQ(m1, m2);
}

TEST(TMatrix, assign_operator_change_matrix_size) {
    TMatrix<int> m1(2), m2(3), m3(4);
    m1 = m2;
    m3 = m2;
    EXPECT_EQ(3, m1.GetSize());
    EXPECT_EQ(3, m3.GetSize());
}

TEST(TMatrix, can_assign_matrices_of_different_size) {
    TMatrix<int> m1(20), m2(15);
    m1[14][3] = 10;
    m2[4][5] = 7;
    m2[3][8] = 8;
    m1 = m2;
    EXPECT_EQ(m1, m2);
}

TEST(TMatrix, compare_equal_matrices_return_true) {
    TMatrix<int> m1(5), m2(5);
    m1[2][3] = 6;
    m1[2][4] = 1;
    m2 = m1;
    EXPECT_TRUE(m1 == m2);
    m2[3][1] = 21;
    EXPECT_TRUE(m1 != m2);
}

TEST(TMatrix, compare_matrix_with_itself_return_true) {
    TMatrix<int> m(20);
    m[2][8] = 18;
    EXPECT_TRUE(m == m);
    EXPECT_FALSE(m != m);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal) {
    TMatrix<int> m1(5), m2(6);
    EXPECT_FALSE(m1 == m2);
    EXPECT_TRUE(m1 != m2);
}

TEST(TMatrix, can_add_matrices_with_equal_size) {
    TMatrix<int> m1(5), m2(5), m3(5);
    m1[1][1] = 6;
    m1[2][2] = 3;
    m2[1][1] = 8;
    m2[2][2] = 2;
    m3[1][1] = 14;
    m3[2][2] = 5;
    EXPECT_EQ(m3, m1 + m2);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size) {
    TVector<int> m1(15), m2(7);
    ASSERT_ANY_THROW(m1 + m2);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size) {
    TMatrix<int> m1(5), m2(5), m3(5);
    m1[1][1] = 6;
    m1[2][2] = 3;
    m2[1][1] = 2;
    m2[2][2] = 1;
    m3[1][1] = 4;
    m3[2][2] = 2;
    EXPECT_EQ(m3, m1 - m2);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size) {
    TVector<int> m1(2), m2(4);
    ASSERT_ANY_THROW(m1 - m2);
}

