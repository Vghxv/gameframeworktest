from PIL import Image
import os

dir = "img_png"

for i,file in enumerate(os.listdir(dir)):
     img = Image.open(f"{dir}/{file}")
     img.save(f'{dir}/{i}.bmp')