// Question: https://leetcode.com/problems/two-sum
// Solution: Using two for loops to traverse go through all possible pairs and find the pair that has sum = target.
// Time complexity: O(n^2)

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int *num = malloc(2*sizeof(int));
    for(int i = 0; i<numsSize; i++){
        for(int j = i+1; j<numsSize; j++){
            if(target == nums[i] + nums[j]){
                num[0] = i;
                num[1] = j;
                *returnSize = 2;
            }
        }
    }
    if (*returnSize != 2)
        *returnSize == 0;
    return num;
}