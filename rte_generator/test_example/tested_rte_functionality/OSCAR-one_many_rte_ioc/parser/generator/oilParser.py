import string
import os.path
# import generator as gr
from functools import wraps

class oilParserClass:
    def __init__(self, file):
        self.file =  file
        self.lines = None
        self.line = 0
        self.inst = 0
        self.config = []
        self.a = []
        self.i = 0
    
    def removeComments(self):
        # todo removeall comments
        for l in range(len(self.lines)):
            # remove spaces and tabs at start and end of the line
            self.lines[l] = self.lines[l].strip()
                        
            condition = True
            while condition == True:
                # replaces multiply spaces with only one
                self.lines[l] = ' '.join(self.lines[l].split())    #去除多餘空格
                # remove multpy tabs or tabs with one space
                self.lines[l] = self.lines[l].replace('\t','')    #去除\t
                if ( len(self.lines[l]) > 1 ) and ( self.lines[l].find("  ") != -1):
                    condition = True
                else:
                    condition = False
            # remove spaces sides of = 
            
            self.lines[l] = self.lines[l].replace(" = ", "=")

            # remove space before ; 
            self.lines[l] = self.lines[l].replace(" ;",";")

            # remove ; */
            self.lines[l] = self.lines[l].replace(";","")

            # remove c++ comments 
            if ( self.lines[l].find("//") != -1 ):
                tmp = self.lines[l].split("//")
                self.lines[l] = tmp[0]

            # remove c comments in a complete line0.
            # to do...remove complex comments
            if ( self.lines[l].find("/*") == 0 and self.lines[l].find("*/") == len(self.lines[l])-2):
                self.lines[l] = ""
        
    def resetLine(self):
        self.line = 0

    def nextLine(self):
      self.line += 1

    def eof(self):
        ret = False
        if ( self.line == len(self.lines) ):
            ret = True
        return ret

    def getDefinition(self):
        ret = ["", "", False, False]
        tmp = self.lines[self.line]
        if  ( tmp.find("{") != -1 ):
            ret[2] = True
            tmp = tmp.split("{")
            tmp = tmp[0]
            #print(tmp)
            if ( tmp.find("=") != -1 ):
                ret[3] = True
        if (tmp != ""):
            if ( tmp.find("=") != -1 ):
                tmp = tmp.split("=")
                ret[0] = tmp[0]
                ret[1] = tmp[1]
            else:
                tmp = tmp.split(" ")
                
                ret[0] = tmp[0]
                if len(tmp[1]) != 0:
                    ret[1] = tmp[1]
                else:
                    ret[1] = ""
        return ret

    

    def oilParserClass(self):
        #if (os.path.exists(file) == False):
        #    gr.error('Configuration file ' + file + ' not found.')
        f = open(self.file)
        self.lines = f.readlines()
        entry = []
        self.removeComments()
        #print(self.lines)
        self.resetLine()

        #$entry["root"] = "/OSEK";
        #$entry["type"] = "OSEK";
        #$entry["name"] = "";

        #$this->config[] = $entry;

        #$this->parser("/OSEK");
        self.parser("")

    def getOil(self):
        return self.config

    
    def setVar(varname, val):
        def wrapper(originFunction):
            @wraps(originFunction)
            def inner(*arg, **kwarg):
                return originFunction(*arg, **kwarg)
            setattr(inner, varname, val)
            return inner  # wrapper return
        return wrapper
    '''
    @setVar("inst", 0)        #靜態變數  
    '''
    def parser(self, root):
        entry = {}
        self.inst += 1
        
        while( ( ( self.inst == 1 ) and (self.eof() == False ) ) or
               ( ( self.inst != 1 ) and (self.lines[self.line].find("}") == -1  ) ) ):
            ddef = self.getDefinition()    #ddef = def

            if ( ddef[0] != ""):
                self.a.append({"root": root})
                self.a[self.i]["type"] = ddef[0].strip()
                self.a[self.i]["value"] = ddef[1].strip()      #trim 換成strip
                #print(entry)
                #print(self.config)
                self.config.append(self.a[self.i])
                self.i += 1
                if ( ddef[2] == True ):
                    self.nextLine()
                    if ( ddef[0] != "AUTOSTART" ):
                        if ( ddef[3] == True ):
                            self.parser(root + "/" + ddef[0].strip())
                        else:
                            self.parser(root + "/" + ddef[1].strip())
                    else:
                        self.parser(root)
                else:
                    self.nextLine()
                #print(entry)

                
                #print(self.config)
            
            else:
                self.nextLine()
        
        if ( self.inst != 1 ):
            self.nextLine()
        
        self.inst -= 1

    def add(self, entry):
        
        self.config.append(entry)


