class MockIStudentsDataProvider : public IStudentsDataProvider {
  public:
    MOCK_CONST_METHOD0(hasNext,
            bool());
    MOCK_METHOD0(getNext,
            const Student&());
    MOCK_METHOD0(reset,
            void());
    MOCK_METHOD2(foo,
            void(int a, double b));
};
