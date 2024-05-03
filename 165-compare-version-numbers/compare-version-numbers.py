class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        version1 = version1.split('.')
        version2 = version2.split('.')
        idx = 0
        while idx < len(version1) and idx < len(version2):
            if int(version1[idx]) == int(version2[idx]):
                idx += 1
                continue
            if int(version1[idx]) < int(version2[idx]):
                return -1
            else:
                return 1

        while idx < len(version1):
            if int(version1[idx]):
                return 1
            idx += 1
        while idx < len(version2):
            if int(version2[idx]):
                return -1
            idx +=1
        return 0