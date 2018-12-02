//
// Created by sampru on 19/11/18.
//

#include <gtest/gtest.h>
#include "../lib/Matriz.h"

TEST(tmariz, construct) {
    matriz m{3, 3};
    EXPECT_EQ (3, matriz.fil);
    EXPECT_EQ (3, matriz.col);
}