 //Implement next permutation, which rearranges numbers into the 
 //lexicographically next greater permutation of numbers.
//If such arrangement is not possible, it must rearrange it as the 
//lowest possible order (ie, sorted in ascending order).
//The replacement must be in-place, do not allocate extra memory.
//Here are some examples. Inputs are in the left-hand column and 
//its corresponding outputs are in the right-hand column.
//1,2,3 → 1,3,2
//3,2,1 → 1,2,3
//1,1,5 → 1,5,1
// 假设输入为  5 5 2 4 7 6 3
// 从后往前观察，对于A[5] = 6 >= A[6] = 3。（交换A[5]和A[6]得到的排列： 5 5 2 4 7 3 6 小于原排列，这一步是没有必要做的，只是为了让大家看清楚）
// A[4] = 7 >= A[5] >= A[6]。(交换A[4]和A[5]或者A[4]和A[6]等，得到的都比原排列小)
// A[3] = 4 < A[4] >= A[5] >= A[6]，这时从7 6 3中选择6，6是这三个数中大于4的最小的数，交换A[3] = 4和A[5] = 6，得到： 5 5 2 6 7 4 3
// 明显5 5 2 6 7 4 3比原排列大，但不是原排列的next permutation。
// 需要调整7 4 3得到最小的3 4 7，最终就是输出5 5 2 4 3 6 7
// 对于输入3 2 1
// 找不到任何一个A[i - 1] < A[i]，所以输出为它的（循环）下一个： 1 2 3
class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int i = (int)num.size() - 1;
        for (; i > 0; i--) {
            if (num[i] > num[i-1])
                break;
        }
        if (i == 0)
            sort(num.begin(), num.end());
        else {
            for (int j = (int)num.size() - 1; j >= i; j--) {
                if (num[j] > num[i-1]) {
                    swap(num[j], num[i-1]);
                    break;
                }
            }
            sort(num.begin()+i, num.end());
        }
    }
};
