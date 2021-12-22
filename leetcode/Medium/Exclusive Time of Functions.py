from typing import List

def exclusiveTime(n: int, logs: List[str]) -> List[int]:

    ans = [0] * n
    st = []
    for idx, log in enumerate(logs):
        id, state, ts = log.split(':')
        id = int(id)
        ts = int(ts)
        if idx > 0:
            preState, prets = logs[idx-1].split(':')[1:]
            prets = int(prets)
            if state == "start":
                if len(st):
                    st[-1][1] += ts - (prets + (preState == "end"))
            else:
                st[-1][1] += ts - prets + (preState == "start")
                id, time = st[-1]
                ans[id] += time
                st.pop()
        if state == "start":
            st.append([id, 0])
    return ans