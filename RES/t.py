from PIL import IMAGE
import os

dir = "img_png"

for i,file in eumerate(os.listdir(dir)):
     img = Image.open(file)
     a = '{i}.bmp'
     img.save(a)