class Solution {      
public:
    void merge(vector<int>& array, int left, int mid, int right) {
        vector<int> temp;
        int i = left;
        int j = mid + 1;

        while (i <= mid && j <= right) {
            if (array[i] <= array[j]) {
                temp.push_back(array[i]);
                i++;
            } 
            else {
                temp.push_back(array[j]);
                j++;
            }
        }

        while (i <= mid) {
            temp.push_back(array[i]);
            i++;
        }

        while (j <= right) {
            temp.push_back(array[j]);
            j++;
        }

        for (int x = 0; x < temp.size(); x++) {
            array[left + x] = temp[x];
        }
    }

    void mergesort(vector<int>& array, int left, int right) {
        if (left < right){
            int mid = left + (right - left) / 2;
            mergesort(array, left, mid);
            mergesort(array, mid + 1, right);
            merge(array, left, mid, right);
        }
    }

    vector<int> sortArray(vector<int>& array) {
        mergesort(array, 0, array.size() - 1);
        return array;
    }
};