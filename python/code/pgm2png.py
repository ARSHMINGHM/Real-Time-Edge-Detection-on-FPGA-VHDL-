import cv2
import os

# Define input and output paths
input_path = r"X:\pro\New folder (2)\output.pgm"
output_path = r"X:\pro\New folder (2)\output.png"

# Load the PGM image as grayscale
image = cv2.imread(input_path, cv2.IMREAD_GRAYSCALE)

# Check if loaded successfully
if image is None:
    print("❌ Failed to read image. Check the path or file.")
else:
    # Save as PNG
    success = cv2.imwrite(output_path, image)
    if success:
        print("✅ Successfully saved as PNG at:", output_path)
    else:
        print("❌ Failed to save PNG.")
