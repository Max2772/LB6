#include <gtest/gtest.h>
#include <sstream> 
#include "funcs.cpp"
#include "head.h"

auto cinBuf = std::cin.rdbuf(); 
auto old_buffer = std::cout.rdbuf(nullptr);

TEST(charToInteger, Test1){
    char test[] = "1";
    EXPECT_EQ(charToInteger(test), 1); 
}

TEST(charToInteger, Test2){
    char test[] = "99999999999999";
    EXPECT_EQ(charToInteger(test), 9); 
}

TEST(charToInteger, Test3){
    char test[] = "\n";
    EXPECT_EQ(charToInteger(test), -38); 
}

TEST(charToInteger, Test4){
    char test[] = "HELLOWORLD";
    EXPECT_EQ(charToInteger(test), 24); 
}

TEST(readCharToStringForType, Test1){
    char test[] = "3.1415\n";
    FILE* temp_file = tmpfile();
    fprintf(temp_file, "%s", test);
    rewind(temp_file);
    FILE* original_stdin = stdin;
    stdin = temp_file;
    EXPECT_EQ(readCharToStringForType(test), -INF);
    stdin = original_stdin;
    fclose(temp_file);
}

TEST(readCharToStringForType, Test2){
    char test[] = "djfuigdfuigihkergeriughefuiguihjgbdfhbdfhbhjdfbvhjdfbvhjdf vhjvdfbkj\n";
    FILE* temp_file = tmpfile();
    fprintf(temp_file, "%s", test);
    rewind(temp_file);
    FILE* original_stdin = stdin;
    stdin = temp_file;
    EXPECT_EQ(readCharToStringForType(test), -INF);
    stdin = original_stdin;
    fclose(temp_file);
}

TEST(readCharToStringForType, Test3){
    char test[] = "\n";
    FILE* temp_file = tmpfile();
    fprintf(temp_file, "%s", test);
    rewind(temp_file);
    FILE* original_stdin = stdin;
    stdin = temp_file;
    EXPECT_EQ(readCharToStringForType(test), -INF);
    stdin = original_stdin;
    fclose(temp_file);
}

TEST(readCharToStringForType, Test4){
    char test[] = "1\n";
    FILE* temp_file = tmpfile();
    fprintf(temp_file, "%s", test);
    rewind(temp_file);
    FILE* original_stdin = stdin;
    stdin = temp_file;
    EXPECT_EQ(readCharToStringForType(test), 1);
    stdin = original_stdin;
    fclose(temp_file);
}

TEST(stringSize, Test1){
    char test[] = "HELLOWORLD\n";
    EXPECT_EQ(stringSize(test), 10); 
}
TEST(stringSize, Test2){
    char test[] = "1011010111101010\n";
    EXPECT_EQ(stringSize(test), 16); 
}

TEST(stringSize, Test3){
    char test[] = "\n";
    EXPECT_EQ(stringSize(test), 0); 
}

TEST(maxSubString, Test1){
    char test[] = "101101\n";
    int size = (sizeof(test)/sizeof(test[0])) - 2;
    EXPECT_EQ(maxSubString(test, size), 2); 
}

TEST(maxSubString, Test2){
    char test[] = "10110010101000000000001011111111111010101010101010101000000000001010010000000001010111111101111111010100010101\n";
    int size = (sizeof(test)/sizeof(test[0])) - 2;
    EXPECT_EQ(maxSubString(test, size), 11); 
}

TEST(maxSubString, Test3){
    char test[] = "\n";
    int size = (sizeof(test)/sizeof(test[0])) - 2;
    EXPECT_EQ(maxSubString(test, size), 0); 
}

/*
TEST(ReadIntegerTest, INT_InvalidInput3){
    std::istringstream input("abc\nkdskosmgomsongonsdgn\n");
    std::cin.rdbuf(input.rdbuf()); 
    EXPECT_EQ(readIntegerInLine(), 0);
    std::cin.rdbuf(cinBuf);
}

TEST(ReadDoubleTest, DOUBLE_ValidInput){
    std::istringstream input("2.718281828459045\n"); 
    std::cin.rdbuf(input.rdbuf());
    EXPECT_NEAR(readDoubleInLine(), 2.71828, 0.00001); 
    std::cin.rdbuf(cinBuf);
}

TEST(ReadDoubleTest, DOUBLE_InvalidInput){  
    std::istringstream input("dsonndsfondfjiiufbodfioidfwoeijl4s654g\n");
    std::cin.rdbuf(input.rdbuf()); 
    EXPECT_EQ(readDoubleInLine(), 0);
    std::cin.rdbuf(cinBuf);
}
*/
int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}