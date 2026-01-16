class Solution {
    public static int[] searchRange(int[] nums, int target) {
        int st=0, en = nums.length-1;
        int[] k = new int[2];
        while(st<=en){
            int mid = (en+st)/2;

            if(target==nums[mid]){
                for(int i=0; i<2; i++){
                    k[i] = mid;
                    if(mid<0)
                    k[i] = -1;
                    
                }
            }
            
            else if(target<nums[mid])
            en = mid-1;
            else
            st = mid+1;
        }
        return k;
    }

    public static void main(String[] args) {
        int[] arr = {5,7,7,8,8,10};
        int tar = 8;
        searchRange(arr, tar);
    }
}