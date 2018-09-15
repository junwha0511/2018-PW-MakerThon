#필요한 모듈 import
import openpyxl #엑셀을 다루기 위한 모듈
from PIL import Image, ImageDraw, ImageFont #이미지를 다루기 위한 모듈

   
#초기 선언
fnt = ImageFont.truetype('C:/Users/Junwha-PC/Documents/programming/2018-PW-MakerTon/asdf.ttf', 20) #글꼴 지정
count = 0 #index Counter
arr = {} #단어-뜻 형식으로 저장될 딕셔너리
wb = openpyxl.load_workbook('C:/Users/Junwha-PC/Documents/programming/2018-PW-MakerTon/2000words.xlsx') #엑셀 파일 열기
ws = wb.active #현재 활성화 된 시트 가져오기

#데이터 파싱
for r in ws.rows:
    arr[r[0].value] = r[1].value #1열: 단어, 2열: 뜻

#데이터 변환
for a in arr:
    count += 1
    word = str(a)+'  '+str(arr[a]) #단어와 뜻을 공백 두개와 함게 합친다.

    image = Image.new("1",(700, 20),"black") #700x20 이미지 생성
    draw = ImageDraw.Draw(image) #이미지 위에 그린다.
    draw.text((0,0), word, fill = "white", font=fnt) # (0,0)의 위치에서부터 word를 검정색으로 쓴다.
    image.save('C:/Users/Junwha-PC/Documents/programming/2018-PW-MakerTon/img/'+str(count)+'.bmp')
    #파싱
    pxArr = ""
    bArr = image.tobytes()
    image.save
    f = open(('C:/Users/Junwha-PC/Documents/programming/2018-PW-MakerTon/files/'+str(count)+'.txt'),'w') #새 파일을 생성한다.
    pxArr=pxArr[0:(pxArr.__len__()-1)]
    # f.write("#ifndef _"+str(count)+"_h_\n")
    # f.write("#define _"+str(count)+"_h_\n\n")
    # f.write("#define width "+str(wid*20)+"\n")
    # f.write("#define height 20\n\n")
    # f.write("static const uint8_t PROGMEM word"+str(count)+"[] ={\n")

    c = 1 #몇 번째 반복 중인지 확인
    for i, data in enumerate(bArr):
        if i!=(len(bArr)-1):
            if c<20: 
                f.write(str(hex(data))+",")
                c+=1
            elif c==20:
                f.write(str(hex(data))+",\n")
                c=1
        elif i==(len(bArr)-1):
            f.write(str(hex(data)))
    f.close() #파일을 닫는다.
print("Your files are completely converted.")    
print("파일이 성공적으로 변환되었습니다.")

