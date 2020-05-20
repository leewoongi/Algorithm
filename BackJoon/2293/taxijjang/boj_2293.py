import sys

n,k = map(int,sys.stdin.readline().split())

coin = []
for _ in range(n):
    coin.append(int(sys.stdin.readline()))

dp = [0] * (k + 1)
dp[0] = 1

for c in coin:
    for index in range(k+1):
        if index - c < 0:
            continue
        dp[index] = dp[index] + dp[index- c]
print(dp[k])