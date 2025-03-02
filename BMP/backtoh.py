from PIL import Image

def bmp_to_hex(image_path):
    # Open the BMP file
    with Image.open(image_path) as img:
        img = img.convert('RGB')  # Convert image to RGB (just in case it's not)
        width, height = img.size
        pixels = list(img.getdata())  # Get all pixels from the image

    # Prepare the output format: hexadecimal values, swapping Red and Blue
    hex_data = []
    for r, g, b in pixels:
        # Swap r and b
        hex_value = '0x{:02X}{:02X}{:02X}'.format(b, g, r)  # Swapped here for BGR format
        hex_data.append(hex_value)

    # Optional: format for direct use in C/C++ arrays
    hex_string = ', '.join(hex_data)
    return hex_string

# Path to your BMP image
image_path = 'D:\\BMPP\\INST_SLOT_1h.bmp'  # Make sure to use the correct path
formatted_hex_data = bmp_to_hex(image_path)

# Save the output to a text file
output_file_path = 'D:\\BMPP\\formatted_hex_data.txt'  # Path to the output file
with open(output_file_path, 'w') as file:
    file.write(formatted_hex_data)

print("Data has been saved to", output_file_path)
