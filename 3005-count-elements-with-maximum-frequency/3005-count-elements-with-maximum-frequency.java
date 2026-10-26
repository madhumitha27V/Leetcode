class Solution {
    public int maxFrequencyElements(int[] nums) {
        
        HashMap <Integer,Integer> map = new HashMap<>();
        int max = 0, count = 0;

        for(int num : nums){
            map.put(num, map.getOrDefault(num, 0) + 1);
        }

        for(int key : map.keySet()){
            
            if(map.get(key) > max){
                max = map.get(key);
            }

            

        }

        for(int key : map.keySet()){
            if(max == map.get(key))
                count = count + map.get(key);
        }

    return count;

    }
}