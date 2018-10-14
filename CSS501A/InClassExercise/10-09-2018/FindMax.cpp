

int findMaxComparedToMax(int* nums, int size){
    //set a variable to "ma: to the first nnubmer"
    int max = nums[0];// 1 count

    //compare "max" to the second number
    //if second number is bigger than max, update max
    //repeat for all element
    for(int i = 1; i < size; i++){// n count
        if(*(nums + i) > max){// 1 count
            max = *(nums + i);// 1 count
        }
    }

    return max; // 1 count
}

int findMaxToAll(){

}

int main(int argc, const char* argv){

}