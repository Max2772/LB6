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

TEST(pow, Test1){
    int a = 100, b = 0;
    EXPECT_EQ(pow(a, b), 1); 
}

TEST(pow, Test2){
    int a = 2147483647, b = 1;
    EXPECT_EQ(pow(a, b), 2147483647); 
}

TEST(pow, Test3){
    int a = 2, b = 30;
    EXPECT_EQ(pow(a, b), 1073741824); 
}

TEST(stringToInteger, Test1){
    char test[] = "123456789";
    int size = sizeof(test)/sizeof(char) - 1;
    EXPECT_EQ(stringToInteger(test, size), 123456789); 
}

TEST(stringToInteger, Test2){
    char test[] = "0";
    int size = sizeof(test)/sizeof(char) - 1;
    EXPECT_EQ(stringToInteger(test, size), 0); 
}

TEST(stringToInteger, Test3){
    char test[] = "2147483647";
    int size = sizeof(test)/sizeof(char) - 1;
    EXPECT_EQ(stringToInteger(test, size), 2147483647); 
}

TEST(readCharToStringForAmount, Test1){
    char test[] = "1fnhuisjioghasnjgkbasisgnongsdlkgnjk1\n";
    FILE* temp_file = tmpfile();
    fprintf(temp_file, "%s", test);
    rewind(temp_file);
    FILE* original_stdin = stdin;
    stdin = temp_file;
    EXPECT_EQ(readCharToStringForAmount(test), -INF);
    stdin = original_stdin;
    fclose(temp_file);
}

TEST(readCharToStringForAmount, Test2){
    char test[] = "2147483647\n";
    FILE* temp_file = tmpfile();
    fprintf(temp_file, "%s", test);
    rewind(temp_file);
    FILE* original_stdin = stdin;
    stdin = temp_file;
    EXPECT_EQ(readCharToStringForAmount(test), 1);
    stdin = original_stdin;
    fclose(temp_file);
}

TEST(readCharToStringForAmount, Test3){
    char test[] = "2147483647214748364721474836472147483647214748364721474836472147483647214748364\n";
    FILE* temp_file = tmpfile();
    fprintf(temp_file, "%s", test);
    rewind(temp_file);
    FILE* original_stdin = stdin;
    stdin = temp_file;
    EXPECT_EQ(readCharToStringForAmount(test), 1);
    stdin = original_stdin;
    fclose(temp_file);
}

TEST(readCharToStringForAmount, Test4){
    char test[] = "\n";
    FILE* temp_file = tmpfile();
    fprintf(temp_file, "%s", test);
    rewind(temp_file);
    FILE* original_stdin = stdin;
    stdin = temp_file;
    EXPECT_EQ(readCharToStringForAmount(test), -INF);
    stdin = original_stdin;
    fclose(temp_file);
}

TEST(isCyrillic, Test1){
    char test[] = "Ъ";
    EXPECT_EQ(isCyrillic(test[0],test[1]), 1); 
}

TEST(isCyrillic, Test2){
    char test[] = "ZZ";
    EXPECT_EQ(isCyrillic(test[0],test[1]), 0); 
}

TEST(isCyrillic, Test3){
    char test[] = "##";
    EXPECT_EQ(isCyrillic(test[0],test[1]), 0); 
}

TEST(defineGender, Test1){
    char test[] = "Яблоко";
    int size = sizeof(test)/sizeof(char) - 1;
    EXPECT_EQ(defineGender(test, size), 2); 
}

TEST(defineGender, Test2){
    char test[] = "Ананас";
    int size = sizeof(test)/sizeof(char) - 1;
    EXPECT_EQ(defineGender(test, size), 0); 
}

TEST(defineGender, Test3){
    char test[] = "Девушка";
    int size = sizeof(test)/sizeof(char) - 1;
    EXPECT_EQ(defineGender(test, size), 1); 
}

TEST(readCharToStringForInput, Test1){
    char test[] = "ЛЫВЬПЛТЩЫВТШЫДОЛАРЬТШЬЫРЬДЫАТРЫОДТРТЛЫВЬПЛТЩЫВТШЫДОЛАРЬТШЬЫРЬДЫАТРЫОДТРТФЫППВЫР\n";
    FILE* temp_file = tmpfile();
    fprintf(temp_file, "%s", test);
    rewind(temp_file);
    FILE* original_stdin = stdin;
    stdin = temp_file;
    EXPECT_EQ(readCharToStringForInput(test), 1);
    stdin = original_stdin;
    fclose(temp_file);
}

TEST(readCharToStringForInput, Test2){
    char test[] = "SOMEENGLISHTEXTFORTESTYOYSOMEENGLISHTEXTFORTESTYOYSOMEENGLISHTEXTFORTESTYOYSOME\n";
    FILE* temp_file = tmpfile();
    fprintf(temp_file, "%s", test);
    rewind(temp_file);
    FILE* original_stdin = stdin;
    stdin = temp_file;
    EXPECT_EQ(readCharToStringForInput(test), -INF);
    stdin = original_stdin;
    fclose(temp_file);
}

TEST(readCharToStringForInput, Test3){
    char test[] = "\n";
    FILE* temp_file = tmpfile();
    fprintf(temp_file, "%s", test);
    rewind(temp_file);
    FILE* original_stdin = stdin;
    stdin = temp_file;
    EXPECT_EQ(readCharToStringForInput(test), -INF);
    stdin = original_stdin;
    fclose(temp_file);
}

int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}