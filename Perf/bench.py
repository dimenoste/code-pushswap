#!/usr/bin/env python3
import subprocess
import random
import time
import matplotlib.pyplot as plt

# --------------------------
# Configuration
# --------------------------
MODES = ["simple", "medium", "complex"]
NUM_RUNS = 500
LIST_SIZE = 500
MAX_INT = 1000

results = {mode: {"times": [], "moves": [], "disorder": []} for mode in MODES}


# --------------------------
# Helper functions
# --------------------------
def count_inversions(nums):
    """Count all pair inversions (full-pair disorder)."""
    inv = 0
    n = len(nums)
    for i in range(n):
        for j in range(i + 1, n):
            if nums[i] > nums[j]:
                inv += 1
    return inv


def compute_disorder(nums):
    """Compute disorder fraction 0.0–1.0 (matches C compute_disorder)."""
    n = len(nums)
    if n < 2:
        return 0.0
    total_pairs = n * (n - 1) // 2
    return count_inversions(nums) / total_pairs


def generate_list_with_target_disorder_fast(nums, target_fraction):
    """
    Generate a list with approximate full-pair disorder in O(n log n).
    nums: sorted list of unique numbers
    target_fraction: 0.0 -> 1.0
    """
    n = len(nums)
    if n <= 1:
        return nums

    mid = n // 2
    left = generate_list_with_target_disorder_fast(nums[:mid], target_fraction)
    right = generate_list_with_target_disorder_fast(nums[mid:], target_fraction)

    merged = []
    while left and right:
        # Probability of taking right first increases disorder
        prob_right = 0.5 + (target_fraction - 0.5) * 2
        if random.random() < prob_right:
            merged.append(right.pop(0))
        else:
            merged.append(left.pop(0))
    merged += left + right
    return merged


def generate_benchmark_list(size, target_fraction):
    """
    Generates a shuffled, unique list with disorder in 0.01->0.99 range.
    """
    nums = random.sample(range(1, MAX_INT + 1), size)
    nums.sort()
    nums = generate_list_with_target_disorder_fast(nums, target_fraction)
    actual_disorder = compute_disorder(nums)
    if actual_disorder <= 0.005 or actual_disorder >= 0.995:
        random.shuffle(nums)
    return nums


# --------------------------
# Benchmark loop
# --------------------------
for mode in MODES:
    print(f"\n=== Running benchmark for mode: {mode} ===")
    for run in range(NUM_RUNS):
        # Target disorder fraction from 0.01 -> 0.99
        target_disorder = 0.01 + 0.98 * run / (NUM_RUNS - 1)
        nums = generate_benchmark_list(LIST_SIZE, target_disorder)
        disorder_actual = compute_disorder(nums)
        nums_str = list(map(str, nums))

        try:
            start = time.perf_counter()
            proc = subprocess.run(
                ["../push_swap"] + nums_str + [f"--{mode}", "--count-only"],
                capture_output=True,
                text=True,
                timeout=20
            )
            end = time.perf_counter()
            t = end - start

            out_lines = proc.stdout.splitlines()
            if len(out_lines) < 2:
                print(f"Run {run+1}: output incomplete, skipping")
                continue

            try:
                disorder_reported = float(out_lines[0].strip())
                moves = int(out_lines[1].strip())
            except ValueError:
                print(f"Run {run+1}: failed to parse output, skipping")
                continue

            results[mode]["disorder"].append(disorder_reported)
            results[mode]["moves"].append(moves)
            results[mode]["times"].append(t)

            print(f"Run {run+1}/{NUM_RUNS} | {mode} | disorder={disorder_reported:.4f} | moves={moves} | time={t:.3f}s")

        except subprocess.TimeoutExpired:
            print(f"Run {run+1}: timeout, skipping")
            continue


# --------------------------
# Plotting: separate plot for each algorithm
# --------------------------
for mode in MODES:
    plt.figure(figsize=(12, 6))
    scatter = plt.scatter(
        results[mode]["times"],
        results[mode]["moves"],
        c=results[mode]["disorder"],
        cmap="viridis",
        alpha=0.8
    )
    plt.xlabel("CPU Time (s)")
    plt.ylabel("Moves")
    plt.title(f"Push_swap: Moves vs Time with Disorder Gradient ({mode})")
    plt.colorbar(scatter, label="Disorder")
    plt.grid(True)
    plt.tight_layout()
    plt.savefig(f"perf_disorder_plot_{mode}.png")
    plt.close()
    print(f"Plot saved as perf_disorder_plot_{mode}.png")

print("\nBenchmark complete. All plots saved.")