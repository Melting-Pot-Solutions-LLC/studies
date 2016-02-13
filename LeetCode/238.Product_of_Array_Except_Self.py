Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6].

#PYTHON
class Solution(object):
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        #first round
        #multiply all the elements before ith element and store that at the ith position of answer
        answer = []
        answer.append(1)
        for i in range(1, len(nums)):
        	answer.append(nums[i-1]*answer[i-1])
        
        #second round
        #multiply all the elements after ith element and store at ith position.
        i = len(nums) - 2
        while(i>=0):
        	answer[i] = answer[i]*nums[i+1]
        	nums[i] = nums[i]*nums[i+1]
        	i = i - 1
        	
        return answer

//C

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) 
{
    int i = 0;
    int* answer = (int*)malloc(sizeof(int)*numsSize);
    
    if(answer)
    {
        answer[0] = 1;
        for(i = 1; i < numsSize; i++)
        {
            answer[i] = nums[i-1]*answer[i-1];
        }
        
        for(i = numsSize-2; i>=0; i--)
        {
            answer[i] = answer[i]*nums[i+1];
            nums[i] = nums[i]*nums[i+1];
        }
    }
    
    *returnSize = numsSize; 
    return (int*)answer;
    
}