#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <functional>
#include <cstdlib>

namespace pdg_test
{
    struct TestCase
    {
        std::string name;
        std::function<void()> func;
    };

    inline std::vector<TestCase> &registry()
    {
        static std::vector<TestCase> tests;
        return tests;
    }

    struct TestRegister
    {
        TestRegister(const std::string &name, std::function<void()> func)
        {
            registry().push_back({name, std::move(func)});
        }
    };

#define TEST(TestSuiteName, TestName)                                    \
    void TestSuiteName##_##TestName();                                   \
    static pdg_test::TestRegister register_##TestSuiteName##_##TestName( \
        #TestSuiteName "." #TestName, TestSuiteName##_##TestName);       \
    void TestSuiteName##_##TestName()

#define EXPECT_EQ(val1, val2)                                                           \
    do                                                                                  \
    {                                                                                   \
        auto v1 = (val1);                                                               \
        auto v2 = (val2);                                                               \
        if (v1 != v2)                                                                   \
        {                                                                               \
            std::cerr << __FILE__ << ":" << __LINE__                                    \
                      << ": Failure\nExpected: " << v1 << "\n  Actual: " << v2 << '\n'; \
            std::exit(1);                                                               \
        }                                                                               \
    } while (0)

    inline int run_all_tests()
    {
        int passed = 0;
        for (const auto &test : registry())
        {
            std::cout << "[ RUN      ] " << test.name << '\n';
            try
            {
                test.func();
                std::cout << "[       OK ] " << test.name << "\n\n";
                ++passed;
            }
            catch (...)
            {
                std::cout << "[  FAILED  ] " << test.name << "\n\n";
            }
        }
        std::cout << passed << " tests passed. " << registry().size() - passed << " failed.\n";
        return (passed == registry().size()) ? 0 : 1;
    }

}