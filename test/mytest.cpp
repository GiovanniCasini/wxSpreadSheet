#include <gtest/gtest.h>
#include "../source/main.h" 

wxIMPLEMENT_APP(MyApp);



bool MyApp::OnInit()
{
    testing::InitGoogleTest();
    RUN_ALL_TESTS();
    return 0;
}
   
class TestSpreadSheet : public testing::Test{

};


TEST(TestSpreadSheet, TestProd){
    Observer* obs = new Observer();
    Griglia* g = new Griglia(obs);

    g->setGridValue(0,3,5);
    g->setGridValue(3,3,10);

    EXPECT_EQ(g->getMatrix()[0][3],51);
}

