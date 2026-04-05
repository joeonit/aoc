ranges = []
ids = []
id_count = 0

with open("input.txt") as f:
    for line in f:
        line = line.strip()
        if line == "":
            break
        start, end = line.split("-")
        ranges.append((int(start), int(end)))

    for line in f:
        line = line.strip()
        if line:
            ids.append(int(line))

for id in ids:
    if any(r[0] <= id <= r[1] for r in ranges):
        id_count += 1

print(id_count)
