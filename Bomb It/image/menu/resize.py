from PIL import Image
import os

def resize_image(image_path, new_height):
    # Open the image
    img = Image.open(image_path)
    
    # Calculate the new width while maintaining the aspect ratio
    width_percent = (new_height / float(img.size[1]))
    new_width = int((float(img.size[0]) * float(width_percent)))
    
    # Resize the image
    resized_img = img.resize((new_width, new_height), Image.ANTIALIAS)
    
    # Save the resized image with the same name
    filename, file_extension = os.path.splitext(image_path)
    resized_img.save(filename + "_resized" + file_extension)

# Example usage
image_path = "statusBar.png"  # Change this to your image file name
new_height = 900
resize_image(image_path, new_height)
