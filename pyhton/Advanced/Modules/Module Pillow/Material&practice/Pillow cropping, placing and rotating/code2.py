from PIL import Image                       #module or the picture work
image = Image.open("cat2.jpg")              #opening the pic
region = image.crop((100, 10, 200, 215))    #crop arguments
region = region.transpose(Image.ROTATE_90)  #rotating the image
region.show()                               #don't forget to change the variable for a different one to see the result


#===========Different roatating methods===========#
#=================================================#
#1. example.FLIP_LEFT_RIGHT
#2. example.FLIP_TO_BOTTOM
#3. example.ROTATE_90
#4. example.ROTATE_180
#5. example.ROTATE_270
#6. example = example.rotate(45)