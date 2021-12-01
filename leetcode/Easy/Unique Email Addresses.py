
def numUniqueEmails(self, emails: List[str]) -> int:
    d = {}
    ans = 0
    for email in emails:
        name, domain = email.split('@')
        mail = (''.join(name.split('+')[0].split('.'))) + '@' + domain
        if mail not in d:
            d[mail] = 1
            ans+=1

    return ans