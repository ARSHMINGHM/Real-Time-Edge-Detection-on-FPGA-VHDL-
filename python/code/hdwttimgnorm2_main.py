import cv2
import numpy as np
import os

# === CONFIG ===
img_path = r"C:\Users\arshm\Desktop\306161-3840x2160-desktop-4k-interstellar-background.jpg"
clip_percent = 95  # Clipping for contrast
apply_gamma = True
gamma_value = 1.2

# === Load and prepare image ===
img = cv2.imread(img_path, cv2.IMREAD_GRAYSCALE)
h, w = img.shape

# Ensure even dimensions for 2x2 blocks
h -= h % 2
w -= w % 2
img = img[:h, :w]

# === Initialize subband arrays ===
LL = np.zeros((h//2, w//2), dtype=np.float32)
LH = np.zeros_like(LL)
HL = np.zeros_like(LL)
HH = np.zeros_like(LL)

# === Haar 2x2 transform ===
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

# === Contrast Stretching with Clipping ===
def contrast_clip_norm(x, clip_percent=95):
    limit = np.percentile(np.abs(x), clip_percent)
    x = np.clip(x, -limit, +limit)
    x = ((x + limit) / (2 * limit)) * 255.0
    return np.clip(x, 0, 255).astype(np.uint8)

def normalize_LL(x):
    return np.clip((x / 510.0) * 255.0, 0, 255).astype(np.uint8)

# === Gamma Correction (Optional) ===
def gamma_correct(img, gamma=1.2):
    img = img / 255.0
    img = np.power(img, gamma)
    return np.clip(img * 255, 0, 255).astype(np.uint8)

# === Apply Normalization ===
ll_custom = normalize_LL(LL)
lh_custom = contrast_clip_norm(LH, clip_percent)
hl_custom = contrast_clip_norm(HL, clip_percent)
hh_custom = contrast_clip_norm(HH, clip_percent)

if apply_gamma:
    lh_custom = gamma_correct(lh_custom, gamma_value)
    hl_custom = gamma_correct(hl_custom, gamma_value)
    hh_custom = gamma_correct(hh_custom, gamma_value)

# === Save Subbands ===
save_dir = os.path.dirname(img_path)

cv2.imwrite(os.path.join(save_dir, "ll_custom.png"), ll_custom)
cv2.imwrite(os.path.join(save_dir, "lh_custom.png"), lh_custom)
cv2.imwrite(os.path.join(save_dir, "hl_custom.png"), hl_custom)
cv2.imwrite(os.path.join(save_dir, "hh_custom.png"), hh_custom)

# === Save Composite Grid (LL | LH / HL | HH) ===
grid = np.vstack([
    np.hstack([ll_custom, lh_custom]),
    np.hstack([hl_custom, hh_custom])
])
cv2.imwrite(os.path.join(save_dir, "wavelet_grid_custom.png"), grid)

print("✅ Done. All subband images and grid saved to:")
print(save_dir)
