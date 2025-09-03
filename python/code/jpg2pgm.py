from PIL import Image
import numpy as np

def jpg_to_pgm(input_path, output_path):
    # Load image and convert to grayscale
    img = Image.open(input_path).convert("L")  # "L" mode = 8-bit grayscale

    # Convert to numpy array
    img_array = np.array(img)

    height, width = img_array.shape

    with open(output_path, 'wb') as f:
        # Write PGM header
        f.write(f'P5\n{width} {height}\n255\n'.encode())
        # Write pixel data
        f.write(img_array.tobytes())

    print(f"✅ Saved PGM file: {output_path}")

# Example usage
if __name__ == "__main__":
    jpg_path = r"X:\pro\New folder (2)\53626148993-a17af7fc99-o.jpg"
    pgm_path = r"X:\pro\New folder (2)\outputpgmpython.pgm"
    jpg_to_pgm(jpg_path, pgm_path)
