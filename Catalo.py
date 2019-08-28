import os
import re
import sys

class Catalo:
    """
    生成md文件目录的脚本，需要传入两个命令行参数：

    python Catalo.py [filepath] [options]

    :param: filepath: 要生成目录的文件或文件夹路径，不传或传入 -h 直接打印帮助信息
        如果传入文件夹路径，会为该文件夹下所有 .md 类型文件添加目录；
        允许传入绝对路径或相对路径。
    :param: [options]: 可选参数，有五种选项，-r,-w,-wr或-wr,-d,-h不区分大小写。

    -r: 只在终端打印目录，手动复制添加。
    -w: 在文件开头自动写入目录。
    -rw/-wr: 自动写入目录，同时打印在终端。
    -d: 删除由脚本添加的目录，区分标准是两个MD5字符串注释 ，所以如果修改了这两部分，使用该参数可能会删除整篇文章。
    -h: 打印帮助信息。

    """
    
    # TODO: 在特定位置添加目录
    # TODO：改变参数传递顺序，第一个参数不传或传入 -h 直接打印帮助信息

    def __init__(self, args: list):
        self._code = False  # 标记代码块

        if len(args) < 2:
            print(help(self))
            sys.exit()
        else:
            if args[1].lower() == '-h':
                print(help(self))
                sys.exit()
            else:
                self._filepath = args[1]
            try:
                second = args[2]
            except IndexError:
                second = '-RW'

            if second.lower() == '-r':
                self._is_read = True
                self._is_write = False
                self._is_Delete = False
            if second.lower() == '-w':
                self._is_read = False
                self._is_write = True
                self._is_Delete = False
            if second.lower() == '-rw' or second.lower() == '-wr':
                self._is_read = True
                self._is_write = True
                self._is_Delete = False
            if second.lower() == '-d':
                self._is_read = False
                self._is_write = False
                self._is_Delete = True
            if second.lower() == '-h':
                print(help(self))
                sys.exit()



    @staticmethod
    def _build_swop_file(source_path):
        """
        建立交换文件
        """
        swop_file_path = source_path + '.swop.md'
        os.system(f'copy {source_path} {swop_file_path}')
        return swop_file_path
    

    def _read_and_creat_catalo(self, swop_file_path):
        """
        读交换文件，并且生成文章目录
        """
        with open(swop_file_path, 'r', encoding='utf-8') as fp:
            lines = fp.readlines()

            for line in lines:

                # 避免代码块中python风格的注释被当作一级标题
                r = r'^```.+'
                res = re.match(r, line)
                if res is not None:
                    self._code = True
                r2 = r'^```$'
                res2 = re.match(r2, line)
                if res2 is not None:
                    self._code = False  # 代码块结束

                # 找到标题行
                r = r'^(#*# ).+'
                resault = re.match(r, line)
                if resault is not None and self._code is False:
                    resault = resault.group()
                    title = resault
                    

                    r3 = r'^(#*)'
                    r4 = r'^(#* )'

                    # 判断有几个#
                    resault = re.match(r3, resault).group()
                    title_size = len(resault)

                    # 根据#数量计算空格数
                    space_num = (title_size - 1) * 2

                    # 得到标题内容
                    # print(resault)
                    content = re.sub(r4, '', title)
                    space = ' '
                    # url = parse.quote(content)  # url编码                   
                    # repl = f'{space * space_num}* [{content}](#{url})'
                    repl = f'{space * space_num}* [{content}](#{content})'  # 列表内容
                    yield repl


    def _write_in_source_file(self, source_file_path: str):
        """
        把文章目录写入到源文件
        """
        
        swop_file_path = source_file_path + '.swop.md'
        is_first_write =True
        for repl in self._read_and_creat_catalo(swop_file_path):
            if self._is_write:
                # 第一次直接写入，以后追加写入
                if is_first_write:
                    write_type = 'w'
                else:
                    write_type = 'a'
                
                with open(source_file_path, write_type, encoding='utf-8') as fp:
                    if is_first_write:
                        fp.write(
                            '<!--961032830987546d0e6d54829fc886f6-->\n\n目录(Catalo)\n\n')
                    fp.write(repl + '\n')
                    is_first_write = False
            if self._is_read:
                print(repl)
        if self._is_write:
            # 最后再添加一行，用来与原文件区分
            with open(source_file_path, 'a', encoding='utf-8') as fp:
                # TODO: 通过该行与原文件内容进行区分，文章更新时便于删除通过脚本创建的目录，添加新目录
                fp.write('\n<!--a46263f7a69f33f39fc26f907cdb773a-->\n')
        if self._is_read:
            print()
        


    @staticmethod
    def _merge_file(source_file_path):
        """
        合并源文件和交换文件
        """
        swop_file_path = source_file_path + '.swop.md'
        with open(source_file_path, 'a', encoding='utf-8') as source_fp:
            with open(swop_file_path, 'r', encoding='utf-8') as swop_fp:
                lines = swop_fp.readlines()
                for line in lines:
                    source_fp.write(line)


    @staticmethod
    def _dele_swop_file(source_file_path):
        """
        删除交换文件
        """
        swop_file_path = source_file_path + '.swop.md'
        os.remove(swop_file_path)

    def _delete(self, filepath):
        """
        删除由本脚本添加的目录
        """
        source_file_path = filepath
        swop_file_path = source_file_path + '.swop.md'

        with open(swop_file_path, 'r', encoding='utf-8') as fp:
            lines = fp.readlines()
            isdelete = False
            is_first_write = True
            for line in lines:
                r = r'^(<!--961032830987546d0e6d54829fc886f6-->)'
                res = re.match(r, line)
                if res is not None:
                    isdelete = True
                
                if is_first_write:
                    write_type = 'w'
                else:
                    write_type = 'a'

                flag = '<!--a46263f7a69f33f39fc26f907cdb773a-->'
                if line != flag:
                    if isdelete is False :
                        with open(source_file_path, write_type, encoding='utf-8') as sour_fp:
                            sour_fp.write(line)
                            is_first_write = False
                
                r2 = r'^(<!--a46263f7a69f33f39fc26f907cdb773a-->)$'
                res2 = re.match(r2, line)
                if res2 is not None:
                    # TODO:
                    isdelete = False



    def _file(self, filepath: str):
        """
        文件，执行这个函数
        """
        source_file_path = os.path.abspath(filepath)
        file_name = filepath.split('\\')[-1]
        self._build_swop_file(source_file_path)

        if self._is_Delete is False:
            self._write_in_source_file(source_file_path)
            self._merge_file(source_file_path)
            if self._is_write:
                print(f'{file_name} 目录已添加')
        else:
            self._delete(source_file_path)
            print(f'{file_name} 目录已删除')
        
        self._dele_swop_file(source_file_path)

    def _folder(self, filepath):
        """
        文件夹，执行这个函数
        """
        # 得到该目录下的所有文件
        list_dir = os.listdir(filepath)
        path_save = filepath
        for dir in list_dir:
            if filepath[-1] == '\\':
                filepath = f'{path_save}{dir}'
            else:
                filepath = f'{path_save}\\{dir}'

            abs_root_dir = os.path.abspath(filepath)
            if os.path.isfile(abs_root_dir):
                filetype = abs_root_dir.split('.')[-1]
                if filetype.lower() == 'md':
                    absdir = os.path.abspath(abs_root_dir)
                    self._file(absdir)
            
            else:
                absdir = os.path.abspath(abs_root_dir)
                self._folder(absdir)


    def run(self):
        """
        程序入口，判断是文件夹还是文件
        """
        path = os.path.abspath(self._filepath)
        if os.path.isfile(path):
            self._file(path)
        else:
            self._folder(path)


if __name__ == '__main__':
    argv = sys.argv
    print(argv)
    catalo = Catalo(argv)
    print()
    catalo.run()
