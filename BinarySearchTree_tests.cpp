// Project UID db1f506d06d84ab787baf250c265e24e

#include "BinarySearchTree.h"
#include "unit_test_framework.h"



TEST(test_empty_tree) {
    // empty tree
    BinarySearchTree<int> tree;

    ASSERT_TRUE(tree.size() == 0);
    ASSERT_TRUE(tree.height() == 0);

    ASSERT_TRUE(tree.empty());

    ASSERT_TRUE(tree.find(5) == tree.end());

    ASSERT_TRUE(tree.max_element() == tree.end());
    ASSERT_TRUE(tree.min_element() == tree.end());
    ASSERT_TRUE(tree.min_greater_than(5) == tree.end());
    

}

TEST(test_basic_tree) {
    // testing size, height, insert, empty, find, min/max, min greater than
    BinarySearchTree<int> tree;
//
    tree.insert(5);

    ASSERT_TRUE(tree.size() == 1);
    ASSERT_TRUE(tree.height() == 1);
    ASSERT_FALSE(tree.empty());
    ASSERT_TRUE(*(tree.find(5)) == 5);
    ASSERT_TRUE(tree.find(2) == tree.end());
    ASSERT_TRUE(*tree.max_element() == 5);
    ASSERT_TRUE(*tree.min_element() == 5);

    tree.insert(3);
    tree.insert(8);

    ASSERT_TRUE(tree.size() == 3);
    ASSERT_TRUE(tree.height() == 2);
    ASSERT_TRUE(*tree.max_element() == 8);
    ASSERT_TRUE(*tree.min_element() == 3);
    ASSERT_TRUE(*(tree.find(3)) == 3);
    ASSERT_TRUE(*(tree.find(8)) == 8);

    tree.insert(1);
    tree.insert(10);
    tree.insert(7);

    ASSERT_TRUE(tree.size() == 6);
    ASSERT_TRUE(tree.height() == 3);
    ASSERT_TRUE(*tree.max_element() == 10);
    ASSERT_TRUE(*tree.min_element() == 1);
    ASSERT_TRUE(*tree.find(1) == 1);
    ASSERT_TRUE(*tree.find(10) == 10);

    ASSERT_TRUE(tree.min_greater_than(10) == tree.end());
    ASSERT_TRUE(*tree.min_greater_than(7) == 8);
    ASSERT_TRUE(*tree.min_greater_than(1) == 3);
}

TEST(test_copy_nodes) {
    BinarySearchTree<int> tree1;
    tree1.insert(1);                      // just so there's something to copy
    BinarySearchTree<int> tree2 = tree1;  // copy constructor is called
    ASSERT_TRUE(*tree2.find(1) == 1);

    BinarySearchTree<int> t1;
    t1.insert(5);
    t1.insert(7);
    BinarySearchTree<int> t2;
    t2.insert(20);
    t2.insert(3);
    t2 = t1;                     // t2 already exists before this line
    ASSERT_TRUE(*t2.find(7) == 7)

}

TEST(test_check_sorting_invariant) {
    // empty tree
//    BinarySearchTree<int> tree;
//    ASSERT_TRUE(tree.check_sorting_invariant());

    // tree w/o left/right nodes
    BinarySearchTree<int> tree1;
    tree1.insert(10);
    ASSERT_TRUE(tree1.check_sorting_invariant());

    // tree that follows invariant
    BinarySearchTree<int> tree4;
    tree4.insert(21);
    tree4.insert(14);
    tree4.insert(29);
    tree4.insert(0);
    tree4.insert(22);
    tree4.insert(15);
    tree4.insert(30);
    ASSERT_TRUE(tree4.check_sorting_invariant());

    // tree that does not follow invariant
    // using @5195
    BinarySearchTree<int> tree2;
    tree2.insert(21);
    tree2.insert(14);
    tree2.insert(29);
    tree2.insert(0);
    tree2.insert(15);
    BinarySearchTree<int>::Iterator i = tree2.insert(23); // here
    // declare an iterator to store it, then you dereference the iterator & assign to it
    tree2.insert(30);
    tree2.insert(5);
    tree2.insert(19);
    BinarySearchTree<int>::Iterator j = tree2.insert(22); // here
    tree2.insert(35);
    tree2.insert(10);
    *i = 22;
    *j = 6;
    ASSERT_FALSE(tree2.check_sorting_invariant());

    // tree with duplicates
    BinarySearchTree<int> tree3;
    tree3.insert(4);
    tree3.insert(5);
    BinarySearchTree<int>::Iterator l = tree3.insert(2);
    *l = 4;
    ASSERT_FALSE(tree3.check_sorting_invariant());

    // node->left > node
    BinarySearchTree<int> tree5;
    tree5.insert(15);
    BinarySearchTree<int>::Iterator a = tree5.insert(10);
    *a = 20;
    ASSERT_FALSE(tree5.check_sorting_invariant());
}

TEST(test_traverse) {
    // test an empty string for both
    BinarySearchTree<int> tree;
    
    std::ostringstream oss_preorder;
    tree.traverse_preorder(oss_preorder);
    std::cout << "preorder" << std::endl;
    std::cout << oss_preorder.str() << std::endl << std::endl;
    ASSERT_TRUE(oss_preorder.str() == "");

    std::ostringstream oss_inorder;
    tree.traverse_inorder(oss_inorder);
    std::cout << "inorder" << std::endl;
    std::cout << oss_inorder.str() << std::endl << std::endl;
    ASSERT_TRUE(oss_inorder.str() == "");
    
    // traverse inorder + preorder
    BinarySearchTree<int> tree2;
    // print 20 18 17 19 22 21 24
    tree2.insert(20);
    tree2.insert(18);
    tree2.insert(22);
    tree2.insert(17);
    tree2.insert(19);
    tree2.insert(21);
    tree2.insert(24);
    std::ostringstream oss_preorder2;
    tree2.traverse_preorder(oss_preorder2);
    std::cout << "preorder" << std::endl;
    std::cout << oss_preorder2.str() << std::endl << std::endl;
    ASSERT_TRUE(oss_preorder2.str() == "20 18 17 19 22 21 24 ");
    
    // print 17 18 19 20 21 22 24
    std::ostringstream oss_inorder2;
    tree2.traverse_inorder(oss_inorder2);
    std::cout << "inorder" << std::endl;
    std::cout << oss_inorder2.str() << std::endl << std::endl;
    ASSERT_TRUE(oss_inorder2.str() == "17 18 19 20 21 22 24 ");
}

TEST_MAIN()
