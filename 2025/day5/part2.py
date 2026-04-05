ranges = []

with open("input.txt") as f:
    for line in f:
        line = line.strip()
        if line == "":
            break
        start, end = line.split("-")
        ranges.append((int(start), int(end)))

ranges.sort()
merged = []
for start, end in ranges:
    if not merged or start > merged[-1][1] + 1:
        merged.append((start, end))
    else:
        merged[-1] = (merged[-1][0], max(merged[-1][1], end))

print(sum(end - start + 1 for start, end in merged))
