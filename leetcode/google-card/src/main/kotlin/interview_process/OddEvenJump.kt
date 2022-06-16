package interview_process

import java.util.TreeMap

class OddEvenJump {
    fun oddEvenJumps(arr: IntArray): Int {
        //init dp
        val dp = Array(arr.size) { position ->
            Array(2) {
                position == arr.size - 1
            }
        }
        //init treemap
        val treeMap = TreeMap<Int, Int>()
        treeMap[arr[arr.size - 1]] = arr.size - 1
        //calculate answer
        var answer = 1
        for (position in arr.size - 2 downTo 0) {
            treeMap.ceilingEntry(arr[position])?.value?.let { nextGreater ->
                dp[position][0] = dp[nextGreater][1]
            }
            treeMap.floorEntry(arr[position])?.value?.let { nextSmaller ->
                dp[position][1] = dp[nextSmaller][0]
            }
            if (dp[position][0]) {
                answer++ //possible start
            }
            treeMap[arr[position]] = position
        }
        return answer
    }
}
fun main() {
    OddEvenJump().apply {
        oddEvenJumps(intArrayOf(10, 13, 12, 14, 15)).also {
            println(it)
        }
    }
}