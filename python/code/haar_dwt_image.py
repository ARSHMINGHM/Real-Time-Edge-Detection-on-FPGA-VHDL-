import cv2
import numpy as np
import pywt
import os

def dwt_block(block, wavelet='haar'):
    """ اعمال DWT روی یک بلوک 2D از تصویر """
    coeffs2 = pywt.dwt2(block, wavelet)
    LL, (LH, HL, HH) = coeffs2
    return LL  # فقط خروجی LL نگه‌داری می‌شود

def process_image_blockwise(image, block_size=8):
    h, w = image.shape
    output = np.zeros((h // 2, w // 2), dtype=np.uint8)

    for i in range(0, h, block_size):
        for j in range(0, w, block_size):
            block = image[i:i + block_size, j:j + block_size]
            if block.shape[0] < block_size or block.shape[1] < block_size:
                continue  # نادیده گرفتن بلاک‌های ناقص

            LL = dwt_block(block)
            # نرمال‌سازی و قراردادن در مکان خودش
            LL = cv2.normalize(LL, None, 0, 255, cv2.NORM_MINMAX)
            LL = np.uint8(LL)

            output[i//2:i//2 + block_size//2, j//2:j//2 + block_size//2] = LL

    return output

def process_image_streamwise(image, wavelet='haar'):
    """ شبیه‌سازی پردازش استریم - خط به خط """
    h, w = image.shape
    output = np.zeros((h // 2, w // 2), dtype=np.uint8)

    # هر دو خط را با هم می‌گیریم چون DWT به 2D نیاز دارد
    for i in range(0, h - 1, 2):
        block = image[i:i+2, :]  # دو خط
        if block.shape[0] < 2:
            continue

        # اعمال DWT به صورت 1D روی هر سطر (و سپس روی ستون‌ها)
        row_dwt = np.array([pywt.dwt(row, wavelet)[0] for row in block])
        col_dwt = np.array([pywt.dwt(row_dwt[:, i], wavelet)[0] for i in range(row_dwt.shape[1])]).T
        col_dwt = cv2.normalize(col_dwt, None, 0, 255, cv2.NORM_MINMAX)
        output[i//2, :col_dwt.shape[1]] = np.uint8(col_dwt[0])  # فقط سطر اول

    return output

def main():
    input_image_path = r"C:\Users\arshm\Desktop\dwt_output2.jpg"
    image = cv2.imread(input_image_path, cv2.IMREAD_GRAYSCALE)

    if image is None:
        print("❌ تصویر ورودی پیدا نشد.")
        return

    print("✅ شروع پردازش بلوکی:")
    block_output = process_image_blockwise(image, block_size=8)
    cv2.imwrite(r"C:\Users\arshm\Desktop\dwt_block_output.jpg", block_output)

    print("✅ شروع پردازش استریمی:")
    stream_output = process_image_streamwise(image)
    cv2.imwrite(r"C:\Users\arshm\Desktop\dwt_stream_output.jpg", stream_output)

    print("✅ هر دو تصویر ذخیره شدند.")

if __name__ == "__main__":
    main()
