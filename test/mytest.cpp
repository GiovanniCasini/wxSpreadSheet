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

TEST(TestSpreadSheet, TestSumT){
    Observer* obs = new Observer();
    Griglia* g = new Griglia(obs);

    g->setGridValue(0, 0, 5);
    g->setGridValue(2, 0, 10);
    g->setGridValue(4, 0, 1);

    EXPECT_EQ(g->getMatrix()[0][0], 16);
}

TEST(TestSpreadSheet, TestMaxT){
    Observer* obs = new Observer();
    Griglia* g = new Griglia(obs);

    g->setGridValue(0, 1, 3);
    g->setGridValue(2, 1, 10);
    g->setGridValue(4, 1, -4);

    EXPECT_EQ(g->getMatrix()[0][1], 10);
}

TEST(TestSpreadSheet, TestMinT){
    Observer* obs = new Observer();
    Griglia* g = new Griglia(obs);

    g->setGridValue(1, 2, 5);
    g->setGridValue(2, 2, 13);
    g->setGridValue(3, 2, 2);

    EXPECT_EQ(g->getMatrix()[0][2], 2);
}

TEST(TestSpreadSheet, TestProdT){
    Observer* obs = new Observer();
    Griglia* g = new Griglia(obs);

    g->setGridValue(0, 3, 2);
    g->setGridValue(5, 3, 4);
    g->setGridValue(7, 3, 3);

    EXPECT_EQ(g->getMatrix()[0][3], 24);
}

TEST(TestSpreadSheet, TestMeanT){
    Observer* obs = new Observer();
    Griglia* g = new Griglia(obs);

    g->setGridValue(0, 4, 2);
    g->setGridValue(1, 4, 4);
    g->setGridValue(2, 4, 6);

    EXPECT_EQ(g->getMatrix()[0][4], 4);
}

TEST(TestSpreadSheet, TestSumF){
    Observer* obs = new Observer();
    Griglia* g = new Griglia(obs);

    g->setGridValue(0, 0, 5);
    g->setGridValue(2, 0, 10);
    g->setGridValue(3, 0, 3);

    EXPECT_EQ(g->getMatrix()[0][0], 16);
}

TEST(TestSpreadSheet, TestMaxF){
    Observer* obs = new Observer();
    Griglia* g = new Griglia(obs);

    g->setGridValue(0, 1, 30);
    g->setGridValue(2, 1, 10);
    g->setGridValue(4, 1, -4);

    EXPECT_EQ(g->getMatrix()[0][1], 10);
}

TEST(TestSpreadSheet, TestMinF){
    Observer* obs = new Observer();
    Griglia* g = new Griglia(obs);

    g->setGridValue(1, 2, 5);
    g->setGridValue(2, 2, 13);
    g->setGridValue(3, 2, 20);

    EXPECT_EQ(g->getMatrix()[0][2], 2);
}

TEST(TestSpreadSheet, TestProdF){
    Observer* obs = new Observer();
    Griglia* g = new Griglia(obs);

    g->setGridValue(0, 3, 2);
    g->setGridValue(5, 3, 3);
    g->setGridValue(7, 3, 3);

    EXPECT_EQ(g->getMatrix()[0][3], 24);
}

TEST(TestSpreadSheet, TestMeanF){
    Observer* obs = new Observer();
    Griglia* g = new Griglia(obs);

    g->setGridValue(0, 4, 7);
    g->setGridValue(1, 4, 4);
    g->setGridValue(2, 4, 6);

    EXPECT_EQ(g->getMatrix()[0][4], 4);
}

TEST(TestSpreadSheet, TestChangeSumValue){
    Observer* obs = new Observer();
    Griglia* g = new Griglia(obs);

    g->setGridValue(0, 0, 1);
    g->setGridValue(1, 0, 2);
    g->setGridValue(2, 0, 3);

    g->setGridValue(0, 0, 4);

    EXPECT_EQ(g->getMatrix()[0][0], 9);
}

