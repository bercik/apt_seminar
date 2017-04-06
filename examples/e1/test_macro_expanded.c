class SumTest_PositiveArgs_Test : public ::testing::Test 
{ 
    public: 
        SumTest_PositiveArgs_Test() {} 
    
    private: 
        virtual void TestBody(); 

        static ::testing::TestInfo* const test_info_ __attribute__ ((unused)); 
        SumTest_PositiveArgs_Test(SumTest_PositiveArgs_Test const &); 
        void operator=(SumTest_PositiveArgs_Test const &);
};

::testing::TestInfo* const SumTest_PositiveArgs_Test ::test_info_ = 
    ::testing::internal::MakeAndRegisterTestInfo( 
            "SumTest", "PositiveArgs", __null, __null, 
            ::testing::internal::CodeLocation("p1/test.cpp", 4), 
            (::testing::internal::GetTestTypeId()), 
            ::testing::Test::SetUpTestCase, ::testing::Test::TearDownTestCase, 
            new ::testing::internal::TestFactoryImpl< SumTest_PositiveArgs_Test>);

void SumTest_PositiveArgs_Test::TestBody()
{
    switch (0) 
        case 0: 
        default: 
            if (const ::testing::AssertionResult gtest_ar = 
                    (::testing::internal:: EqHelper<(sizeof(::testing::internal::IsNullLiteralHelper(4)) == 1)>::Compare("4", "sum(3, 1)", 4, sum(3, 1)))) ; 
            
            else return ::testing::internal::AssertHelper(::testing::TestPartResult::kFatalFailure, "p1/test.cpp", 6, gtest_ar.failure_message()) = ::testing::Message();
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
