public class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        int[] nums = new int[Math.min(nums1.length,nums2.length)];
        Arrays.sort(nums1); Arrays.sort(nums2);
        int k=0;
        for(int i=0, j=0; i!=nums1.length; ++i) {
            for(; j!=nums2.length && nums2[j]<nums1[i]; ++j);
            if(j!=nums2.length && nums2[j]==nums1[i] && ( k==0 || nums[k-1]!=nums1[i] )) nums[k++]=nums1[i];
        }
        return Arrays.copyOfRange(nums, 0, k);
    }
}
