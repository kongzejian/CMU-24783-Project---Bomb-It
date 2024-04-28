import os
from PIL import Image

def resize_images(directory):
    # List all files in the directory
    files = os.listdir(directory)

    for file in files:
        # Check if the file is an image (you may need to add more extensions if needed)
        if file.endswith(".jpg") or file.endswith(".png") or file.endswith(".jpeg"):
            # Open the image
            image_path = os.path.join(directory, file)
            img = Image.open(image_path)
            
            # Resize the image to 60x60
            img_resized = img.resize((60, 60))
            
            # Save the resized image, covering the original image
            img_resized.save(image_path)
            print(f"Resized {file}")

# Provide the directory containing images
directory = "."
resize_images(directory)
