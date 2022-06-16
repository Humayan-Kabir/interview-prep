package interview_process

class UniqueEmailAddresses {
     fun numUniqueEmails(emails: Array<String>): Int {
        val hashSet = HashSet<String>()
        for (email in emails) {
            email.split('@').also { parts ->
                val filteredEmail = parts.first().split('+').first().replace(".", "")
                val validDomain = parts[1]
                hashSet.add("$filteredEmail@$validDomain")
            }
        }
        return hashSet.size
    }
}