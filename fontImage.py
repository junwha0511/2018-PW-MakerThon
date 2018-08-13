# coding: utf-8
from PIL import Image, ImageDraw, ImageFont
base = Image.new("L",(100,50),"white")

fnt = ImageFont.truetype('C:/Users/Junwha-PC/Documents/programming/2018-PW-MakerTon/asdf.ttf', 50)
d = ImageDraw.Draw(base)
txt = "안"

d.text((0,0), txt, fill='black', font=fnt)
base.convert("L").show()
# pixels = base.load()
# print('const char pixels[] = {')
# w, h = base.size    
# for y in range(h):
#     print('\t'),
#     for x in range(w):
#         print(hex(pixels[x,y]), end = '')
#         print(',', end = '')
#     print()
# print('};')

