class Solution {
public:
    int trap(vector<int>& height) {
        int lmax=0,rmax=0,total=0;
        int n=height.size();
        int l=0,r=n-1;
        while(l<r){
            if(height[l]<=height[r]){
                if(lmax>height[l])
                total+=lmax-height[l];
                else
                lmax=height[l];
                l=l+1;
            }
            else{
                if(rmax>height[r])
                total+=rmax-height[r];
                else
                rmax=height[r];
                r=r-1;
            }
        }
        return total;
       /* int left = 0;
        int right = height.size() - 1;
        int leftMax = height[left];
        int rightMax = height[right];
        int water = 0;

        while (left < right) {
            if (leftMax < rightMax) {
                left++;
                leftMax = max(leftMax, height[left]);
                water += leftMax - height[left];
            } else {
                right--;
                rightMax = max(rightMax, height[right]);
                water += rightMax - height[right];
            }
        }

        return water;  */      
    }
};