cmake_minimum_required(VERSION 3.6)
project(lectcode_practice)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -std=gnu++11")

#set(BASE_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
#INCLUDE_DIRECTORIES(${BASE_INCLUDE_DIR})
#
#AUX_SOURCE_DIRECTORY(./src/ SRC_LIST)
#ADD_EXECUTABLE(lectcode_practice main.cpp ${SRC_LIST})

#set(EXE_NAME main)
#target_link_libraries(${EXE_NAME} )

set(SOURCE_FILES main.cpp include/UniqueBinarySearchTreesII.h src/UniqueBinarySearchTreesII.cpp include/KthLargestElementinanArray.h src/KthLargestElementinanArray.cpp include/MSTPrim.h src/MSTPrim.cpp include/GroupAnagrams.h src/GroupAnagrams.cpp include/CombinationSumII.h src/CombinationSumII.cpp include/shortestPath.h src/shortestPath.cpp include/AddTwoNumbers.h src/AddTwoNumbers.cpp src/EvaluateReversePolishNotation.cpp include/redAndBlack.h src/redAndBlack.cpp include/KthSmallestElementinaBST.h src/KthSmallestElementinaBST.cpp include/TrappingRainWaterII.h src/TrappingRainWaterII.cpp include/RussianDollEnvelopes.h src/RussianDollEnvelopes.cpp include/LongestIncreasingSubsequence.h src/LongestIncreasingSubsequence.cpp include/SerializeandDeserializeBinaryTree.h src/SerializeandDeserializeBinaryTree.cpp include/SlidingWindowMaximum.h src/SlidingWindowMaximum.cpp include/ReverseNodesink-Group.h src/ReverseNodesink-Group.cpp include/RecoverBinarySearchTree.h src/RecoverBinarySearchTree.cpp include/EditDistance.h src/EditDistance.cpp include/DistinctSubsequences.h src/DistinctSubsequences.cpp include/MinimumWindowSubstring.h src/MinimumWindowSubstring.cpp include/LinkedListCycle.h src/LinkedListCycle.cpp include/ConstructBinaryTreefromPreorderandInorderTraversal.h src/ConstructBinaryTreefromPreorderandInorderTraversal.cpp include/ContainsDuplicateII.h src/ContainsDuplicateII.cpp include/Fibonacci.h src/Fibonacci.cpp include/RemoveDuplicateLetters.h src/RemoveDuplicateLetters.cpp)
add_executable(lectcode_practice ${SOURCE_FILES})