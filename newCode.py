#필요한 모듈 import
import openpyxl #엑셀을 다루기 위한 모듈
from PIL import Image, ImageDraw, ImageFont, ImagePalette #이미지를 다루기 위한 모듈

#초기 선언
fnt = ImageFont.truetype('C:/Users/Junwha-PC/Documents/programming/2018-PW-MakerTon/asdf.ttf', 20)#글꼴 지정
count = 0 #index counter
arr = {} #단어-뜻 형식으로 저장될 딕셔너리
wb = openpyxl.load_workbook('C:/Users/Junwha-PC/Documents/programming/2018-PW-MakerTon/2000words.xlsx') #엑셀 파일 열기
ws = wb.active #현재 활성화 된 시트 가져오기

#데이터 파싱
for r in ws.rows:
    arr[r[0].value] = r[1].value #1열: 단어, 2열: 뜻


#데이터 변환
for a in arr:
    if count==0:
        print(a)
        count+=1
        word = str(a)+'  '+str(arr[a]) #단어와 뜻을 공백 두개와 함게 합친다.
        wid = word.__len__()#문자열의 길이를 너비 변수로 둔다.
        image = Image.new("1",((20*wid), 20),"black") #50x너비변수를 가로로, 50을 세로로 하는 이미지 생성
        draw = ImageDraw.Draw(image) #이미지 위에 그린다.
        draw.text((0,0), word, fill = "white", font=fnt) # (0,0)의 위치에서부터 word를 검정색으로 쓴다.
        print(wid)
        arr = image.tobytes()
        c=1
        for i in arr:
            if (c<10):
                print(str((i))+",",end="")
            if c==10:
                print(str((i))+",")
                c = 1
                
        print(1)
        


