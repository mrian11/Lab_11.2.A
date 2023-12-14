#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_11.2.A/LAb.cpp"  // Include the header/source file where the function is defined

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab112A
{
    TEST_CLASS(UnitTestLab112A)
    {
    public:

        TEST_METHOD(TestStudentsWithPhysics5)
        {
  
            std::string testFilename = "test_data.bin";

            std::ofstream testFile(testFilename, std::ios::binary);
            if (testFile.is_open())
            {

                Student std_Ph5;
                std_Ph5.Phisic = 5;
                strcpy_s(std_Ph5.Prizv, "TestStudent1");
                testFile.write(reinterpret_cast<const char*>(&std_Ph5), sizeof(Student));

               
                Student std_Oth;
                std_Oth.Phisic = 4;
                strcpy_s(std_Oth.Prizv, "TestStudent2");
                testFile.write(reinterpret_cast<const char*>(&std_Oth), sizeof(Student));

                testFile.close();
            }

            StudentsWithPhysics5(testFilename);           
        }
    };
}
