n, l, r, ql, qr = tuple(int(val) for val in raw_input().split())

sumPref = [0] * (n + 1)
nums = [int(val) for val in raw_input().split()]

for i in xrange(n):
	sumPref[i + 1] = sumPref[i] + nums[i]

res = sumPref[n] * r + qr * (n - 1)


def get_diffs(indL):
	diff = max(0, abs(indL - (n - indL)) - 1)
	if indL == n / 2:
		return min(ql, qr) * diff
	return ql * diff if indL > n / 2 else qr * diff


for i in xrange(1, n + 1):
	res = min(res, sumPref[i] * l + (sumPref[n] - sumPref[i]) * r + get_diffs(i))

print res