from PIL import Image;

img = Image.open('C:/Users/Junwha-PC/Desktop/photo/1.jpg')
    img = img.resize((int(img.width/2),int(img.height/2)))
print(img.width)
print(img.height)   
arr = img.tobytes()

count = 0

for a in arr:
    if count<50:
        print(str(hex(a))+",",end="")
        count+=1
    elif count==50:
        print(str(hex(a))+",")
        count=0

