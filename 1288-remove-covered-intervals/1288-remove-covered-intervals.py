class Solution:
  def removeCoveredIntervals(self, intervals: list[list[int]]) -> int:
    ans = 0
    prevEnd = 0

    for _, end in sorted(intervals, key=lambda x: (x[0], -x[1])):
      if prevEnd < end:
        prevEnd = end
        ans += 1

    return ans


