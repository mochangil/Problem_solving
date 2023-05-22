import numpy as np

# print("Input Key: ")
# key = list(map(int,input().split()))
print('Decryption Begins')
key = [5,8,13,7]
keyarr = np.array([[key[0],key[1]],[key[2],key[3]]])
# print(keyarr)

#암호화
def HillEncryption(words,key):
    plain = np.array([words[0],words[1]])
    cipher = (plain@key)%26
    return cipher

#복호화
def HillDecryption(words,key):
    g = (key[0][0]*key[1][1]-key[0][1]*key[1][0])%26
    for i in range(1,26):
        if (g*i)%26 == 1:
            break
    invkey = np.array([[key[1][1],(-1*key[0][1])%26],[(-1*key[1][0])%26,key[0][0]]])
    invkey = (invkey*i)%26
    plaintext = (words@invkey)%26
    # print("words = ",words)
    # print("invkey = ", invkey)
    # print("plaintext = ",plaintext)
    return plaintext

#단어를 0~25의 숫자로 변환
def Wordstonumber(ogword):
    standard = ord('A')
    if ogword == " ":
        return ogword
    else:
        words = ord(ogword[0])-standard,ord(ogword[-1])-standard
        words = HillDecryption(words,keyarr)

        if len(ogword) > 2:
            return chr(words[0]+standard)+" "+chr(words[-1]+standard)
        
        return chr(words[0]+standard)+chr(words[-1]+standard)


#암호문 -> 원문
fin = open("ciphertext1.txt","r")
fout = open("restoretext1.txt","w")

linecount = 0
while True:
    linecount += 1
    line = fin.readline()
    if not line: break
    line = line.upper()
    
    #줄바꿈문자 제거
    if line[-1] == "\n":
        line = line[0:len(line)-1]
    
    i = 0
    while i<len(line):
        nextchar = True
        if line[i] == " ":
            word = " "
            i -= 1
        elif line[i+1] == " ":
            word = line[i]+" "+line[i+2]
            i += 1
        else:
            word = line[i]+line[i+1]
        
        i+=2
        words = Wordstonumber(word)

        if i >= len(line):
            if linecount > 1:
                words = words[0]+"\n"
            else:
                words = words[0]

        print(words,end="")
        fout.write(words)

