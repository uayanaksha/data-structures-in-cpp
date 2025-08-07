#include <gtest/gtest.h>
#include "./stack.cpp"

TEST(StackTest, PushTest){
  Stack<int> s;
  for(int i{1}; i<=1<<20; i<<=1){
    s.push(i);
    ASSERT_EQ(i, s.top());
  }
  s.clear();
  ASSERT_TRUE(s.empty());
}

TEST(StackTest, PopTest){
  Stack<char> s;
  for(char c='a'; c <= 'z'; c++){
    s.push(c);
  }
  for(char c='z'; c >= 'a'; c--){
    ASSERT_EQ(c, s.top());
    s.pop();
  }
}

TEST(StackTest, ClearTest){
  Stack<char> s;
  for(char c='a'; c <= 'z'; c++){
    s.push(c);
  }
  s.clear();
  ASSERT_TRUE(s.empty());
}



int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
