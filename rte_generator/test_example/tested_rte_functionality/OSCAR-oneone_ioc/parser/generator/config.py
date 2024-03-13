from generator.oilParser import oilParserClass
from functools import wraps

class configClass():
    def __init__(self):
        self.config = []

    #def configClass():
    
    def parseOilFile(self, file):
      parser = oilParserClass(self, file)
      tmp = parser.getOil()
      for element in tmp:
        self.config.append(element)

    #def parseAutosarFile():

    def getValue(self, root, type):
        ret = False
        for element in self.config:
            if  ((element["root"] == root) and (element["type"] == type)) :
                value = element["value"]
                if(value.find("\"") != -1):
                    # remove quotation marks
                    value = value[1:-1]
                return value
        return ret


    def getValuewithParent(self, root, type, parent):
        ret = False
        flag = 0

        for element in self.config:
            if ( element["root"] == root) and (element["type"] == type):
                flag = 1
                value = element["value"]
                if(value.find( "\"") != -1):
                    # remove quotation marks 
                    value = value[1:-1]
            
        # print($element["type"] ."  R(".$element["root"].")". "  P($parent)" . "  T($type)\n")
            if((flag == 1) and element["type"] == parent):
                return value
        return ret

    def getBase(self, db, root):
        ret = []
        for el in db:
            if el["root"] == root:
                ret.append(el)
        return ret

    def getCount(self, root, type):
        ret = 0
        for element in self.config:
            if ( ( (element["root"] == root) and (element["type"] == type) ) or ( (element["root"] == root) and (type == "*") ) ):
                ret += 1
        return ret

    def getList(self, root, type):
        ret = []
        for element in self.config:
            #print(element["type"])
            #print(type)
            if ( ( (element["root"] == root) and (element["type"] == type) ) or ( (element["root"] == root) and (type == "*") ) ):
                ret.append(element["value"])
        return ret

    def getListwithParent(self, root, type, parent):
        ret = False
        flag = 0
        for element in self.config:
            if ( ( (element["root"] == root) and (element["type"] == type) ) or ( (element["root"] == root) and (type == "*") ) ):
                flag = 1
                value = element["value"]
            if((flag == 1) and element["type"] == parent):
                return value
        return ret

    def listAll(self):
        ret = []
        ret = self.listar(self.config)
        return ret

    def exist(self, root, attr):
        attributes = self.getAttributes(root)
        for attribute in attributes:
            if (attribute == attr):
                return True
        return False

    def getAttributes(self, root):
        ret = []
        for element in self.config:
            if ( element["root"] == root ):
                ret.append(element["type"])
        return ret

    
    
confile = "osekout.oil"
parser = oilParserClass(confile)
parser.oilParserClass()

global config
config = configClass()
config.config = parser.getOil()



