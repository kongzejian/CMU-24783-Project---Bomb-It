import os
from PIL import Image

def resize_image(image_path, new_height):
    # Open the image
    img = Image.open(image_path)
    
    # Calculate the width maintaining aspect ratio
    height_percent = (new_height / float(img.size[1]))
    new_width = int((float(img.size[0]) * float(height_percent)))
    
    # Resize the image
    resized_img = img.resize((new_width, new_height), Image.ANTIALIAS)
    
    return resized_img

def main():
    # Get the current directory
    current_dir = os.getcwd()

    # Get all files ending with "left.png" or "right.png"
    image_files = [file for file in os.listdir(current_dir) if file.endswith(('left.png', 'right.png'))]

    # Resize images
    for file_name in image_files:
        image_path = os.path.join(current_dir, file_name)
        resized_img = resize_image(image_path, 84)
        resized_img.save(image_path)  # Overwrite the original image with the resized one

if __name__ == "__main__":
    main()
