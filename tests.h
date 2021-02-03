//
// Created by Kurisu on 12/23/2020.
//

#ifndef LAB3_TESTS_H
#define LAB3_TESTS_H
#include <iostream>
#include <gtest/gtest.h>
#include "tests.h"
#include <random>
#include <time.h>
int runTests(){
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
#endif //LAB3_TESTS_H
