from PIL import Image
import os

def resize_images(directory):
    # Get a list of all files in the directory
    files = os.listdir(directory)
    
    # Iterate over each file
    for file in files:
        # Check if the file is an image (you can add more image extensions if needed)
        if file.endswith('.jpg') or file.endswith('.jpeg') or file.endswith('.png'):
            # Open the image
            if(file == 'menu.png' or file == 'over.png'):
                image_path = os.path.join(directory, file)
                image = Image.open(image_path)
                
                # Resize the image
                resized_image = image.resize((1279, 900))
                
                # Save the resized image with the same name
                resized_image.save(image_path)

# Replace 'directory_path' with the path to your directory containing images
directory_path = '.'
resize_images(directory_path)
