# parse_data.py
import re
from collections import defaultdict

# File containing your benchmark output
filename = "data_100"

# Dictionary to store results per algorithm
results = defaultdict(lambda: {"moves": [], "times": []})

current_mode = None

# Regular expression to extract data from each run line
line_re = re.compile(
    r"Run \d+/\d+ \| (\w+) \| disorder=[\d.]+ \| moves=(\d+) \| time=([\d.]+)s"
)

with open(filename) as f:
    for line in f:
        line = line.strip()
        if not line:
            continue  # skip blank lines
        if line.startswith("==="):
            # Extract mode from the comment line
            m = re.search(r"mode: (\w+)", line)
            if m:
                current_mode = m.group(1)
            continue
        # Match run lines
        m = line_re.match(line)
        if m:
            mode, moves, t = m.groups()
            results[mode]["moves"].append(int(moves))
            results[mode]["times"].append(float(t))

# Compute and print averages
for mode in results:
    moves = results[mode]["moves"]
    times = results[mode]["times"]
    avg_moves = sum(moves) / len(moves) if moves else 0
    avg_time = sum(times) / len(times) if times else 0
    print(f"{mode.capitalize()} Mode | Average Moves: {avg_moves:.2f} | Average Time: {avg_time:.4f}s")