#include <gtest/gtest.h>
#include "../source/main.h" 

wxIMPLEMENT_APP(MyApp);



bool MyApp::OnInit()
{
    Observer* OBS = new Observer();
    MyFrame *frame = new MyFrame(*OBS);
    testing::InitGoogleTest();
    RUN_ALL_TESTS();
    return 0;
}
   
class TestSpreadSheet : public testing::Test{

};


TEST(TestSpreadSheet, TestProd){
    EXPECT_EQ(0,1);
}

TEST(TestSpreadSheet, TestMean){
    EXPECT_EQ(1,1);
}

TEST(TestSpreadSheet, TestSum){
    EXPECT_EQ(56, 56);
}