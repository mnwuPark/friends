import os, datetime
kcal = 0

def wist():
    l = datetime.datetime.now()
    ll = str(l.year)+"_"+str(l.month)+"_"+str(l.day)
    return ll

def main():
    today = wist()
    file = os.getcwd()
    if os.path.isfile(file+"\\"+today+".txt"):
        opf = open(today+".txt", "r")
    else:
        opf = open(today+".txt", "w")
        opf.write("0")
    opf.close()
    while True:
        global kcal
        os.system('cls')
        opf = open(today+".txt", "r")
        opfr = opf.read()
        kcal = int(opfr)
        opf.close()
        print("pre kcal = "+str(kcal))
        print("insert kcal\n")
        kcal = int(input("")) + kcal
        opf = open(today+".txt", "w")
        opf.write(str(kcal))
        opf.close()
main()