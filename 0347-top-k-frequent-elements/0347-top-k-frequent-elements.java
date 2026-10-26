class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        
        HashMap <Integer, Integer> map = new HashMap<>();
            for(int num : nums){
                map.put(num, map.getOrDefault(num, 0) + 1);
            }
        
      List<Map.Entry<Integer, Integer>> list = map.entrySet().stream()
            .sorted(Map.Entry.<Integer, Integer>comparingByValue().reversed())
            .toList();

        for(int i = 0 ; i < k ; i++){
            nums[i] = list.get(i).getKey();
        }
        
        return Arrays.copyOf(nums, k);
    }
}