
print("input Key (no space): ")
key = input()
print("select options: \n 1) Encryption \n 2) Decryption")
options = int(input())

def Wordstonumber(lines):
    numlines=[]
    for i in range(0,len(lines)):
        if lines[i] == " ":
            numlines.append(" ")
        else:
            numlines.append(ord(lines[i])-ord('A'))
    return numlines

def Numbertowords(lines):
    wordlines=''
    for i in range(0,len(lines)):
        if lines[i] == " ":
            wordlines += " "
        else:
            wordlines += (chr(lines[i]+ord('A')))
    return wordlines

def VigenereEncryption(line,key):
    cipher = []
    for i in range(0,len(line)):
        if line[i] == " ":
            cipher.append(" ")
        else:
            cipher.append((line[i]+key[i%len(key)])%26)
    return cipher

def VigenereDecryption(cipher,key):
    plain = []
    for i in range(0,len(cipher)):
        if cipher[i] == " ":
            plain.append(" ")
        else:
            plain.append((cipher[i]-key[i%len(key)])%26)
    return plain

if options == 1:
    fin = open("plaintext2.txt","r")
    fout = open("ciphertext2.txt","w")

    while True:
        line = fin.readline()
        if not line: break
        line = line.upper()

        line = Wordstonumber(line)
        key = Wordstonumber(key)
        cipherline = VigenereEncryption(line,key)

        ciphertext = Numbertowords(cipherline)
        print(ciphertext)
        fout.write(ciphertext)

elif options == 2:
    fin = open("ciphertext2.txt","r")
    fout = open("restoretext2.txt","w")

    while True:
        line = fin.readline()
        if not line: break
        line = line.upper()

        line = Wordstonumber(line)
        key = Wordstonumber(key)

        plainline = VigenereDecryption(line,key)
        plaintext = Numbertowords(plainline)
        print(plaintext)
        fout.write(plaintext)
