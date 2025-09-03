# README: VHDL Haar Wavelet Image Processing on FPGA

## 📌 Project Goal
Implement and simulate a VHDL module for image transformation using the **Haar Wavelet Transform**. The design is simulated first in Python and C, then translated to HLS C for FPGA implementation.

---

## 📚 References
- "Hardware Description of Multi-Directional Fast Sobel Edge Detection Processor by VHDL"
- "Implementation of Edge Detection Algorithms in Real Time on FPGA"

---

## 🧱 Project Steps

### 1. Initial Python Implementation
- Implemented filters (smoothing, edge detection).
- Simulated classic edge detection methods.
- Output stored in `python/` folder.

### 2. C Implementation
- Developed `2x2` and `3x3` window logic with shift registers for hardware-like behavior.

### 3. Window Generator Module (HLS C)
- Generates `2x2` windows from input pixel stream.
- Two versions:
  - Basic C
  - HLS-optimized version using `#pragma HLS`

### 4. Window Processor
- Applies Haar Wavelet filters:
  - LL (Approximation)
  - LH (Horizontal)
  - HL (Vertical)
  - HH (Diagonal)
- Uses predefined 2x2 kernels for each output.

### 5. Comparator Function
- Combines LL, LH, HL, HH outputs into 8-bit pixel values.
- Provides combinations:
  - `LL + HH` (smooth + detail)
  - `LH + HL` (horizontal + vertical edges)
  - `HH + LH + HL` (detailed edges)
- Outputs normalized pixel values (uint8_t).

### 6. SaveToRamAndOutput
- Loops through image pixels.
- Applies `comparator` for each pixel window.
- Saves edge-detected output as `.pgm` image.

---

## 🧪 Testbenches

- `arraygeneratorpixeltb`: Tests window generation.
- `windowprocessortb`: Tests Haar wavelet transform values.
- `comparatortb`: Verifies edge intensity and combination.
- `general tb`: Loads PGM, applies transform, saves result.

---

## 🖼️ Sample Outputs
- Shows input, grayscale conversion, Haar transform result.
- Output images saved as `.pgm`.

---

## 🛠️ Tools Used
- **Vivado HLS** for hardware synthesis and simulation.
- Python and C for prototyping and verification.

---

## 🗂️ File Structure (suggested)
project/
│
├── python/ # Python simulations
├── c_implementation/ # C-based logic
├── hls/ # HLS-compatible C code
├── testbenches/ # Test code for verification
├── output_images/ # Resultant PGM images
└── report/ # Vivado synthesis report

---

## ✅ Build & Run Instructions (HLS)

1. Load image (PGM format) into memory.
2. Call `SaveToRamAndOutput` with image data.
3. Generated output is written to disk as PGM.
4. Use Vivado HLS to synthesize C modules.

---

## 📷 Output Examples
- Input: Grayscale image
- Output: LL, LH, HL, HH channels + combinations
- Format: `.pgm` (portable graymap)

---

## 🧾 Note
- This project is optimized for streaming architectures (line-by-line pixel input).
- Careful with noise; filters were tuned to reduce it while keeping edges sharp.
