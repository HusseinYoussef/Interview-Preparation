
def validIPAddress(queryIP: str) -> str:

    ipv4 = queryIP.split('.')
    ipv6 = queryIP.split(':')

    ans = True
    if len(ipv4) == 4:
        for s in ipv4:
            if len(s) and s.isnumeric() and int(s) >= 0 and int(s) <= 255 and (s[0] != '0' or len(s) == 1):
                continue
            ans = False
            break
        if ans:
            return "IPv4"
   
    ans = True
    if len(ipv6) == 8:
        for s in ipv6:
            if not(1 <= len(s) <= 4):
                return "Neither"
            for c in s:
                if('0' <= c <= '9' or 'a' <= c <= 'f' or 'A' <= c <= 'F'):
                    continue
                return "Neither"
        if ans:
            return "IPv6"
    return "Neither"