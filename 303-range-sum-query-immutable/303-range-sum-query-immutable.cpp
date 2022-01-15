class NumArray {
private:
    vector<int> array;
public:
    NumArray(vector<int>& nums) {
        array = nums;
    }
    
    int sumRange(int i, int j) {
        int sum = 0;
        for(; i <= j; i++)
            sum += array[i];
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */