#include <gtest/gtest.h>
#include "../include/lib.h"

TEST(HelloTest, DefaultConstructor)
{

    FiveDigit e;

    size_t size = e.getSize();
    unsigned char *data = e.getData();

    EXPECT_EQ(size, 0);
    EXPECT_EQ(data, nullptr);
}

TEST(HelloTest, SizeAndDefaultConstructor)
{

    size_t n = 5;
    unsigned char t = '1';
    FiveDigit e(n, t);

    size_t size = e.getSize();
    unsigned char *data = e.getData();

    EXPECT_EQ(size, n);
    for (size_t i = 0; i < size; ++i)
    {
        EXPECT_EQ(data[i], t);
    }
}

TEST(HelloTest, InitializerListConstructor)
{

    std::initializer_list<unsigned char> t = {'1', '4', '3'};
    FiveDigit e(t);

    size_t size = e.getSize();
    unsigned char *data = e.getData();

    EXPECT_EQ(size, t.size());
    size_t i = 0;
    for (unsigned char digit : t)
    {
        EXPECT_EQ(data[i++], digit);
    }
}

TEST(HelloTest, StringConstructor)
{

    std::string t = "143";
    FiveDigit e(t);

    size_t size = e.getSize();
    unsigned char *data = e.getData();

    EXPECT_EQ(size, t.size());
    for (size_t i = 0; i < size; ++i)
    {
        EXPECT_EQ(data[i], t[i]);
    }
}

TEST(HelloTest, AssignmentOperator)
{

    FiveDigit e1("143");
    FiveDigit e2("143");

    e2 = e1;

    EXPECT_EQ(e2.getSize(), e1.getSize());
    for (int i = 0; i < e2.getSize(); ++i)
    {
        EXPECT_EQ(e1.getData()[i], e2.getData()[i]);
    }
}

TEST(HelloTest, AdditionOperator)
{

    FiveDigit e1("111");
    FiveDigit e2("134");

    e1 += e2;

    std::string ans = "300";
    EXPECT_EQ(e1.getSize(), 3);
    for (int i = 0; i < e1.getSize(); ++i)
    {
        EXPECT_EQ(e1.getData()[i], ans[i]);
    }
}

TEST(HelloTest, SubtractionOperator)
{

    FiveDigit e1("112");
    FiveDigit e2("12");

    e1 -= e2;

    std::string ans = "100";
    EXPECT_EQ(e1.getSize(), 3);
    for (int i = 0; i < e1.getSize(); ++i)
    {
        EXPECT_EQ(e1.getData()[i], ans[i]);
    }
}

TEST(HelloTest, EqualityOperator)
{

    FiveDigit e1("112");
    FiveDigit e2("112");
    FiveDigit e3("132");

    EXPECT_TRUE(e1 == e2);
    EXPECT_FALSE(e1 == e3);
}

TEST(HelloTest, LessThanOperator)
{

    FiveDigit e1("123");
    FiveDigit e2("234");

    EXPECT_TRUE(e1 < e2);
    EXPECT_FALSE(e2 < e1);
}

TEST(HelloTest, GreaterThanOperator)
{

    FiveDigit e1("333");
    FiveDigit e2("222");

    EXPECT_TRUE(e1 > e2);
    EXPECT_FALSE(e2 > e1);
}