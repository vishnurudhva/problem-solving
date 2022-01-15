class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int size = arr.size();
        if(size < 3) return false;
        int i = 0;
        while(i < size - 1 && arr[i] < arr[i + 1]) i++;
        if(i == 0 || i == size - 1) return false;
        while(i < size - 1 && arr[i] > arr[i + 1]) i++;
        if(i == size - 1) return true;
        
        return false;
    }
};