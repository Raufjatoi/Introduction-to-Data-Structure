import easyocr

reader = easyocr.Reader(['en'])  

result = reader.readtext('sample.png')

for detection in result:
    print(detection[1])
