import numpy as np

# print("Input Key: ")
# key = list(map(int,input().split()))
print('Encryption Begins')
key = [5,8,13,7]
keyarr = np.array([[key[0],key[1]],[key[2],key[3]]])


def HillEncryption(words,key):
    plain = np.array([words[0],words[1]])
    cipher = (plain@key)%26
    return cipher

def SeperateLineToNumberWords(ogword):
    standard = ord('A')
    if ogword == " ":
        return ogword
    else:
        words = ord(ogword[0])-standard,ord(ogword[-1])-standard
        words = HillEncryption(words,keyarr)

        if len(ogword) > 2:
            return chr(words[0]+standard)+" "+chr(words[-1]+standard)
        
        return chr(words[0]+standard)+chr(words[-1]+standard)



fin = open("plaintext1.txt","r")
fout = open("ciphertext1.txt","w")

while True:
    line = fin.readline()
    if not line: break
    line = line.upper()

    if line[-1] == "\n":
        line = line[0:len(line)-1]
    
    i = 0
    while i<len(line):
        nextchar = True
        if line[i] == " ":
            word = " "
            i -= 1
        elif i+1==len(line):
            word = line[i]+"X"
            nextchar=False
        elif line[i+1] == " ":
            word = line[i]+" "+line[i+2]
            i += 1
        else:
            word = line[i]+line[i+1]
        
        i+=2
        words = SeperateLineToNumberWords(word)

        if nextchar == False:
            print(words)
            fout.write(words+"\n")
        else:
            print(words,end="")
            fout.write(words)

