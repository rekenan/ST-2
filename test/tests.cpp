// Copyright 2024 MamedovKenan

#include <gtest/gtest.h>
#include <cstdint>
#include "circle.h"
#include "tasks.h"

TEST(CircleTest, RadiusTest) {
    Circle c(5.0);
    EXPECT_EQ(c.getRadius(), 5.0);
}

TEST(CircleTest, FerenceTest) {
    Circle c(5.0);
    EXPECT_NEAR(c.getFerence(), 31.4159, 0.0001);
}

TEST(CircleTest, AreaTest) {
    Circle c(5.0);
    EXPECT_NEAR(c.getArea(), 78.5398, 0.0001);
}

TEST(CircleTest, SetRadius) {
    Circle c(5.0);
    c.setRadius(10.0);
    EXPECT_EQ(c.getRadius(), 10.0);
    EXPECT_NEAR(c.getFerence(), 62.8318, 0.0001);
    EXPECT_NEAR(c.getArea(), 314.1593, 0.0001);
}

TEST(CircleTest, SetFerence) {
    Circle c(5.0);
    c.setFerence(31.4159);
    EXPECT_NEAR(c.getRadius(), 5.0, 0.0001);
    EXPECT_NEAR(c.getArea(), 78.5398, 0.0001);
}

TEST(CircleTest, SetArea) {
    Circle c(5.0);
    c.setArea(78.5398);
    EXPECT_NEAR(c.getRadius(), 5.0, 0.0001);
    EXPECT_NEAR(c.getFerence(), 31.4159, 0.0001);
}

// Земля и веревка
TEST(TaskTest, RopeGapTest) {
    double earthRadius = 6378.1;
    double ropeIncrease = 1.0;
    EXPECT_NEAR(calculateGapAfterRope(earthRadius, ropeIncrease),
                0.1592, 0.0001);
}

// Бассейн
TEST(TaskTest, PoolCostTest) {
    double poolRadius = 3.0;
    double pathWidth = 1.0;
    double concreteCost = 1000.0;
    double fenceCost = 2000.0;

    double totalCost = calculateCostOfPoolAndPath(poolRadius,
                pathWidth, concreteCost, fenceCost);
    EXPECT_NEAR(totalCost, 65973.4457, 0.0001);
}

TEST(CircleTest, NegativeRadius) {
    Circle c(-5.0);
    EXPECT_LE(c.getRadius(), 0.0);
}

TEST(CircleTest, LargeRadius) {
    Circle c(1000000);
    EXPECT_NEAR(c.getFerence(), 6283185.307, 0.001);
    EXPECT_NEAR(c.getArea(), 3.14159265358979e12, 1.0);
}

TEST(TaskTest, ZeroPathWidth) {
    double poolRadius = 3.0;
    double pathWidth = 0.0;
    double concreteCost = 1000.0;
    double fenceCost = 2000.0;

    double totalCost = calculateCostOfPoolAndPath(poolRadius,
                pathWidth, concreteCost, fenceCost);
    EXPECT_NEAR(totalCost, 37699.1118, 0.0001);
}
