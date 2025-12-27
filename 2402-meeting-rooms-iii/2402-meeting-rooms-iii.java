import java.util.*;

class Solution {
    public int mostBooked(int n, int[][] meetings) {

        Arrays.sort(meetings, (a, b) -> Integer.compare(a[0], b[0]));
        PriorityQueue<Integer> availableRooms = new PriorityQueue<>();
        PriorityQueue<long[]> busyRooms = new PriorityQueue<>(
            (a, b) -> a[0] != b[0]
                    ? Long.compare(a[0], b[0])
                    : Long.compare(a[1], b[1])
        );

        for (int i = 0; i < n; i++) {
            availableRooms.offer(i);
        }

        int[] meetingCount = new int[n];

        for (int[] meeting : meetings) {
            long start = meeting[0];
            long end = meeting[1];
            long duration = end - start;
            while (!busyRooms.isEmpty() && busyRooms.peek()[0] <= start) {
                availableRooms.offer((int) busyRooms.poll()[1]);
            }

            if (!availableRooms.isEmpty()) {
                int room = availableRooms.poll();
                busyRooms.offer(new long[]{end, room});
                meetingCount[room]++;
            } else {
                long[] earliest = busyRooms.poll();
                long newEnd = earliest[0] + duration;
                int room = (int) earliest[1];

                busyRooms.offer(new long[]{newEnd, room});
                meetingCount[room]++;
            }
        }

        int result = 0;
        for (int i = 1; i < n; i++) {
            if (meetingCount[i] > meetingCount[result]) {
                result = i;
            }
        }

        return result;
    }
}
