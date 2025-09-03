import cv2
import numpy as np
import os

# Input image path
img_path = r"X:\pro\New folder\iss071e487194orig.jpg"

# Read image and convert to grayscale
img = cv2.imread(img_path, cv2.IMREAD_GRAYSCALE)
h, w = img.shape

# Make sure dimensions are even
h -= h % 2
w -= w % 2
img = img[:h, :w]

# Prepare empty arrays
LL = np.zeros((h//2, w//2), dtype=np.float32)
LH = np.zeros_like(LL)
HL = np.zeros_like(LL)
HH = np.zeros_like(LL)

# Apply 2x2 Haar wavelet transform block-wise
for i in range(0, h, 2):
    for j in range(0, w, 2):
        a = float(img[i, j])
        b = float(img[i, j+1])
        c = float(img[i+1, j])
        d = float(img[i+1, j+1])

        ll = 0.5 * (a + b + c + d)
        lh = 0.5 * (a + b - c - d)
        hl = 0.5 * (a - b + c - d)
        hh = 0.5 * (a - b - c + d)

        ii, jj = i//2, j//2
        LL[ii, jj] = ll
        LH[ii, jj] = lh
        HL[ii, jj] = hl
        HH[ii, jj] = hh

# --- Custom normalization using theoretical min/max ---
def custom_norm_LL(x):  # Range [0, 510]
    return np.clip((x / 510.0) * 255.0, 0, 255).astype(np.uint8)

def custom_norm_other(x):  # Range [-255, 255]
    return np.clip(((x + 255.0) / 510.0) * 255.0, 0, 255).astype(np.uint8)

ll_custom = custom_norm_LL(LL)
lh_custom = custom_norm_other(LH)
hl_custom = custom_norm_other(HL)
hh_custom = custom_norm_other(HH)

# --- Standard normalization ---
def std_norm(x):
    x_min, x_max = x.min(), x.max()
    return np.clip(((x - x_min) / (x_max - x_min)) * 255.0, 0, 255).astype(np.uint8)

ll_std = std_norm(LL)
lh_std = std_norm(LH)
hl_std = std_norm(HL)
hh_std = std_norm(HH)
whole_cus =  lh_custom + hl_custom + hh_custom
whole_std =  lh_std + hl_std + hh_std
# --- Save all 8 images ---
save_dir = os.path.dirname(img_path)

cv2.imwrite(os.path.join(save_dir, "ll_norm_custom.png"), ll_custom)
cv2.imwrite(os.path.join(save_dir, "lh_norm_custom.png"), lh_custom)
cv2.imwrite(os.path.join(save_dir, "hl_norm_custom.png"), hl_custom)
cv2.imwrite(os.path.join(save_dir, "hh_norm_custom.png"), hh_custom)

cv2.imwrite(os.path.join(save_dir, "ll_norm_std.png"), ll_std)
cv2.imwrite(os.path.join(save_dir, "lh_norm_std.png"), lh_std)
cv2.imwrite(os.path.join(save_dir, "hl_norm_std.png"), hl_std)
cv2.imwrite(os.path.join(save_dir, "hh_norm_std.png"), hh_std)
cv2.imwrite(os.path.join(save_dir, "whole_cus.png"), whole_cus)
cv2.imwrite(os.path.join(save_dir, "whole_std.png"), whole_std)

def edge_map_from_coeff(x, clip_percent=99):
    abs_x = np.abs(x)
    limit = np.percentile(abs_x, clip_percent)
    abs_x = np.clip(abs_x, 0, limit)
    norm = (abs_x / limit) * 255.0
    return norm.astype(np.uint8)

# Create edge maps
lh_edges = edge_map_from_coeff(LH)
hl_edges = edge_map_from_coeff(HL)
hh_edges = edge_map_from_coeff(HH)

# Save individual edge subbands
cv2.imwrite(os.path.join(save_dir, "lh_edges.png"), lh_edges)
cv2.imwrite(os.path.join(save_dir, "hl_edges.png"), hl_edges)
cv2.imwrite(os.path.join(save_dir, "hh_edges.png"), hh_edges)

# --- Combine them visually like edge detector ---
combined_edges = cv2.addWeighted(lh_edges, 1.0, hl_edges, 1.0, 0)
combined_edges = cv2.addWeighted(combined_edges, 1.0, hh_edges, 1.0, 0)
combined_edges = np.clip(combined_edges, 0, 255).astype(np.uint8)

# Save final edge image
cv2.imwrite(os.path.join(save_dir, "haar_combined_edges.png"), combined_edges)
stacked_edges = np.hstack([lh_edges, hl_edges, hh_edges, combined_edges])
cv2.imwrite(os.path.join(save_dir, "stacked_edges_row.png"), stacked_edges)
def edge_map_strong_only(x, clip_percent=99, show_percent=90):
    abs_x = np.abs(x)
    limit = np.percentile(abs_x, clip_percent)  # cutoff at 99%
    abs_x = np.clip(abs_x, 0, limit)

    # Normalize to [0, 255]
    norm = (abs_x / limit) * 255.0

    # Threshold: keep only strong ones
    thresh = np.percentile(norm, show_percent)
    binary_edge = np.where(norm >= thresh, 255, 0).astype(np.uint8)
    return binary_edge
lh_strong = edge_map_strong_only(LH, clip_percent=99, show_percent=99)
hl_strong = edge_map_strong_only(HL, clip_percent=99, show_percent=99)
hh_strong = edge_map_strong_only(HH, clip_percent=99, show_percent=99)

# Stack or combine as you did before
cv2.imwrite(os.path.join(save_dir, "lh_strong_edges.png"), lh_strong)
cv2.imwrite(os.path.join(save_dir, "hl_strong_edges.png"), hl_strong)
cv2.imwrite(os.path.join(save_dir, "hh_strong_edges.png"), hh_strong)

combined_strong = np.maximum.reduce([lh_strong, hl_strong, hh_strong])
cv2.imwrite(os.path.join(save_dir, "strong_edge_map.png"), combined_strong)
def percentile(sorted_list, percent):
    k = (len(sorted_list) - 1) * (percent / 100.0)
    f = int(k)
    c = min(f + 1, len(sorted_list) - 1)
    if f == c:
        return sorted_list[int(k)]
    d0 = sorted_list[f] * (c - k)
    d1 = sorted_list[c] * (k - f)
    return d0 + d1

def flatten(matrix):
    return [v for row in matrix for v in row]

def abs_matrix(matrix):
    return [[abs(val) for val in row] for row in matrix]

def clip_matrix(matrix, clip_val):
    return [[min(val, clip_val) for val in row] for row in matrix]

def normalize_matrix(matrix, limit):
    return [[(val / limit) * 255 for val in row] for row in matrix]

def threshold_matrix(matrix, threshold):
    return [[255 if val >= threshold else 0 for val in row] for row in matrix]

def edge_map_strong_only_pure(matrix, clip_percent=99, show_percent=90):
    # Step 1: Absolute value
    abs_mat = abs_matrix(matrix)

    # Step 2: Flatten for percentile
    flat = flatten(abs_mat)
    flat.sort()

    # Step 3: Clip limit and clip matrix
    clip_limit = percentile(flat, clip_percent)
    clipped = clip_matrix(abs_mat, clip_limit)

    # Step 4: Normalize
    normalized = normalize_matrix(clipped, clip_limit)

    # Step 5: Threshold to keep only strong edges
    flat_norm = flatten(normalized)
    flat_norm.sort()
    threshold_val = percentile(flat_norm, show_percent)

    binary_output = threshold_matrix(normalized, threshold_val)
    return binary_output
lh_strong2 = edge_map_strong_only_pure(LH, clip_percent=99, show_percent=99)
hl_strong2 = edge_map_strong_only_pure(HL, clip_percent=99, show_percent=99)
hh_strong2 = edge_map_strong_only_pure(HH, clip_percent=99, show_percent=99)

# Stack or combine as you did before
cv2.imwrite(os.path.join(save_dir, "lh_strong_edges2.png"), np.array(lh_strong2, dtype=np.uint8))
cv2.imwrite(os.path.join(save_dir, "hl_strong_edges2.png"), np.array(hl_strong2, dtype=np.uint8))
cv2.imwrite(os.path.join(save_dir, "hh_strong_edges2.png"), np.array(hh_strong2, dtype=np.uint8))
print("✅ 4")
combined_strong2 = np.maximum.reduce([
    np.array(lh_strong2),
    np.array(hl_strong2),
    np.array(hh_strong2)
])
cv2.imwrite(os.path.join(save_dir, "strong_edge_map2.png"), combined_strong2.astype(np.uint8))
print("✅ 3")
def edge_map_strong_fixed_threshold(matrix, abs_limit=255, min_strength=1):
    binary = []
    for row in matrix:
        binary_row = []
        for val in row:
            v = abs(val)
            v = min(v, abs_limit)
            norm = (v / abs_limit) * 255
            binary_row.append(255 if norm >= min_strength else 0)
        binary.append(binary_row)
    return binary
print("✅ 2")
lh_strong3 = edge_map_strong_fixed_threshold(LH)
hl_strong3 = edge_map_strong_fixed_threshold(HL)
hh_strong3 = edge_map_strong_fixed_threshold(HH)
print("✅ 1")
# Stack or combine as you did before
cv2.imwrite(os.path.join(save_dir, "lh_strong_edges3.png"), np.array(lh_strong3, dtype=np.uint8))
cv2.imwrite(os.path.join(save_dir, "hl_strong_edges3.png"), np.array(hl_strong3, dtype=np.uint8))
cv2.imwrite(os.path.join(save_dir, "hh_strong_edges3.png"), np.array(hh_strong3, dtype=np.uint8))
print("✅ 0")
combined_strong3 = np.maximum.reduce([
    np.array(lh_strong3),
    np.array(hl_strong3),
    np.array(hh_strong3)
])
cv2.imwrite(os.path.join(save_dir, "strong_edge_map3.png"), combined_strong3.astype(np.uint8))

print("✅ Done. Images saved next to the original file.")# --- Edge Enhancement from High-Pass Subbands ---