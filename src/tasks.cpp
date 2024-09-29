// Copyright 2024 MamedovKenan

#include "tasks.h"
#include "circle.h"

// Земля и верёвка
double calculateGapAfterRope(double earthRadius, double ropeIncrease) {
    Circle earth(earthRadius);
    double newFerence = earth.getFerence() + ropeIncrease;
    earth.setFerence(newFerence);
    return earth.getRadius() - earthRadius;
}

// Бассейн
double calculateCostOfPoolAndPath(double poolRadius,
                                  double pathWidth,
                                  double concreteCostPerSqMeter,
                                  double fenceCostPerMeter) {
    Circle pool(poolRadius);
    Circle totalArea(poolRadius + pathWidth);

    double pathArea = totalArea.getArea() - pool.getArea();
    double fenceLength = totalArea.getFerence();

    double concreteCost = pathArea * concreteCostPerSqMeter;
    double fenceCost = fenceLength * fenceCostPerMeter;

    return concreteCost + fenceCost;
}
