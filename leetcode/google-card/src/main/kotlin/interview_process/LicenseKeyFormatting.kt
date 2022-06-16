package interview_process

class LicenseKeyFormatting {
    fun licenseKeyFormatting(s: String, k: Int): String {
        var taken = 0
        var formattedStr = ""
        for (ch in s.reversed()) {
            if (ch != '-') {
                if (taken < k) {
                    taken++
                } else {
                    formattedStr += '-'
                    taken = 1
                }
                formattedStr += ch.uppercaseChar()
            }
        }
        return formattedStr.reversed()
    }
}

fun main() {
    with(LicenseKeyFormatting()) {
        listOf(Pair("5F3Z-2e-9-w", 4), Pair("2-5g-3-J", 2)).forEach { (licenseKey, k) ->
            println("input -> s : $licenseKey k: $k")
            println("output ->  ${licenseKeyFormatting(licenseKey, k)}")
        }
    }
}