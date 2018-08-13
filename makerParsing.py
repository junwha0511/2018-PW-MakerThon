import openpyxl

wb = openpyxl.load_workbook('C:/Users/Junwha-PC/Documents/Programming/2018-PW-MakerTon') #엑셀 파일 열기

ws = wb.active #현재 활성화 된 시트 가져오기

count = 0 #단어 2000개를 파싱해올 때 사용할 count

arr = {} #딕셔너리

for r in ws.rows:
    arr[r[1].value] = r[2].value
    arr[r[4].value] = r[5].value
# 1,2번 인덱스, 4,5번 인덱스

for a in arr:
    print(a)
    print(arr[a])
print(arr.__len__())

'''
1. 단어 데이터 시트를 스케치 코드에 배열로 포함해 로드한다.
2. 단어 데이터 시트의 사용자가 외운 단어, 못 외운 단어를 EEPROM에 저장하고, 가져온다.
3. EEPROM에는 못 외운 단어의 저장 영역이 1일 전, 2일 전, 3일 전으로 영역이 나누어져있다.
4. 할당 시간대가 되면 3일 전 못 외운 단어와
'''