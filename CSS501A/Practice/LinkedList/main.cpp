#include "LinkedList.hpp"
#include "ListInterface.hpp"

int main(int argc, const char * argv[]) {
    
    ListInterface<std::string>* listPtr = new LinkedList<std::string>();

    std::string data[] = {"one", "two", "three", "four", "five", "six"};
    
    listPtr->insert(1, data[0]);
    listPtr->insert(2,data[1]);
    
    for(int i = 1; i <= 2; i++){
        std::cout << listPtr->getEntry(i) << std::endl;
    }
    
//    std::cout << "isEmpty: returns " << listPtr->isEmpty()
//    << "; should be 1 (true)" << std::endl;
//    for (int i = 0; i < ITEM_COUNT; i++)
//    {
//        if (listPtr->insert(i + 1, data[i]))
//        {
//            try
//            {
//                std::cout << "Inserted " << listPtr->getEntry(i + 1)
//                << " at position " << (i + 1) << std::endl;
//            }
//            catch (std::logic_error except)
//            {
//                std::cout << "Failed to get entry at position "
//                << (i + 1) << std::endl;
//            }
//        }
//        else
//            std::cout << "Cannot insert " << data[i] << " at position " << (i + 1)
//            << std::endl;
//    }  // end for
    
//    for (int i = 0; i < listPtr->getLength(); i++)
//    {
//        std::cout << listPtr->getEntry(i + 1) << std::endl;
//    }
//
//    std::string seven = "seven";
//    listPtr->insert(7, seven);
//
//    for (int i = 0; i < listPtr->getLength(); i++)
//    {
//        std::cout << listPtr->getEntry(i + 1) << std::endl;
//    }
    
    return 0;
}