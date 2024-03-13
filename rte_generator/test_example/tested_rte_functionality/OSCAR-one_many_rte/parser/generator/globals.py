global genfile
global warnings

global inc_path
inc_path = "../Os_Configure/inc/"

global src_path
src_path = "../Os_Configure/src/"

global application_path
application_path = "../application"

def warning(msg):
    global warnings
    #warnings += 1
    print("WARNING: " + msg)
    #print("WARNING: " + warnings)
    # 程式暫停的例子
    print("現在將暫停程式執行...")
    input("按 Enter 鍵繼續...")

def error(msg):
    global warnings
    #warnings += 1
    print("ERROR: " + msg)
    # 程式暫停的例子
    print("現在將暫停程式執行...")
    input("按 Enter 鍵繼續...")



def printFile(str):
    global genfile
    print ("{}".format(str),file=genfile)

def printFileSpace(str):
    global genfile
    print ("{}".format(str), file=genfile, end ='')