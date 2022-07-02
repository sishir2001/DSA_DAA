class Solution {
public:
    pair<int,int> get_j(int n,int k){
        // T(N) = O(N)
        int lb = 1,j = 1,up = n-1,lb_add = n-1,up_add = n-2,prev_ub = 0;
        pair<int,int> p;
        while(lb <= ub){
            if(k >= lb && k <= ub){
                p.first = j;p.second = prev_ub;
                break;
            }
            prev_ub = ub;
            ub += ub_add;
            lb+= lb_add;
            j++;
            ub_add = lb_add;
            lb_add--;
        }
        return p;
    }
    int partition(vector<int> &nums,int l,int r){
        // T(N) = O(N)
        int p = r;
        r = r-1;
        while(l <= r){
            if(nums[l] < nums[p])
                l++;
            else{
                swap(nums[l],nums[r]);
                r--;
            }
        }
        swap(nums[l],nums[p]);
        return l;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        
        // T(N) = nlogn  
        sort(nums.begin(),nums.end()); // nlogn
        int n = nums.size(),i = 0;
        pair<int,int> interval = this->get_j(n,k); // n
        int rel_index = k-interval.second -1;
        vector<int> pair_diff;
        for(int j = interval.first;j < n;j++){ // n
            int diff = nums[j]-nums[i];
            pair_diff.push_back(diff);
            i++;
        }
        
        // need to find the rel_index , using quick select algorithm
        int l = 0,r = pari_diff.size()-1,res = 0;
        // nlogn
        while(l <= r){
            int p = this->partition(pair_diff,l,r);
            if(p == rel_index){
                res = pair_diff[p];
                break;
            }
            else if(p < rel_index)
                l=p+1;
            else
                r = p-1;
        }
        return res;
    }
};