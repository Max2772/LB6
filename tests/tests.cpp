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

TEST(getAlphabetNumber, Test1){
    char test = 'A';
    EXPECT_EQ(getAlphabetNumber(test), 1); 
}

TEST(getAlphabetNumber, Test2){
    wchar_t test = L'Ъ';
    EXPECT_EQ(getAlphabetNumber(test), -22); 
}

TEST(getAlphabetNumber, Test3){
    char test = '0';
    EXPECT_EQ(getAlphabetNumber(test), -16); 
}

TEST(getAlphabetNumber, Test4){
    char test = 'Z';
    EXPECT_EQ(getAlphabetNumber(test), 26); 
}

int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}