import re
from urllib import parse
import sys


class Catalo:
    def __init__(self, filepath: str):
        self._filepath = filepath
        filetype = filepath.split('.')[-1]
        if filetype.lower() != 'md':
            error = Exception('请传入md类型文件')
            raise error
        self._code = False


    def _read(self):
        with open(self._filepath, 'r', encoding='utf-8') as fp:
            lines = fp.readlines()       

            for line in lines:
                r = r'^```.+'
                res = re.match(r, line)
                if res is not None:
                    self._code = True

                r2 = r'^```$'
                res2 = re.match(r2, line)
                if res2 is not None:  
                    self._code = False

                r = r'^(#*# ).+'
                resault = re.match(r, line)
                if resault is not None and self._code is not True:
                    resault = resault.group()
                    yield resault


    def _Conversion(self):
        for item in self._read():
            r = r'^(#*)'
            r2 = r'^(#* )'
            resault = re.match(r, item).group()
            title_size = len(resault)
            space_num = (title_size - 1) * 2
            content = re.sub(r2, '', item)
            url = content  # url编码
            repl = f'{" " * space_num} * [{content}](#{url})'
            resault = re.sub(r,repl, resault)
            print(resault)


    def run(self):
        self._Conversion()
                

if __name__ == '__main__':
    path = sys.argv[1]
    catalo = Catalo(path)
    print()
    catalo.run()
