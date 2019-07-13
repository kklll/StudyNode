```python
# 671,476,771, 501
import requests, json, time, re
from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.common.action_chains import ActionChains
from PIL import Image
from pytesseract import *
import numpy as np
import re

banji = [
    '17070047'
]
timeout=0.3
# with open('E:\\python代码\\venv\\ok.json') as file_obj:
#     finish=json.load(file_obj)
#     #print(finish)
# file_obj.close()
xxxx=0
i = 0
b = webdriver.Firefox()
needlist=["毛泽东思想和中国特色社会主义理论体系概论","大学英语A（4）","算法分析与设计","计算机网络基础","大学物理实验 （2）","算法程序设计实验周","面向对象程序设计（C++）","体育（4）"]
# for banjibianhao in banji:
#     for bianhao in range(1, 60):
#         if bianhao < 10:
#             bianhao = '0' + str(bianhao)
#         xuehao = str(str(banjibianhao) + str(bianhao))
#         print(str(banjibianhao) + str(bianhao))
with open("C:\\Users\\DeepBlue\\Desktop\\name.CSV", "r") as num:
    while True:
        line = num.readline()
        etc = line.split(",")
        name = etc[0]
        xuehao = etc[1]
        if not name:
            break
        # if xuehao in finish:
        #     continue
        ActionChains(b).key_down(Keys.CONTROL).send_keys("t").key_up(Keys.CONTROL).perform()
        b.get('http://202.207.177.39:8089/')
        time.sleep(timeout)
        tupian = b.get_screenshot_as_file("e:\\1.png")
        region = (671, 476, 771, 501)
        c = Image.open("e:\\1.png")
        d = c.crop(region)
        # d.show()
        asd = pytesseract.image_to_string(d)
        asd = asd.replace(' ', '')
        asd = asd.replace('.', '')
        asd = asd.replace("'", '')
        asd = asd.replace(';', '')
        asd = asd.replace('`', '')
        asd = asd.replace('/', '')
        asd = asd.replace('!', '')
        asd = asd.replace('"', '')
        asd = asd.replace('<', '')
        asd = asd.replace('>', '')
        asd = asd.replace('`', '')
        asd = asd.replace('"', '')
        asd = asd.upper()
        if asd != '':
            asd = asd
        else:
            asd = 'aaaa'
        # b.find_element_by_xpath(
        #     '/html/body/table/tbody/tr/td/table[3]/tbody/tr[1]/td[2]/form/table/tbody/tr[2]/td/table/tbody/tr[1]/td[2]/input').send_keys(
        #     str(banjibianhao) + str(bianhao))
        # b.find_element_by_xpath(
        #     '/html/body/table/tbody/tr/td/table[3]/tbody/tr[1]/td[2]/form/table/tbody/tr[2]/td/table/tbody/tr[2]/td[2]/input').send_keys(
        #     str(banjibianhao) + str(bianhao))
        b.find_element_by_xpath(
            '/html/body/table/tbody/tr/td/table[3]/tbody/tr[1]/td[2]/form/table/tbody/tr[2]/td/table/tbody/tr[1]/td[2]/input').send_keys(
            xuehao)
        b.find_element_by_xpath(
            '/html/body/table/tbody/tr/td/table[3]/tbody/tr[1]/td[2]/form/table/tbody/tr[2]/td/table/tbody/tr[2]/td[2]/input').send_keys(
            xuehao)
        b.find_element_by_xpath(
            '/html/body/table/tbody/tr/td/table[3]/tbody/tr[1]/td[2]/form/table/tbody/tr[2]/td/table/tbody/tr[3]/td[2]/input').send_keys(
            asd)
        b.find_element_by_xpath('//*[@id="btnSure"]').click()
        # print(b.page_source)
        ActionChains(b).key_down(Keys.CONTROL).send_keys("w").key_up(Keys.CONTROL).perform()
        key1 = '<strong><font color="#990000">(.*?)</font></strong><br>'
        xinxi = re.findall(key1, b.page_source)
        if xinxi:
            while '你输入的验证码错误，请您重新输入！' in xinxi:
                time.sleep(timeout)
                tupian = b.get_screenshot_as_file("e:\\1.png")
                region = (671, 476, 771, 501)
                c = Image.open("e:\\1.png")
                d = c.crop(region)
                asd = pytesseract.image_to_string(d)
                asd = asd.replace(' ', '')
                asd = asd.replace('.', '')
                asd = asd.replace("'", '')
                asd = asd.replace(';', '')
                asd = asd.replace('`', '')
                asd = asd.replace('/', '')
                asd = asd.replace('!', '')
                asd = asd.replace('"', '')
                asd = asd.replace('<', '')
                asd = asd.replace('>', '')
                asd = asd.replace('`', '')
                asd = asd.replace('"', '')
                asd = asd.upper()
                if asd != '':
                    asd = asd
                else:
                    asd = 'aaaa'
                # b.find_element_by_xpath(
                #     '/html/body/table/tbody/tr/td/table[3]/tbody/tr[1]/td[2]/form/table/tbody/tr[2]/td/table/tbody/tr[1]/td[2]/input').send_keys(
                #     str(banjibianhao) + str(bianhao))
                # b.find_element_by_xpath(
                #     '/html/body/table/tbody/tr/td/table[3]/tbody/tr[1]/td[2]/form/table/tbody/tr[2]/td/table/tbody/tr[2]/td[2]/input').send_keys(
                #     str(banjibianhao) + str(bianhao))
                b.find_element_by_xpath(
                    '/html/body/table/tbody/tr/td/table[3]/tbody/tr[1]/td[2]/form/table/tbody/tr[2]/td/table/tbody/tr[1]/td[2]/input').send_keys(
                    xuehao)
                b.find_element_by_xpath(
                    '/html/body/table/tbody/tr/td/table[3]/tbody/tr[1]/td[2]/form/table/tbody/tr[2]/td/table/tbody/tr[2]/td[2]/input').send_keys(
                    xuehao)
                b.find_element_by_xpath(
                    '/html/body/table/tbody/tr/td/table[3]/tbody/tr[1]/td[2]/form/table/tbody/tr[2]/td/table/tbody/tr[3]/td[2]/input').send_keys(
                    asd)
                b.find_element_by_xpath('//*[@id="btnSure"]').click()
                key1 = '<strong><font color="#990000">(.*?)</font></strong><br>'
                xinxi = re.findall(key1, b.page_source)
            if '您的密码不正确，请您重新输入！' in xinxi:
                i = i + 1
                if i == 3:
                    break
                ActionChains(b).key_down(Keys.CONTROL).send_keys("w").key_up(Keys.CONTROL).perform()
                continue
        req = requests.session()
        cookies = b.get_cookies()
        # print(cookies)
        for cookie in cookies:
            req.cookies.set(cookie['name'], cookie['value'])
        req.headers.clear()
        try:
            b.delete_all_cookies()
        except:
            continue
        jieguo = req.get('http://202.207.177.39:8089/xjInfoAction.do?oper=xjxx')
        xingming = '<td class="fieldName" width="180">姓名:&nbsp;</td>\r\n\t\t\t\t\t\t\t\t\t\t\r\n\t\t\t\t\t\t\t\t\t\t<td width="275">\r\n\t\t\t\t\t\t\t\t\t\t&nbsp;(.*?)\r\n\t\t\t\t\t\t\t\t\t\t</td>'
        xingming1 = re.findall(xingming, jieguo.text)
        # jieguo = req.get('http://202.207.177.39:8089/gradeLnAllAction.do?type=ln&oper=fainfo&fajhh=2442')
        jieguo=req.get("http://202.207.177.39:8089/gradeLnAllAction.do?type=ln&oper=qbinfo&lnxndm=2018-2019%D1%A7%C4%EA%B4%BA(%C1%BD%D1%A7%C6%DA)#qb_2018-2019学年春(两学期)")
        # b.close()
        # print(jieguo.content)
        # print(jieguo.text)
        bixiuchengji = '<td align="center">\r\n\s*(.*?)\r\n\s*</td>\r\n\s*<td align="center">\r\n\s*&nbsp;\r\n\s*</td>\r\n \s*<td align="center">\r\n \s* .*?\r\n\s*</td>\r\n\s*<td align="center">\r\n\s*.*?\r\n\s*</td>\r\n\s*<td align="center">\r\n\s*\r\n\s*\t*<p align="center">(.*?)&nbsp;'
        #         wuli='物理:&nbsp;\r\n\t\t\t\t\t\t\t\t\t</td>\r\n\t\t\t\t\t\t\t\t\t\r\n\t\t\t\t\t\t\t\t\t\r\n\t\t\t\t\t\t\t\t\t<td align="left" width="275" \r\n\t\t\t\t\t\t\t\t\t\t>\r\n\t\t\t\t\t\t\t\t\t\r\n\t\t\t\t\t\t\t\t\t  &nbsp;(.*?)\r\n\t\t\t\t\t\t\t\t\t</td>'
        #         yingyu='英语:&nbsp;\r\n\t\t\t\t\t\t\t\t\t</td>\r\n\t\t\t\t\t\t\t\t\t\r\n\t\t\t\t\t\t\t\t\t\r\n\t\t\t\t\t\t\t\t\t<td align="left" width="275" \r\n\t\t\t\t\t\t\t\t\t\t>\r\n\t\t\t\t\t\t\t\t\t\r\n\t\t\t\t\t\t\t\t\t  &nbsp;(.*?)\r\n\t\t\t\t\t\t\t\t\t</td>'
        #         xingming1=re.findall(xingming,jieguo.text)
        chengji1 = re.findall(bixiuchengji, jieguo.text)
        # print(chengji1)
        xx = np.array(chengji1)
        print(xx.shape[0])
        print(chengji1)
        chengjiname=[i[0] for i in chengji1 ]
        chengjiresult=[i[1] for i in chengji1 ]
        fp = open("C:\\Users\\DeepBlue\\Desktop\\成绩.txt", "a+")
        # if chengji1[1][0] == '中国近现代史纲要' and chengji1[4][0] == '大学英语A（2）' and chengji1[9][0] == '离散数学' and chengji1[11][
        #     0] == '高等数学A （2）' and chengji1[13][0] == '大学物理A （1）':
        #     print('ok!')
        #         jiguan1=re.findall(wuli,jieguo.text)
        #         jiguan1=re.findall(yingyu,jieguo.text)
        #         shenfenzheng1=re.findall(shenfenzheng,jieguo.text)
        #         print(xingming1)
        #         print(xingbie1)
        #         print(jiguan1)
        #         print(shenfenzheng1)
        if xxxx==0:
            fp.write(",,")
            for i in needlist:
                fp.write(i+",")
            fp.write("\r\n")
        fp.write(name+","+xuehao+",")
        for x in needlist:
            if(x in chengjiname):
                for i in range(xx.shape[0]):
                    if chengji1[i][0]==x:
                        fp.write(chengji1[i][1]+',')
            else:
                fp.write(str(-1)+",")
        fp.write("\n")
        fp.flush()
        xxxx+=1
fp.close()
        # fp = open("C:\\Users\\DeepBlue\\Desktop\\成绩.txt", "a")
        # fp.write(
        #     str(xuehao) + str(name) + '\t' + xingming1[0] + '\t' + chengji1[0][1] + '\t' + chengji1[4][
        #         1] + '\t' + chengji1[9][1] + '\t' + chengji1[11][1] + '\t' + chengji1[13][1] + '\t' + chengji1[-1][
        #         1] + '\n')
        # fp.close()
#         finish.append(str(banjibianhao)+str(bianhao))
#         with open('E:\\python代码\\venv\\ok.json','w')as file_obj2:
#             json.dump(finish,file_obj2)
#         file_obj.close()
#         i=0
# start =time.clock()
# print(start)

```