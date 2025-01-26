//
// Created by skytl on 1/26/25.
//

#include "bst.hpp"
#include "catch.hpp"

TEST_CASE("BST Constructor", "[BST]") {
    const BST bst;
    const std::string message = "END OF TREE";
    std::ostringstream os;
    os << bst;
    REQUIRE(os.str() == message);
    REQUIRE(bst.height() == 0);
}